/*
 * @file utils.c
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Header file containing exportable methods.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

static node BSTNewNode ( nodePtr rootPtr, node parentNode, char *key, char *value);
static node BSTNonEmptyInsert( node root, char *key, char *value );

void BSTInit( nodePtr rootPtr )
{
    *rootPtr = NULL;
}

node BSTLeft ( node root )
{
    return ( node_null ( root ) ? NULL : root -> bn -> left -> parentStructPtr );
}

node BSTRight ( node root )
{
    return ( node_null ( root ) ? NULL : root -> bn -> right -> parentStructPtr );
}

node BSTParent ( node root )
{
    return ( node_null ( root ) ? NULL : root -> bn -> parent -> parentStructPtr );
}

static node BSTNewNode ( nodePtr rootPtr, node parentNode, char *key, char *value)
{
    printf ("\n%p\n", (void *) rootPtr);
    printf ("\n%p\n", (void *) *rootPtr);

    ( *rootPtr ) = node_new ( key, value, 'b' );
    ( *rootPtr )->bn -> left = NULL;
    ( *rootPtr )->bn -> right = NULL;

    if ( node_null ( parentNode ) )
        ( *rootPtr )->bn -> parent = NULL;
    else
        ( *rootPtr )->bn -> parent = parentNode -> bn;

    return *rootPtr;
}


static node BSTNonEmptyInsert( node root, char *key, char *value )
{
    /*
     * since &(right(root)) and &(left(root)) cannot be done, we can't use the
     * ADT functions and we can't use an extra variable.
     * http://stackoverflow.com/questions/11397818/using-unary-operator-on-function-return-value
     * Moreover the compound literal trick doesn't work (assertion failed).
     */

    if ( keys_less( key, key_get( root ) ) ) {

        if ( !node_null( BSTLeft( root ) ) )
            return ( BSTNonEmptyInsert( BSTLeft( root ), key, value ) );

        else
            return ( BSTNewNode( &( root->bn->left->parentStructPtr ), root, key, value ) );

    } else if ( keys_greater( key, key_get( root ) ) ) {

        if ( !node_null( BSTRight( root ) ) )
            return ( BSTNonEmptyInsert( BSTRight( root ), key, value ) );

        else {
    printf ("\n%s %s\n", key_get ( root ), key );
            return ( BSTNewNode( &( root->bn->right->parentStructPtr ), root, 
key, value ) ); }
    }
    /*
     * Key equal (i.e. element already in tree.)
     */
    else
        return NULL;
}


node BSTInsert( nodePtr rootPtr, char *key, char *value )
{
    /*
     * Since random elements are generated, we can't use the following assert:
     * assert (key is not present in tree).
     * assert (node_null (BSTSearch (*ptree, key)));
     * Instead of this, we return NULL if a key is already present in the
     * tree.
     */
    if ( element_null ( key ) || element_null ( value ) )
        return NULL;
    else if ( node_null( *rootPtr ) )
        return ( BSTNewNode( rootPtr, NULL, key, value ) );
    else
        return ( BSTNonEmptyInsert( *rootPtr, key, value ) );
}
