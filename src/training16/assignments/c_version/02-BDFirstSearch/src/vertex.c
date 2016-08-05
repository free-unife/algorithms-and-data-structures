/*
 * vertex.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "vertex.h"
#include "libncc.h"
#include "utils.h"

Vertex
vertex_new (Vertex * vRef, Vid id)
{
  *vRef = malloc_safe (sizeof (struct VertexObject));
  (*vRef)->id = id;
  sprintf ((*vRef)->color, "%s", "WHITE");
  (*vRef)->d = 0;
  (*vRef)->f = 0;
  (*vRef)->p = NULL;

  return *vRef;
}

Vertex
vertex_getFromId (list vertices, Vid id)
{
  while (!list_null (vertices))
    {
      if (list_head (vertices)->id == id)
	return (list_head (vertices));
      else
	vertices = list_next (vertices);
    }

  /* Vertex with input id not found. */
  return NULL;
}

void
vertex_destroy (Vertex v)
{
  assert (!element_null (v));
  free (v);
}

void
vertex_print (Vertex v)
{
  assert (!element_null (v));
  fprintf (stderr, "%p:%d:%s:%d:%d:%p",
	   (void *) v, v->id, v->color, v->d, v->f, (void *) v->p);
  if (v->d == INF)
    fprintf (stderr, ";UNREACHABLE");
  fprintf (stderr, "\n");
}
