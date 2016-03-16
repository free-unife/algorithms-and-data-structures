/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_INSERTIONSORT_H
#define M_INSERTIONSORT_H
#include "insertionSort.h"
#endif


int main( void )
{

    int *V;
    size_t i;
    clock_t start, end;


    /* Run insetion sort for i arrays.  */
    for ( i = 0; i < ARRAY_SIZE; i++ ) {
        if ( ( V = calloc( i, sizeof( int ) ) ) == NULL )
            exit( EXIT_FAILURE );

        /* Riempimento array con i elementi pseudocasuali.  */
        genRandomArray( V, i );

        start = clock(  );
        insertionSort( V, i );
        end = clock(  );

        fprintf( stdout, "%d    %f\n", ( int ) i, measureRunningTime( start, end ) );

        free( V );
    }

    exit( EXIT_SUCCESS );

}


void insertionSort( int *V, size_t n )
{

    size_t j;
    int i, key;


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

    return;

}
