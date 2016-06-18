/*
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#ifndef M_GLOBALDEFINES_H

/**
 * @brief Include the main header.
 */
#define M_GLOBALDEFINES_H

/**
 * @brief Tell the compiler that we want ISO C99 source, and check if the
 * system has ANSI C 99.
 */
#define ISOC99_SOURCE
#define _POSIX_C_SOURCE 199309L
#if __STDC_VERSION__ != 199901L
#error "ANSI C99 not available"
#endif

/*
 * Comment out the following to disable all asserts.
 */
/*#define NDEBUG*/

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct VertexObject *Vertex;
typedef struct VertexListNodeObject *VertexListNode;
typedef struct GraphObject *Graph;

struct VertexObject
{
  unsigned int id;
  char *name;
  char colour;
  int distance;
  struct VertexObject *parent;
};

struct VertexListNodeObject
{
  struct VertexObject *v;
  struct VertexListNodeObject *next;
  struct VertexListNodeObject *prev;
};

struct GraphObject
{
  /* 1-0 values. */
  unsigned int **adjacencyMatrix;
  struct VertexListNodeObject *vl;
};

extern bool element_null (void *element);
extern void *malloc_safe (size_t size);

extern Vertex vertex_new (unsigned int id, char *name, char colour,
			  int distance, Vertex parent);
extern void vertex_print (Vertex v);
extern void vertex_delete (Vertex * vRef);

extern VertexListNode vertexlistnode_new (Vertex connectedVertex,
					  VertexListNode next,
					  VertexListNode prev);
extern void vertexlistnode_print (VertexListNode vln);
extern void vertexlistnode_delete (VertexListNode * vlnRef);
extern VertexListNode vertexlistnode_insert (VertexListNode head,
					     Vertex toBeIns);
extern VertexListNode vertexlistnode_removeWhites (VertexListNode head);
extern void vertexlistnode_printlist (VertexListNode head);

#endif
