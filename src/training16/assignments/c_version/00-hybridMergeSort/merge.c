/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

void merge( int *array, int p, int q, int r )
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j, k;
    int *L, *R;

    if ( ( L = malloc( ( n1 + 1 ) * sizeof( int ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    if ( ( R = malloc( ( n2 + 1 ) * sizeof( int ) ) ) == NULL ) {
        if ( errno )
            perror( strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    for ( i = 0; lt( i, n1 ); i++ )
        L[i] = el( array, p + i );

    for ( j = 0; lt( j, n2 ); j++ )
        R[j] = el( array, q + 1 + j );

    L[n1] = INF;
    R[n2] = INF;

    i = 0;
    j = 0;
    for ( k = p; le( k, r ); k++ ) {
        if ( le( el( L, i ), el( R, j ) ) ) {
            array[k] = el( L, i );
            i++;
        } else {
            array[k] = el( R, j );
            j++;
        }
    }

    free( L );
    free( R );
}

