/*
 * graph.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "vertex.h"
#include "graph.h"
#include "libncc.h"
#include "utils.h"

static void graph_sETtOTALvERTICES (Graph g, int totalVertices);
static void graph_nEWaDJACENCYlISTS (Graph g, int numberOfVertices);
static void graph_nEWvERTEXlIST (Graph g, int numberOfVertices);
static void graph_dESTROYaDJACENCYlIST (Graph g, Vertex v);
static void graph_rEMOVEfROMvERTEXlIST (Graph g, Vertex v);
static void graph_rEMOVEfROMaDJACENCYlISTS (Graph g, Vertex v);
static void graph_dESTROYvERTEXrEFERENCES (Graph g, Vertex v);
static void graph_dESTROYaDJACENCYlISTS (Graph g);
static void graph_dESTROYvERTEXlIST (Graph g);
static bool graph_cHECKaDJACENCYvALIDITYnOToUToFbOUNDS (Graph g, Vid from,
							Vid to);
static bool graph_cHECKaDJACENCYvALIDITYvERTICESeXISTENCE (Graph g,
							   Vid from, Vid to);
static bool graph_cHECKaDJACENCYvALIDITYnOdOUBLEeDGES (Graph g, Vid from,
						       Vid to);
static bool graph_cHECKaDJACENCYvALIDITY (Graph g, Vid from, Vid to);

/**********************
 **** Constructors ****
 **********************
 */
static void
graph_sETtOTALvERTICES (Graph g, int totalVertices)
{
  assert (!element_null (g));
  /* Assign initial number of vertices. */
  g->totalVertices = totalVertices;
}

static void
graph_nEWaDJACENCYlISTS (Graph g, int numberOfVertices)
{
  int i;

  assert (!element_null (g));
  /* New adjacency lists. */
  g->adjacencies = malloc_safe (sizeof (list) * numberOfVertices);
  for (i = 0; i < numberOfVertices; i++)
    list_init (&(g->adjacencies[i]));
}

static void
graph_nEWvERTEXlIST (Graph g, int numberOfVertices)
{
  int i;
  Vertex v;

  assert (!element_null (g));
  /* New vertex list. */
  list_init (&(g->vertices));
  for (i = 0; i < numberOfVertices; i++)
    list_append (vertex_new (&v, i), &(g->vertices));
}

/*********************
 **** Destructors ****
 *********************
 */
/* Destroy from v to u. */
static void
graph_dESTROYaDJACENCYlIST (Graph g, Vertex v)
{
  assert (!element_null (g) && !element_null (v));
  list_destroy (&(g->adjacencies[v->id]));
}

/* Remove v from the vertex list. */
static void
graph_rEMOVEfROMvERTEXlIST (Graph g, Vertex v)
{
  list vertices = g->vertices;

  assert (!element_null (g) && !element_null (v));
  while (!list_null (vertices))
    {
      if (list_head (vertices)->id == v->id)
	list_remove (&(g->vertices), vertices);
      vertices = list_next (vertices);
    }
}

/* Destroy from u to v, i.e. remove all v entries in adj lists.
 * From all active vertices, iterate through their adjacency lists
 * and remove all occurrences of v.
 */
static void
graph_rEMOVEfROMaDJACENCYlISTS (Graph g, Vertex v)
{
  list vertices = g->vertices;
  list *adjacencies = g->adjacencies;
  list adjs;

  assert (!element_null (g) && !element_null (v));
  while (!list_null (vertices))
    {
      adjs = adjacencies[list_head (vertices)->id];
      while (!list_null (adjs))
	{
	  if (list_head (adjs)->id == v->id)
	    list_remove (&(g->adjacencies[list_head (vertices)->id]), adjs);
	  adjs = list_next (adjs);
	}
      vertices = list_next (vertices);
    }
}

static void
graph_dESTROYvERTEXrEFERENCES (Graph g, Vertex v)
{
  assert (!element_null (g) && !element_null (v));
  graph_dESTROYaDJACENCYlIST (g, v);
  graph_rEMOVEfROMvERTEXlIST (g, v);
  graph_rEMOVEfROMaDJACENCYlISTS (g, v);
}

static void
graph_dESTROYaDJACENCYlISTS (Graph g)
{
  assert (!element_null (g));
  free (g->adjacencies);
}

