/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

/* NATIVE FUNCTIONS.  */

/* Checks if a list is empty.
 * If the head pointer is NULL, the list is empty */
boolean nullSQ( referenceToNodePointerSQ ref )
{
    return *ref == EMPTY;
}


/* This function adds an nodePointer e in the head of the list, and
 * changes the head of the list to the new node that holds e.
 */
void consSQ( nodePointer el, referenceToNodePointerSQ ref )
{
    pointerToNodeSQ np;

    if ( ( np = malloc( sizeof( struct nodeSQ ) ) ) == NULL )
        exit( EXIT_FAILURE );
    np->el = el;
    np->next = *ref;
    *ref = np;
    return;
}

/* Same as cons, except that the node is added on the tail of the list.  */
void tailConsSQ( nodePointer el, referenceToNodePointerSQ ref )
{
    referenceToNodePointerSQ refNew;

    if ( nullSQ( ref ) ) {
        consSQ( el, ref );
    } else {
        while ( lengthSQ( ref ) > 1 ) {
            ref = cdrSQ( ref );
        }
        if ( ( refNew = malloc( sizeof( pointerToNodeSQ * ) ) ) == NULL )
            exit( EXIT_FAILURE );
        consSQ( el, refNew );
        ( *ref )->next = *refNew;
    }
    return;
}

/* Get value of the first node's nodePointer field.  */
nodePointer carSQ( referenceToNodePointerSQ ref )
{
    assert( !nullSQ( ref ) );
    return ( *ref )->el;
}


/* Changes the referenceToNodePointerSQ one step ahead in the list (i.e: the
 * function returns a new head corresponding to the address of the second node.
 */
referenceToNodePointerSQ cdrSQ( referenceToNodePointerSQ ref )
{
    assert( !nullSQ( ref ) );
    return &( ( *ref )->next );
}


/* Initialize a nodePointer variable with EMPTY.  */
void initSQ( referenceToNodePointerSQ ref )
{
    *ref = EMPTY;
    return;
}


/* Calculate the length of the list using the native functions.  */
int lengthSQ( referenceToNodePointerSQ ref )
{
    return ( nullSQ( ref ) ? 0 : 1 + lengthSQ( cdrSQ( ref ) ) );
}


/* Print the whole list.  */
void printAllSQ( referenceToNodePointerSQ ref )
{
    int index = 0;
    if ( nullSQ( ref ) ) {
        printf( "EMPTY\n" );
    } else {
        while ( lengthSQ( ref ) > 0 ) {
            printf( "Node [%d] -> el == %d\n", index, carSQ( ref ) );
            index = index + 1;
            ref = cdrSQ( ref );
        }
    }

    return;
}


/* Free the list.  */
referenceToNodePointerSQ freeAllSQ( referenceToNodePointerSQ ref )
{
    while ( !nullSQ( ref ) ) {
        pointerToNodeSQ toDelete = *ref;
        ref = cdrSQ( ref );
        free( toDelete );
    }
    return ref;
}
