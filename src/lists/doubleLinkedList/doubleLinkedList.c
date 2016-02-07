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
    newNode->prev = dummy;
    dummy->next->prev = newNode;
    dummy->next = newNode;



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
    newNode->next = dummy;
    newNode->prev = dummy->prev;
    dummy->prev->next = newNode;
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

/* Extract the node after dummy  */
element extractNodeInHead( headPointer hp )
{
    element extracted;
    nodePointer dummy = *hp;
    nodePointer toDelete = dummy->next;

    /* Extract the element */
    extracted = toDelete->el;

    /* Fix pointers */
    dummy->next = toDelete->next;
    toDelete->next->prev = dummy;

    free( toDelete );

    return extracted;
}

/* Extract the node before dummy  */
element extractNodeInQueue( headPointer hp )
{
    element extracted;
    nodePointer dummy = *hp;
    nodePointer toDelete = dummy->prev;

    /* Extract the element */
    extracted = toDelete->el;

    /* Fix pointers */
    dummy->prev = toDelete->prev;
    toDelete->prev->next = dummy;

    free( toDelete );

    return extracted;
}

/* This function returns an array that have the same size of the input list,
 * every array's element is a reference to a founded node.
 * if no element is found, all the array elements have EMPTY as default value.
 * example:
 * node[0]->el = 3  -  node[2]->el = 2  -  node[3]->el = 1
 * toSearch = 2
 * will return --> foundedNodes[3] = { &node[2], EMPTY, EMPTY }
 */
nodePointer *searchForElement( element toSearch, headPointer hp )
{

    /* save the reference of dummy node */
    nodePointer refToDummy = *hp;
    nodePointer succNode = ( *hp )->next;
    nodePointer *foundedNodes;
    nodePointer **toReturn;

    int lenghOfList = lengthDoubleLinkedList( hp );
    int i;

    /* Initialize the array */
    if ( ( foundedNodes =
           malloc( sizeof( lenghOfList * sizeof( nodePointer ) ) ) ) ==
         NULL )
        exit( EXIT_FAILURE );

    for ( i = 0; i < lenghOfList; ++i ) {
        foundedNodes[i] = EMPTY;
    }

    toReturn = &foundedNodes;

    /* Begin scan */
    i = 0;
    while ( succNode != refToDummy ) {
        if ( succNode->el == toSearch ) {
            foundedNodes[i] = succNode;
            i = i + 1;
        }
        succNode = succNode->next;
    }

    return *toReturn;
}

/* Extract a node given his reference. */
element extractNodeInMiddle( nodePointer np )
{
    element extracted;
    nodePointer toDelete = np;

    /* Extract element */
    extracted = toDelete->el;

    /* Fix pointers */
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    free( toDelete );

    return extracted;
}

/* Free all the element of the list.
 * It also deletes the dummy node.
 * Must recall initDoubleLinkedList() to reuse the list. */
headPointer freeDoubleLinkedList( headPointer hp )
{
    while ( lengthDoubleLinkedList( hp ) > 0 ) {
        extractNodeInHead( hp );
    }
    free( *hp );
    *hp = EMPTY;
    return hp;
}
