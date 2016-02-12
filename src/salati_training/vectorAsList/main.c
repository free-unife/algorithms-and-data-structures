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
    node tmpp = NULL, tmp;

    newVector = createInitializedVector( 2, 5 );
    ( void ) newVector;

    tmpp = *( newVector );
    tmp = tmpp;

    while ( tmp != NULL ) {
        printf( "%d\n", tmp->el );
        tmp = tmp->next;
    }

    tmp = tmpp;
    while ( tmp != NULL ) {
        printf( "%d\n", tmp->el );
        tmp = tmp->next;
    }


/*    printf( "%d", ( *( newVector ) )->next->el );*/


/*    printf( "%d\n", vectorLength( newVector ) );
    printf( "%d\n", vectorLength( newVector ) );
*/
/*    printf( "%d", getElementValue( newVector, 3 ) );*/


    return 0;
}
