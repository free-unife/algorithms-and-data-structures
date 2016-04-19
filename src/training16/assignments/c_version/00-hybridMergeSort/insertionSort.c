/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

void insertionSort( int *array, int startInd, int endInd )
{
    int j;
    int i, key;

    for ( j = startInd + 1; le( j, endInd ); j++ ) {
        key = el( array, j );
        i = j - 1;

        while ( ge( i, startInd ) && gt( el( array, i ), key ) ) {
            array[i + 1] = el( array, i );
            i--;
        }
        array[i + 1] = key;
    }
}

#ifdef M_INSERTIONSORT_C
int main( void )
{
    int *array;
    clock_t start, end;

    fprintf( stderr, "\n\nInitializing array\n" );
    initArray( &array );
    if ( arrayEmpty( array ) )
        fprintf( stderr, "[ OK ] Array is empty\n" );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );


    fprintf( stderr, "\n\nGenerating random array of %d elements\n", 100 );
    array = genRandomArray( 100 );


    fprintf( stderr, "\n\nIs array still empty?\n" );
    if ( !arrayEmpty( array ) )
        fprintf( stderr, "[ OK ] Array is not empty\n" );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );


    fprintf( stderr, "\n\nInsertion sort test\n" );
    start = clock(  );
    insertionSort( array, 0, 100 - 1 );
    end = clock(  );
    if ( arrayOrdered( array ) )
        fprintf( stderr, "[ OK ] Array has been ordered in %f s\n",
                 runningTime( start, end ) );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );

    free( array );

    return 0;
}
#endif
