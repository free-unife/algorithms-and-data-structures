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
    tRoot lefti = EMPTYTREE;
    tRoot righti = EMPTYTREE;
    tRoot rooti = EMPTYTREE;
    tRoot anotherNode = EMPTYTREE;


    lefti = constree( "sono il left!", EMPTYTREE, EMPTYTREE );
    righti = constree( "sono il right!", EMPTYTREE, EMPTYTREE );
    rooti = constree( "SONO LA RADICE!!", lefti, righti );

    anotherNode = constree( "SONO LA RADICE!!", EMPTYTREE, righti );

    printf( "%s\n", root( rooti ) );
    printf( "%s\n", root( left( rooti ) ) );
    printf( "%s\n", root( right( rooti ) ) );
    printf( "%s\n", root( right( anotherNode ) ) );

    return 0;
}
