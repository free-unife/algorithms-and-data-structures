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
    headPointer headOfVertexList;
    headPointer headOfEdgeList;
    nodePointer referenceToVertexNodes[10];
    nodePointer referenceToEdgeNodes[10];
    tPointer tp;

    if ( ( headOfVertexList = malloc( sizeof( nodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );

    if ( ( headOfEdgeList = malloc( sizeof( nodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );


    initTree (tp);

    initDoubleLinkedList( headOfVertexList );
    initDoubleLinkedList( headOfEdgeList );


    /*  Dummy example: */
    /*  printf( "w = %d\n", ( ( ( *( referenceToVertexNodes[1]->edgeListIn ) ) ->next )->edgeAddr )->w );  */

    return 0;

}
