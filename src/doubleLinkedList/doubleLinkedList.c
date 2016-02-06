/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "doubleLinkedList.h"
#endif

/* NATIVE FUNCTIONS.  */

/* Init the list with a dummy node that points himself */
void initDoubleLinkedList( headPointer hp )
{
    init( hp );

    /* insert a dummy node */
    cons( 0, hp );

    /* setup his next and prec pointers to itself */
    ( *hp )->next = ( *hp );
    ( *hp )->prev = ( *hp );

    return;
}
