/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_MYBRIDMERGESORT_H
#define M_HYBRIDMERGESORT_H
#include "hybridMergeSort.h"
#endif

static void hybridMergeSort( int *V, int p, int r, int k );
static second sumTimes( second * diffs );
static size_t getK( second * sum );


int main( void )
{

    int *V, *Vcpy0 = NULL, *Vcpy1 = NULL;
    size_t i, k;
    clock_t startHybrid, endHybrid, startMerge, endMerge;
    second timeHybrid, timeMerge, *timeSum, *diffRunningTimes;


    /* Array of the sums of all the diffRunningTimes.  */
    if ( ( timeSum = malloc( ( KMAX + 1 ) * sizeof( second ) ) ) == NULL )
        exit( EXIT_FAILURE );

    for ( k = 0; k <= KMAX; k++ ) {

        if ( ( diffRunningTimes =
               malloc( ARRAY_SIZE * sizeof( second ) ) ) == NULL )
            exit( EXIT_FAILURE );

        for ( i = 1; i <= ARRAY_SIZE; i++ ) {
            /* We should use the same arrays for the same i on different k to
             * have a better result.
             * For purpose of simplicity we are generating new ones every
             * time.
             */
            if ( ( V = calloc( i, sizeof( int ) ) ) == NULL )
                exit( EXIT_FAILURE );

            /* To have a significant result we must use the same array for
             * the two algoritms. Since this is not functional programming,
             * copies of the array V are provided to hybridMergeSort and
             * mergeSort.  */
            if ( ( Vcpy0 = calloc( i, sizeof( int ) ) ) == NULL )
                exit( EXIT_FAILURE );

            if ( ( Vcpy1 = calloc( i, sizeof( int ) ) ) == NULL )
                exit( EXIT_FAILURE );

            genRandomArray( V, i );

            memcpy( Vcpy0, V, i );
            memcpy( Vcpy1, V, i );

            startHybrid = clock(  );
            hybridMergeSort( Vcpy0, 0, ( int ) i - 1, ( int ) k );
            endHybrid = clock(  );
            /* This guarantees that the array is sorted.  */
            assert( isArraySorted( Vcpy0, 0, i - 1 ) );

            startMerge = clock(  );
            mergeSort( Vcpy1, 0, ( int ) i - 1 );
            endMerge = clock(  );
            assert( isArraySorted( Vcpy1, 0, i - 1 ) );

            timeHybrid = measureRunningTime( startHybrid, endHybrid );
            timeMerge = measureRunningTime( startMerge, endMerge );

            /* Save the difference of the running times of the two algorithms
             * for the current array size = i.  */
            diffRunningTimes[i - 1] = timeHybrid - timeMerge;

            /* Raw data used for the plotting.  */
            fprintf( stdout, "%d    %f\n", ( int ) i,
                     ( timeHybrid - timeMerge ) );

            free( V );
            free( Vcpy0 );
            free( Vcpy1 );
        }

        timeSum[k] = sumTimes( diffRunningTimes );

        free( diffRunningTimes );

    }

    fprintf( stderr, "k is about %d\n", ( int ) getK( timeSum ) );

    free( timeSum );

    exit( EXIT_SUCCESS );

}

static void hybridMergeSort( int *V, int p, int r, int k )
{
    int q;

    if( (r - p) <= k ) {
        insertionSort( V, ( size_t ) p, ( size_t ) r );
    }
    
    else{
        if( p < r ){
            hybridMergeSort( V, p, q, k );
            hybridMergeSort( V, q + 1, r, k );
            merge( V, p, q, r );
        }
    }

    return;
}

/* Sum all the the hybrid - merge times for the current k.  */
static second sumTimes( second * diffs )
{

    size_t i;
    second sum;


    sum = 0;
    for ( i = 0; i < ARRAY_SIZE; i++ )
        sum += diffs[i];


    return sum;

}

/* k is the index corresponding to the sum with the least difference.
 * This means that k is part of the input responsible for the least execution
 * time.  */
static size_t getK( second * sum )
{
    second kVal;
    size_t i, k;


    k = 0;
    kVal = sum[0];
    for ( i = 1; i < KMAX + 1; i++ ) {
        if ( sum[i] < kVal ) {
            kVal = sum[i];
            k = i;
        }
    }

    return k;

}
