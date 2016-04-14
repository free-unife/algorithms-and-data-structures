/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"
/*#define PEDANTIC*/

static bool LISTHTListNodeEmpty( listNode head );

#ifdef PEDANTIC
static bool LISTHTListNodePtrEmpty( listNodePtr headPtr );
#endif
static listNode LISTHTClearList( listNode head );
static bool LISTHTEmptySlot( htListSlot slot );
static listNode LISTHTList( htListSlot slot );
static listNodePtr LISTHTListPtr( htListSlot slot );
static bool LISTHTNewListNode( htListSlot slot, char *key, char *value );
static htListSlot LISTHTNewSlot( htListSlot * hashTable,
                                 unsigned int slotId );
static void LISTHTFreeSlot( htListSlot * hashTable, unsigned int slotId );
static bool LISTHTNonEmptyDelete( htListSlot * hashTable,
                                  unsigned int slotId, char *key );

static bool LISTHTListNodeEmpty( listNode head )
{
    return ( LISTEmpty( head ) );
}

#ifdef PEDANTIC
static bool LISTHTListNodePtrEmpty( listNodePtr headPtr )
{
    return ( headPtr == EMPTY );
}
#endif

char *LISTHTListNodeKey( listNode head )
{
    return ( LISTKey( head ) );
}

char *LISTHTListNodeVal( listNode head )
{
    return ( LISTVal( head ) );
}

static listNode LISTHTClearList( listNode head )
{
    return ( LISTClear( head ) );
}

bool LISTHTClearSlot( htListSlot * hashTable, unsigned int slotId )
{
    /*
     * Slot is already empty.  
     */
    if ( LISTHTEmptySlot( LISTHTSlot( hashTable, slotId ) ) )
        return true;
    /*
     * If the tree has been cleared correctly, the pointer associated to the
     * * slot must also be cleared. 
     */
    else if ( LISTHTListNodeEmpty
              ( LISTHTClearList
                ( LISTHTList( LISTHTSlot( hashTable, slotId ) ) ) ) ) {
        LISTHTFreeSlot( hashTable, slotId );
        return true;
    } else
        return false;
}

void LISTHTInit( htListSlot * hashTable )
{
    int i;

    for ( i = 0; i < M; i++ )
        hashTable[i] = EMPTY;
}

/* Check if the LIST corresponding to the current slot exists.  */
static bool LISTHTEmptySlot( htListSlot slot )
{
    return ( slot == EMPTY );
}

htListSlot LISTHTSlot( htListSlot * hashTable, unsigned int slotId )
{
    return ( hashTable[slotId] );
}

/* Return pointer to the head node of the LIST corresponding to the input slot.  */
static listNode LISTHTList( htListSlot slot )
{
    return ( **slot );
}

/* Return LIST pointer from input slot.  */
static listNodePtr LISTHTListPtr( htListSlot slot )
{
    return ( *slot );
}

