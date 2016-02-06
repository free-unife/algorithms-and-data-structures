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

    stackPointer stack = malloc( sizeof( nodePointer * ) );
/*    initStack( stack );*/

    pushStack( 10, stack );
    pushStack( 20, stack );
    pushStack( 30, stack );

    printStack( stack );

    printf( "%d\n", popStack( stack ) );
    printf( "POP\n" );

    printStack( stack );

    printf( "%d\n", popStack( stack ) );
    printf( "POP\n" );

    printStack( stack );

    printf( "%d\n", popStack( stack ) );
    printf( "POP\n" );

    printStack( stack );

    stack = freeStack( stack );
    printStack( stack );

    return 0;

}
