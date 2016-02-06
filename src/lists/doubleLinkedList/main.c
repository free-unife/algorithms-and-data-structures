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


    /* Italian traduction:
     * Se il campo next di dummy punta a se stesso e
     * se il campo prev di dummy punta a se stesso e
     * se il campo prev e next di dummy coincidono e
     * se il campo elemento vale 0
     * allora initDoubleLinked list FUNZIONA!
     */
    if ( ( *head == ( *head )->next ) && ( *head == ( *head )->prev )
         && ( ( *head )->next == ( *head )->prev ) && ( *head )->el == 0 ) {
        printf( "initDoubleLinkedList WORKS\n" );
    }

    return 0;
}
