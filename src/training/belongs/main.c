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

    int vector[8] = { 2, 4, 5, 6, 7, 8, 8, 9 };
    int notOrderedVector[8] = { 2, 6, 5, 6, 7, 8, 9, 8 };
    int index;


    index = belongs( 90, vector, 0, 7 );
    printf( "index = %d\n", index );

    index = belongs( 2, vector, 0, 6 );
    printf( "index = %d\n", index );

    index = belongs( 2, vector, 1, 6 );
    printf( "index = %d\n", index );

    index = belongs( 9, vector, 0, 7 );

    printf( "index = %d\n", index );

    index = belongs( 8, vector, 0, 7 );
    printf( "index = %d\n", index );

    index = belongs( 2, vector, 0, 0 );
    printf( "index = %d\n", index );

    index = belongs( 4, vector, 0, 0 );
    printf( "index = %d\n", index );

    index = belongs( 4, vector, 0, -1 );
    printf( "index = %d\n", index );


    index = belongs( 6, notOrderedVector, 0, 7 );
    printf( "index = %d\n", index );

    return 0;

}
