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

#ifndef STRING
#define STRING
#include <string.h>
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
typedef struct graphElement *nodePointer;

/* pointerToNode is a pointer to type nodePointer */
typedef nodePointer *headPointer;

/* This struct contains a physical node rappresentation */
struct graphElement {
    /* Vertex part */
    char *name;

    /* If edgeListIn == edgeListOut, then it's a non oriented graph. */
    headPointer edgeListOut;
    headPointer edgeListIn;


    /* Edge part */

    /* Usually an edge weight is positive, but in some cases it can be
     * negative.  */
    weight w;

    /* Addresses of the starting and the arrival node.  */
    nodePointer fromNode;
    nodePointer toNode;

    /* Common part */

    /* Element of edgeListOut or edgeListIn */
    nodePointer edgeAddr;

    /* All the nodes are connected to each other by a double linked list.
     * This makes adding and deleting new nodes less time consuming.  */
    struct graphElement *prev;
    struct graphElement *next;
};


/* TODO */
/* element extractNodeInHead( headPointer hp );
element extractNodeInQueue( headPointer hp );
nodePointer *searchForElement( element toSearch, headPointer hp );
element extractNodeInMiddle( nodePointer np );
headPointer freeDoubleLinkedList( headPointer hp ); */

boolean isDoubleLinkedListEmpty( headPointer hp );
void initDoubleLinkedList( headPointer hp );
int lengthDoubleLinkedList( headPointer hp );

nodePointer newEdge( weight w, nodePointer fromNode, nodePointer toNode,
                     headPointer hp );

nodePointer newVertex( char *name, headPointer hp );

nodePointer connectVertex( headPointer edgehp,
                           nodePointer fromNode, nodePointer toNode,
                           weight w );


void insertEdgeInList( nodePointer np, headPointer hp );

nodePointer searchEdge( nodePointer fromNode, nodePointer toNode,
                        headPointer hp );

nodePointer searchVertex( char *nameToSearch, headPointer hp );

void insertNodeInQueue( headPointer hp, nodePointer np );

void printNodeEdges( headPointer hp );

void freeNodeInHead( headPointer hp );

void freeDoubleLinkedList( headPointer hp );

void freeGraph( headPointer headVertexList, headPointer headEdgeList );
