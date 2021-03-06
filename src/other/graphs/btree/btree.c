/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef TREE_H
#define TREE_H
#include "btree.h"
#endif


static headPointer globalPointerToVertexHead;
static headPointer globalPointerToEdgeHead;

boolean emptyTree( tree t )
{
    return ( t == EMPTY );
}

void initTrees( void )
{
    if ( ( globalPointerToVertexHead =
           malloc( sizeof( nodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );

    if ( ( globalPointerToEdgeHead =
           malloc( sizeof( nodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );

    initDoubleLinkedList( globalPointerToVertexHead );
    initDoubleLinkedList( globalPointerToEdgeHead );

    return;
}

tree consTree( element e, tree leftTree, tree rightTree )
{

    tree root = EMPTYTREE;

    /* If there's no left and right three, make a new tree.  */
    if ( emptyTree( leftTree ) && emptyTree( rightTree ) ) {
        /* After this call a new graph will be initialized.  */
        root =
            newVertex( e, globalPointerToVertexHead,
                       globalPointerToEdgeHead );

    } else if ( emptyTree( rightTree ) ) {
        root =
            newVertex( e, globalPointerToVertexHead,
                       globalPointerToEdgeHead );
        connectVertex( globalPointerToEdgeHead, root, leftTree, 'l' );

    } else if ( emptyTree( leftTree ) ) {
        root =
            newVertex( e, globalPointerToVertexHead,
                       globalPointerToEdgeHead );
        connectVertex( globalPointerToEdgeHead, root, rightTree, 'r' );
    }
    /* otherwise make new vertex as root and two trees as son  */
    else {
        root =
            newVertex( e, globalPointerToVertexHead,
                       globalPointerToEdgeHead );
        connectVertex( globalPointerToEdgeHead, root, leftTree, 'l' );
        connectVertex( globalPointerToEdgeHead, root, rightTree, 'r' );
    }

    return root;
}

/* return left subtree, it assumes that left node is the first edge in list */
tree left( tree t )
{
    nodePointer dummy;
    nodePointer thisEdge;

    assert( !emptyTree( t ) );

    dummy = ( *( t->edgeListOut ) );
    thisEdge = dummy->next;

    while ( thisEdge != dummy ) {

        if ( thisEdge->edgeAddr->w == 'l' ) {
            return ( ( thisEdge->edgeAddr )->toNode );
        }

        thisEdge = thisEdge->next;
    }

    return EMPTYTREE;
}

/* return right subtree, it assumes that left node is the second edge in list */
tree right( tree t )
{
    nodePointer dummy;
    nodePointer thisEdge;

    assert( !emptyTree( t ) );

    dummy = ( *( t->edgeListOut ) );
    thisEdge = dummy->next;


    while ( thisEdge != dummy ) {

        if ( thisEdge->edgeAddr->w == 'r' ) {
            return ( ( thisEdge->edgeAddr )->toNode );
        }

        thisEdge = thisEdge->next;
    }

    return EMPTYTREE;
}


/* this is the equivalent function to car, as view inside lists */
element root( tree t )
{
    assert( !emptyTree( t ) );

    return t->name;
}

/* Returns the number of nodes inside a tree */
int findWeight( tree t )
{
    return ( emptyTree( t ) ? 0
             : 1 + findWeight( left( t ) ) + findWeight( right( t ) ) );
}

boolean lessThan( element newEl, element rootEl )
{
    if ( atoi( newEl ) < atoi( rootEl ) ) {
        return true;
    } else {
        return false;
    }
}

boolean greaterThan( element newEl, element rootEl )
{
    if ( atoi( newEl ) > atoi( rootEl ) ) {
        return true;
    } else {
        return false;
    }
}

/* In-order insert */
tree insOrd( element el, tree t )
{
    /* P = { el ∉ t } */
    if ( emptyTree( t ) ) {
        return consTree( el, EMPTYTREE, EMPTYTREE );
    }

    else if ( lessThan( el, root( t ) ) ) {
        return consTree( root( t ), insOrd( el, left( t ) ), right( t ) );
    }
    /* greaterThan(el, root(t)) */
    else {
        return consTree( root( t ), left( t ), insOrd( el, right( t ) ) );
    }
}

/* Recirsive version.
 * NULL is returned if element with corresponding key is not found.
 */
tree searchBST ( tree t, element key )
{

    if (emptyTree (t)) {
        return EMPTYTREE;
    }
    else if (root (t) == key) {
        return t;
    }
    else if (lessThan( key, root( t ))) {
        return (searchBST (left (t), key));
    }
    else {
        return (searchBST (right (t), key));
    }

}

boolean isBST (tree t, element minKey, element maxKey)
{

    if (emptyTree (t)) {
        return true;
    }
    if (lessThan (root (t), minKey) || greaterThan (root(t), maxKey)) {
        return false;
    }

    return ( isBST(left(t), minKey, root (t)) && isBST(right (t), root (t), maxKey));

}

/* Binary tree visit functions.
 * These functions assign a progressive weight ((*graphElelement) -> w) (with
 * the first one given by input) to each vertex, depending on the order of the
 * visit. This weight is useful to know whether any vertex is a descendent of a
 * given vertex (preOrder and postOrder) or to know whether any node is the
 * left (w <) or right (w >) child of a parent (inOrder).
 * Each one of the three functions returns the number of nodes in the (sub)tree
 * root.
 */

/* Visit root, left and right.  */
int preOrder( tree root, int number )
{

    int leftKids, rightKids;


    assert( !emptyTree( root ) );

    printf( "Visiting %s\n", root->name );
    /* givenNo = weight w. */
    root->w = number;

    leftKids =
        ( !emptyTree( left( root ) ) ? preOrder( left( root ), number + 1 )
          : 0 );
    rightKids =
        ( !emptyTree( right( root ) ) ?
          preOrder( right( root ), number + 1 + leftKids ) : 0 );

    root->size = leftKids + rightKids + 1;

    return root->size;
}

/* Visit left, root and right.  */
int inOrder( tree root, int number )
{

    int leftKids, rightKids;


    assert( !emptyTree( root ) );

    leftKids =
        ( !emptyTree( left( root ) ) ? inOrder( left( root ), number )
          : 0 );

    printf( "Visiting %s\n", root->name );
    /* givenNo = weight w. */
    root->w = number + leftKids;

    rightKids =
        ( !emptyTree( right( root ) ) ?
          inOrder( right( root ), number + leftKids + 1 ) : 0 );

    root->size = leftKids + 1 + rightKids;

    return root->size;
}

/* Visit left, right and root.  */
int postOrder( tree root, int number )
{

    int leftKids, rightKids;


    assert( !emptyTree( root ) );

    leftKids =
        ( !emptyTree( left( root ) ) ? postOrder( left( root ), number )
          : 0 );

    rightKids =
        ( !emptyTree( right( root ) ) ?
          postOrder( right( root ), number + leftKids ) : 0 );

    printf( "Visiting %s\n", root->name );
    /* givenNo = weight w. */
    root->w = number + leftKids + rightKids;

    root->size = leftKids + rightKids + 1;

    return root->size;
}
