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

boolean isEmptyEdgeList( pointerToEdge pte )
{
    return ( pte == EMPTY ? true : false );
}

void newNodeList( referenceToNodePointer refN )
{
    *refN = EMPTY;
    return;
}

void newEdgeList( referenceToEdgePointer refE )
{
    *refE = EMPTY;
    return;
}

/* Create a new node.  */
pointerToNode newNode( referenceToNodePointer refN, char *nodeName )
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

    return newNode;
}

/* Create a new edge.  */
/* This function should only be called from connectNodes function.  */
pointerToEdge newEdge( referenceToEdgePointer refE, weight W )
{
    pointerToEdge newEdge, tmp, tmpp = NULL;


    /* Go through node list until a NULL one is foud.  */
    if ( ( newEdge = malloc( sizeof( struct edge ) ) ) == NULL )
        exit( EXIT_FAILURE );

    ( newEdge )->w = W;

    ( newEdge )->fromNode = EMPTY;
    ( newEdge )->toNode = EMPTY;

    ( newEdge )->edgeOutListNext = EMPTY;
    ( newEdge )->edgeOutListPrev = EMPTY;
    ( newEdge )->edgeInListNext = EMPTY;
    ( newEdge )->edgeInListPrev = EMPTY;

    ( newEdge )->prev = NULL;
    ( newEdge )->next = NULL;

    if ( isEmptyEdgeList( *refE ) ) {
        *refE = newEdge;

    } else {
        tmp = *refE;
        while ( !isEmptyEdgeList( tmp->next ) ) {
            tmpp = tmp;
            tmp = ( tmp )->next;
        }

        ( tmp )->next = newEdge;
        ( tmp )->prev = tmpp;
        ( newEdge )->prev = tmp;

    }

    return newEdge;
}


/* Connect two nodes and return the new edge.  */
pointerToEdge connectNodes( referenceToEdgePointer refE,
                            referenceToNodePointer headOfNodeList,
                            pointerToNode fromNode, pointerToNode toNode,
                            weight W )
{

    pointerToEdge eP;

    if ( isEmptyNodeList( *headOfNodeList ) ) {
        printf( "Cannot connect 0 nodes.\n" );
        exit( EXIT_FAILURE );
    }

    eP = newEdge( refE, W );

    ( eP )->fromNode = fromNode;
    ( eP )->toNode = toNode;

    /* Update edge out and in proprieties */
    /* TODO */


    return eP;
}
