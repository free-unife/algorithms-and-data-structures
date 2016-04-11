/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

static bool LISTKeyEqual( char *key1, char *key2 );
static list LISTPredecessor( list head );
static list LISTSuccessor( list head );
static list LISTNewNode( listPtr headPtr, list prec, char *key,
                         char *value );
static list LISTNonEmptyInsert( list head, char *key, char *value );
static bool LISTNonEmptyDelete( listPtr headPtr, list head, char *key );

#ifdef M_LISTMAIN_C
static void printList( list head );
#endif

void LISTInit( listPtr headPtr )
{
    *headPtr = EMPTY;
}

bool LISTEmpty( list head )
{
    return ( head == EMPTY );
}

char *LISTKey( list head )
{
    assert( !LISTEmpty( head ) );
    return ( !LISTEmpty( head ) ? head->key : EMPTYKEY );
}

char *LISTVal( list head )
{
    assert( !LISTEmpty( head ) );
    return ( !LISTEmpty( head ) ? head->value : EMPTYVAL );
}

static bool LISTKeyEqual( char *key1, char *key2 )
{
    assert( ( key1 != NULL ) && ( key2 != NULL ) );
    return ( ( strcmp( key1, key2 ) == 0 ) ? true : false );
}

static list LISTPredecessor( list head )
{
    assert( !LISTEmpty( head ) );
    return ( head->prev );
}

static list LISTSuccessor( list head )
{
    assert( !LISTEmpty( head ) );
    return ( head->next );
}

