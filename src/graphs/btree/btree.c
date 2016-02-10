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


boolean emptyTree( tree t )
{
    return ( t == EMPTY );
}

tree consTree( element e, tree leftTree, tree rightTree )
{

    tree root = EMPTYTREE;

    /*
    char stringElement[10];
    sprintf(stringElement, "%d", e);
    */

    /* if there's no left and right three, make a new tree */
    if ( emptyTree( leftTree ) && emptyTree( rightTree ) ) {
        root = newVertex( e, EMPTY );

    } else if ( emptyTree( rightTree ) ) {
        root = newVertex( e, leftTree->pointerToVertexHead );
        connectVertex( leftTree->pointerToEdgeHead, root, leftTree, 0 );

    } else if ( emptyTree( leftTree ) ) {
        printf
            ( "Left tree cannot be empty if right tree is not empty!\n" );

    }
    /* otherwise make new vertex as root and two trees as son  */
    else {
        root = newVertex(e, leftTree->pointerToVertexHead );
        connectVertex( leftTree->pointerToEdgeHead, root, leftTree, 0 );
        connectVertex( leftTree->pointerToEdgeHead, root, rightTree, 0 );
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

    if ( dummy == thisEdge ) {
        return EMPTYTREE;
    } else {
        return ( thisEdge->edgeAddr->toNode );
    }
}

/* return right subtree, it assumes that left node is the second edge in list */
tree right( tree t )
{
    nodePointer dummy;
    nodePointer thisEdge;


    assert( !emptyTree( t ) );

    dummy = ( *( t->edgeListOut ) );
    thisEdge = dummy->next;

    if ( dummy == thisEdge ) {
        return EMPTYTREE;
    } else {
        return ( thisEdge->next->edgeAddr->toNode );
    }
}


/* this is the equivalent function to car, as view inside lists */
element root( tree t )
{
    assert( !emptyTree( t ) );

    return t->name;
    /*return atoi(t->name)*/
}

/* Max number of nodes inside a tree */
int findWeight(tree t) {
    return( emptyTree(t) ? 0
                         : 1 + findWeight(left( t )) + findWeight(right(t )));
}

/* In-order insert */
tree insOrd(element el, tree t){
/* P = { el ∉ t } */
if (emptyTree(t)){
    printf("Almeno la testa dovrebbe esserci eh.. \n");
    return consTree(el, EMPTYTREE, EMPTYTREE);
}
    

else if ( el < root(t) ){
    return consTree( root(t), insOrd( el, left(t) ), right(t));
}
/* greaterThan(el, root(t)) */
else{
    return consTree(root(t), left(t), insOrd( el, right(t)));
}
  
    
}