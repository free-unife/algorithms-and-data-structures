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

    tree aTree = EMPTYTREE, bTree = EMPTYTREE, aRoot, bRoot;
    int nodeNum;

    (void) aTree;
    (void) aRoot;
    (void) nodeNum;

    /* Create the lists.  */
    initTrees(  );

/*
    aTree = insOrd( "20", aTree );

    aTree = insOrd( "10", aTree );
    aTree = insOrd( "30", aTree );

    aTree = insOrd( "5", aTree );
    aTree = insOrd( "15", aTree );
    aTree = insOrd( "25", aTree );
    aTree = insOrd( "35", aTree );

    aRoot = aTree;
*/
    bTree = insOrd( "43", bTree );
    bTree = insOrd( "31", bTree );
    bTree = insOrd( "52", bTree );
    bTree = insOrd( "12", bTree );

    bRoot = bTree;

    preOrder( bRoot, 0 );

/*    printf( "Vertex inside global vertex list:\n" );
    printVertex( aRoot->pointerToVertexHead );
    printf( "\n\n" );
    printf( "\nPre-order visit:\n" );
    preOrder( aRoot, 0 );
    printf( "\n\n" );
    printf( "In-order visit:\n" );
    inOrder( aRoot, 0 );
    printf( "\n\n" );
    printf( "Post-order visit:\n" );
    nodeNum = postOrder( aRoot, 0 );
    printf( "Number of nodes of the imput tree = %d\n", nodeNum );
    printf( "\n\n" );

    printf( "Pre-order visit on the second tree:\n" );
    preOrder( bRoot, 0 );
    printf( "\n\n" );



    if (isBST (aRoot, "0", "100")) {
        aTree = searchBST (aRoot, "35");
        printf ("\n\n");
        printf ("aTree is a BST\n");
    }
    else {
        printf ("aTree is not a BST \n");
    }
*/

    if (isBST (bRoot, "0", "100")) {
        bTree = searchBST (bRoot, "43");
        printf ("%s\n", bTree -> name);
        bTree = searchBST (bRoot, "31");
        printf ("%s\n", bTree -> name);
        bTree = searchBST (bRoot, "52");
        printf ("%s\n", bTree -> name);
        bTree = searchBST (bRoot, "12");
        printf ("%s\n", bTree -> name);
        printf ("\n\n");
        printf ("bTree is a BST\n");
    }
    else {
        printf ("bTree is not a BST \n");
    }

    printf ("\n");



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
