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
static double insertionSort( int *V, size_t n );


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
        /* Il seme e' impostato con i microsecondi.  */
        srand( t1.tv_usec * t1.tv_sec );
        tmp = rand(  );
        V[i] = tmp;
    }

}

static double insertionSort( int *V, size_t n )
{

    size_t i;
    int j, key;
    clock_t start, end;


    start = clock(  );

    /* Sort.  */
    for ( i = 1; i < n; i++ ) {
        key = V[i];
        j = ( int ) i - 1;
        while ( j >= 0 && V[j] > key ) {
            V[j + 1] = V[j];
            j--;
        }
        V[j + 1] = key;
    }

    end = clock(  );

    fprintf( stdout, "\n" );

    return ( double ) ( ( double ) ( end - start ) /
                        ( double ) CLOCKS_PER_SEC );

}
