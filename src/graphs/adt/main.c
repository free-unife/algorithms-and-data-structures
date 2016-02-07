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
    referenceToNodePointer pNode;
    referenceToEdgePointer pEdge;

    /* Get the correct amount of space for the headPointer variable. */
    if ( ( pNode = malloc( sizeof( referenceToNodePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );

    if ( ( pEdge = malloc( sizeof( referenceToEdgePointer * ) ) ) == NULL )
        exit( EXIT_FAILURE );


    newNodeList( pNode );
    newNode( pNode, "test" );
    newNode( pNode, "toast" );
    newNode( pNode, "a toast to the good ones" );

    printf( "%s\n%ss\n%s\n", ( *pNode )->name, ( ( *pNode )->next )->name,
            ( ( ( *pNode )->next )->next )->name );


/*    newEdge( pEdge );*/

    return 0;

}