/* New slot -> allocate new listNodePtr.  */
static htListSlot LISTHTNewSlot( htListSlot * hashTable,
                                 unsigned int slotId )
{

    listNodePtr doubleLinked;


    assert( LISTHTEmptySlot( LISTHTSlot( hashTable, slotId ) ) );

    if ( ( hashTable[slotId] = malloc( sizeof( listNodePtr ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    if ( ( doubleLinked = malloc( sizeof( listNode ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    LISTInit( doubleLinked );

    *( LISTHTSlot( hashTable, slotId ) ) = doubleLinked;

    return ( LISTHTSlot( hashTable, slotId ) );

}

static bool LISTHTNewListNode( htListSlot slot, char *key, char *value )
{
    return ( !LISTHTListNodeEmpty
             ( LISTInsert( LISTHTListPtr( slot ), key, value ) ) );
}

/* Return true if LISTHTNewNode was successful, else otherwise.  */
bool LISTHTInsert( htListSlot * hashTable, unsigned int slotId, char *key,
                   char *value )
{
    if ( LISTHTEmptySlot( LISTHTSlot( hashTable, slotId ) ) )
        LISTHTNewSlot( hashTable, slotId );

    return ( LISTHTNewListNode
             ( LISTHTSlot( hashTable, slotId ), key, value ) );
}

listNode LISTHTSearch( htListSlot slot, char *key )
{
    if ( LISTHTEmptySlot( slot ) )
        return EMPTY;
    else
        return ( LISTSearch( LISTHTList( slot ), key ) );
}

static void LISTHTFreeSlot( htListSlot * hashTable, unsigned int slotId )
{
    /*
     * free the listNodePtr.  
     */
#ifdef PEDANTIC
    if ( !LISTHTListNodePtrEmpty
         ( LISTHTListPtr( LISTHTSlot( hashTable, slotId )
            ) ) )
#endif
        free( LISTHTListPtr( LISTHTSlot( hashTable, slotId ) ) );
    /*
     * free( *( hashTable[slotId] ) ); 
     */

    hashTable[slotId] = EMPTY;
}

/*
 * When list is empty current slot must be set to null.
 * Before this listNodePtr must be freed.
 */
static bool LISTHTNonEmptyDelete( htListSlot * hashTable,
                                  unsigned int slotId, char *key )
{
    bool retval;

    retval =
        LISTDelete( LISTHTListPtr( LISTHTSlot( hashTable, slotId ) ),
                    key );
    if ( retval
         &&
         LISTHTListNodeEmpty( LISTHTList
                              ( LISTHTSlot( hashTable, slotId ) ) ) )
        LISTHTFreeSlot( hashTable, slotId );

    return retval;
}

bool LISTHTDelete( htListSlot * hashTable, unsigned int slotId, char *key )
{
    /*
     * Slot empty -> nothing to delete.  
     */
    if ( LISTHTEmptySlot( LISTHTSlot( hashTable, slotId ) ) )
        return false;
    else
        return ( LISTHTNonEmptyDelete( hashTable, slotId, key ) );
}


#ifdef M_LISTHTMAIN_C
int main( void )
{
    htListSlot *hashTable;

    if ( ( hashTable = malloc( sizeof( htListSlot ) * M ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    fprintf( stderr, "Initialization of the LISTHT\n" );
    LISTHTInit( hashTable );
    fprintf( stderr, "[ OK ] LISTHT initialized\n" );


    fprintf( stderr, "\n\nTest slot %d of the LISTHT\n", M - 1 );
    if ( LISTHTEmptySlot( LISTHTSlot( hashTable, M - 1 ) ) )
        fprintf( stderr, "[ OK ] Current slot is empty\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr,
             "\n\nAdd a new slot in the same position (%d) and check if it is still empty\n",
             M - 1 );
    if ( LISTHTEmptySlot( LISTHTNewSlot( hashTable, M - 1 ) ) )
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    else
        fprintf( stderr, "[ OK ] Current slot is being used\n" );


    fprintf( stderr,
             "\n\nInsert some elements in the LISTHT but on a different slot\n" );
    if ( LISTHTInsert( hashTable, M - 2, "00", "ciao" ) )
        fprintf( stderr,
                 "[ OK ] Inserted node with key %s and value %s in slot %d\n",
                 "00", "ciao", M - 2 );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    LISTHTInsert( hashTable, M - 2, "02", "hallo" );
    LISTHTInsert( hashTable, M - 2, "01", "hola" );
    LISTHTInsert( hashTable, M - 2, "03", "hello" );


    fprintf( stderr,
             "\n\nInsert the same element as before (%s %s in slot %d)\n",
             "00", "ciao", M - 2 );
    if ( LISTHTInsert( hashTable, M - 2, "00", "ciao" ) )
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    else
        fprintf( stderr, "[ OK ] Element with key %s already exists\n",
                 "00" );


    fprintf( stderr, "\n\nLISTHT search test\n" );
    fprintf( stderr,
             "Get value of node with key %s in slot %d which should be %s: %s\n",
             "01", M - 2, "hola",
             LISTHTListNodeVal( LISTHTSearch
                                ( LISTHTSlot( hashTable, M - 2 ),
                                  "01" ) ) );
    fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr,
             "\n\nSearch for a non existing element in an existing slot.\n" );
    fprintf( stderr, "Searching for node with key %s in slot %d\n", "10",
             M - 2 );
    if ( LISTHTListNodeEmpty
         ( LISTHTSearch( LISTHTSlot( hashTable, M - 2 ), "10" ) ) )
        fprintf( stderr, "[ OK ] This message should be shown\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nDeletion of an element\n" );
    if ( LISTHTDelete( hashTable, M - 2, "02" ) )
        fprintf( stderr,
                 "[ OK ] Element with key %s in slot %d has been deleted\n",
                 "02", M - 2 );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nDeletion of a non-existing element\n" );
    if ( !LISTHTDelete( hashTable, M - 2, "02" ) )
        fprintf( stderr, "[ OK ] Cannot delete a non-existing element\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr,
             "\n\nInsert and delete starting with an empty slot (on %d)\n",
             M - 3 );
    if ( LISTHTInsert( hashTable, M - 3, "10", "bao" )
         && LISTHTInsert( hashTable, M - 3, "15", "GNU" )
         && LISTHTDelete( hashTable, M - 3, "10" )
         && LISTHTDelete( hashTable, M - 3, "15" )
         && LISTHTEmptySlot( LISTHTSlot( hashTable, M - 3 ) ) )
        fprintf( stderr,
                 "[ OK ] Insertion and deletion of %d elements successful\n",
                 2 );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nClear an entire slot (on %d)\n", M - 2 );
    if ( LISTHTClearSlot( hashTable, M - 2 )
         && LISTHTEmptySlot( LISTHTSlot( hashTable, M - 2 ) ) )
        fprintf( stderr, "[ OK ] The whole slot %d has been cleared\n",
                 M - 2 );

    fprintf( stderr, "\n\nClear an entire empty slot (on %d)\n", M - 40 );
    if ( LISTHTClearSlot( hashTable, M - 40 )
         && LISTHTEmptySlot( LISTHTSlot( hashTable, M - 40 ) ) )
        fprintf( stderr, "[ OK ] The whole slot %d has been cleared\n",
                 M - 40 );
    free( hashTable );

    return 0;
}
#endif
