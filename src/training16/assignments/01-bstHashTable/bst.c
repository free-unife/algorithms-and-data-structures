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


void initBST( bst root )
{

    root = EMPTY;
    ( void ) root;

}

boolean isBSTEmpty( bst root )
{

    return ( root == EMPTY );

}

bst newNode( char *key, char *value )
{
    bst nodeAddress;


    if ( ( nodeAddress = malloc( sizeof( struct node ) ) ) == NULL )
        exit( EXIT_FAILURE );

    nodeAddress->key = key;
    nodeAddress->value = value;
    nodeAddress->left = EMPTY;
    nodeAddress->right = EMPTY;
    nodeAddress->parent = EMPTY;

    return nodeAddress;

}

boolean lessThan( char *key1, char *key2 )
{

    assert ((key1 != NULL) && (key2 != NULL));

    if ( atoi( key1 ) < atoi( key2 ) ) {
        return true;
    } else {
        return false;
    }

}

boolean greaterThan( char *key1, char *key2 )
{

    assert ((key1 != NULL) && (key2 != NULL));

    if ( atoi( key1 ) > atoi( key2 ) ) {
        return true;
    } else {
        return false;
    }

}

bst insert( char *key, char *value, bst root )
{

    assert ((key != NULL) && (value != NULL));

    if ( isBSTEmpty( root ) ) {
        printf ("in\n");
        return newNode( key, value );
    } else if ( lessThan( key, root->key ) ) {
        insert( key, value, left (root) );
    } else {
        insert( key, value, right (root) );
    }

    return EMPTY;

}

bst left( bst root )
{

    assert (root != EMPTY);

    return ( root->left );

}

bst right( bst root )
{

    assert (root != EMPTY);

    return ( root->right );

}

#ifdef M_BSTMAIN_C
int main( void )
{

    bst bsTree = EMPTY, tmp;


    initBST( bsTree );
    if ( isBSTEmpty( bsTree ) )
        fprintf( stderr, "bsTree is empty\n" );

    bsTree = insert( "00", "ciao", bsTree );
    tmp = insert( "02", "hola", bsTree );
    tmp = insert( "01", "hallo", bsTree );

    if ( !isBSTEmpty( left (bsTree) ) )
        fprintf( stderr, "bsTree is NOT empty\n" );

    fprintf (stderr, "%p %s\n", (void *) (left (bsTree)), tmp -> value);


    return 0;

}
#endif

/*
bst search(char *key, bst root);
boolean delete(char *key, bst root);
boolean isBST(bst root);
*/
