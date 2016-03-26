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


void HTinit( htSlot * hashTable )
{

    int i;

    for ( i = 0; i < M; i++ )
        hashTable[i] = EMPTY;

    return;

}

/* Check if the BST corresponding to the current slot exists.  */
bool HTEmptySlot( htSlot slot )
{

    return ( slot == EMPTY );

}

htSlot HTSlot( htSlot * hashTable, unsigned int slotId )
{

    return ( hashTable[slotId] );

}

/* Return pointer to the root node of the BST corresponding to the input
 * slot.
 */
bst HTBst( htSlot slot )
{

    return ( **slot );

}

/* Return BST pointer from input slot.  */
bstPtr HTBstPtr( htSlot slot )
{

    return ( *slot );

}

/* New slot -> allocate new bstPtr.  */
htSlot HTNewSlot( htSlot * hashTable, unsigned int slotId )
{

    bstPtr bsTree;


    assert( HTEmptySlot( HTSlot( hashTable, slotId ) ) );

    if ( ( hashTable[slotId] = malloc( sizeof( bstPtr ) ) ) == NULL )
        exit( EXIT_FAILURE );

    if ( ( bsTree = malloc( sizeof( bst ) ) ) == NULL )
        exit( EXIT_FAILURE );

    BSTInit( bsTree );

    *( HTSlot( hashTable, slotId ) ) = bsTree;

    return ( HTSlot( hashTable, slotId ) );

}

bool HTNewBSTNode( htSlot slot, char *key, char *value )
{

    return ( !BSTEmpty( BSTInsert( HTBstPtr( slot ), key, value ) ) );

}

/* Return true if HTNewNode was successful, else otherwise.  */
bool HTInsert( htSlot * hashTable, unsigned int slotId, char *key,
               char *value )
{

    if ( HTEmptySlot( HTSlot( hashTable, slotId ) ) )
        HTNewSlot( hashTable, slotId );

    return ( HTNewBSTNode( HTSlot( hashTable, slotId ), key, value ) );

}

bst HTSearch( htSlot slot, char *key )
{

    if ( HTEmptySlot( slot ) )
        return EMPTY;
    else
        return ( BSTSearch( HTBst( slot ), key ) );

}

void HTFreeSlot( htSlot * hashTable, unsigned int slotId )
{

    /* free the bstPtr.  */
    free( *( hashTable[slotId] ) );
    hashTable[slotId] = EMPTY;

}

/*
 * When tree is empty current slot must be set to null.
 * Before this bstPtr must be freed.
 */
bool HTNonEmptyDelete( htSlot * hashTable, unsigned int slotId, char *key )
{

    bool retval;


    retval = BSTDelete( HTBstPtr( HTSlot( hashTable, slotId ) ), key );
    if ( retval && BSTEmpty( HTBst( HTSlot( hashTable, slotId ) ) ) )
        HTFreeSlot( hashTable, slotId );

    return retval;

}

bool HTDelete( htSlot * hashTable, unsigned int slotId, char *key )
{

    /* Slot empty -> nothing to delete.  */
    if ( HTEmptySlot( HTSlot( hashTable, slotId ) ) )
        return true;
    else
        return ( HTNonEmptyDelete( hashTable, slotId, key ) );

}


/* http://www.cse.yorku.ca/~oz/hash.html djb2 */
/* Output is unsigned because we have buckets from 0 to M - 1.  */
unsigned int HTHash( char *input )
{

    unsigned int key = 5381, i;


    i = 0;
    while ( input[i] != '\0' ) {
        key = ( key << 5 ) + key + ( ( unsigned int ) input[i] );       /* hash * 33 + c */
        i++;
    }

    return ( key % M );

}

#ifdef M_HTMAIN_C
int main( void )
{

    htSlot *hashTable;


    if ( ( hashTable = malloc( sizeof( htSlot ) * M ) ) == NULL )
        exit( EXIT_FAILURE );

    fprintf( stderr, "Initialization of the HT\n" );
    HTinit( hashTable );
    fprintf( stderr, "[ OK ] HT initialized\n" );


    fprintf( stderr, "\n\nTest slot %d of the HT\n", M - 1 );
    if ( HTEmptySlot( HTSlot( hashTable, M - 1 ) ) )
        fprintf( stderr, "[ OK ] Current slot is empty\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr,
             "\n\nAdd a new slot in the same position (%d) and check if it is still empty\n",
             M - 1 );
    if ( HTEmptySlot( HTNewSlot( hashTable, M - 1 ) ) )
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    else
        fprintf( stderr, "[ OK ] Current slot is being used\n" );


    fprintf( stderr,
             "\n\nInsert some elements in the HT but on a different slot\n" );
    if ( HTInsert( hashTable, M - 2, "00", "ciao" ) )
        fprintf( stderr,
                 "[ OK ] Inserted node with key %s and value %s in slot %d\n",
                 "00", "ciao", M - 2 );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    HTInsert( hashTable, M - 2, "02", "hallo" );
    HTInsert( hashTable, M - 2, "01", "hola" );
    HTInsert( hashTable, M - 2, "03", "hello" );


    fprintf( stderr,
             "\n\nInsert the same element as before (%s %s in slot %d)\n",
             "00", "ciao", M - 2 );
    if ( HTInsert( hashTable, M - 2, "00", "ciao" ) )
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    else
        fprintf( stderr, "[ OK ] Element with key %s already exists\n",
                 "00" );


    fprintf( stderr, "\n\nHT search test\n" );
    fprintf( stderr,
             "Get value of node with key %s in slot %d which should be %s: %s\n",
             "01", M - 2, "hola",
             BSTVal( HTSearch( HTSlot( hashTable, M - 2 ), "01" ) ) );
    fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr,
             "\n\nSearch for a non existing element in an existing slot.\n" );
    fprintf( stderr, "Searching for node with key %s in slot %d\n", "10",
             M - 2 );
    if ( BSTEmpty( HTSearch( HTSlot( hashTable, M - 2 ), "10" ) ) )
        fprintf( stderr, "[ OK ] This message should be shown\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nDeletion of an element\n" );
    if ( HTDelete( hashTable, M - 2, "02" ) )
        fprintf( stderr,
                 "[ OK ] Element with key %s in slot %d has been deleted\n",
                 "02", M - 2 );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nDeletion of a non-existing element\n" );
    if ( HTDelete( hashTable, M - 2, "02" ) )
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    else
        fprintf( stderr, "[ OK ] Cannot delete a non-existing element\n" );

    fprintf( stderr,
             "\n\nInsert and delete starting with an empty slot (on %d)\n",
             M - 3 );
    if ( HTInsert( hashTable, M - 3, "10", "bao" )
         && HTInsert( hashTable, M - 3, "15", "GNU" )
         && HTDelete( hashTable, M - 3, "10" )
         && HTDelete( hashTable, M - 3, "15" )
         && HTEmptySlot( HTSlot( hashTable, M - 3 ) ) )
        fprintf( stderr,
                 "[ OK ] Insertion and deletion of %d elements successful\n",
                 2 );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );

    return 0;

}
#endif
