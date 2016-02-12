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

    newVector = createInitializedVector( 2, 5 );
   



    printf( "%d\n", vectorLength( newVector ) );
    printf( "%d\n", vectorLength( newVector ) );
    printf( "%d\n", getElementValue( newVector, 1 ) );


    return 0;
}
