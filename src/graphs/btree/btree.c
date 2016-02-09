/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef TREE_H
#define TREE_H
#include "btree.h"
#endif


/* TODO */

boolean emptyTree( tRoot t )
{
    return ( t == EMPTY );
}

tRoot constree( element e, tRoot leftTree, tRoot rightTree )
{

    tRoot root;


    if ( ( leftTree == EMPTYTREE ) && ( rightTree == EMPTYTREE ) ) {

        root = newVertex( e, EMPTY );


        return root;
    }

    return NULL;
}
