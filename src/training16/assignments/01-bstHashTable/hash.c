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


/* http://www.cse.yorku.ca/~oz/hash.html djb2 */
/* Output is unsigned because we have buckets from 0 to M - 1.  */
size_t hash( char *input )
{

    size_t key = 5381, i;


    i = 0;
    while ( input[i] != '\0' ) {
        key = ( ( key << 5 ) + key ) + ( ( size_t ) input[i] ); /* hash * 33 + c */
        i++;
    }

    return ( key % M );

}

/* Dummy stuff.  */
bstPointer *initHashTable( void )
{

    bstPointer *hashTable;


    if ( ( hashTable = calloc( M, sizeof( bstPointer ) ) ) == NULL )
        exit( EXIT_FAILURE );

    return hashTable;

}

void printHashTable( bstPointer * hash )
{

    size_t i;


    for ( i = 0; i < M; i++ )
        fprintf( stderr, "%p ", ( void * ) hash[i] );
    fprintf( stderr, "\n" );


    return;

}

#ifdef M_HASHMAIN_C
int main( void )
{

    char *string;
    size_t key;
    bstPointer *hashTable;


    hashTable = initHashTable(  );
    while ( true ) {
        if ( ( string = calloc( 500, sizeof( char ) ) ) == NULL )
            exit( EXIT_FAILURE );

        printf( "%p\n", ( void * ) string );
        fprintf( stdout, "Value to be hashed (^C to quit): " );
        scanf( "%s", string );

        key = hash( string );

        hashTable[key] = string;
        printf( "key = %u\n", ( unsigned int ) key );

        printf( "Hash table status: " );
        printHashTable( hashTable );

/*        free (string);*/
    }

    return 0;

}
#endif
