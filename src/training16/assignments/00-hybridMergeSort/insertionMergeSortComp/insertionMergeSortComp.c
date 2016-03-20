/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_INSERTIONMERGESORTCOMP_H
#define M_INSERTIONMERGESORTCOMP_H
#include "insertionMergeSortComp.h"
#endif


int main( void )
{

    int *V, *Vcpy0 = NULL, *Vcpy1 = NULL;
    size_t i;
    clock_t startInsertion, endInsertion, startMerge, endMerge;
    second timeInsertion, timeMerge;
    second diffTime, *diffRunningTimes;
    int zero = 0, sum, n;


    if ( ( diffRunningTimes = malloc( ARRAY_SIZE * sizeof( second ) ) ) == NULL )
            exit( EXIT_FAILURE );
    for (i = 0; i < ARRAY_SIZE; i++)
        diffRunningTimes[i] = INF;

    for ( i = 1; i <= ARRAY_SIZE; i++ ) {
        if ( ( V = calloc( i, sizeof( int ) ) ) == NULL )
            exit( EXIT_FAILURE );

        if ( ( Vcpy0 = calloc( i, sizeof( int ) ) ) == NULL )
            exit( EXIT_FAILURE );

        if ( ( Vcpy1 = calloc( i, sizeof( int ) ) ) == NULL )
            exit( EXIT_FAILURE );

        /* Riempimento array con i elementi pseudocasuali.  */
        genRandomArray( V, i );

        memcpy ( Vcpy0, V, i );
        memcpy ( Vcpy1, V, i );

        startInsertion = clock(  );
        insertionSort( Vcpy0, 0, ( int ) i - 1 );
        endInsertion = clock(  );
        assert (isArraySorted (Vcpy0, 0, i - 1));

        startMerge = clock(  );
        mergeSort( Vcpy1, 0, ( int ) i - 1 );
        endMerge = clock(  );
        assert (isArraySorted (Vcpy0, 0, i - 1));

        timeInsertion = measureRunningTime (startInsertion, endInsertion);
        timeMerge = measureRunningTime (startMerge, endMerge);

        diffTime = fabs ( timeInsertion - timeMerge );

        fprintf( stdout, "%d    %.8f\n", ( int ) i, diffTime );

        if (i > LOWER_BOUND_INDEX && diffTime <= TOL)
            diffRunningTimes[i - 1] = diffTime;

        free( V );
        free ( Vcpy0 );
        free ( Vcpy1 );
    }

    /* Find the zero values (where merge sort is equal to inserion sort)  */
    fprintf (stderr, "Possible values for input size where merge sort performs like inserion sort (with tolerance %.8f): [ ", TOL);
    sum = 0;
    n = 0;
    /* Get the mean value of the indices of diffRunningTime <= TOL.  */
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (diffRunningTimes[i] != INF) {
            fprintf (stderr, "%d ", (int) i + 1);
            sum += i + 1;
            n++;
        }
    }
    fprintf (stderr, "]\n");

    if (n > 0) {
        zero = sum / n;
        fprintf (stderr, "mean = zero ~= %d\n", zero);
    }


    exit( EXIT_SUCCESS );

}

