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

    tree aTree = EMPTYTREE, root;
    int nodeNum;

    nodePointer referenceToVertexNodes[10];
    nodePointer referenceToEdgeNodes[10];
    headPointer headOfVertexList = EMPTY;
    headPointer headOfEdgeList = EMPTY;


    /* Create a btree with the graph functions.  */

    referenceToVertexNodes[0] = newVertex( "root", EMPTY, EMPTY );
    headOfVertexList = referenceToVertexNodes[0]->pointerToVertexHead;
    headOfEdgeList = referenceToVertexNodes[0]->pointerToEdgeHead;

    referenceToVertexNodes[1] =
        newVertex( "left", headOfVertexList, headOfEdgeList );

    referenceToVertexNodes[2] =
        newVertex( "right", headOfVertexList, headOfEdgeList );


    referenceToEdgeNodes[0] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[0],
                                             referenceToVertexNodes[1],
                                             'l' );

    referenceToEdgeNodes[1] = connectVertex( headOfEdgeList,
                                             referenceToVertexNodes[0],
                                             referenceToVertexNodes[2],
                                             'r' );

    ( void ) referenceToEdgeNodes;

    printVertex( headOfVertexList );
    breadthFirstSearch( headOfVertexList, referenceToVertexNodes[0] );
    printVertexDistancesFromRootNode( headOfVertexList,
                                      referenceToVertexNodes[0] );

    /* Create a btree tree with the btree functions.  */

    aTree = insOrd( "20", aTree );

    aTree = insOrd( "10", aTree );
    aTree = insOrd( "30", aTree );

    aTree = insOrd( "5", aTree );
    aTree = insOrd( "15", aTree );
    aTree = insOrd( "25", aTree );
    aTree = insOrd( "35", aTree );

    root = aTree;

    printVertex( root->pointerToVertexHead );
    breadthFirstSearch( root->pointerToVertexHead, root );
    printVertexDistancesFromRootNode( root->pointerToVertexHead, root );

    preOrder( root, 0 );
    printf( "\n\n" );
    inOrder( root, 0 );
    printf( "\n\n" );
    nodeNum = postOrder( root, 0 );
    printf( "\n\n" );

    printf( "Number of nodes of the imput tree = %d\n", nodeNum );

    /*
       printf( "Weight of aTree: %d\n", findWeight( aTree ) );
       printf( "Root have to be 0 : --> %s\n", root( aTree ) );
       printf( "Right son of root --> %s\n", root( right( aTree ) ) );
       printf( "Left son of root --> %s\n", root( left( aTree ) ) );
       printf( " son of root --> %s\n", root( left( left( aTree ) ) ) );
       printf( " son of root --> %s\n", root( right( left( aTree ) ) ) );
       printf( " son of root --> %s\n", root( left( right( aTree ) ) ) );
       printf( " son of root --> %s\n", root( right( right( aTree ) ) ) );
     */

    return 0;
}
