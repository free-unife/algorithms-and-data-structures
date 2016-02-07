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

boolean isEmptyNodeList( pointerToNode ptn )
{
    return ( ptn == EMPTY ? true : false );
}

void newNodeList( referenceToNodePointer refN )
{
    *refN = EMPTY;
    return;
}

/* Create a new node.  */
void newNode( referenceToNodePointer refN, char *nodeName )
{
    pointerToNode newNode, tmp, tmpp = NULL;


    /* Go through node list until a NULL one is foud.  */
    if ( ( newNode = malloc( sizeof( struct node ) ) ) == NULL )
        exit( EXIT_FAILURE );

    ( newNode )->name = nodeName;
    ( newNode )->edgeListOut = EMPTY;
    ( newNode )->edgeListIn = EMPTY;
    ( newNode )->prev = NULL;
    ( newNode )->next = NULL;

    if ( isEmptyNodeList( *refN ) ) {
        *refN = newNode;

    } else {
        tmp = *refN;
        while ( !isEmptyNodeList( tmp->next ) ) {
            tmpp = tmp;
            tmp = ( tmp )->next;
        }

        ( tmp )->next = newNode;
        ( tmp )->prev = tmpp;
        ( newNode )->prev = tmp;

    }

    return;
}

/*
void newEdge( referenceToEdgePointer refE, weight w )
{
    *refE = malloc( sizeof( struct edge ) );
    return;
}

*/

/*
connectNodes 
    newEdge (weight 0, 
*/
