/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

#if defined M_MAIN_C
int main( void )
{
    int attempt, k;
    int *array, *arrayMergeSort, *arrayHybridSort;
    clock_t start, end;
    double mergeSortTime, hybridSortTime;

    fprintf( stdout, "%s    %s    %s    %s    %s\n", "attempt", "K",
             "arraySize", "mergeSortTime", "hybridSortTime" );

    for ( attempt = 0; attempt < ATTEMPTS; attempt++ ) {
        initArray( &array );

        for ( k = MIN_K; k <= MAX_K; k++ ) {
            initArray( &arrayHybridSort );
            initArray( &arrayMergeSort );

            array = genRandomArray( COMPARISON_SIZE );

            assert( !arrayEmpty( array ) );

            /*
             * Get copies of the original array. 
             */
            arrayMergeSort = copyArray( array );
            arrayHybridSort = copyArray( array );
            assert( arrayEqual( array, arrayMergeSort ) );
            assert( arrayEqual( array, arrayHybridSort ) );

            start = clock(  );
            mergeSort( arrayMergeSort, 0, COMPARISON_SIZE - 1 );
            end = clock(  );
            mergeSortTime = runningTime( start, end );

            start = clock(  );
            hybridSort( arrayHybridSort, 0, COMPARISON_SIZE - 1, k );
            end = clock(  );
            hybridSortTime = runningTime( start, end );

            /*
             * Check if the arrays are ordered. 
             */
            assert( arrayEqual( arrayMergeSort, arrayHybridSort ) );
            assert( arrayOrdered( arrayMergeSort ) );
            assert( arrayOrdered( arrayHybridSort ) );

            free( arrayMergeSort );
            free( arrayHybridSort );

            /*
             * Print the results so that gnuplot can catch and use them. 
             */
            fprintf( stdout, "%d    %d    %d    %f    %f\n", attempt, k,
                     COMPARISON_SIZE, mergeSortTime, hybridSortTime );
        }
        free( array );
    }

    return 0;
}
#endif
