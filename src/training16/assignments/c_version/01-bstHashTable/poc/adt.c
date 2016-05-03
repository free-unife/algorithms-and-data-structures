/*
 * @file adt.c
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

bool node_null ( node n )
{
    return ( n == NULL );
}

char *key_get ( node n )
{
    return ( node_null ( n ) ? NULL : n -> key );
}

bool key_set ( node n, char *key )
{
    if ( node_null ( n ) )
        return false;
    else
    {
        n -> key = key;
        return true;
    }
}

char *value_get ( node n )
{
    return ( node_null ( n ) ? NULL : n -> value );
}

bool value_set ( node n, char *value )
{
    if ( node_null ( n ) )
        return false;
    else
    {
        n -> value = value;
        return true;
    }
}

bool keys_equal( char *key1, char *key2 )
{
    assert( ( key1 != NULL ) && ( key2 != NULL ) );
    return ( ( strcmp( key1, key2 ) == 0 ) ? true : false );
}

bool keys_less( char *key1, char *key2 )
{
    assert( ( key1 != NULL ) && ( key2 != NULL ) );
    return ( ( strcmp( key1, key2 ) < 0 ) ? true : false );
}

bool keys_greater( char *key1, char *key2 )
{
    assert( ( key1 != NULL ) && ( key2 != NULL ) );
    return ( ( strcmp( key1, key2 ) > 0 ) ? true : false );
}


/* ========================= */

node node_new ( char *key, char * value, char type )
{
    node new_node;
    struct listNode *l;
    struct bstNode *b;

    new_node = malloc_safe ( sizeof ( struct Node ) );

    /* BST */
    if ( type == 'b' )
    {
        b = malloc_safe ( sizeof ( struct bstNode ) );
        new_node -> ln = NULL;
        new_node -> bn = b;
        ( new_node -> bn ) -> parentStructPtr = new_node;
    /* LIST */
    } else {
        l = malloc_safe ( sizeof ( struct listNode ) );
        new_node -> ln = l;
        new_node -> bn = NULL;
        ( new_node -> ln ) -> parentStructPtr = new_node;
    }

    new_node->key = key;
    new_node->value = value;

    return new_node;


}

void nodes_connect ( node from, node to )
{
    assert ( from != NULL && to != NULL);

    /* List only. */
    if ( from -> bn == NULL && to -> bn == NULL ) {
        ( from -> ln ) -> next = to -> ln;
        ( to -> ln ) -> prev = from -> ln;
        ( to -> ln ) -> next = NULL;
    } else if ( from -> ln == NULL && to -> ln == NULL ) {
        ( from -> bn ) -> left = to -> bn;
        /* etc... */
    }

}

void node_print ( node n );

void list_print ( node l )
{
    if ( l == NULL )
        return;
    else
    {
        printf ( "%s\t%s\n", l -> key, l -> value );
        if ( l->ln != NULL && l->ln->next != NULL )
            node_print ( l -> ln -> next -> parentStructPtr );
    }
}

void bst_print( node b )
{
    (void) b;
    printf ("bst print\n");
}

void node_print ( node n )
{
    if ( n == NULL )
        return;
    /* list only */
    else if ( n -> bn == NULL  )
    {
        list_print ( n );
    }
    else if ( n -> ln == NULL)
    {
        bst_print ( n );
    }
}
