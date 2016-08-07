/*
 * dfs.c
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
#include "dfs.h"

/* Return maximum stack size. */
int
dFS (Graph g, Vid sId)
{
  int max = 0;
  int time = 0;
  list *adjacencies = g->adjacencies;
  list vertices = g->vertices;
  list adjs;
  Vertex s = vertex_getFromId (g->vertices, sId), u, v;
  stack S;

  assert (!element_null (g) && !element_null (s));
  /* Set default values. Unreachable vertices are removed with bFS, so the d 
   * field of the vertices must not be modified in dFS. */
  while (!list_null (vertices))
  {
        sprintf (list_head (vertices) -> color, "%s", "WHITE");
        list_head (vertices) -> p = NULL;
        vertices = list_next (vertices);
  }

  /* Discovering s. */
  sprintf (s->color, "%s", "GRAY");
  time++;
  s->d = time;
  stack_init (&S);
  stack_push (s, &S);

  while (!stack_null (S))
    {
      u = stack_pop (&S);
      adjs = adjacencies[u->id];
      while (!list_null (adjs))
	{
	  v = list_head (adjs);
	  /* If vertex has not been visited. */
	  if (strcmp (v->color, "WHITE") == 0)
	    {
	      sprintf (v->color, "%s", "GRAY");
	      v->p = u;
	      time++;
	      v->d = time;
	      stack_push (v, &S);
	      if (stack_length (S) > max)
		max = stack_length (S);
	    }
	  adjs = list_next (adjs);
	}
      sprintf (u->color, "%s", "BLACK");
      time++;
      u->f = time;
    }
  sprintf (s->color, "%s", "BLACK");
  time++;
  s->f = time;

  return max;
}