static void
graph_dESTROYvERTEXlIST (Graph g)
{
  list vertices = g->vertices;
  Vertex v = list_head (vertices);

  assert (!element_null (g));
  while (!list_null (vertices))
    {
      v = list_head (vertices);
      graph_dESTROYvERTEXrEFERENCES (g, v);
      vertex_destroy (v);
      vertices = list_next (vertices);
    }
}

/*************************
 **** Other functions ****
 *************************
 */
/* Basic out of bounds check. */
static bool
graph_cHECKaDJACENCYvALIDITYnOToUToFbOUNDS (Graph g, Vid from, Vid to)
{
  int totalVertices = g->totalVertices;

  assert (!element_null (g));
  if (from > totalVertices - 1 || to > totalVertices - 1)
    return false;
  else
    return true;
}

/* Both vertices must exist */
static bool
graph_cHECKaDJACENCYvALIDITYvERTICESeXISTENCE (Graph g, Vid from, Vid to)
{
  list vertices = g->vertices;

  assert (!element_null (g));
  if (element_null (vertex_getFromId (vertices, from))
      || element_null (vertex_getFromId (vertices, to)))
    return false;
  else
    return true;
}

/* No double edges are permitted. */
static bool
graph_cHECKaDJACENCYvALIDITYnOdOUBLEeDGES (Graph g, int idFrom, int idTo)
{
  list lFrom = g->adjacencies[idFrom];

  assert (!element_null (g));
  /* Vertex already exists in idFrom's adjacency list. */
  if (!element_null (vertex_getFromId (lFrom, idTo)))
    return false;
  else
    return true;
}

static bool
graph_cHECKaDJACENCYvALIDITY (Graph g, int idFrom, int idTo)
{
  /* These controls are important because the graphs will be generated 
   * randomly.
   */
  assert (!element_null (g));
  if (!graph_cHECKaDJACENCYvALIDITYnOToUToFbOUNDS (g, idFrom, idTo)
      || !graph_cHECKaDJACENCYvALIDITYvERTICESeXISTENCE (g, idFrom, idTo)
      || !graph_cHECKaDJACENCYvALIDITYnOdOUBLEeDGES (g, idFrom, idTo))
    return false;
  else
    return true;
}

/**************************
 **** Public functions ****
 **************************
 */
Graph
graph_new (Graph * gRef, int numberOfVertices)
{
  *gRef = malloc_safe (sizeof (struct GraphObject));

  graph_sETtOTALvERTICES (*gRef, numberOfVertices);
  graph_nEWaDJACENCYlISTS (*gRef, numberOfVertices);
  graph_nEWvERTEXlIST (*gRef, numberOfVertices);

  return *gRef;
}

/* from adj to. */
bool
graph_setAdjacent (Graph g, Vid from, Vid to)
{
  assert (!element_null (g));

  if (graph_cHECKaDJACENCYvALIDITY (g, from, to))
    {
      list_append (vertex_getFromId (g->vertices, to),
		   &(g->adjacencies[from]));
      return true;
    }
  else
    return false;
}

/* Remove a vertex and all its references. */
void
graph_destroyVertex (Graph g, Vid id)
{
  Vertex v = vertex_getFromId (g->vertices, id);

  assert (!element_null (g));
  if (!element_null (v))
    {
      graph_dESTROYvERTEXrEFERENCES (g, v);
      vertex_destroy (v);
    }
}

void
graph_destroy (Graph * gRef)
{
  graph_dESTROYvERTEXlIST (*gRef);
  graph_dESTROYaDJACENCYlISTS (*gRef);
  free (*gRef);
  *gRef = NULL;
}


void
graph_print (Graph g)
{
  list adjs;
  list vertices = g->vertices;

  assert (!element_null (g));
  fprintf (stderr, "Data of Graph %p\n", (void *) g);
  fprintf (stderr, "----\n");
  fprintf (stderr, "Number of initial Vertices %d\n", g->totalVertices);
  fprintf (stderr, "Number of active Vertices %d\n", list_length (vertices));
  fprintf (stderr, "----\n");

  while (!list_null (vertices))
    {
      vertex_print (list_head (vertices));
      fprintf (stderr, "\tadjacencies: ");
      adjs = g->adjacencies[list_head (vertices)->id];
      while (!list_null (adjs))
	{
	  fprintf (stderr, "%d ", list_head (adjs)->id);
	  adjs = list_next (adjs);
	}
      fprintf (stderr, "\n");
      vertices = list_next (vertices);
    }
}
