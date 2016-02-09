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


boolean emptyTree( tRoot t )
{
    return ( t == EMPTY );
}

tRoot constree( element e, tRoot leftTree, tRoot rightTree )
{

    tRoot root = EMPTYTREE;

    /* if there's no left and right three, make a new tree */
    if ( emptyTree (leftTree ) && emptyTree ( rightTree) ) {
        root = newVertex( e, EMPTY );
    }
    else if ( emptyTree (rightTree) ) {
        root = newVertex (e, leftTree->pointerToVertexHead);
        connectVertex (leftTree->pointerToEdgeHead, root, leftTree, 0);
    }
    else if (emptyTree (leftTree)) {
        printf ("Left tree cannot be empty if right tree is not empty!\n");
    }
    /* otherwise make new vertex as root and two trees as son  */
    else {
        root = newVertex( e, leftTree->pointerToVertexHead );
        connectVertex( leftTree->pointerToEdgeHead, root, leftTree, 0 );
        connectVertex( leftTree->pointerToEdgeHead, root, rightTree, 0 );
    }

    return root;
}

/* return left subtree, it assumes that left node is the first edge in list */
tRoot left( tRoot t )
{
    nodePointer dummy = ( *( t->edgeListOut ) );
    nodePointer thisEdge = dummy->next;

    if ( dummy == thisEdge ) {
        return EMPTYTREE;
    } else {
        return ( thisEdge->edgeAddr->toNode );
    }
}

/* return right subtree, it assumes that left node is the second edge in list */
tRoot right( tRoot t )
{
    nodePointer dummy = ( *( t->edgeListOut ) );
    nodePointer thisEdge = dummy->next;

    if ( dummy == thisEdge ) {
        return EMPTYTREE;
    } else {
        return ( thisEdge->next->edgeAddr->toNode );
    }
}


/* this is the equivalent function to car, as view inside lists */
element root( tRoot t )
{
    return t->name;
}
