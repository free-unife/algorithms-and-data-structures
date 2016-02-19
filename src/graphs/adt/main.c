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

    nodePointer referenceToVertexNodes[10];
    nodePointer referenceToEdgeNodes[10];
    headPointer headOfVertexList = EMPTY;
    headPointer headOfEdgeList = EMPTY;
    nodePointer rootVertex;


    referenceToVertexNodes[0] = newVertex( "Ferrara", EMPTY, EMPTY );
    headOfVertexList = referenceToVertexNodes[0]->pointerToVertexHead;
    headOfEdgeList = referenceToVertexNodes[0]->pointerToEdgeHead;

    referenceToVertexNodes[1] =
        newVertex( "Bologna", headOfVertexList, headOfEdgeList );
    referenceToVertexNodes[2] =
        newVertex( "Rovigo", headOfVertexList, headOfEdgeList );
    referenceToVertexNodes[3] =
        newVertex( "Ravenna", headOfVertexList, headOfEdgeList );
    referenceToVertexNodes[4] =
        newVertex( "Mantova", headOfVertexList, headOfEdgeList );
    referenceToVertexNodes[5] =
        newVertex( "Torino", headOfVertexList, headOfEdgeList );
    referenceToVertexNodes[6] =
        newVertex( "Vaduz", headOfVertexList, headOfEdgeList );
    referenceToVertexNodes[7] =
        newVertex( "Balzers", headOfVertexList, headOfEdgeList );


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
                                             referenceToVertexNodes[5],
                                             100 );

    referenceToEdgeNodes[6] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[5],
                                             referenceToVertexNodes[6],
                                             200 );



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

    rootVertex = referenceToVertexNodes[0];
    breadthFirstSearch( headOfVertexList, rootVertex );
    printVertexDistancesFromRootNode( headOfVertexList, rootVertex );

    printf( "\n" );

    singleSourceShortestPaths( headOfVertexList, rootVertex );
/*    printVertexDistancesFromRootNode( headOfVertexList, rootVertex );*/


    freeGraph( headOfVertexList, headOfEdgeList );

    /*  Dummy example: */
    /*  printf( "w = %d\n", ( ( ( *( referenceToVertexNodes[1]->edgeListIn ) ) ->next )->edgeAddr )->w );  */

    return 0;

}
