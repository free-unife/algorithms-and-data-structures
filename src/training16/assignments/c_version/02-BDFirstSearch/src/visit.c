/*
 * visit.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "utils.h"
#include "libncc.h"
#include "vertex.h"
#include "graph.h"
#include "visit.h"

static int visit_dEPTHvISIT (Graph g, Vertex u, int time);

/* Return maximum queue size. */
int
visit_BFS (Graph g, Vertex s)
{
  /* See DFS for the reason why max starts from 1. */
  int max = 1;
  list vertices = g->vertices;
  list *adjacencies = g->adjacencies;
  list adjs;
  Vertex u, v;
  queue Q;

  assert (!element_null (g) || !element_null (s));
  /* Set default values. */
  while (!list_null (vertices))
    {
      u = list_head (vertices);
      if (u->id != s->id)
	{
	  sprintf (u->color, "%s", "WHITE");
	  u->d = INF;
	  u->p = NULL;
	}
      vertices = list_next (vertices);
    }
  sprintf (s->color, "%s", "GRAY");

  queue_init (&Q);
  queue_enqueue (s, &Q);
  while (!queue_null (Q))
    {
      u = queue_dequeue (&Q);
      adjs = adjacencies[u->id];
      while (!list_null (adjs))
	{
	  v = list_head (adjs);
	  if ((strcmp (v->color, "WHITE")) == 0)
	    {
	      sprintf (v->color, "%s", "GRAY");
	      v->d = u->d + 1;
	      v->p = u;
	      queue_enqueue (v, &Q);

	      /* Get queue maximum. */
	      if (queue_length (Q) > max)
		max = queue_length (Q);
	    }
	  adjs = list_next (adjs);
	}
    }

  list_destroy (&Q);

  return max;
}

/* Return maximum stack size. */
int
visit_DFS (Graph g, Vertex s)
{
  /* max starts from 1 because of the push operation of s. */
  int max = 1;
  int time = 0;
  list *adjacencies = g->adjacencies;
  list vertices = g->vertices;
  list adjs;
  Vertex u, v;
  stack S;
  bool adjsToVisit;

  assert (!element_null (g) || !element_null (s));
  /* Set default values. Unreachable vertices are removed with bFS, so the d 
   * field of the vertices must not be modified in dFS.
   */
  while (!list_null (vertices))
    {
      sprintf (list_head (vertices)->color, "%s", "WHITE");
      list_head (vertices)->p = NULL;
      vertices = list_next (vertices);
    }

  /* Discovering s. */
  sprintf (s->color, "%s", "GRAY");
  time++;
  s->d = time;
  stack_init (&S);
  stack_push (s, &S);
  /* Stack length == 1 here. */

  while (!stack_null (S))
    {
      u = list_head (S);
      adjs = adjacencies[u->id];
      adjsToVisit = true;
      while (!list_null (adjs))
	{
	  v = list_head (adjs);
	  /* If the vertex has not been visited. */
	  if (strcmp (v->color, "WHITE") == 0)
	    {
	      sprintf (v->color, "%s", "GRAY");
	      v->p = u;
	      time++;
	      v->d = time;
	      stack_push (v, &S);

	      if (stack_length (S) > max)
		max = stack_length (S);

	      break;
	    }
	  else
	    {
	      adjsToVisit = false;
	    }

	  adjs = list_next (adjs);
	}

      if (adjsToVisit == false || list_null (adjacencies[u->id]))
	{
	  sprintf (u->color, "%s", "BLACK");
	  stack_pop (&S);
	  time++;
	  u->f = time;
	}
    }

  return max;
}

/* Unreachable vertices have v->d == INF. */
void
visit_removeUnreachableVertices (Graph g)
{
  list vertices = g->vertices;

  assert (!element_null (g));
  while (!list_null (vertices))
    {
      if (list_head (vertices)->d == INF)
	graph_destroyVertex (g, list_head (vertices)->id);
      vertices = list_next (vertices);
    }
}


/* Other stuff */

static int
visit_dEPTHvISIT (Graph g, Vertex u, int time)
{
  list *adjacencies = g->adjacencies;
  list adjs;
  Vertex v;

  time++;
  u->d = time;
  sprintf (u->color, "%s", "GRAY");

  adjs = adjacencies[u->id];
  while (!list_null (adjs))
    {
      v = list_head (adjs);
      if (strcmp (v->color, "WHITE") == 0)
	{
	  v->p = u;
	  visit_dEPTHvISIT (g, v, time);
	}

      sprintf (u->color, "%s", "BLACK");
      time++;
      u->f = time;
      adjs = list_next (adjs);
    }

  return time;
}

void
visit_DFSRecursive (Graph g)
{
  list vertices = g->vertices;
  Vertex u;
  int time;

  assert (!element_null (g));
  while (!list_null (vertices))
    {
      u = list_head (vertices);
      sprintf (u->color, "%s", "WHITE");
      u->p = NULL;
      vertices = list_next (vertices);
    }
  time = 0;

  vertices = g->vertices;
  while (!list_null (vertices))
    {
      u = list_head (vertices);
      if (strcmp (u->color, "WHITE") == 0)
	time = visit_dEPTHvISIT (g, u, time);
      vertices = list_next (vertices);
    }
}
