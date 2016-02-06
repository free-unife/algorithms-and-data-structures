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
    int i = 0;
    headPointer head;


    /* Get the correct amount of space for the headPointer variable. */
    head = malloc( sizeof( headPointer ) );

    initList( head );
    if ( null( head ) )
        printf( "List is null\n" );

    if ( sizeof( **head ) == sizeof( struct node ) )
        printf( "SAME SIZES %lu\n", sizeof( struct node ) );

    printf( "%p\n", ( void * ) *head );
    ( **head ).el = 500;

    for ( i = 0; i < 100; ++i ) {
        cons( i, head );
    }

    printList( head );
    head = freeList( head );
    printList( head );

    return 0;

}
