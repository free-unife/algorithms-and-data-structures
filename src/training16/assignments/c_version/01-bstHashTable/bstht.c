/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

static bool BSTHTTreeNodeEmpty( treeNode root );
static bool BSTHTEmptySlot( htTreeSlot slot );
static treeNode BSTHTBst( htTreeSlot slot );
static treeNodePtr BSTHTBstPtr( htTreeSlot slot );
static bool BSTHTNewTreeNode( htTreeSlot slot, char *key, char *value );
static htTreeSlot BSTHTNewSlot( htTreeSlot * hashTable, unsigned int slotId );
static void BSTHTFreeSlot( htTreeSlot * hashTable, unsigned int slotId );
static bool BSTHTNonEmptyDelete( htTreeSlot * hashTable, unsigned int slotId,
                              char *key );

static bool BSTHTTreeNodeEmpty( treeNode root )
{
    return ( BSTEmpty( root ) );
}

char *BSTHTTreeNodeKey( treeNode root )
{
    return ( BSTKey( root ) );
}

char *BSTHTTreeNodeVal( treeNode root )
{
    return ( BSTVal( root ) );
}

void BSTHTInit( htTreeSlot * hashTable )
{
    int i;

    for ( i = 0; i < M; i++ )
        hashTable[i] = EMPTY;
}

/* Check if the BST corresponding to the current slot exists.  */
static bool BSTHTEmptySlot( htTreeSlot slot )
{
    return ( slot == EMPTY );
}

htTreeSlot BSTHTSlot( htTreeSlot * hashTable, unsigned int slotId )
{
    return ( hashTable[slotId] );
}

/* Return pointer to the root node of the BST corresponding to the input slot.  */
static treeNode BSTHTBst( htTreeSlot slot )
{
    return ( **slot );
}

/* Return BST pointer from input slot.  */
static treeNodePtr BSTHTBstPtr( htTreeSlot slot )
{
    return ( *slot );
}

