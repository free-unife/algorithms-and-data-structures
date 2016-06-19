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

#define EMPTYLIST EMPTY

/* nodePointer is a pointer to struct physicalNode */
typedef struct node *pointerToNode;

/* pointerToNode is a pointer to type nodePointer */
typedef pointerToNode *referenceToNodePointer;

typedef struct node physicalNode;

/* nodePointer is a pointer to struct physicalNode */
typedef pointerToNode nodePointer;

/* headPointer is a pointer to type nodePointer */
typedef referenceToNodePointer headPointer;

typedef struct GraphObject *Graph;


#define false 0
#define true  1
#define EMPTY NULL


/* New datatype.  */
typedef int boolean;
typedef unsigned int element;

/* This struct contains a physical node rappresentation */
struct node {
    struct node *next;

    element el;
    char color[10];
    struct node *pi;
    element d;
    element f;

    struct node *prev;
};

struct GraphObject
{
  /* 1-0 values. */
  unsigned int leadingDimension;
  unsigned int *adjMatrix;
  headPointer head;
};

boolean null( referenceToNodePointer ref );
void cons( element el, char *color, pointerToNode pi, element d, element f, referenceToNodePointer ref );
void tailCons( element el, char *color, pointerToNode pi, element d, element f,  referenceToNodePointer ref );
element car( referenceToNodePointer ref );
referenceToNodePointer cdr( referenceToNodePointer ref );
void init( referenceToNodePointer ref );
int length( referenceToNodePointer ref );
void printAll( referenceToNodePointer ref );
referenceToNodePointer freeAll( referenceToNodePointer ref );

/* all this function have to consider the dummy node. */
void initDoubleLinkedList( headPointer hp );
int lengthDoubleLinkedList( headPointer hp );
boolean isDoubleLinkedListEmpty( headPointer hp );
void insertNodeInHead( element el, char *color, nodePointer pi, element d, element f, headPointer hp );
void insertNodeInQueue( element el, char *color, nodePointer pi, element d, element f, headPointer hp );
void printDoubleLinkedList( headPointer hp );
element extractNodeInHead( headPointer hp );
element extractNodeInQueue( headPointer hp );
nodePointer *searchForElement( element toSearch, headPointer hp );
element extractNodeInMiddle( nodePointer np );
headPointer freeDoubleLinkedList( headPointer hp );

extern bool element_null (void *element);
extern void *malloc_safe (size_t size);

extern Graph graph_new (unsigned int numberOfNodes, double vertexConnectionProbability);
extern void graph_print (Graph g);
extern nodePointer *vertexlistnode_getneighbors (Graph g, nodePointer vertex);
/*extern Vertex vertex_new (unsigned int id, char colour,
			  int distance, Vertex parent, Vertex prev, Vertex next);
extern void vertex_edit (Vertex toEdit, unsigned int id, char colour, int distance, Vertex parent, Vertex prev, Vertex next);
extern void vertex_print (Vertex v);
extern void vertex_delete (Vertex * vRef);
*/
/*extern VertexListNode vertexlistnode_new (Vertex connectedVertex,
					  VertexListNode next,
					  VertexListNode prev);
extern void vertexlistnode_print (VertexListNode vln);
extern void vertexlistnode_delete (VertexListNode * vlnRef);
extern VertexListNode vertexlistnode_insert (VertexListNode head,
					     Vertex toBeIns);
extern VertexListNode vertexlistnode_removeWhites (VertexListNode head);
extern void vertexlistnode_printlist (VertexListNode head);

extern bool adjacencymatrix_areverticesconnected(Graph g, unsigned int src_id, unsigned int dst_id);
extern Graph graph_new (unsigned int numberOfNodes, double vertexConnectionProbability);
extern void graph_print (Graph g);

extern VertexListNode vertexlistnode_getneighbors (Graph g, Vertex v);
*/
#endif

/*typedef struct VertexObject *Vertex;

struct VertexObject
{
  unsigned int id;
  char colour;
  int distance;
  struct VertexObject *parent;
  struct VertexObject *prev;
  struct VertexObject *next;
};
*/


/* Function Prototypes.  */
