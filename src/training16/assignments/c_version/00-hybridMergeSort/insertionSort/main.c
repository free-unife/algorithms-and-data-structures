/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_MAININSERTIONSORT_H
#define M_MAININSERTIONSORT_H
#include "main.h"
#endif


int main( void )
{

    int *V;
    size_t i;
    clock_t start, end;


    /* Run insetion sort for i arrays.  */
    for ( i = 1; i <= ARRAY_SIZE; i++ ) {
        if ( ( V = calloc( i, sizeof( int ) ) ) == NULL )
            exit( EXIT_FAILURE );

        /* Riempimento array con i elementi pseudocasuali.  */
        genRandomArray( V, i );

        start = clock(  );
        insertionSort( V, 0, i - 1 );
        end = clock(  );
        assert (isArraySorted (V, 0, i - 1));

        fprintf( stdout, "%d    %f\n", ( int ) i, measureRunningTime( start, end ) );

        free( V );
    }

    exit( EXIT_SUCCESS );

}
