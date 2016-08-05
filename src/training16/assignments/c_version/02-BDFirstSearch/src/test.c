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
#include "bfs.h"

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

#elif defined BFS_C
int
main (void)
{
  int i;
  int n = 10;
  Graph g;

  graph_new (&g, n);
  for (i = 0; i < n - 2; i++)
    graph_setAdjacent (g, i, i + 1);
  graph_print (g);

  i = bFS (g, 0);

  /* Check that all reachable vertices are really reachable. */
  for (i = 0; i < n - 1; i++)
    assert (vertex_getFromId (g->vertices, i)->d != INF);

  graph_print (g);
  fprintf (stderr, "Max queue length = %d\n", i);

  /* Remove unrechable vertices. */
  bFS_removeUnreachableVertices (g);
  graph_print (g);

  graph_destroy (&g);
  assert (element_null (g));

  return 0;
}

#endif
