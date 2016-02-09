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
    headPointer headOfVertexList;
    headPointer headOfEdgeList;
    nodePointer referenceToVertexNodes[10];
    nodePointer referenceToEdgeNodes[10];


    if ( ( headOfVertexList = malloc( sizeof( nodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );

    if ( ( headOfEdgeList = malloc( sizeof( nodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );


    initDoubleLinkedList( headOfVertexList );
    initDoubleLinkedList( headOfEdgeList );


    referenceToVertexNodes[0] = newVertex( "Ferrara", headOfVertexList );
    referenceToVertexNodes[1] = newVertex( "Bologna", headOfVertexList );
    referenceToVertexNodes[2] = newVertex( "Rovigo", headOfVertexList );
    referenceToVertexNodes[3] = newVertex( "Ravenna", headOfVertexList );
    referenceToVertexNodes[4] = newVertex( "Mantova", headOfVertexList );
    referenceToVertexNodes[5] = newVertex( "Mantova", headOfVertexList );
    referenceToVertexNodes[6] = newVertex( "Torino", headOfVertexList );


    referenceToEdgeNodes[0] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[0],
                                             referenceToVertexNodes[1],
                                             47 );

    referenceToEdgeNodes[1] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[0],
                                             referenceToVertexNodes[2],
                                             33 );

    referenceToEdgeNodes[2] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[0],
                                             referenceToVertexNodes[3],
                                             75 );


    referenceToEdgeNodes[3] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[0],
                                             referenceToVertexNodes[4],
                                             93 );

    referenceToEdgeNodes[4] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[4],
                                             referenceToVertexNodes[2],
                                             50 );

    referenceToEdgeNodes[5] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[4],
                                             referenceToVertexNodes[2],
                                             50 );

    /* Loope edge is permitted.  */
    referenceToEdgeNodes[6] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[6],
                                             referenceToVertexNodes[6],
                                             0 );


    printf( "lenght of vertexList = %d\n",
            lengthDoubleLinkedList( headOfVertexList ) );

    printf( "lenght of edgeList = %d\n",
            lengthDoubleLinkedList( headOfEdgeList ) );

    printf( "lenght of outEdgeList[0] = %d\n",
            lengthDoubleLinkedList( referenceToVertexNodes
                                    [0]->edgeListOut ) );

    printf( "lenght of inEdgeList[1] = %d\n",
            lengthDoubleLinkedList( referenceToVertexNodes
                                    [1]->edgeListIn ) );

    printf( "referenceToEdgeNodes[2]->weight = %d should be equal to 75\n",
            referenceToEdgeNodes[2]->w );

    printNodeEdges( referenceToVertexNodes[0]->edgeListOut );
    printNodeEdges( referenceToVertexNodes[1]->edgeListIn );
    printNodeEdges( referenceToVertexNodes[4]->edgeListOut );

    freeGraph( headOfVertexList, headOfEdgeList );
    /*  Dummy example: */
    /*  printf( "w = %d\n", ( ( ( *( referenceToVertexNodes[1]->edgeListIn ) ) ->next )->edgeAddr )->w );  */

    return 0;

}
