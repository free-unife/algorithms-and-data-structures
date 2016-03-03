/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "insertionSort.h"


int main( void )
{

    int *V, i = 0;
    double runningTime;


    /* variabile fino a quelli testati.  */
    for ( i = 0; i < 2000; i++ ) {
        if ( ( V = malloc( sizeof( int ) * i ) ) == NULL )
            exit( EXIT_FAILURE );

        /* Riempimento array con x elementi pseudocasuali.  */
        genRandom( V, i );

        /* Chiamata a insertionSort.  */
        runningTime = insertionSort( V, i );

        fprintf( stdout, "%d    %f", i, runningTime );

        free( V );
    }
    /* Check array ordinato.  */
    /*checkArray(V, limit); */

    exit( EXIT_SUCCESS );

}

void genRandom( int *V, int n )
{

    int i = 0, tmp;
    struct timeval t1;


    for ( i = 0; i < n; i++ ) {
        gettimeofday( &t1, NULL );
        /* Il seme e' impostato con i microsecondi.  */
        srand( t1.tv_usec * t1.tv_sec );
        tmp = rand(  );
        V[i] = tmp;

        /*fprintf (stderr, "V[%d]=%d\n", i, V[i]); */
    }

}

double insertionSort( int *V, int n )
{

    int j = 1, key, i;
    clock_t start, end;


    /* Clock start.  */
    start = clock(  );
    for ( j = 1; j < n; j++ ) {
        key = V[j];
        i = j - 1;
        while ( i >= 0 && V[i] > key ) {
            V[i + 1] = V[i];
            i--;
        }
        V[i + 1] = key;
    }
    /* Clock check.  */
    end = clock(  );
/*	fprintf(stderr, "%f", (double) end - start);*/
    fprintf( stdout, "\n" );
/*	for (i = 0; i < n; i++)
		fprintf (stderr, "V[%d]=%d\n", i, V[i]); */

    return ( double ) ( ( end - start ) / ( double ) CLOCKS_PER_SEC );

}
