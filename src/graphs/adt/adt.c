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

/* Insert a vertex before the dummy node */
nodePointer newVertex( char *name, headPointer hp )
{
    nodePointer dummy = *hp;
    nodePointer newNode;

    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* Insert vetex name.  */
    newNode->name = name;

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
    nodePointer dummy = *hp;
    nodePointer newNode;

    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* Insert edge info.  */
    newNode->w = w;
    newNode->fromNode = fromNode;
    newNode->toNode = toNode;

    /* Fix list pointers.  */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return newNode;
}

nodePointer connectNodes( headPointer edgehp,
                          nodePointer fromNode, nodePointer toNode,
                          weight w )
{
    nodePointer edgeP;

    edgeP = newEdge( w, fromNode, toNode, edgehp );

    /* from -> out && to -> In.  */
    insertNodeInQueue( fromNode->edgeListOut, edgeP );
    insertNodeInQueue( toNode->edgeListIn, edgeP );

    return edgeP;
}

void insertNodeInQueue( headPointer hp, nodePointer np )
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
}
