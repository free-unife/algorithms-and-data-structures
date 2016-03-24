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


void BSTinit( bst * root )
{

    *root = EMPTY;

    return;

}

boolean BSTEmpty( bst root )
{

    return ( root == EMPTY );

}

char *BSTKey( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( root->key );

}

char *BSTVal( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( root->value );

}

bst BSTLeft( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( root->left );

}

bst BSTRight( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( root->right );

}

bst BSTParent( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( root->parent );

}

boolean BSTKeyEqual( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    return ( atoi( key1 ) == atoi( key2 ) ? true : false );

}

boolean BSTKeyLess( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    return ( atoi( key1 ) < atoi( key2 ) ? true : false );

}

boolean BSTKeyGreater( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    return ( atoi( key1 ) > atoi( key2 ) ? true : false );

}

bst BSTNewNode( bst * ptree, bst parent, char *key, char *value )
{

    if ( ( ( *ptree ) = malloc( sizeof( struct node ) ) ) == NULL )
        exit( EXIT_FAILURE );

    ( *ptree )->key = key;
    ( *ptree )->value = value;
    ( *ptree )->left = EMPTY;
    ( *ptree )->right = EMPTY;
    ( *ptree )->parent = parent;

    return *ptree;

}

bst BSTNonEmptyInsert( bst root, char *key, char *value )
{

    /* since &(right(root)) and &(left(root)) cannot be done, we can't use the
     * ADT functions and we can't use an extra variable. FIXME
     * http://stackoverflow.com/questions/11397818/using-unary-operator-on-function-return-value
     */

    if ( BSTKeyLess( key, BSTKey( root ) ) ) {

        if ( !BSTEmpty( BSTLeft( root ) ) )
            return ( BSTNonEmptyInsert( BSTLeft( root ), key, value ) );

        else
            return ( BSTNewNode( &( root->left ), root, key, value ) );

    } else if ( BSTKeyGreater( key, BSTKey( root ) ) ) {

        if ( !BSTEmpty( BSTRight( root ) ) )
            return ( BSTNonEmptyInsert( BSTRight( root ), key, value ) );

        else
            return ( BSTNewNode( &( root->right ), root, key, value ) );
    }

    /* Key equal (i.e. element already in tree.)  */
    else
        return EMPTY;

}

bst BSTinsert( bst * ptree, char *key, char *value )
{

    /* Since random elements are generated, we can't use the following assert:
     * assert (key is not present in tree).
     * assert (BSTEmpty (BSTSearch (*ptree, key)));
     * Instead of this, we return EMPTY if a key is already present in the
     * tree.
     */

    assert( ( key != NULL ) && ( value != NULL ) );

    if ( BSTEmpty( *ptree ) )
        return ( BSTNewNode( ptree, EMPTY, key, value ) );
    else
        return ( BSTNonEmptyInsert( *ptree, key, value ) );

}

/* If the left element of the root is EMPTY return bst pointer, else goto
 * left node and re-test the condition.  */
bst BSTMinElement( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( !BSTEmpty( BSTLeft( root ) ) ?
             BSTMinElement( BSTLeft( root ) ) : root );

}

bst BSTMaxElement( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( !BSTEmpty( BSTRight( root ) ) ?
             BSTMaxElement( BSTRight( root ) ) : root );

}

bst BSTSearch( bst root, char *key )
{

    if ( BSTEmpty( root ) )
        return EMPTY;
    else if ( BSTKeyEqual( BSTKey( root ), key ) )
        return root;
    else if ( BSTKeyGreater( BSTKey( root ), key ) )
        return ( BSTSearch( BSTLeft( root ), key ) );
    else
        return ( BSTSearch( BSTRight( root ), key ) );

}

boolean BSTis( bst root, char *minKey, char *maxKey )
{

    if ( BSTEmpty( root ) )
        return true;
    if ( BSTKeyLess( BSTKey( root ), minKey )
         || BSTKeyGreater( BSTKey( root ), maxKey ) )
        return false;

    return ( BSTis( BSTLeft( root ), minKey, BSTKey( root ) )
             && BSTis( BSTRight( root ), BSTKey( root ), maxKey ) );

}

/* Before implementing the delete function we need successor and predecessor
 * functions.
 */
/* bst BSTdelete(bst *ptree, char *key);  */


#ifdef M_BSTMAIN_C
int main( void )
{

    bst *bsTree;


    if ( ( bsTree = malloc( sizeof( bst ) ) ) == NULL )
        exit( EXIT_FAILURE );

    BSTinit( bsTree );
    if ( BSTEmpty( *bsTree ) )
        fprintf( stderr, "bsTree is empty\n" );


    fprintf( stderr, "\n\nInserting Elements...\n" );
    BSTinsert( bsTree, "01", "ciao" );
    BSTinsert( bsTree, "02", "hello" );
    BSTinsert( bsTree, "00", "hola" );
    BSTinsert( bsTree, "04", "hallo" );
    if ( BSTinsert( bsTree, "03", "testing" ) == EMPTY )
        fprintf( stderr, "NOT OK\n" );
    if ( BSTinsert( bsTree, "03", "bad Value" ) == EMPTY )
        fprintf( stderr, "OK\n" );


    fprintf( stderr, "\n\nManual tree traversal\n" );
    fprintf( stderr, "%s\n", BSTKey( BSTLeft( *bsTree ) ) );
    fprintf( stderr, "%s\n", BSTKey( BSTRight( *bsTree ) ) );
    fprintf( stderr, "%s\n", BSTKey( BSTRight( BSTRight( *bsTree ) ) ) );
    fprintf( stderr, "%s\n",
             BSTKey( BSTLeft( BSTRight( BSTRight( *bsTree ) ) ) ) );


    fprintf( stderr, "\n\nMin and max\n" );
    printf( "min = %s\n", BSTKey( BSTMinElement( *bsTree ) ) );
    printf( "max = %s\n", BSTKey( BSTMaxElement( *bsTree ) ) );


    fprintf( stderr, "\n\nSearch for key 03\n" );
    fprintf( stderr, "value of 03 = %s\n",
             BSTVal( BSTSearch( *bsTree, "03" ) ) );
    fprintf( stderr, "Search non-existing key 103\n" );
    if ( !BSTSearch( *bsTree, "103" ) )
        fprintf( stderr, "value of 103 = %s\n", "(null)" );


    if ( BSTis( *bsTree, "00", "99" ) )
        fprintf( stderr, "\n\nInput tree is a BST\n" );
    else
        fprintf( stderr, "\n\nInput tree is NOT a BST\n" );


    fprintf( stderr, "\n\nCheck parent fields\n" );
    fprintf( stderr, "Parent of node with key %s = %s\n", "03",
             BSTKey( BSTParent( BSTSearch( *bsTree, "03" ) ) ) );

    return 0;

}
#endif
