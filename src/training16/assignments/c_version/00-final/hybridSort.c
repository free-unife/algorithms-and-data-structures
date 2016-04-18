/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

void hybridSort( int *array, int p, int r, int k )
{
    int q;

    if( le( ( r - p ), k ) )
        insertionSort( array, p, r );
    else
        if ( lt ( p, r ) )
        {
            q = ( p + r ) / 2;
            hybridSort( array, p, q, k );
            hybridSort ( array, q + 1, r, k );
            merge ( array, p, q, r );
        }
}

#ifdef M_HYBRIDSORT_C
int main( void )
{
    int *array;
    clock_t start, end;
    int k;

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


    fprintf( stderr, "\n\nHybrid sort test\n" );
    k = findK ( );
    start = clock(  );
    hybridSort( array, 0, 100 - 1, k );
    end = clock(  );
    if ( arrayOrdered( array ) )
        fprintf( stderr, "[ OK ] Array has been ordered in %f s, with k = %d\n", runningTime( start, end ), k );
    else
        fprintf( stderr, "[ ERR ] This message should not be shown\n" );

    free( array );

    return 0;
}
#endif
