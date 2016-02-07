/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


/* Standard libraries.  */

#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

#ifndef ASSERT
#define ASSERT
#include <assert.h>
#endif


/* Definitions.  */

#define false 0
#define true  1
#define EMPTY NULL


/* New datatype.  */
typedef int boolean;
typedef int element;
typedef int weight;

/* nodePointer is a pointer to struct physicalNode */
typedef struct node *pointerToNode;
typedef struct edge *pointerToEdge;

/* pointerToNode is a pointer to type nodePointer */
typedef pointerToNode *referenceToNodePointer;
typedef pointerToEdge *referenceToEdgePointer;


/* This struct contains a physical node rappresentation */
struct node {
    char *name;

    /* If fromTo == toFrom, then it's a non oriented graph. */
    struct edge *edgeListOut;
    struct edge *edgeListIn;

    /* All the nodes are connected to each other by a double linked list.
     * This makes adding and deleting new nodes less time consuming.  */
    struct node *prev;
    struct node *next;
};

struct edge {
    /* Usually an edge weight is positive, but in some cases it can be
     * negative.  */
    weight w;

    /* Addresses of the starting and the arrival node.  */
    struct node *fromNode;
    struct node *toNode;

    /* Given a node, the following pointer are able to tell the input and
     * output edges of that node. */
    struct edge *edgeOutListNext;
    struct edge *edgeOutListPrev;
    struct edge *edgeInListNext;
    struct edge *edgeInListPrev;

    /* Just like the nodes, the edges are in a double linked list.  */
    struct edge *prev;
    struct edge *next;
};

/* Function Prototypes.  */
boolean isEmptyNodeList( pointerToNode ptn );
void newNodeList( referenceToNodePointer refN );
void newNode( referenceToNodePointer refN, char *nodeName );

void newEdge( referenceToEdgePointer refE );


/* boolean null( referenceToNodePointer ref );
void cons( element el, referenceToNodePointer ref );
void tailCons( element el, referenceToNodePointer ref );
element car( referenceToNodePointer ref );
referenceToNodePointer cdr( referenceToNodePointer ref );
int length( referenceToNodePointer ref );
void printAll( referenceToNodePointer ref );
referenceToNodePointer freeAll( referenceToNodePointer ref ); */
