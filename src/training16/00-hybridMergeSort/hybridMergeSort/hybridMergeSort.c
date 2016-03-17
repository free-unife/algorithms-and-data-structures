/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_MYBRIDMERGESORT_H
#define M_HYBRIDMERGESORT_H
#include "hybridMergeSort.h"
#endif

static void hybridMergeSort( int *V, int p, int r);
static boolean isArrayOrdered( int *V, size_t low, size_t high );


int main( void )
{

    int *V, *Vcpy0 = NULL, *Vcpy1 = NULL;
    size_t i;
    clock_t startHybrid, endHybrid, startMerge, endMerge;
    second timeHybrid, timeMerge;

    /* Run insetion sort for i arrays.  */
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

        startHybrid = clock(  );
        hybridMergeSort( Vcpy0, 0, ( int ) i - 1 );
        endHybrid = clock(  );
        assert (isArrayOrdered (Vcpy0, 0, i - 1));

        startMerge = clock(  );
        mergeSort( Vcpy1, 0, ( int ) i - 1 );
        endMerge = clock(  );
        assert (isArrayOrdered (Vcpy1, 0, i - 1));

        timeHybrid = measureRunningTime (startHybrid, endHybrid);
        timeMerge = measureRunningTime (startMerge, endMerge);

        fprintf( stdout, "%d    diff=%f   hy=%f    mr=%f\n", ( int ) i, ( 
timeHybrid - timeMerge ), timeHybrid, timeMerge );

/*        fprintf( stdout, "%d    %f\n", ( int ) i, fabs ( timeInsertion - 
timeMerge ) );*/

        free( V );
        free ( Vcpy0 );
        free ( Vcpy1 );
    }

    exit( EXIT_SUCCESS );

}

static void hybridMergeSort( int *V, int p, int r)
{

    int q;


    if (p < r)
    {
        q = ( p + r ) / 2;
        hybridMergeSort(V, p, q);
        hybridMergeSort(V, q + 1, r);

        if (r - p <= K)
            insertionSort( V, p, r );
        else
            merge(V, p, q, r);
    }


    return;

}


static boolean isArrayOrdered( int *V, size_t low, size_t high )
{

    size_t i;


    i = low;
    /* Since there can be multiple equal elements, the == statement holds.  */
    while ( i < high && V[i] <= V[i + 1] )
        i++;

    /* i >= high.  */
    if ( i == high ) {
        /* Array is ordered.  */
        return true;
    }
    /* i < high */
    else {
        /* Array is not ordered.  */
        return false;
    }

}

