/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "doubleLinkedList.h"
#endif

/* NATIVE FUNCTIONS.  */

/* Init the list with a dummy node that points himself */
void initDoubleLinkedList( headPointer hp )
{
    init( hp );

    /* insert a dummy node */
    cons( 0, hp );

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

/* Insert a node after the dummy node */
void insertNodeInHead( element el, headPointer hp )
{
    nodePointer dummy = *hp;
    nodePointer newNode;

    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct node ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* insert his element */
    newNode->el = el;

    /* fix list pointers */
    newNode->next = dummy->next;
    dummy->next = newNode;
    newNode->prev = dummy;
    dummy->prev->prev = newNode;

    return;
}

/* Insert a node before the dummy node */
void insertNodeInQueue( element el, headPointer hp )
{
    nodePointer dummy = *hp;
    nodePointer newNode;

    /* allocate memory for the node */
    if ( ( newNode = malloc( sizeof( struct node ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* insert his element */
    newNode->el = el;

    /* fix list pointers */
    dummy->prev->next = newNode;
    newNode->next = dummy;
    newNode->prev = dummy->prev;
    dummy->prev = newNode;


    return;
}

void printDoubleLinkedList( headPointer hp )
{
    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;
    int index;

    if ( isDoubleLinkedListEmpty( hp ) ) {
        printf( "EMPTYLIST\n" );
        return;
    }

    index = 0;

    while ( succNode != refToDummy ) {
        printf( "Node [%d] -> el == %d\n", index, succNode->el );
        succNode = succNode->next;
        index = index + 1;
    }
}
