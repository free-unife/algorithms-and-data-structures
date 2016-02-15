/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef MAIN_H
#define MAIN_H
#include "main.h"
#endif


int main( void )
{

    int n = 7, i;
    int v[7] = { 9, 2, 7, 4, 0, 5, 6 };

    straightInsertion( v, n );

    for ( i = 0; i < n; i++ )
        printf( "%d ", v[i] );

    printf( "\n" );

    return 0;

}
