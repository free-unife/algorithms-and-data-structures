/*
 * vertex.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined VERTEX_H
#define VERTEX_H

#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libncc.h"

#define INF INT_MAX

struct VertexObject
{
  int id;
  /* No need to use free for the color field. */
  char color[10];
  int d;
  int f;
  struct VertexObject *p;
};

typedef struct VertexObject *Vertex;
/* Vertex id*/
typedef int Vid;

extern Vertex vertex_new (Vertex * vRef, Vid id);
extern Vertex vertex_getFromId (list vertexList, Vid id);
extern void vertex_destroy (Vertex v);
extern void vertex_print (Vertex v);

#endif
