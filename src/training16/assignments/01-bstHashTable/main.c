/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

static char *genRandomString( int len );

static char *genRandomString( int len )
{
    int i;
    char *str;
    struct timeval t1;

    if ( ( str = calloc( len + 1, sizeof( char ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /*
     * FIXME: gettimeofday() is a POSIX function (not ANSI C99) and it is 
     * also deprecated. 
     */
    gettimeofday( &t1, NULL );
    /*
     * Seed is set in microseconds.
     */
    srand( t1.tv_usec * t1.tv_usec );

    for ( i = 0; i < len; i++ ) {
        /*
         * Strings are len charaters long and each charater is in the domain 
         * [KEYCHARMIN - KEYCHARMAX]. 
         */
        str[i] = ( rand(  ) % ( KEYCHARMAX - KEYCHARMIN ) ) + KEYCHARMIN;
        assert( str[i] >= KEYCHARMIN && str[i] <= KEYCHARMAX );
    }

    assert( ( int ) strlen( str ) == len );

    return str;
}

int main( void )
{
    htSlot *hashTable;
    int j, i, duplicateKeys, nonDeletedElements;
    int elements[MAINLOOPTESTS] = { M / 10, M, M * 10, M * 100 };
    char **keys;

    fprintf( stderr, "\n\nGen random string test\n" );
    fprintf( stderr, "%s\n", genRandomString( KEYLENGTH ) );
    fprintf( stderr, "[ OK ] This message should be shown\n" );

    for ( j = 0; j < MAINLOOPTESTS; j++ ) {
        duplicateKeys = 0;
        nonDeletedElements = 0;

        fprintf( stderr, "HT load factor = %f\n",
                 ( double ) elements[j] / M );

        if ( ( hashTable = malloc( sizeof( htSlot ) * M ) ) == NULL ) {
            if ( errno )
                perror( strerror( errno ) );
            exit( EXIT_FAILURE );
        }

        fprintf( stderr, "Initialization of the HT\n" );
        HTBSTInit( hashTable );
        fprintf( stderr, "[ OK ] HT initialized\n" );


        if ( ( keys = malloc( sizeof( char * ) * elements[j] ) ) == NULL ) {
            if ( errno )
                perror( strerror( errno ) );
            exit( EXIT_FAILURE );
        }
        fprintf( stderr, "\n\nInserting %d random elelemts in the HT\n",
                 elements[j] );
        for ( i = 0; i < elements[j]; i++ ) {
            keys[i] = genRandomString( KEYLENGTH );
            if ( !HTBSTInsert( hashTable, keys[i],
                               genRandomString( KEYLENGTH ) ) )
                duplicateKeys++;
        }
        if ( duplicateKeys == 0 )
            fprintf( stderr,
                     "[ OK ] Random string generator gave no duplicate keys\n" );
        else
            fprintf( stderr,
                     "[ ERR ] %d Duplicate keys from random string generator\n",
                     duplicateKeys );


        fprintf( stderr,
                 "\n\nDeleting all the previous %d elements in the HT\n",
                 elements[j] );
        for ( i = 0; i < elements[j]; i++ ) {
            if ( !HTBSTDelete( hashTable, keys[i] ) )
                nonDeletedElements++;
        }
        if ( nonDeletedElements == 0 )
            fprintf( stderr,
                     "[ OK ] All elements of the HT have been deleted\n" );
        else
            fprintf( stderr, "[ ERR ] %d elements have not been deleted\n",
                     nonDeletedElements );

        free( keys );
        free( hashTable );
    }

    return 0;
}
