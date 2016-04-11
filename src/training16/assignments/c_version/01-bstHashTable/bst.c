/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

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
}

bool BSTEmpty( bst root )
{
    return ( root == EMPTY );
}

char *BSTKey( bst root )
{
    assert( !BSTEmpty( root ) );
    return ( !BSTEmpty( root ) ? root->key : EMPTYKEY );
}

char *BSTVal( bst root )
{
    assert( !BSTEmpty( root ) );
    return ( !BSTEmpty( root ) ? root->value : EMPTYVAL );
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
    return ( ( strcmp( key1, key2 ) == 0 ) ? true : false );
}

static bool BSTKeyLess( char *key1, char *key2 )
{
    assert( ( key1 != NULL ) && ( key2 != NULL ) );
    return ( ( strcmp( key1, key2 ) < 0 ) ? true : false );
}

static bool BSTKeyGreater( char *key1, char *key2 )
{
    assert( ( key1 != NULL ) && ( key2 != NULL ) );
    return ( ( strcmp( key1, key2 ) > 0 ) ? true : false );
}

static bst BSTNewNode( bstPtr rootPtr, bst parent, char *key, char *value )
{
    if ( ( ( *rootPtr ) = malloc( sizeof( struct bstNode ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    ( *rootPtr )->key = key;
    ( *rootPtr )->value = value;
    ( *rootPtr )->left = EMPTY;
    ( *rootPtr )->right = EMPTY;
    ( *rootPtr )->parent = parent;

    return *rootPtr;
}

static bst BSTNonEmptyInsert( bst root, char *key, char *value )
{
    /*
     * since &(right(root)) and &(left(root)) cannot be done, we can't use the
     * ADT functions and we can't use an extra variable.
     * http://stackoverflow.com/questions/11397818/using-unary-operator-on-function-return-value
     * Moreover the compound literal trick doesn't work (assertion failed).
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

    /*
     * Key equal (i.e. element already in tree.)  
     */
    else
        return EMPTY;
}

bst BSTInsert( bstPtr rootPtr, char *key, char *value )
{
    /*
     * Since random elements are generated, we can't use the following assert:
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
    /*
     * key == root -> key.  
     */
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
            /*
             * Two sons.  
             */
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
    /*
     * An empty tree cannot be deleted. 
     */
    if ( BSTEmpty( *rootPtr ) )
        return false;
    else
        return ( BSTNonEmptyDelete( rootPtr, *rootPtr, key ) );
}

#ifdef M_BSTMAIN_C
int main( void )
{
    bstPtr bsTree;

    if ( ( bsTree = malloc( sizeof( bst ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }


    fprintf( stderr, "Initializing BST\n" );
    BSTInit( bsTree );
    if ( BSTEmpty( *bsTree ) )
        fprintf( stderr, "[ OK ] BST is empty\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nInserting Elements...\n" );
    BSTInsert( bsTree, "01", "ciao" );
    BSTInsert( bsTree, "02", "hello" );
    BSTInsert( bsTree, "00", "hola" );
    BSTInsert( bsTree, "04", "hallo" );
    if ( BSTEmpty( BSTInsert( bsTree, "03", "testing" ) ) )
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    if ( BSTEmpty( BSTInsert( bsTree, "03", "bad Value" ) ) )
        fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr, "\n\nManual tree traversal\n" );
    fprintf( stderr, "%s\n", BSTKey( BSTLeft( *bsTree ) ) );
    fprintf( stderr, "%s\n", BSTKey( BSTRight( *bsTree ) ) );
    fprintf( stderr, "%s\n", BSTKey( BSTRight( BSTRight( *bsTree ) ) ) );
    fprintf( stderr, "%s\n",
             BSTKey( BSTLeft( BSTRight( BSTRight( *bsTree ) ) ) ) );
    fprintf( stderr,
             "[ OK ] This message should be shown and all previously printed values should be !(nil)\n" );


    fprintf( stderr, "\n\nMin and max\n" );
    fprintf( stderr, "min = %s\n", BSTKey( BSTMinElement( *bsTree ) ) );
    fprintf( stderr, "max = %s\n", BSTKey( BSTMaxElement( *bsTree ) ) );
    fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr, "\n\nSearch for key %s\n", "03" );
    fprintf( stderr, "value of %s = %s\n",
             "03", BSTVal( BSTSearch( *bsTree, "03" ) ) );
    fprintf( stderr, "Search non-existing key %s\n", "103" );
    if ( BSTEmpty( BSTSearch( *bsTree, "103" ) ) )
        fprintf( stderr, "[ OK ] Node with key 103 does not exist\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr,
             "\n\nIs a BST test with minKey = %s and maxKey = %s\n", "00",
             "99" );
    if ( BSTis( *bsTree, "00", "99" ) )
        fprintf( stderr, "[ OK ] Input tree is a BST\n" );
    else
        fprintf( stderr, "[ ERR ] Input tree is NOT a BST\n" );


    fprintf( stderr,
             "\n\nDeletion of non-existing node in a non-empty BST\n" );
    if ( !BSTDelete( bsTree, "10" ) )
        fprintf( stderr, "[ OK ] Node with key 10 cannot be deleted\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nManual tree deletion\n" );
    if ( BSTDelete( bsTree, "00" ) && BSTDelete( bsTree, "01" )
         && BSTDelete( bsTree, "02" ) && BSTDelete( bsTree, "03" )
         && BSTDelete( bsTree, "04" ) ) {
        if ( BSTEmpty( *bsTree ) )
            fprintf( stderr, "[ OK ] The whole tree has been deleted\n" );
        else
            fprintf( stderr,
                     "[ ERR ] This message should NOT be shown\n" );
    }


    fprintf( stderr, "\n\nEmpty tree deletion\n" );
    if ( !BSTDelete( bsTree, "00" ) )
        fprintf( stderr, "[ OK ] Cannot delete an empty tree\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nInserting Elements...\n" );
    BSTInsert( bsTree, "01", "ciao" );
    BSTInsert( bsTree, "02", "hello" );
    BSTInsert( bsTree, "00", "hola" );
    BSTInsert( bsTree, "04", "hallo" );
    BSTInsert( bsTree, "03", "testing" );
    BSTInsert( bsTree, "05", "good morning" );
    fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr, "\n\nCheck parent fields\n" );
    fprintf( stderr, "Parent of node with key %s = %s\n", "03",
             BSTKey( BSTParent( BSTSearch( *bsTree, "03" ) ) ) );
    if ( BSTDelete
         ( bsTree, BSTKey( BSTParent( BSTSearch( *bsTree, "03" ) ) ) ) )
        fprintf( stderr,
                 "[ OK ] Node with key %s has been deleted, Now the parent of %s should be %s: %s\n",
                 "04", "03", "02",
                 BSTKey( BSTParent( BSTSearch( *bsTree, "03" ) ) ) );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    free( bsTree );

    return 0;
}
#endif
