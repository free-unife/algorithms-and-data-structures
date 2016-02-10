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
    tree aTree = EMPTYTREE;

    aTree = insOrd( "4", aTree );
    aTree = insOrd( "2", aTree );
    aTree = insOrd( "6", aTree );

    aTree = insOrd( "0", aTree );
    aTree = insOrd( "1", aTree );
    aTree = insOrd( "5", aTree );
    aTree = insOrd( "7", aTree );

    printf( "Weight of aTree: %d\n", findWeight( aTree ) );
    printf( "Root have to be 0 : --> %s\n", root( aTree ) );
    printf( "Right son of root --> %s\n", root( right( aTree ) ) );
    printf( "Left son of root --> %s\n", root( right( right( aTree ) ) ) );
    printf( "Right son of right --> %s\n",
            root( right( right( right( aTree ) ) ) ) );

    ( void ) aTree;

    return 0;
}
