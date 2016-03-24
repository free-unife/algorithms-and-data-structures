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

boolean BSTKeyEqual (char *key1, char *key2 )
{

    return (atoi (key1) == atoi (key2) ? true : false);

}

boolean BSTKeyLess( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    if ( atoi( key1 ) < atoi( key2 ) ) {
        return true;
    } else {
        return false;
    }

}

boolean BSTKeyGreater( char *key1, char *key2 )
{

    assert( ( key1 != NULL ) && ( key2 != NULL ) );

    if ( atoi( key1 ) > atoi( key2 ) ) {
        return true;
    } else {
        return false;
    }

}

void BSTNewNode( bst * ptree, char *key, char *value )
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

void BSTNonEmptyInsert( bst root, char *key, char *value )
{

    /* since &(right(root)) and &(left(root)) cannot be done, we can't use the
     * ADT functions and we can't use an extra variable. FIXME
     * http://stackoverflow.com/questions/11397818/using-unary-operator-on-function-return-value
     */

    assert( ( key != NULL ) && ( value != NULL ) );

    if ( BSTKeyLess( key, BSTKey( root ) ) ) {
        if ( !BSTEmpty( BSTLeft( root ) ) ) {
            BSTNonEmptyInsert( BSTLeft( root ), key, value );
        } else {
            BSTNewNode( &(root -> left), key, value );
        }
    } else {
        if ( !BSTEmpty( BSTRight( root ) ) ) {
            BSTNonEmptyInsert( BSTRight( root ), key, value );
        } else {
            BSTNewNode( &(root -> right), key, value );
        }
    }

    return;

}

void BSTinsert( bst * ptree, char *key, char *value )
{

    /* assert (key is not present in tree).  */

    if ( ( *ptree ) == EMPTY )
        BSTNewNode( ptree, key, value );
    else
        BSTNonEmptyInsert( *ptree, key, value );

    return;

}

/* If the left element of the root is EMPTY return bst pointer, else goto
 * left node and re-test the condition.  */
bst BSTMinElement (bst root)
{

    assert( !BSTEmpty( root ) );

    return (!BSTEmpty (BSTLeft (root)) ? BSTMinElement (BSTLeft (root)) : root);

}

bst BSTMaxElement (bst root)
{

    assert( !BSTEmpty( root ) );

    return (!BSTEmpty (BSTRight (root)) ? BSTMaxElement (BSTRight (root)) : root);

}


bst BSTSearch( bst root, char *key )
{

    if (BSTEmpty (root))
        return EMPTY;
    else if ( BSTKeyEqual (BSTKey (root), key) )
        return root;
    else if ( BSTKeyGreater (BSTKey (root), key ) )
        return ( BSTSearch (BSTLeft (root), key));
    else
        return ( BSTSearch (BSTRight (root), key));

}

/*
boolean delete(char *key, bst root);
boolean isBST(bst root);
*/

#ifdef M_BSTMAIN_C
int main( void )
{

    bst *bsTree;


    if ( ( bsTree = malloc( sizeof( bst ) ) ) == NULL )
        exit( EXIT_FAILURE );

    BSTinit( bsTree );
    if ( BSTEmpty( *bsTree ) )
        fprintf( stderr, "bsTree is empty\n" );

    fprintf (stderr, "Inserting Elements...\n");
    BSTinsert( bsTree, "01", "ciao" );
    BSTinsert( bsTree, "02", "hello" );
    BSTinsert( bsTree, "00", "hola" );
    BSTinsert( bsTree, "04", "hallo" );
    BSTinsert( bsTree, "03", "testing" );

    fprintf ( stderr, "Manual tree traversal\n");
    fprintf( stderr, "%s\n", BSTKey( BSTLeft (*bsTree) ) );
    fprintf( stderr, "%s\n", BSTKey( BSTRight (*bsTree) ) );
    fprintf( stderr, "%s\n", BSTKey( BSTRight ( BSTRight (*bsTree) ) ) );
    fprintf( stderr, "%s\n", BSTKey( BSTLeft ( BSTRight ( BSTRight (*bsTree) ) ) ) );

    fprintf ( stderr, "Min and max:\n" );
    printf( "min = %s\n", BSTKey (BSTMinElement (*bsTree)) );
    printf( "max = %s\n", BSTKey (BSTMaxElement (*bsTree)) );

    fprintf (stderr, "Search for key 03\n");
    fprintf (stderr, "value of 03 = %s\n", BSTVal (BSTSearch (*bsTree, "03")));

    return 0;

}
#endif
