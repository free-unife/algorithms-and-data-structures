/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

#ifdef M_HTLISTMAIN_C
static char *HTLISTElementKey( listElement el );
static char *HTLISTElementVal( listElement el );
#endif

#ifdef M_HTLISTMAIN_C
static char *HTLISTElementKey( listElement el )
{
    return ( LISTHTListNodeKey( el ) );
}

static char *HTLISTElementVal( listElement el )
{
    return ( LISTHTListNodeVal( el ) );
}
#endif

/* Functions wrappers related to the LISTHT functions. */
void HTLISTInit( htListSlot * hashTable )
{
    LISTHTInit( hashTable );
}

bool HTLISTInsert( htListSlot * hashTable, char *key, char *value )
{
    return ( LISTHTInsert( hashTable, hash( key ), key, value ) );
}

listElement HTLISTSearch( htListSlot * hashTable, char *key )
{
    return ( LISTHTSearch( LISTHTSlot( hashTable, hash( key ) ), key ) );
}

bool HTLISTDelete( htListSlot * hashTable, char *key )
{
    return ( LISTHTDelete( hashTable, hash( key ), key ) );
}

#ifdef M_HTLISTMAIN_C
int main( void )
{
    htListSlot *hashTable;

    if ( ( hashTable = malloc( sizeof( htListSlot ) * M ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    fprintf( stderr, "Initialization of the HT\n" );
    HTLISTInit( hashTable );
    fprintf( stderr, "[ OK ] HT initialized\n" );


    fprintf( stderr,
             "\n\nInsert some elements in the HT using the hash function\n" );
    if ( HTLISTInsert( hashTable, "00", "ciao" ) )
        fprintf( stderr,
                 "[ OK ] Inserted node with key %s and value %s in slot %u\n",
                 "00", "ciao", hash( "00" ) );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    if ( !HTLISTInsert( hashTable, "00", "ciao" ) )
        fprintf( stderr,
                 "[ OK ] Node with key %s and value %s in slot %u already present in HT\n",
                 "00", "ciao", hash( "00" ) );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    HTLISTInsert( hashTable, "02", "hallo" );
    HTLISTInsert( hashTable, "01", "hola" );
    HTLISTInsert( hashTable, "03", "hello" );


    fprintf( stderr, "\n\nGet key and value from a search\n" );
    fprintf( stderr, "Returned Values should be %s and %s\n", "01",
             "hola" );
    fprintf( stderr, "%s\n",
             HTLISTElementKey( HTLISTSearch( hashTable, "01" ) ) );
    fprintf( stderr, "%s\n",
             HTLISTElementVal( HTLISTSearch( hashTable, "01" ) ) );
    fprintf( stderr, "[ OK ] This message should be shown\n" );


    fprintf( stderr, "\n\nDouble deletion test\n" );
    if ( HTLISTDelete( hashTable, "00" )
         && !HTLISTDelete( hashTable, "00" ) )
        fprintf( stderr, "[ OK ] Deletion of %s successful\n", "00" );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );

    return 0;
}
#endif