static list LISTNewNode( listPtr headPtr, list prec, char *key,
                         char *value )
{
    if ( ( ( *headPtr ) = malloc( sizeof( struct listNode ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    ( *headPtr )->key = key;
    ( *headPtr )->value = value;
    ( *headPtr )->prev = prec;
    ( *headPtr )->next = EMPTY;

    return *headPtr;
}

static list LISTNonEmptyInsert( list head, char *key, char *value )
{
    if ( LISTKeyEqual( LISTKey( head ), key ) )
        return EMPTY;
    else if ( !LISTEmpty( LISTSuccessor( head ) ) )
        return ( LISTNonEmptyInsert( LISTSuccessor( head ), key, value ) );
    else
        return ( LISTNewNode( &( head->next ), head, key, value ) );
}

list LISTInsert( listPtr headPtr, char *key, char *value )
{
    assert( ( key != NULL ) && ( value != NULL ) );

    if ( LISTEmpty( *headPtr ) )
        return ( LISTNewNode( headPtr, EMPTY, key, value ) );
    else
        return ( LISTNonEmptyInsert( *headPtr, key, value ) );
}

list LISTSearch( list head, char *key )
{
    if ( LISTEmpty( head ) )
        return EMPTY;
    else if ( LISTKeyEqual( LISTKey( head ), key ) )
        return head;
    else
        return ( LISTSearch( LISTSuccessor( head ), key ) );
}

static bool LISTNonEmptyDelete( listPtr headPtr, list head, char *key )
{
    /*
     * Element not found. 
     */
    if ( LISTEmpty( head ) )
        return false;

    /*
     * Element may still be in list. 
     */
    else if ( !LISTKeyEqual( key, LISTKey( head ) ) )
        return ( LISTNonEmptyDelete
                 ( &( head->next ), LISTSuccessor( head ), key ) );
    /*
     * The element to delete has been found.  We now have the usual cases for a 
     * linked list without a dummy node. 
     */
    else {
        /*
         * There is only one element in list. 
         */
        if ( LISTEmpty( LISTPredecessor( head ) )
             && LISTEmpty( LISTSuccessor( head ) ) ) {
            *headPtr = EMPTY;
            free( head );
        }
        /*
         * Element to delete is at the head of the list. 
         */
        else if ( LISTEmpty( LISTPredecessor( head ) ) ) {
            *headPtr = LISTSuccessor( head );
            ( head->next )->prev = EMPTY;
            free( head );
            /*
             * Element to delete is at the tail of the list. 
             */
        } else if ( LISTEmpty( LISTSuccessor( head ) ) ) {
            ( head->prev )->next = EMPTY;
            free( head );
            /*
             * Element to delete is in the middle of the list. 
             */
        } else {
            ( head->prev )->next = LISTSuccessor( head );
            ( head->next )->prev = LISTPredecessor( head );
            free( head );
        }
    }

    return true;
}

bool LISTDelete( listPtr headPtr, char *key )
{
    /*
     * An empty list cannot be deleted. 
     */
    if ( LISTEmpty( *headPtr ) )
        return false;
    else
        return ( LISTNonEmptyDelete( headPtr, *headPtr, key ) );
}

#ifdef M_LISTMAIN_C
static void printList( list head )
{
    if ( LISTEmpty( head ) )
        fprintf( stderr, "No more elements to print.\n" );
    else {
        fprintf( stderr, "%s  %s\n", LISTKey( head ), LISTVal( head ) );
        printList( LISTSuccessor( head ) );
    }
}
#endif

#ifdef M_LISTMAIN_C
int main( void )
{
    listPtr doubleLinked;

    if ( ( doubleLinked = malloc( sizeof( list ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }


    fprintf( stderr, "Initializing LIST\n" );
    LISTInit( doubleLinked );
    if ( LISTEmpty( *doubleLinked ) )
        fprintf( stderr, "[ OK ] LIST is empty\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nInserting Elements...\n" );
    LISTInsert( doubleLinked, "01", "ciao" );
    LISTInsert( doubleLinked, "02", "hello" );
    LISTInsert( doubleLinked, "00", "hola" );
    LISTInsert( doubleLinked, "04", "hallo" );
    if ( LISTEmpty( LISTInsert( doubleLinked, "03", "testing" ) ) )
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    if ( LISTEmpty( LISTInsert( doubleLinked, "03", "bad Value" ) ) )
        fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr, "Manual element search\n" );
    fprintf( stderr, "%s\n", LISTKey( LISTSuccessor( *doubleLinked ) ) );
    fprintf( stderr, "%s\n",
             LISTKey( LISTPredecessor
                      ( LISTSuccessor( *doubleLinked ) ) ) );
    fprintf( stderr, "%s\n",
             LISTKey( LISTSuccessor( LISTSuccessor( *doubleLinked ) ) ) );
    fprintf( stderr, "%s\n",
             LISTKey( LISTSuccessor
                      ( LISTSuccessor
                        ( LISTSuccessor( *doubleLinked ) ) ) ) );
    fprintf( stderr,
             "[ OK ] This message should be shown and all previously printed values should be !(nil)\n" );


    fprintf( stderr, "\n\nSearch for key %s\n", "03" );
    fprintf( stderr, "value of %s = %s\n",
             "03", LISTVal( LISTSearch( *doubleLinked, "03" ) ) );
    fprintf( stderr, "Search non-existing key %s\n", "103" );
    if ( LISTEmpty( LISTSearch( *doubleLinked, "103" ) ) )
        fprintf( stderr, "[ OK ] Node with key 103 does not exist\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr,
             "\n\nDeletion of non-existing node in a non-empty list\n" );
    if ( !LISTDelete( doubleLinked, "10" ) )
        fprintf( stderr, "[ OK ] Node with key 10 cannot be deleted\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nPrinting list\n" );
    printList( *doubleLinked );


    fprintf( stderr, "\n\nManual list deletion\n" );
    if ( LISTDelete( doubleLinked, "00" )
         && LISTDelete( doubleLinked, "01" )
         && LISTDelete( doubleLinked, "02" )
         && LISTDelete( doubleLinked, "03" )
         && LISTDelete( doubleLinked, "04" ) ) {
        if ( LISTEmpty( *doubleLinked ) )
            fprintf( stderr, "[ OK ] The whole list has been deleted\n" );
        else
            fprintf( stderr,
                     "[ ERR ] This message should NOT be shown\n" );
    }


    fprintf( stderr, "\n\nPrinting list\n" );
    printList( *doubleLinked );


    fprintf( stderr, "\n\nEmpty list deletion\n" );
    if ( !LISTDelete( doubleLinked, "00" ) )
        fprintf( stderr, "[ OK ] Cannot delete an empty list\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nInserting Elements...\n" );
    LISTInsert( doubleLinked, "01", "ciao" );
    LISTInsert( doubleLinked, "02", "hello" );
    LISTInsert( doubleLinked, "00", "hola" );
    LISTInsert( doubleLinked, "04", "hallo" );
    LISTInsert( doubleLinked, "03", "testing" );
    LISTInsert( doubleLinked, "05", "good morning" );
    fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr, "\n\nPrinting list\n" );
    printList( *doubleLinked );


    free( doubleLinked );

    return 0;
}
#endif
