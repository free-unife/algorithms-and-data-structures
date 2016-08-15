/*
 * main.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "vertex.h"
#include "libncc.h"
#include "utils.h"
#include "graph.h"
#include "visit.h"
#include "helper.h"
#include "main.h"

int
main (void)
{
  int i, stackLen, queueLen;
  /* 0 <= p <= 1. */
  double edge_probability = 0.00075;
  Graph g;
  Vertex s;

  fprintf (stdout, "size    bfs    dfs\n");
  for (i = 1; i <= MAX_GRAPH_SIZE; i++)
    {
      helper_genRandomGraph (&g, i, edge_probability);
      s = helper_getRandomSource (g);

      /* If s is set adjacent to all vertices:
       * Depth of graph from s == 1 -> minimal stack usage.
       * Breadth of graph from s == max -> max queue usage.
       */
      helper_setMaxBreadth (g, s);
      /* helper_setMaxDepth (g); */

      /* Sets the unreachable vertices to INF,
       * so they can be easily removed.
       */
      visit_BFS (g, s);
      visit_removeUnreachableVertices (g);

      queueLen = visit_BFS (g, s);
      stackLen = visit_DFS (g, s);
      fprintf (stdout, "%d    %d    %d\n", i, queueLen, stackLen);

      graph_destroy (&g);
    }

  return 0;
}
