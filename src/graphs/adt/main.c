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
    headPointer headOfNodeList;
    headPointer headOfEdgeList;
    nodePointer referenceToVertexNodes[10];
    nodePointer referenceToEdgeNodes[10];


    if ( ( headOfNodeList = malloc( sizeof( nodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );

    if ( ( headOfEdgeList = malloc( sizeof( nodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );


    initDoubleLinkedList( headOfNodeList );
    initDoubleLinkedList( headOfEdgeList );


    referenceToVertexNodes[0] = newVertex( "zero", headOfNodeList );
    referenceToVertexNodes[1] = newVertex( "one", headOfNodeList );
    referenceToVertexNodes[2] = newVertex( "two", headOfNodeList );


    ( void ) referenceToVertexNodes;

    referenceToEdgeNodes[0] = connectNodes( headOfEdgeList,
                                            referenceToVertexNodes[0],
                                            referenceToVertexNodes[1],
                                            10 );

    printf( "lenght of outEdgeList[0] = %d\n",
            lengthDoubleLinkedList( referenceToVertexNodes
                                    [0]->edgeListOut ) );

/*    printf( "lenght of inEdgeList[0] = %d\n",
            lengthDoubleLinkedList( referenceToVertexNodes
                                    [0]->edgeListIn ) );
*/

    ( void ) referenceToEdgeNodes;

/*

       printf( "firstEdge->weight = %d\n", ( firstEdge )->w );
       printf( "firstEdge->fromNode = %s\n",
       ( ( firstEdge )->fromNode )->name );



       referenceToEdgeNodes[1] = connectNodes( headOfEdgeList,
       headOfNodeList, referenceToVertexNodes[0], referenceToVertexNodes[2], 3 );

       printf( "secondEdge->weight = %d\n", ( secondEdge )->w );
       printf( "secondEdge->fromNode = %s\n",
       ( ( secondEdge )->fromNode )->name );
       printf( "secondEdge->toNode = %s\n",
       ( ( secondEdge )->toNode )->name );



       referenceToEdgeNodes[2] = connectNodes( headOfEdgeList,
       headOfNodeList, referenceToVertexNodes[2], referenceToVertexNodes[1], 8 );


     */
    return 0;

}
