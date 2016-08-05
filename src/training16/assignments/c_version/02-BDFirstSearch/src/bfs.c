/*
 * bfs.c
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
#include "bfs.h"

/* Return maximum queue size. */
int
bFS (Graph g, Vid sId)
{
  int max = 0;
  list vertices = g->vertices;
  list *adjacencies = g->adjacencies;
  list adjs;
  Vertex s = vertex_getFromId (g->vertices, sId), u, v;
  queue Q;

  assert (!element_null (g) && !element_null (s));
  while (!list_null (vertices))
    {
      u = list_head (vertices);
      if (!(s->id == u->id))
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

void
bFS_removeUnreachableVertices (Graph g)
{
    list vertices = g->vertices;

    assert (!element_null(g));
    while (!list_null (vertices))
    {
        if (list_head(vertices) -> d == INF)
            graph_destroyVertex (g, list_head(vertices) -> id);
        vertices = list_next (vertices);
    }
}

