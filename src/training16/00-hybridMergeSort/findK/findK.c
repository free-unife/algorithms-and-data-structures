/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_FINDK_H
#define M_FINDK_H
#include "findK.h"
#endif


int main( void )
{

    int *V, *Vcpy0 = NULL, *Vcpy1 = NULL;
    size_t i;
    clock_t startInsertion, endInsertion, startMerge, endMerge;
    second timeInsertion, timeMerge;

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

        startInsertion = clock(  );
        insertionSort( Vcpy0, 0, ( int ) i - 1 );
        endInsertion = clock(  );

        startMerge = clock(  );
        mergeSort( Vcpy1, 0, ( int ) i - 1 );
        endMerge = clock(  );

        timeInsertion = measureRunningTime (startInsertion, endInsertion);
        timeMerge = measureRunningTime (startMerge, endMerge);

/*        fprintf( stdout, "%d    diff=%f   ins=%f    mr=%f\n", ( int ) i, ( 
timeInsertion - timeMerge ), timeInsertion, timeMerge );*/

        fprintf( stdout, "%d    %f\n", ( int ) i, fabs ( timeInsertion - 
timeMerge ) );

        free( V );
        free ( Vcpy0 );
        free ( Vcpy1 );
    }

    exit( EXIT_SUCCESS );

}

