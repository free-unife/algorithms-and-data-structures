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


static bst BSTLeft( bst root );
static bst BSTRight( bst root );
static bst BSTParent( bst root );
static bst BSTMaxElement( bst root );
#ifdef M_BSTMAIN_C
static bst BSTMinElement( bst root );
#endif
static bst BSTPredecessor( bst root );
static bool BSTLeaf( bst root );
static bool BSTKeyEqual( char *key1, char *key2 );
static bool BSTKeyLess( char *key1, char *key2 );
static bool BSTKeyGreater( char *key1, char *key2 );
static bst BSTNewNode( bstPtr rootPtr, bst parent, char *key,
                       char *value );
static bst BSTNonEmptyInsert( bst root, char *key, char *value );
#ifdef M_BSTMAIN_C
static bool BSTis( bst root, char *minKey, char *maxKey );
#endif
static bool BSTNonEmptyDelete( bstPtr rootPtr, bst root, char *key );


void BSTInit( bstPtr rootPtr )
{

    *rootPtr = EMPTY;

    return;

}

bool BSTEmpty( bst root )
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

static bst BSTLeft( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( root->left );

}

static bst BSTRight( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( root->right );

}

static bst BSTParent( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( root->parent );

}

#ifdef M_BSTMAIN_C
static bst BSTMinElement( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( !BSTEmpty( BSTLeft( root ) ) ?
             BSTMaxElement( BSTLeft( root ) ) : root );

}
#endif

/* If the right element of the root is EMPTY return bst pointer, else goto
 * left node and re-test the condition.  */
static bst BSTMaxElement( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( !BSTEmpty( BSTRight( root ) ) ?
             BSTMaxElement( BSTRight( root ) ) : root );

}

static bst BSTPredecessor( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( BSTMaxElement( BSTLeft( root ) ) );

}

static bool BSTLeaf( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( ( BSTEmpty( BSTLeft( root ) ) )
             && ( BSTEmpty( BSTRight( root ) ) ) );

}

static bool BSTLeftSon( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( ( !BSTEmpty( BSTLeft( root ) ) )
             && ( BSTEmpty( BSTRight( root ) ) ) );

}

static bool BSTRightSon( bst root )
{

    assert( !BSTEmpty( root ) );

    return ( ( BSTEmpty( BSTLeft( root ) ) )
             && ( !BSTEmpty( BSTRight( root ) ) ) );

}

static bool BSTKeyEqual( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    return ( atoi( key1 ) == atoi( key2 ) ? true : false );

}

static bool BSTKeyLess( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    return ( atoi( key1 ) < atoi( key2 ) ? true : false );

}

static bool BSTKeyGreater( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    return ( atoi( key1 ) > atoi( key2 ) ? true : false );

}

static bst BSTNewNode( bstPtr rootPtr, bst parent, char *key, char *value )
{

    if ( ( ( *rootPtr ) = malloc( sizeof( struct node ) ) ) == NULL )
        exit( EXIT_FAILURE );

    ( *rootPtr )->key = key;
    ( *rootPtr )->value = value;
    ( *rootPtr )->left = EMPTY;
    ( *rootPtr )->right = EMPTY;
    ( *rootPtr )->parent = parent;

    return *rootPtr;

}

static bst BSTNonEmptyInsert( bst root, char *key, char *value )
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

