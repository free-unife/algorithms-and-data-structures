/*
 * test.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "graph.h"
#include "libncc.h"
#include "test.h"
#include "utils.h"
#include "vertex.h"
#include "visit.h"
#include "helper.h"

#if defined VERTEX_C
int
main (void)
{
  Vertex v;
  list vertices;

  assert (!element_null (vertex_new (&v, 5)));
  vertex_print (v);

  list_init (&vertices);
  list_append (v, &vertices);
  assert (!element_null (vertex_getFromId (vertices, 5)));

  list_destroy (&vertices);
  vertex_destroy (v);

  return 0;
}

#elif defined GRAPH_C
int
main (void)
{
  int n = 10;
  Graph g;

  graph_new (&g, n);
  assert (list_length (g->vertices) == n);

  assert (graph_setAdjacent (g, 2, 4) && graph_setAdjacent (g, 5, 2));

  /* Remove vertex 2. */
  graph_destroyVertex (g, 2);

  /* Assert all new adjacencies. */
  assert (graph_setAdjacent (g, 0, 1)
	  && graph_setAdjacent (g, 0, 0)
	  && graph_setAdjacent (g, 1, 0)
	  && graph_setAdjacent (g, 3, 5)
	  && graph_setAdjacent (g, n - 1, (n - 1) / 2));

  /* Out of bounds. */
  assert (!graph_setAdjacent (g, 10, 11)
	  || !graph_setAdjacent (g, 1, 15) || !graph_setAdjacent (g, 13, 5));

  /* Deleted vertex. */
  assert (!graph_setAdjacent (g, 0, 2) || !graph_setAdjacent (g, 2, 0));

  /* Double edges. */
  assert (!graph_setAdjacent (g, 0, 1) || !graph_setAdjacent (g, 1, 0));

  graph_print (g);

  graph_destroy (&g);
  assert (element_null (g));

  return 0;
}

#elif defined VISIT_C
static void populateGraph (Graph g);

static void
populateGraph (Graph g)
{
  assert (!element_null (g));

  graph_setAdjacent (g, 0, 1);
  graph_setAdjacent (g, 0, 2);
  graph_setAdjacent (g, 1, 3);
  graph_setAdjacent (g, 2, 4);
  graph_setAdjacent (g, 2, 5);
  graph_setAdjacent (g, 3, 1);
  graph_setAdjacent (g, 4, 3);
  graph_setAdjacent (g, 5, 5);
}

int
main (void)
{
  int n = 6;
  int max1, max2;
  Graph g1, g2;

  graph_new (&g1, n);
  graph_new (&g2, n);

  populateGraph (g1);
  populateGraph (g2);

  visit_BFS (g1, 0);
  visit_BFS (g2, 0);
  graph_print (g1);
  graph_print (g2);

  visit_removeUnreachableVertices (g1);
  visit_removeUnreachableVertices (g2);
  graph_print (g1);
  graph_print (g2);

  max1 = visit_BFS (g1, 0);
  max2 = visit_DFS (g2);
  graph_print (g1);
  graph_print (g2);

  graph_destroy (&g1);
  graph_destroy (&g2);
  assert (element_null (g1));
  assert (element_null (g2));

  fprintf (stderr, "Max queue length = %d\n", max1);
  fprintf (stderr, "Max stack length = %d\n", max2);

  return 0;
}

#elif defined HELPER_C
int
main (void)
{
  int n = 20;
  Graph g;
  /* Edge creation probability. */
  double p = 0.1;
  /* Source vertex. */
  Vertex s;

  helper_genRandomGraph (&g, n, p);
  s = helper_getRandomSource (g);
  assert (!element_null (s));
  graph_print (g);

  graph_destroy (&g);

  return 0;
}

#endif
