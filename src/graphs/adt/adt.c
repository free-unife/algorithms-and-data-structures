/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef ADT_H
#define ADT_H
#include "adt.h"
#endif


/* Init the list with a dummy node that points himself */
void initDoubleLinkedList( headPointer hp )
{
    /* insert a dummy node */
    *hp = malloc( sizeof( struct graphElement ) );

    /* setup his next and prec pointers to itself */
    ( *hp )->next = ( *hp );
    ( *hp )->prev = ( *hp );

    return;
}

/* Calculante list length, if only the dummy node is present,
 * than length( head ) == 0;
 */
int lengthDoubleLinkedList( headPointer hp )
{
    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;

    int size = 0;

    while ( succNode != refToDummy ) {
        succNode = succNode->next;
        size = size + 1;
    }

    return size;
}

/* Tells if the list is EMPTY using lenght() */
boolean isDoubleLinkedListEmpty( headPointer hp )
{
    return lengthDoubleLinkedList( hp ) == 0 ? true : false;
}

nodePointer searchVertex( char *nameToSearch, headPointer hp )
{

    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;
    nodePointer foundNode = EMPTY;


    /* Begin scan */
    while ( succNode != refToDummy ) {
        if ( strcmp( succNode->name, nameToSearch ) == 0 ) {
            foundNode = succNode;
        }
        succNode = succNode->next;
    }

    return foundNode;
}

nodePointer searchEdge( nodePointer fromNode, nodePointer toNode,
                        headPointer hp )
{

    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;
    nodePointer foundNode = EMPTY;

    /* Begin scan */
    while ( succNode != refToDummy ) {
        if ( ( succNode->fromNode == fromNode )
             && ( succNode->toNode == toNode ) ) {
            foundNode = succNode;
        }
        succNode = succNode->next;
    }

    return foundNode;
}

/* Insert a vertex before the dummy node */
nodePointer newVertex( char *name, headPointer hp )
{
    nodePointer foundVertex;
    nodePointer dummy;
    nodePointer newNode;

    if ( hp == EMPTY ) {
        if ( ( hp = malloc( sizeof( nodePointer * ) ) ) == NULL )
            exit( EXIT_FAILURE );

        initDoubleLinkedList( hp );
    }

    dummy = *hp;

    /* every edge node in list must have an atomic value  */
    foundVertex = searchVertex( name, hp );
    if ( foundVertex != EMPTY ) {
        /*
           printf
           ( "The vertex \"%s\" already exists! His in/out connection will be deleted!\n",
           name );
         */
        /* free his in/out connection and reinit those lists */

        freeDoubleLinkedList( foundVertex->edgeListOut );
        freeDoubleLinkedList( foundVertex->edgeListIn );

        foundVertex->edgeListOut = malloc( sizeof( nodePointer * ) );
        initDoubleLinkedList( foundVertex->edgeListOut );

        foundVertex->edgeListIn = malloc( sizeof( nodePointer * ) );
        initDoubleLinkedList( foundVertex->edgeListIn );
        return foundVertex;
    }

    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* Insert vetex name.  */
    newNode->name = name;
    newNode->pointerToVertexHead = hp;

    newNode->edgeListOut = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( newNode->edgeListOut );

    newNode->edgeListIn = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( newNode->edgeListIn );

    /* Fix list pointers.  */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return newNode;
}

/* Insert an edge before the dummy node */
nodePointer newEdge( weight w, nodePointer fromNode, nodePointer toNode,
                     headPointer hp )
{
    nodePointer foundEgde;
    nodePointer dummy;
    nodePointer newNode;

    if ( hp == EMPTY ) {
        if ( ( hp = malloc( sizeof( nodePointer * ) ) ) == NULL )
            exit( EXIT_FAILURE );

        initDoubleLinkedList( hp );
    }

    dummy = *hp;

    /* every edge node in list must have an atomic value */
    foundEgde = searchEdge( fromNode, toNode, hp );
    if ( foundEgde != EMPTY ) {
        printf
            ( "The edge from \"%s\" to \"%s\" already exists! Pay Attention!\n\n",
              fromNode->name, toNode->name );

        return foundEgde;
    }


    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* Insert edge info.  */
    newNode->w = w;
    newNode->fromNode = fromNode;
    newNode->toNode = toNode;

    newNode->pointerToEdgeHead = hp;

    /* Fix list pointers.  */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return newNode;
}

nodePointer connectVertex( headPointer edgehp,
                           nodePointer fromNode, nodePointer toNode,
                           weight w )
{
    nodePointer edgeP;

    edgeP = newEdge( w, fromNode, toNode, edgehp );

    /* from -> out && to -> In.  */
    insertEdgeInList( edgeP, fromNode->edgeListOut );
    insertEdgeInList( edgeP, toNode->edgeListIn );

    return edgeP;
}

void insertEdgeInList( nodePointer np, headPointer hp )
{
    nodePointer dummy = *hp;
    nodePointer newNode;


    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    newNode->edgeAddr = np;

    /* fix list pointers */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return;
}

void printNodeEdges( headPointer hp )
{
    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;

    if ( isDoubleLinkedListEmpty( hp ) ) {
        printf( "No edges\n" );
        return;
    }

    while ( succNode != refToDummy ) {
        printf( "%d ", ( succNode->edgeAddr )->w );
        succNode = succNode->next;
    }
    printf( "\n" );

    return;
}

void printVertex( headPointer hp )
{

    nodePointer dummy = *hp;
    nodePointer thisVertex = dummy->next;
    int index = 0;

    while ( thisVertex != dummy ) {
        printf( "Vertex[%d]->name = %s\n", index, thisVertex->name );
        index = index + 1;
        thisVertex = thisVertex->next;
    }
    return;
}


/* free the node after dummy  */
void freeNodeInHead( headPointer hp )
{
    nodePointer dummy = *hp;
    nodePointer toDelete = dummy->next;

    /* Fix pointers */
    dummy->next = toDelete->next;
    toDelete->next->prev = dummy;

    free( toDelete );

    return;
}

void freeDoubleLinkedList( headPointer hp )
{
    while ( lengthDoubleLinkedList( hp ) > 0 ) {
        freeNodeInHead( hp );
    }
    free( *hp );
    *hp = EMPTY;

    return;
}

/* Free all the graph given the vertex list */
void freeGraph( headPointer headVertexList, headPointer headEdgeList )
{

    nodePointer dummyVertex = *headVertexList;
    nodePointer thisVertex = dummyVertex->next;

    /* free all the Edge List */
    freeDoubleLinkedList( headEdgeList );

    /* free all in and out edge list for each node */
    while ( thisVertex != dummyVertex ) {

        freeDoubleLinkedList( thisVertex->edgeListOut );
        freeDoubleLinkedList( thisVertex->edgeListIn );

        thisVertex = thisVertex->next;
    }

    /* free all the Vertex List */
    freeDoubleLinkedList( headVertexList );

    return;
}
