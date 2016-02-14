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
    nodePointer *foundedNodes;
    int i;


    initDoubleLinkedList( head );

    insertNodeInHead( 10, head );
    insertNodeInHead( 20, head );
    insertNodeInQueue( 10, head );
    insertNodeInQueue( 20, head );
    insertNodeInHead( 28, head );

    printDoubleLinkedList( head );
    printf( "length: %d\n", lengthDoubleLinkedList( head ) );

    /* Testing search for an element */

    foundedNodes = searchForElement( 10, head );

    printf( "-----\n" );

    i = 0;
    while ( foundedNodes[i] != EMPTY ) {
        printf( "Extracted from middle --> %d\n",
                extractNodeInMiddle( foundedNodes[i] ) );
        i = i + 1;
    }

    printf( "-----\n" );
    printDoubleLinkedList( head );
    printf( "length: %d\n", lengthDoubleLinkedList( head ) );

    /* Testing extraction from head / queue */
    /*
       printf( "-----\n" );
       printf( "Extracted from head --> %d\n", extractNodeInHead( head ) );
       printf( "-----\n" );
       printDoubleLinkedList( head );
       printf( "length: %d\n", lengthDoubleLinkedList( head ) );

       printf( "-----\n" );
       printf( "Extracted from queue --> %d\n", extractNodeInQueue( head ) );
       printf( "-----\n" );
       printDoubleLinkedList( head );
       printf( "length: %d\n", lengthDoubleLinkedList( head ) );

       printf( "-----\n" );
       printf( "Extracted from head --> %d\n", extractNodeInHead( head ) );
       printf( "-----\n" );
       printDoubleLinkedList( head );
       printf( "length: %d\n", lengthDoubleLinkedList( head ) );

       printf( "-----\n" );
       printf( "Extracted from queue --> %d\n", extractNodeInQueue( head ) );
       printf( "-----\n" );
       printDoubleLinkedList( head );
       printf( "length: %d\n", lengthDoubleLinkedList( head ) );

       printf( "-----\n" );
       printf( "Extracted from head --> %d\n", extractNodeInHead( head ) );
       printf( "-----\n" );
       printDoubleLinkedList( head );
       printf( "length: %d\n", lengthDoubleLinkedList( head ) );
     */

    if ( isDoubleLinkedListEmpty( head ) == true ) {
        printf( "The list is empty!\n" );
    } else {
        printf( "The list is not empty!\n" );
    }

    /* Testing freeDoubleLinkedList() */
    /*
       freeDoubleLinkedList( head );

       if ( null( head ) )
       printf( "free is correct!" );
       else
       printf( "free is not correct!" );
     */

    return 0;

}
