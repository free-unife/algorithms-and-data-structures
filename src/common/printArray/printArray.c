/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "printArray.h"


void printArray( int *v, int n )
{

    int i = 0;


    assert( n > 0 );

    for ( i = 0; i < n; i++ )
        printf( "%d ", v[i] );

    printf( "\n" );


    return;

}

void printReverseArray( int *v, int n )
{

    int i = n - 1;


    assert( n > 0 );

    for ( i = n - 1; i >= 0; i-- )
        printf( "%d ", v[i] );

    printf( "\n" );


    return;

}

void printArrayFromTo( int *v, int n, int from, int to )
{

    int i = from;


    assert( n > 0 );
    assert( ( ( from >= 0 ) && ( from <= n - 1 ) )
            && ( ( to <= n - 1 ) && ( to >= 0 ) ) );

    for ( i = from; i <= to; i++ )
        printf( "%d ", v[i] );

    printf( "\n" );


    return;

}

void printReverseArrayFromTo( int *v, int n, int from, int to )
{

    int i = to;


    assert( ( ( from >= 0 ) && ( from <= n - 1 ) )
            && ( ( to <= n - 1 ) && ( to >= 0 ) ) );

    for ( i = to; i >= from; i-- )
        printf( "%d ", v[i] );

    printf( "\n" );


    return;

}
