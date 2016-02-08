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
    *hp = malloc( sizeof( sizeof( struct graphElement ) ) );

    /* setup his next and prec pointers to itself */
    ( *hp )->next = ( *hp );
    ( *hp )->prev = ( *hp );

    printf( "next = %p  prev = %p\n", ( void * ) ( *hp )->next,
            ( void * ) ( *hp )->prev );
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

    /* insert his element */
    newNode->name = name;
    newNode->edgeListOut = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( newNode->edgeListOut );
    printf( "\n\nnext = %p  prev = %p\n\n",
            ( void * ) ( *( newNode->edgeListOut ) )->next,
            ( void * ) ( *( newNode->edgeListOut ) )->prev );
    newNode->edgeListIn = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( newNode->edgeListIn );

    /* fix list pointers */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return newNode;
}

/* Insert a vertex before the dummy node */
nodePointer newEdge( weight w, nodePointer fromNode, nodePointer toNode,
                     headPointer hp )
{
    nodePointer dummy = *hp;
    nodePointer newNode;

    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct graphElement ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* insert his element */
    newNode->w = w;
    newNode->fromNode = fromNode;
    newNode->toNode = toNode;

    /* fix list pointers */
    newNode->prev = dummy->prev;
    newNode->next = dummy;
    dummy->prev->next = newNode;
    dummy->prev = newNode;

    return newNode;
}
