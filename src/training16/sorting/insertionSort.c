/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_INSERTIONSORT_H
#define M_INSERTIONSORT_H
#include "insertionSort.h"
#endif

static void genRandom( int *V, size_t n );
static second insertionSort( int *V, size_t n );
static second getRunningTime( clock_t start, clock_t end );


int main( void )
{

    int *V;
    size_t i;
    double runningTime;


    /* Run insetion sort for i arrays.  */
    for ( i = 0; i < 2000; i++ ) {
        if ( ( V = calloc( i, sizeof( int ) ) ) == NULL )
            exit( EXIT_FAILURE );

        /* Riempimento array con i elementi pseudocasuali.  */
        genRandom( V, i );

        runningTime = insertionSort( V, i );

        fprintf( stdout, "%d    %f", ( int ) i, runningTime );

        free( V );
    }

    /* Check array ordinato.  */
    /*checkArray(V, limit); */

    exit( EXIT_SUCCESS );

}

static void genRandom( int *V, size_t n )
{

    size_t i;
    int tmp;
    struct timeval t1;


    for ( i = 0; i < n; i++ ) {
        gettimeofday( &t1, NULL );
        /* Seed is set in microseconds.  */
        srand( t1.tv_usec * t1.tv_sec );
        tmp = rand(  );
        V[i] = tmp;
    }

}

static second getRunningTime( clock_t start, clock_t end )
{

    return ( ( second ) ( ( double ) ( end - start ) /
                          ( double ) CLOCKS_PER_SEC ) );

}

static second insertionSort( int *V, size_t n )
{

    size_t j;
    int i, key;
    clock_t start, end;


    start = clock(  );

    /* Sort.  */
    for ( j = 1; j < n; j++ ) {
        key = V[j];
        i = ( int ) j - 1;

        while ( i >= 0 && V[i] > key ) {
            V[i + 1] = V[i];
            i--;
        }

        V[i + 1] = key;
    }

    end = clock(  );

    fprintf( stdout, "\n" );

    return getRunningTime( start, end );

}
