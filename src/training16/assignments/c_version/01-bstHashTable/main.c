/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

static double runningTime( clock_t start, clock_t end );
static char *genRandomString( int len );
static void shuffleArrayRandomly( char *array, int len );
static char *getActions( int ins, int search, int del );
double listOperations( char **keys, char *actions, int totalElements );

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
        str[i] =
            ( char ) ( rand(  ) % ( KEYCHARMAX - KEYCHARMIN ) ) +
            KEYCHARMIN;
        assert( ( int ) str[i] >= KEYCHARMIN
                && ( int ) str[i] <= KEYCHARMAX );
    }

    assert( ( int ) strlen( str ) == len );

    return str;
}

/* Fisher yates algorithm:
 * <http://www.dispersiondesign.com/articles/algorithms/shuffle_array_order>
 */
static void shuffleArrayRandomly( char *array, int len )
{
    int i = len - 1;
    int j, tmp;

    srand( time( NULL ) );
    while ( i > 0 ) {
        j = rand(  ) % ( i + 1 );
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        i--;
    }
}

static char *getActions( int ins, int search, int del )
{
    int i;
    char *actions;

    if ( ( actions =
           malloc( sizeof( char ) * ( ins + search + del ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    /*
     * Fill the array with the correct number of actions. 
     */
    while ( i < ins + search + del ) {
        if ( i < ins )
            actions[i] = 'i';
        else if ( i < ins + search )
            actions[i] = 's';
        else if ( i < ins + search + del )
            actions[i] = 'd';
        i++;
    }

    shuffleArrayRandomly( actions, ins + search + del );

    return actions;
}

double listOperations( char **keys, char *actions, int totalElements )
{
    int j;
    clock_t startClock, endClock;
    double totalTime;
    htListSlot *listHashTable;

    /*
     * Create hash table for the lists. 
     */
    if ( ( listHashTable = malloc( sizeof( htListSlot ) * M ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

/*    fprintf (stderr, "---- %p ----\n", (void *) listHashTable ); */

    totalTime = 0.0;
    /*
     * For which decrements until elements* > 0 
     */
    for ( j = 0; j < totalElements; j++ ) {
        if ( actions[j] == 'i' ) {
            /*
             * This counts also the time tried to insert invalid keys. 
             */
            startClock = clock(  );
            while ( !HTLISTInsert( listHashTable, keys[j],
                                   "insertingAlwaysTheSameStringForSimplicity" ) )
            {
            }
            endClock = clock(  );
        } else if ( actions[j] == 's' ) {
            startClock = clock(  );
            HTLISTSearch( listHashTable, keys[j] );
            endClock = clock(  );
        } else {
            startClock = clock(  );
            HTLISTDelete( listHashTable, keys[j] );
            endClock = clock(  );
        }
        totalTime += runningTime( startClock, endClock );
    }

    /*
     * Of course, with the following we don't free the hash table but only its reference. 
     */
/*    free( listHashTable );*/

    return totalTime;
}

double bstOperations( char **keys, char *actions, int totalElements )
{
    int j;
    clock_t startClock, endClock;
    double totalTime;
    htTreeSlot *bstHashTable;

    /*
     * Create hash table for the bst. 
     */
    if ( ( bstHashTable = malloc( sizeof( htTreeSlot ) * M ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

/*    fprintf (stderr, "---- %p ----\n", (void *) bstHashTable ); */

    totalTime = 0.0;
    /*
     * For which decrements until elements* > 0 
     */
    for ( j = 0; j < totalElements; j++ ) {
        if ( actions[j] == 'i' ) {
            /*
             * This counts also the time tried to insert invalid keys. 
             */
            startClock = clock(  );
            while ( !HTBSTInsert( bstHashTable, keys[j],
                                  "insertingAlwaysTheSameStringForSimplicity" ) )
            {
                printf( "in\n" );
            }
            endClock = clock(  );
        } else if ( actions[j] == 's' ) {
            startClock = clock(  );
            HTBSTSearch( bstHashTable, keys[j] );
            endClock = clock(  );
        } else {
            startClock = clock(  );
            HTBSTDelete( bstHashTable, keys[j] );
            endClock = clock(  );
        }
        totalTime += runningTime( startClock, endClock );
    }

    /*
     * Of course, with the following we don't free the hash table but only its reference. 
     */
/*    HTBSTClear ( bstHashTable );  */
/*    free( bstHashTable );*/

    return totalTime;
}


int main( void )
{
    int i, j, elements;
    int elementsToInsert, elementsToSearch, elementsToDelete;
    int totalElements;
    char **keys, *actions;

    for ( i = 1; i <= NUMBER_OF_TESTS; i++ ) {
        /*
         * Calculate the number of elements. 
         */
        elements = M * i;

        /*
         * Generate elements keys. 
         */
        if ( ( keys = malloc( sizeof( char * ) * elements ) ) == NULL ) {
            if ( errno )
                perror( strerror( errno ) );
            exit( EXIT_FAILURE );
        }
        for ( j = 0; j < elements; j++ )
            keys[j] = genRandomString( KEYLENGTH );

        /*
         * Operations (in probability percentages):
         * *  75 % elements = insert
         * *  12.5 % elements = search
         * *  12.5 % elements = delete
         */
        /*
         * From probability percentages to integers. 
         */
        /*
         * A small approximation is done because we are working with integers. 
         */
        elementsToInsert = elements * .75;
        elementsToSearch = elements * .125;
        elementsToDelete = elements * .125;
        totalElements =
            elementsToInsert + elementsToSearch + elementsToDelete;

        /*
         * Get the actions 
         */
        actions =
            getActions( elementsToInsert, elementsToSearch,
                        elementsToDelete );

        fprintf( stderr, "%d    %f", totalElements, listOperations( keys,
                                                                    actions,
                                                                    totalElements ) );

        fprintf( stderr, "    %f\n", bstOperations( keys,
                                                    actions,
                                                    totalElements ) );

        free( actions );
        free( keys );
    }

    return 0;
}
