/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

static double runningTime( clock_t start, clock_t end );
static char *genRandomString( int len );

static double runningTime( clock_t start, clock_t end )
{
    return ( ( ( double ) ( end - start ) / ( double ) CLOCKS_PER_SEC ) );
}

static char *genRandomString( int len )
{
    int i;
    char *str;
    struct timespec t1;

    if ( ( str = calloc( len + 1, sizeof( char ) ) ) == NULL )
        exit( EXIT_FAILURE );

    /*
     * Seed is set in nanoseconds.
     */
    clock_gettime( CLOCK_MONOTONIC, &t1 );
    srand( t1.tv_nsec );

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
    int elements[MAINLOOPTESTS] = { 1, M / 10, M, M * 2, M * 4, M * 10, M * 100, M * 1000 };
    char **keys;
    double loadFactor;
    clock_t insertStart, insertEnd, deleteStart, deleteEnd;

    fprintf( stderr, "\n\nGen random string test\n" );
    fprintf( stderr, "%s\n", genRandomString( KEYLENGTH ) );
    fprintf( stderr, "[ OK ] This message should be shown\n" );

    for ( j = 0; j < MAINLOOPTESTS; j++ ) {
        duplicateKeys = 0;
        nonDeletedElements = 0;
        loadFactor = elements[j] / M;

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

        for ( i = 0; i < elements[j]; i++ )
            keys[i] = genRandomString( KEYLENGTH );

        insertStart = clock(  );

        for ( i = 0; i < elements[j]; i++ ) {
            if ( !HTBSTInsert( hashTable, keys[i],
                               "insertingAlwaysTheSameStringForSimplicity" ) )
                duplicateKeys++;
        }

        insertEnd = clock(  );

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

        deleteStart = clock(  );

        for ( i = 0; i < elements[j]; i++ ) {
            if ( !HTBSTDelete( hashTable, keys[i] ) )
                nonDeletedElements++;
        }

        deleteEnd = clock(  );

        if ( nonDeletedElements == 0 )
            fprintf( stderr,
                     "[ OK ] All elements of the HT have been deleted\n" );
        else
            fprintf( stderr, "[ ERR ] %d elements have not been deleted\n",
                     nonDeletedElements );

        fprintf( stderr, "input size    buckets    load factor    insert    delete\n" );

        fprintf( stdout, "%d    %u    %f    %f    %f\n", elements[j], M, loadFactor, runningTime ( insertStart, insertEnd ), runningTime( deleteStart, deleteEnd ) );

        free( keys );
        free( hashTable );
    }

    return 0;
}
