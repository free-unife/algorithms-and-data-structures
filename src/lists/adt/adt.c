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


/* NATIVE FUNCTIONS.  */

/* Checks if a list is empty.
 * If the head pointer is NULL, the list is empty */
boolean null( referenceToNodePointer ref )
{
    return *ref == EMPTY;
}


/* This function adds an element e in the head of the list, and
 * changes the head of the list to the new node that holds e.
 */
void cons( element el, referenceToNodePointer ref )
{
    pointerToNode np;

    if ( ( np = malloc( sizeof( struct node ) ) ) == NULL )
        exit( EXIT_FAILURE );
    np->el = el;
    np->next = *ref;
    *ref = np;
    return;
}

/* Same as cons, except that the node is added on the tail of the list.  */
void tailCons( element el, referenceToNodePointer ref )
{
    referenceToNodePointer refNew;

    if ( null( ref ) ) {
        cons( el, ref );
    } else {
        while ( length( ref ) > 1 ) {
            ref = cdr( ref );
        }
        if ( ( refNew = malloc( sizeof( pointerToNode * ) ) ) == NULL )
            exit( EXIT_FAILURE );
        cons( el, refNew );
        ( *ref )->next = *refNew;
    }
    return;
}

/* Get value of the first node's element field.  */
element car( referenceToNodePointer ref )
{
    assert( !null( ref ) );
    return ( *ref )->el;
}


/* Changes the referenceToNodePointer one step ahead in the list (i.e: the
 * function returns a new head corresponding to the address of the second node.
 */
referenceToNodePointer cdr( referenceToNodePointer ref )
{
    assert( !null( ref ) );
    return &( ( *ref )->next );
}


/* Initialize a nodePointer variable with EMPTY.  */
void init( referenceToNodePointer ref )
{
    *ref = EMPTY;
    return;
}


/* Calculate the length of the list using the native functions.  */
int length( referenceToNodePointer ref )
{
    return ( null( ref ) ? 0 : 1 + length( cdr( ref ) ) );
}


/* Print the whole list.  */
void printAll( referenceToNodePointer ref )
{
    int index = 0;
    if ( null( ref ) ) {
        printf( "EMPTY\n" );
    } else {
        while ( length( ref ) > 0 ) {
            printf( "Node [%d] -> el == %d\n", index, car( ref ) );
            index = index + 1;
            ref = cdr( ref );
        }
    }

    return;
}


/* Free the list.  */
referenceToNodePointer freeAll( referenceToNodePointer ref )
{
    while ( !null( ref ) ) {
        pointerToNode toDelete = *ref;
        ref = cdr( ref );
        free( toDelete );
    }
    return ref;
}