bst BSTInsert( bstPtr rootPtr, char *key, char *value )
{

    /* Since random elements are generated, we can't use the following assert:
     * assert (key is not present in tree).
     * assert (BSTEmpty (BSTSearch (*ptree, key)));
     * Instead of this, we return EMPTY if a key is already present in the
     * tree.
     */

    assert( ( key != NULL ) && ( value != NULL ) );

    if ( BSTEmpty( *rootPtr ) )
        return ( BSTNewNode( rootPtr, EMPTY, key, value ) );
    else
        return ( BSTNonEmptyInsert( *rootPtr, key, value ) );

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

#ifdef M_BSTMAIN_C
static bool BSTis( bst root, char *minKey, char *maxKey )
{

    if ( BSTEmpty( root ) )
        return true;
    if ( BSTKeyLess( BSTKey( root ), minKey )
         || BSTKeyGreater( BSTKey( root ), maxKey ) )
        return false;

    return ( BSTis( BSTLeft( root ), minKey, BSTKey( root ) )
             && BSTis( BSTRight( root ), BSTKey( root ), maxKey ) );

}
#endif

static bool BSTNonEmptyDelete( bstPtr rootPtr, bst root, char *key )
{

    if ( !BSTKeyEqual( key, BSTKey( root ) ) ) {
        if ( BSTKeyLess( key, BSTKey( root ) ) ) {
            if ( BSTEmpty( BSTLeft( root ) ) )
                return false;
            else
                return ( BSTNonEmptyDelete
                         ( &( root->left ), BSTLeft( root ), key ) );
        } else {
            if ( BSTEmpty( BSTRight( root ) ) )
                return false;
            else
                return ( BSTNonEmptyDelete
                         ( &( root->right ), BSTRight( root ), key ) );
        }
    }
    /* key == root -> key.  */
    else {
        if ( BSTLeaf( root ) ) {
            *rootPtr = EMPTY;
            free( root );
        } else if ( BSTRightSon( root ) ) {
            *rootPtr = BSTRight( root );
            free( root );
        } else if ( BSTLeftSon( root ) ) {
            *rootPtr = BSTLeft( root );
            free( root );
            /* Two sons.  */
        } else {
            root->key = BSTKey( BSTPredecessor( root ) );
            root->value = BSTVal( BSTPredecessor( root ) );
            root->parent = BSTParent( root );
            return ( BSTNonEmptyDelete
                     ( &( root->left ), BSTLeft( root ),
                       BSTKey( root ) ) );
        }
    }

    return true;

}

bool BSTDelete( bstPtr rootPtr, char *key )
{

    /* Deleting an empty tree will result in an empty tree.  */
    if ( BSTEmpty( *rootPtr ) )
        return true;
    else
        return ( BSTNonEmptyDelete( rootPtr, *rootPtr, key ) );

}

#ifdef M_BSTMAIN_C
int main( void )
{

    bstPtr bsTree;


    if ( ( bsTree = malloc( sizeof( bst ) ) ) == NULL )
        exit( EXIT_FAILURE );

    BSTInit( bsTree );
    if ( BSTEmpty( *bsTree ) )
        fprintf( stderr, "bsTree is empty\n" );


    fprintf( stderr, "\n\nInserting Elements...\n" );
    BSTInsert( bsTree, "01", "ciao" );
    BSTInsert( bsTree, "02", "hello" );
    BSTInsert( bsTree, "00", "hola" );
    BSTInsert( bsTree, "04", "hallo" );
    if ( BSTEmpty( BSTInsert( bsTree, "03", "testing" ) ) )
        fprintf( stderr, "This message should NOT be printed\n" );
    if ( BSTEmpty( BSTInsert( bsTree, "03", "bad Value" ) ) )
        fprintf( stderr, "This message should be printed\n" );


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
    if ( BSTEmpty( BSTSearch( *bsTree, "103" ) ) )
        fprintf( stderr,
                 "Pointer to node with key 103 should be (nil): %p\n",
                 ( void * ) BSTSearch( *bsTree, "103" ) );


    fprintf( stderr, "\n\nBST test\n" );
    if ( BSTis( *bsTree, "00", "99" ) )
        fprintf( stderr, "\n\nInput tree is a BST\n" );
    else
        fprintf( stderr, "\n\nInput tree is NOT a BST\n" );


    fprintf( stderr, "\n\nDeletion of non-existing node\n" );
    if ( BSTDelete( bsTree, "10" ) )
        fprintf( stderr, "This message should NOT be printed\n" );
    else
        fprintf( stderr, "This message should be printed\n" );


    fprintf( stderr, "\n\nManual tree deletion\n" );
    if ( BSTDelete( bsTree, "00" ) && BSTDelete( bsTree, "01" )
         && BSTDelete( bsTree, "02" ) && BSTDelete( bsTree, "03" )
         && BSTDelete( bsTree, "04" ) )
        if ( BSTEmpty( *bsTree ) )
            fprintf( stderr, "The whole tree has been deleted\n" );


    fprintf( stderr, "\n\nEmpty tree deletion\n" );
    if ( BSTDelete( bsTree, "00" ) )
        fprintf( stderr, "An empty tree has been deleted\n" );



    fprintf( stderr, "\n\nInserting Elements...\n" );
    BSTInsert( bsTree, "01", "ciao" );
    BSTInsert( bsTree, "02", "hello" );
    BSTInsert( bsTree, "00", "hola" );
    BSTInsert( bsTree, "04", "hallo" );
    BSTInsert( bsTree, "03", "testing" );
    BSTInsert( bsTree, "05", "good morning" );


    fprintf( stderr, "\n\nCheck parent fields\n" );
    fprintf( stderr, "Parent of node with key %s = %s\n", "03",
             BSTKey( BSTParent( BSTSearch( *bsTree, "03" ) ) ) );
    if ( BSTDelete
         ( bsTree, BSTKey( BSTParent( BSTSearch( *bsTree, "03" ) ) ) ) )
        fprintf( stderr,
                 "Node with key %s has been deleted, Now the parent of %s should be %s: %s\n",
                 "04", "03", "02",
                 BSTKey( BSTParent( BSTSearch( *bsTree, "03" ) ) ) );


    return 0;

}
#endif
