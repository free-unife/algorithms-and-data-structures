/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

#ifdef M_HTBSTMAIN_C
static char *HTBSTElementKey( treeElement el );
static char *HTBSTElementVal( treeElement el );
#endif

#ifdef M_HTBSTMAIN_C
static char *HTBSTElementKey( treeElement el )
{
    return ( BSTHTTreeNodeKey( el ) );
}

static char *HTBSTElementVal( treeElement el )
{
    return ( BSTHTTreeNodeVal( el ) );
}
#endif

/* Functions wrappers related to the BSTHT functions. */
void HTBSTInit( htTreeSlot * hashTable )
{
    BSTHTInit( hashTable );
}

bool HTBSTInsert( htTreeSlot * hashTable, char *key, char *value )
{
    return ( BSTHTInsert( hashTable, hash( key ), key, value ) );
}

treeElement HTBSTSearch( htTreeSlot * hashTable, char *key )
{
    return ( BSTHTSearch( BSTHTSlot( hashTable, hash( key ) ), key ) );
}

bool HTBSTDelete( htTreeSlot * hashTable, char *key )
{
    return ( BSTHTDelete( hashTable, hash( key ), key ) );
}

bool HTBSTClearHashTable( htTreeSlot * hashTable,
                          unsigned int numberOfSlots )
{
    unsigned int i;

    for ( i = 0; i < numberOfSlots; i++ )
        if ( !BSTHTClearSlot( hashTable, i ) )
            return false;

    return true;
}

#ifdef M_HTBSTMAIN_C
int main( void )
{
    htTreeSlot *hashTable;

    if ( ( hashTable = malloc( sizeof( htTreeSlot ) * M ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    fprintf( stderr, "Initialization of the HT\n" );
    HTBSTInit( hashTable );
    fprintf( stderr, "[ OK ] HT initialized\n" );


    fprintf( stderr,
             "\n\nInsert some elements in the HT using the hash function\n" );
    if ( HTBSTInsert( hashTable, "00", "ciao" ) )
        fprintf( stderr,
                 "[ OK ] Inserted node with key %s and value %s in slot %u\n",
                 "00", "ciao", hash( "00" ) );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    if ( !HTBSTInsert( hashTable, "00", "ciao" ) )
        fprintf( stderr,
                 "[ OK ] Node with key %s and value %s in slot %u already present in HT\n",
                 "00", "ciao", hash( "00" ) );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    HTBSTInsert( hashTable, "02", "hallo" );
    HTBSTInsert( hashTable, "01", "hola" );
    HTBSTInsert( hashTable, "03", "hello" );


    fprintf( stderr, "\n\nGet key and value from a search\n" );
    fprintf( stderr, "Returned Values should be %s and %s\n", "01",
             "hola" );
    fprintf( stderr, "%s\n",
             HTBSTElementKey( HTBSTSearch( hashTable, "01" ) ) );
    fprintf( stderr, "%s\n",
             HTBSTElementVal( HTBSTSearch( hashTable, "01" ) ) );
    fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr, "\n\nDouble deletion test\n" );
    if ( HTBSTDelete( hashTable, "00" )
         && !HTBSTDelete( hashTable, "00" ) )
        fprintf( stderr, "[ OK ] Deletion of %s successful\n", "00" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nClearing all the hash table\n" );
    if ( HTBSTClearHashTable( hashTable, M ) )
        fprintf( stderr,
                 "[ OK ] All the hash table has been cleared successfuly\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );


    fprintf( stderr, "\n\nClearing all the hash table again\n" );
    if ( HTBSTClearHashTable( hashTable, M ) )
        fprintf( stderr,
                 "[ OK ] All the hash table has been cleared successfuly\n" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );

    free( hashTable );

    return 0;
}
#endif
