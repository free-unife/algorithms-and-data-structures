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
    vector newVector;


    newVector = createInitializedVector( 3, 5 );

    printf( "%d", vectorLength( *newVector ) );
    printf( "%d", vectorLength( *newVector ) );

    printf( "%d", getElementValue( newVector, 3 ) );


    return 0;
}
