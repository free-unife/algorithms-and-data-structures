/*
 * @file utils.c
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Header file containing exportable methods.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

Vertex
vertex_new (unsigned int id, char *name, char colour, int distance,
	    Vertex parent)
{
  Vertex new_vertex = malloc_safe (sizeof (struct VertexObject));

  new_vertex->id = id;
  new_vertex->name = name;
  new_vertex->colour = colour;
  new_vertex->distance = distance;
  new_vertex->parent = parent;

  return new_vertex;
}

void
vertex_print (Vertex v)
{
  fprintf (stderr, "%u:%s:%c:%d:%p\n",
	   v->id, v->name, v->colour, v->distance, (void *) v->parent);
}

void
vertex_delete (Vertex * vRef)
{
  free (*vRef);
  *vRef = NULL;
}
