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
    headPointer head = malloc( sizeof( nodePointer * ) );
    initDoubleLinkedList( head );

    insertNodeInHead( 10, head );
    insertNodeInHead( 20, head );
    insertNodeInQueue( 99, head );
    insertNodeInQueue( 45, head );
    insertNodeInHead( 28, head );
    printDoubleLinkedList( head );

    printf( "length: %d\n", lengthDoubleLinkedList( head ) );

    if ( isDoubleLinkedListEmpty( head ) == true ) {
        printf( "The list is empty!\n" );
    } else {
        printf( "The list is not empty!" );
    }

    return 0;
}