/* New slot -> allocate new treeNodePtr.  */
static htTreeSlot BSTHTNewSlot( htTreeSlot * hashTable, unsigned int slotId )
{

    treeNodePtr bsTree;


    assert( BSTHTEmptySlot( BSTHTSlot( hashTable, slotId ) ) );

    if ( ( hashTable[slotId] = malloc( sizeof( treeNodePtr ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    if ( ( bsTree = malloc( sizeof( treeNode ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    BSTInit( bsTree );

    *( BSTHTSlot( hashTable, slotId ) ) = bsTree;

    return ( BSTHTSlot( hashTable, slotId ) );

}

static bool BSTHTNewTreeNode( htTreeSlot slot, char *key, char *value )
{
    return ( !BSTHTTreeNodeEmpty
             ( BSTInsert( BSTHTBstPtr( slot ), key, value ) ) );
}

/* Return true if BSTHTNewNode was successful, else otherwise.  */
bool BSTHTInsert( htTreeSlot * hashTable, unsigned int slotId, char *key,
               char *value )
{
    if ( BSTHTEmptySlot( BSTHTSlot( hashTable, slotId ) ) )
        BSTHTNewSlot( hashTable, slotId );

    return ( BSTHTNewTreeNode( BSTHTSlot( hashTable, slotId ), key, value ) );
}

treeNode BSTHTSearch( htTreeSlot slot, char *key )
{
    if ( BSTHTEmptySlot( slot ) )
        return EMPTY;
    else
        return ( BSTSearch( BSTHTBst( slot ), key ) );
}

static void BSTHTFreeSlot( htTreeSlot * hashTable, unsigned int slotId )
{
    /*
     * free the treeNodePtr.  
     */
    free( *( hashTable[slotId] ) );
    hashTable[slotId] = EMPTY;

}

/*
 * When tree is empty current slot must be set to null.
 * Before this treeNodePtr must be freed.
 */
static bool BSTHTNonEmptyDelete( htTreeSlot * hashTable, unsigned int slotId,
                              char *key )
{
    bool retval;

    retval = BSTDelete( BSTHTBstPtr( BSTHTSlot( hashTable, slotId ) ), key );
    if ( retval
         && BSTHTTreeNodeEmpty( BSTHTBst( BSTHTSlot( hashTable, slotId ) ) ) )
        BSTHTFreeSlot( hashTable, slotId );

    return retval;
}

bool BSTHTDelete( htTreeSlot * hashTable, unsigned int slotId, char *key )
{
    /*
     * Slot empty -> nothing to delete.  
     */
    if ( BSTHTEmptySlot( BSTHTSlot( hashTable, slotId ) ) )
        return false;
    else
        return ( BSTHTNonEmptyDelete( hashTable, slotId, key ) );
}


#ifdef M_BSTHTMAIN_C
int main( void )
{
    htTreeSlot *hashTable;

    if ( ( hashTable = malloc( sizeof( htTreeSlot ) * M ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    fprintf( stderr, "Initialization of the BSTHT\n" );
    BSTHTInit( hashTable );
    fprintf( stderr, "[ OK ] BSTHT initialized\n" );


    fprintf( stderr, "\n\nTest slot %d of the BSTHT\n", M - 1 );
    if ( BSTHTEmptySlot( BSTHTSlot( hashTable, M - 1 ) ) )
        fprintf( stderr, "[ OK ] Current slot is empty\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr,
             "\n\nAdd a new slot in the same position (%d) and check if it is still empty\n",
             M - 1 );
    if ( BSTHTEmptySlot( BSTHTNewSlot( hashTable, M - 1 ) ) )
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    else
        fprintf( stderr, "[ OK ] Current slot is being used\n" );


    fprintf( stderr,
             "\n\nInsert some elements in the BSTHT but on a different slot\n" );
    if ( BSTHTInsert( hashTable, M - 2, "00", "ciao" ) )
        fprintf( stderr,
                 "[ OK ] Inserted node with key %s and value %s in slot %d\n",
                 "00", "ciao", M - 2 );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    BSTHTInsert( hashTable, M - 2, "02", "hallo" );
    BSTHTInsert( hashTable, M - 2, "01", "hola" );
    BSTHTInsert( hashTable, M - 2, "03", "hello" );


    fprintf( stderr,
             "\n\nInsert the same element as before (%s %s in slot %d)\n",
             "00", "ciao", M - 2 );
    if ( BSTHTInsert( hashTable, M - 2, "00", "ciao" ) )
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    else
        fprintf( stderr, "[ OK ] Element with key %s already exists\n",
                 "00" );


    fprintf( stderr, "\n\nBSTHT search test\n" );
    fprintf( stderr,
             "Get value of node with key %s in slot %d which should be %s: %s\n",
             "01", M - 2, "hola",
             BSTHTTreeNodeVal( BSTHTSearch
                            ( BSTHTSlot( hashTable, M - 2 ), "01" ) ) );
    fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr,
             "\n\nSearch for a non existing element in an existing slot.\n" );
    fprintf( stderr, "Searching for node with key %s in slot %d\n", "10",
             M - 2 );
    if ( BSTHTTreeNodeEmpty( BSTHTSearch( BSTHTSlot( hashTable, M - 2 ), "10" ) ) )
        fprintf( stderr, "[ OK ] This message should be shown\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nDeletion of an element\n" );
    if ( BSTHTDelete( hashTable, M - 2, "02" ) )
        fprintf( stderr,
                 "[ OK ] Element with key %s in slot %d has been deleted\n",
                 "02", M - 2 );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nDeletion of a non-existing element\n" );
    if ( !BSTHTDelete( hashTable, M - 2, "02" ) )
        fprintf( stderr, "[ OK ] Cannot delete a non-existing element\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr,
             "\n\nInsert and delete starting with an empty slot (on %d)\n",
             M - 3 );
    if ( BSTHTInsert( hashTable, M - 3, "10", "bao" )
         && BSTHTInsert( hashTable, M - 3, "15", "GNU" )
         && BSTHTDelete( hashTable, M - 3, "10" )
         && BSTHTDelete( hashTable, M - 3, "15" )
         && BSTHTEmptySlot( BSTHTSlot( hashTable, M - 3 ) ) )
        fprintf( stderr,
                 "[ OK ] Insertion and deletion of %d elements successful\n",
                 2 );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );

    free( hashTable );

    return 0;
}
#endif
