/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

double runningTime( clock_t start, clock_t end )
{
    return ( ( ( double ) ( end - start ) / ( double ) CLOCKS_PER_SEC ) );
}

void genRandomArray( int *V, size_t n )
{

    size_t i;
    int tmp;
    struct timeval t1;


    for ( i = 0; i < n; i++ ) {
        gettimeofday( &t1, NULL );
        /* Seed is set in microseconds.  */
        srand( t1.tv_usec * t1.tv_sec );
        tmp = rand(  );
        V[i] = tmp;
    }

}
