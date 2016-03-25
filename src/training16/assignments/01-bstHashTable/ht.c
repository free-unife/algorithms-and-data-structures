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


void HTinit ( htSlot *hashTable )
{

    int i;

    for ( i = 0; i < M; i++ )
        hashTable [i] = EMPTY;

    return;

}

/* Check if the BST corresponding to the current slot exists.  */
bool HTEmptySlot ( htSlot slot )
{

    return ( slot == EMPTY );

}

/* New slot -> allocate new bstPtr.  */
htSlot HTNewSlot ( htSlot *hashTable, unsigned int slotInd )
{

    bstPtr bsTree;


    assert ( HTEmptySlot ( hashTable[slotInd] ) );

    if ( ( bsTree = malloc( sizeof( bst ) ) ) == NULL )
        exit( EXIT_FAILURE );

    BSTInit( bsTree );

    if ( ( hashTable [slotInd] = malloc ( sizeof ( bstPtr ) ) ) == NULL)
        exit( EXIT_FAILURE );

    *(hashTable [slotInd]) = bsTree;

    return (hashTable [slotInd]);

}



/* http://www.cse.yorku.ca/~oz/hash.html djb2 */
/* Output is unsigned because we have buckets from 0 to M - 1.  */
unsigned int HTHash( char *input )
{

    unsigned int key = 5381, i;


    i = 0;
    while ( input[i] != '\0' ) {
        key = ( ( key << 5 ) + key ) + ( ( unsigned int ) input[i] ); /* hash * 33 + c */
        i++;
    }

    return ( key % M );

}

void HTPrint( bstPtr * hash )
{

    int i;


    for ( i = 0; i < M; i++ )
        fprintf( stderr, "%p ", ( void * ) hash[i] );
    fprintf( stderr, "\n" );


    return;

}

#ifdef M_HTMAIN_C
int main( void )
{

    htSlot *hashTable;


    if ( ( hashTable = malloc ( sizeof ( htSlot ) * M ) ) == NULL )
        exit (EXIT_FAILURE);

    fprintf (stderr, "Initialize and test one slot of the HT\n");
    HTinit ( hashTable );
    if ( HTEmptySlot ( hashTable [M-1] ) )
        fprintf (stderr, "Current slot is empty\n");
    else
        fprintf (stderr, "This message should NOT be shown\n");

    fprintf (stderr, "\n\nAdd a new slot in the same position and check if it is still empty\n");
    if ( HTEmptySlot ( HTNewSlot ( hashTable, M-1 ) ) )
        fprintf (stderr, "This message should NOT be shown\n");
    else
        fprintf (stderr, "Current slot is being used.\n");

    return 0;

}
#endif
