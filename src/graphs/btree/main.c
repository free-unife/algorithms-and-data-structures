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

    tree aTree = EMPTYTREE;
    tree root;
    int nodeNum;


    aTree = insOrd( "20", aTree );

    aTree = insOrd( "10", aTree );
    aTree = insOrd( "30", aTree );

    aTree = insOrd( "5", aTree );
    aTree = insOrd( "15", aTree );
    aTree = insOrd( "25", aTree );
    aTree = insOrd( "35", aTree );

    root = aTree;

    printVertex( aTree->pointerToVertexHead );
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
