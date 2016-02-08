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
        printf
            ( "At least two nodes must exist in order to connect them.\n" );
        exit( EXIT_FAILURE );
    }

    eP = newEdge( refE, W );

    ( eP )->fromNode = fromNode;
    ( eP )->toNode = toNode;

    /* Update edge out and in proprieties */
    updateEdgeOutList( fromNode, refE, eP );


    /* Update fromNode -> listOut */
    ( fromNode )->edgeListOut = eP;
    /* Update toNode -> listIn */
    ( toNode )->edgeListIn = eP;

    return eP;

}

/* There can be n edgeOut and edgeIn lists.  */

/* Find edges in the edge list which have the same value in the fromNode
 * field. The next Edge in that list is the pointerToEdge variable passed to
 * the function. */
/* edgeOutList.  */
void updateEdgeOutList( pointerToNode fromNode,
                        referenceToEdgePointer refE, pointerToEdge pte )
{
    /* tmpp is the last valid edge.  */
    pointerToEdge tmp, tmpp = EMPTY;

    tmp = *refE;

    /* This needs to be corrected.  */
    if ( tmp == NULL );
    else {
        while ( !isEmptyEdgeList( tmp->next ) ) {

            /* If address of node == address stored in currentEdge -> fromNode.  */
            if ( fromNode == ( tmp )->fromNode )
                tmpp = tmp;

            tmp = ( tmp )->next;
        }
    }
    ( tmp )->edgeOutListNext = pte;
    ( tmp )->edgeOutListPrev = tmpp;
    ( pte )->edgeOutListNext = EMPTY;

    return;

}

void printEdgeOutList( pointerToNode ptn )
{
    pointerToEdge tmp;

    tmp = ( ptn )->edgeListOut;
    while ( !isEmptyEdgeList( tmp ) ) {
        printf( "Weight of edges coming out from node %s = %d\n",
                ( ptn )->name, ( tmp )->w );

        tmp = ( tmp )->edgeOutListNext;
    }

}

/* edgeInList.  */
