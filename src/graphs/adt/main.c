/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef MAIN_H
#define MAIN_H
#include "main.h"
#endif

int main( void )
{
    referenceToNodePointer headOfNodeList;
    referenceToEdgePointer headOfEdgeList;
    pointerToNode zero, one, two;
    pointerToEdge firstEdge, secondEdge, thirdEdge;


    /* Get the correct amount of space for the headPointer variable. */
    if ( ( headOfNodeList =
           malloc( sizeof( referenceToNodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );

    if ( ( headOfEdgeList =
           malloc( sizeof( referenceToEdgePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /* Create node and edge lists.  */
    newNodeList( headOfNodeList );
    newEdgeList( headOfEdgeList );

    /* Create three nodes.  */
    zero = newNode( headOfNodeList, "zero" );
    one = newNode( headOfNodeList, "one" );
    two = newNode( headOfNodeList, "two" );

    /* Pointer tests.  */
    printf( "%s\n%s\n%s\n", ( *headOfNodeList )->name,
            ( ( *headOfNodeList )->next )->name,
            ( ( ( *headOfNodeList )->next )->next )->name );
    printf( "%s\n",
            ( ( ( ( ( *headOfNodeList )->next )->next )->prev )->prev )->
            name );


    /* Create the first edge.  */
    firstEdge = connectNodes( headOfEdgeList,
                              headOfNodeList, one, zero, 10 );

    printf( "firstEdge->weight = %d\n", ( firstEdge )->w );
    printf( "firstEdge->fromNode = %s\n",
            ( ( firstEdge )->fromNode )->name );


    /* Create the second edge.  */
    secondEdge = connectNodes( headOfEdgeList,
                               headOfNodeList, zero, two, 3 );

    printf( "secondEdge->weight = %d\n", ( secondEdge )->w );
    printf( "secondEdge->fromNode = %s\n",
            ( ( secondEdge )->fromNode )->name );
    printf( "secondEdge->toNode = %s\n",
            ( ( secondEdge )->toNode )->name );


    /* Create the third edge.  */
    thirdEdge = connectNodes( headOfEdgeList,
                              headOfNodeList, two, one, 8 );

    ( void ) thirdEdge;
    printf( "two->edgeListOut->weight = %d must be equal to 8\n",
            ( ( two )->edgeListOut )->w );

    return 0;

}
