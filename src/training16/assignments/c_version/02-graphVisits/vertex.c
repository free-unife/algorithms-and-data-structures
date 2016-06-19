/*
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

Vertex
vertex_new (unsigned int id, char colour, int distance, Vertex parent)
{
  Vertex new_vertex = malloc_safe (sizeof (struct VertexObject));

  new_vertex->id = id;
  new_vertex->colour = colour;
  new_vertex->distance = distance;
  new_vertex->parent = parent;

  return new_vertex;
}

void
vertex_print (Vertex v)
{
  fprintf (stderr, "%u:%c:%d:%p\n",
	   v->id, v->colour, v->distance, (void *) v->parent);
}

void
vertex_delete (Vertex * vRef)
{
  free (*vRef);
  *vRef = NULL;
}
