/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

#ifdef M_HTBSTMAIN_C
static char *HTBSTElementKey( element el );
static char *HTBSTElementVal( element el );
#endif
static unsigned int HTBSTHash( char *input );

#ifdef M_HTBSTMAIN_C
static char *HTBSTElementKey( element el )
{
    return ( HTTreeNodeKey( el ) );
}

static char *HTBSTElementVal( element el )
{
    return ( HTTreeNodeVal( el ) );
}
#endif

/* http://www.cse.yorku.ca/~oz/hash.html djb2 */
/* Output is unsigned because we have buckets from 0 to M - 1.  */
static unsigned int HTBSTHash( char *input )
{
    unsigned int key = 5381, i;

    i = 0;
    while ( input[i] != '\0' ) {
        key = ( key << 5 ) + key + ( ( unsigned int ) input[i] );       /* hash * 33 + c */
        i++;
    }

    /*
     * Return the slot id.  
     */
    return ( key % M );
}

/* Functions wrappers related to the HT functions.  */
void HTBSTInit( htSlot * hashTable )
{
    HTInit( hashTable );
}

bool HTBSTInsert( htSlot * hashTable, char *key, char *value )
{
    return ( HTInsert( hashTable, HTBSTHash( key ), key, value ) );
}

element HTBSTSearch( htSlot * hashTable, char *key )
{
    return ( HTSearch( HTSlot( hashTable, HTBSTHash( key ) ), key ) );
}

bool HTBSTDelete( htSlot * hashTable, char *key )
{
    return ( HTDelete( hashTable, HTBSTHash( key ), key ) );
}

/* FIXME: Every element in the whole HT must have a unique key! */
#ifdef M_HTBSTMAIN_C
int main( void )
{
    htSlot *hashTable;

    if ( ( hashTable = malloc( sizeof( htSlot ) * M ) ) == NULL ) {
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
                 "00", "ciao", HTBSTHash( "00" ) );
    else
        fprintf( stderr, "[ ERR ] This message should NOT be shown\n" );
    if ( !HTBSTInsert( hashTable, "00", "ciao" ) )
        fprintf( stderr,
                 "[ OK ] Node with key %s and value %s in slot %u already present in HT\n",
                 "00", "ciao", HTBSTHash( "00" ) );
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

    return 0;
}
#endif
