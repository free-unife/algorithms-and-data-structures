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

    stackPointer stack;


    if ( ( stack = malloc( sizeof( stackPointer ) ) ) == NULL )
        exit( EXIT_FAILURE );

    initStack( stack );

    if ( isStackEmpty( stack ) )
        printf( "The stack is empty.\n" );

    pushStack( 10, stack );
    printf( "PUSH\n" );
    printf( "Stack pointer = %p\n", ( void * ) *stack );

    pushStack( 20, stack );
    printf( "PUSH\n" );
    printf( "Stack pointer = %p\n", ( void * ) *stack );

    pushStack( 30, stack );
    printf( "PUSH\n" );
    printf( "Stack pointer = %p\n", ( void * ) *stack );

    printStack( stack );
    printf( "------\n\n" );

    printf( "%d\n", popStack( stack ) );
    printf( "POP\n" );
    printf( "Stack pointer = %p\n", ( void * ) *stack );

    printStack( stack );
    printf( "------\n\n" );

    printf( "%d\n", popStack( stack ) );
    printf( "POP\n" );
    printf( "Stack pointer = %p\n", ( void * ) *stack );

    printStack( stack );
    printf( "------\n\n" );


    printf( "%d\n", popStack( stack ) );
    printf( "POP\n" );
    printf( "Stack pointer = %p\n", ( void * ) *stack );

    printStack( stack );
    printf( "------\n\n" );

    stack = freeStack( stack );
    printStack( stack );

    return 0;

}
