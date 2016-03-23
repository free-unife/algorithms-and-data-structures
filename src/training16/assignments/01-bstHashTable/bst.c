/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_GLOBALDEFINES_H
#define M_GLOBALDEFINES_H
#include "globalDefines.h"
#endif


void initBST( bst * root )
{

    *root = EMPTY;

    return;

}

boolean isBSTEmpty( bst root )
{

    return ( root == EMPTY );

}

char *BSTKey( bst root )
{

    assert( root != EMPTY );

    return ( root->key );

}

char *BSTVal( bst root )
{

    assert( root != EMPTY );

    return ( root->value );

}

bst left( bst root )
{

    assert( root != EMPTY );

    return ( root->left );

}

bst right( bst root )
{

    assert( root != EMPTY );

    return ( root->right );

}

boolean lessThan( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    if ( atoi( key1 ) < atoi( key2 ) ) {
        return true;
    } else {
        return false;
    }

}

boolean greaterThan( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    if ( atoi( key1 ) > atoi( key2 ) ) {
        return true;
    } else {
        return false;
    }

}

void newNode( bst * ptree, char *key, char *value )
{

    if ( ( ( *ptree ) = malloc( sizeof( struct node ) ) ) == NULL )
        exit( EXIT_FAILURE );

    ( *ptree )->key = key;
    ( *ptree )->value = value;
    ( *ptree )->left = EMPTY;
    ( *ptree )->right = EMPTY;
    ( *ptree )->parent = EMPTY;

    return;

}

void nonEmptyInsert( bst root, char *key, char *value )
{

    /* since &(right(root)) and &(left(root)) cannot be done, we can't use the
     * ADT functions and we can't use an extra variable. FIXME
     * http://stackoverflow.com/questions/11397818/using-unary-operator-on-function-return-value
     */

    assert( ( key != NULL ) && ( value != NULL ) );

    if ( lessThan( key, BSTKey( root ) ) ) {
        if ( !isBSTEmpty( left( root ) ) ) {
            nonEmptyInsert( left( root ), key, value );
        } else {
            newNode( &(root -> left), key, value );
        }
    } else {
        if ( !isBSTEmpty( right( root ) ) ) {
            nonEmptyInsert( right( root ), key, value );
        } else {
            newNode( &(root -> right), key, value );
        }
    }

    return;

}

void insert( bst * ptree, char *key, char *value )
{

    /* assert (key is not present in tree).  */

    if ( ( *ptree ) == EMPTY )
        newNode( ptree, key, value );
    else
        nonEmptyInsert( *ptree, key, value );

    return;

}

/*
bst search(char *key, bst root);
boolean delete(char *key, bst root);
boolean isBST(bst root);
bst minBST (bst root);
bst maxBST (bst root);
*/

#ifdef M_BSTMAIN_C
int main( void )
{

    bst *bsTree;


    if ( ( bsTree = malloc( sizeof( bst ) ) ) == NULL )
        exit( EXIT_FAILURE );

    initBST( bsTree );
    if ( isBSTEmpty( *bsTree ) )
        fprintf( stderr, "bsTree is empty\n" );

    fprintf (stderr, "Inserting Elements...\n");
    insert( bsTree, "01", "ciao" );
    insert( bsTree, "02", "hello" );
    insert( bsTree, "00", "hola" );
    insert( bsTree, "04", "hallo" );
    insert( bsTree, "03", "testing" );

    fprintf (stderr, "Manual tree traversal\n");
    printf( "%s\n", BSTKey( left (*bsTree) ) );
    printf( "%s\n", BSTKey( right (*bsTree) ) );
    printf( "%s\n", BSTKey( right ( right (*bsTree) ) ) );
    printf( "%s\n", BSTKey( left ( right ( right (*bsTree) ) ) ) );

    return 0;

}
#endif
