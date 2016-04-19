/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

static int minIndexDoubleArray( double *array, int len );

/* If C the language wasn't strongly typed I could use all the array functions 
 * defined in utils.c. */
static int minIndexDoubleArray( double *array, int len )
{
    int i, minInd;
    double min;

    min = array[0];
    minInd = 0;
    for ( i = 1; i < len; i++ )
        if ( array[i] < min ) {
            min = array[i];
            minInd = i;
        }

    return minInd;
}

/* k is the maximum size where insertion sort performs like merge sort.
 * Before k insertion sort performs better ( and after k merge sort performs
 * better ).
 */
int findK( void )
{
    int attempt, size;
    int *array, *arrayInsertionSort, *arrayMergeSort;
    clock_t start, end;
    double insertionSortTime, mergeSortTime, diffTime;
    double *diffTimes;
    int *possibleK;
    int k;

#ifdef M_FINDK_C
    fprintf( stdout, "%s    %s    %s    %s    %s\n", "attempt",
             "arraySize", "insertionSortTime", "mergeSortTime",
             "diffTime" );
#else
    fprintf( stderr, "%s    %s    %s    %s    %s\n", "attempt",
             "arraySize", "insertionSortTime", "mergeSortTime",
             "diffTime" );
#endif

    possibleK = allocArray( ATTEMPTS );
    for ( attempt = 0; attempt < ATTEMPTS; attempt++ ) {

        if ( ( diffTimes =
               malloc( ( MAX_SIZE - MIN_SIZE ) * sizeof( double ) ) ) ==
             NULL ) {
            if ( errno )
                perror( strerror( errno ) );
            exit( EXIT_FAILURE );
        }

        for ( size = MIN_SIZE; size <= MAX_SIZE; size++ ) {
            initArray( &array );
            initArray( &arrayInsertionSort );
            initArray( &arrayMergeSort );

            array = genRandomArray( size );

            assert( !arrayEmpty( array ) );

            /*
             * Get copies of the original array. 
             */
            arrayInsertionSort = copyArray( array );
            arrayMergeSort = copyArray( array );
            assert( arrayEqual( array, arrayInsertionSort ) );
            assert( arrayEqual( array, arrayMergeSort ) );

            start = clock(  );
            insertionSort( arrayInsertionSort, 0, size - 1 );
            end = clock(  );
            insertionSortTime = runningTime( start, end );

            start = clock(  );
            mergeSort( arrayMergeSort, 0, size - 1 );
            end = clock(  );
            mergeSortTime = runningTime( start, end );

            /*
             * Check if the arrays are ordered. 
             */
            assert( arrayEqual( arrayInsertionSort, arrayMergeSort ) );
            assert( arrayOrdered( arrayInsertionSort ) );
            assert( arrayOrdered( arrayMergeSort ) );

            diffTime = fabs( insertionSortTime - mergeSortTime );

            /*
             * Save times. 
             */
            diffTimes[size - MIN_SIZE] = diffTime;

            free( arrayMergeSort );
            free( arrayInsertionSort );
            free( array );

            /*
             * Print the results so that gnuplot can catch and use them. 
             */
#ifdef M_FINDK_C
            fprintf( stdout, "%d    %d    %f    %f    %f\n", attempt, size,
                     insertionSortTime, mergeSortTime, diffTime );
#else
            fprintf( stderr, "%d    %d    %f    %f    %f\n", attempt, size,
                     insertionSortTime, mergeSortTime, diffTime );
#endif
        }
        possibleK[attempt] = MIN_SIZE +
            minIndexDoubleArray( diffTimes, MAX_SIZE - MIN_SIZE );

        free( diffTimes );
    }

    /*
     * Average of all possible ks. 
     */
    k = arraySum( possibleK ) / arrayLength( possibleK );

    fprintf( stderr, "\n\nPossible k for each one of the %d attempts\n",
             ATTEMPTS );
    printArray( possibleK );

    free( possibleK );

    return k;
}

#ifdef M_FINDK_C
int main( void )
{
    int k;

    k = findK(  );

    fprintf( stderr, "\n\nAvg of possible k is %d\n", k );

    return 0;
}
#endif
