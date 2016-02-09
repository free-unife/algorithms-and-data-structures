/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


/* Standard libraries.  */
#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

#ifndef ASSERT
#define ASSERT
#include <assert.h>
#endif

#ifndef STRING
#define STRING
#include <string.h>
#endif

#ifndef ADT_H
#define ADT_H
#include "../adt/adt.h"
#endif


/* Definitions.  */
#define EMPTYTREE EMPTY


/* New datatype.  */
typedef char *element;

/* The recursive definition states that each node can be a root of a bin tree.
 */
typedef nodePointer tRoot;
typedef headPointer tPointer;


/* Prototypes. */

/* Check if a tree is empty.  */
boolean emptyTree( tRoot t );
/*boolean isDoubleLinkedListEmpty( headPointer hp )*/

/* Add node as new root of left and right tree.  */
tRoot constree( element e, tRoot leftTree, tRoot rightTree );
/*
    newNode = newVertex (e, ?);
    connectVertex (? ,newNode, leftTree, 0)
    connectVertex (? ,newNode, rightTree, 0)
 */

/* root () = car (), preconditions: assert (!emptyTree (t))  */
element root( tRoot t );
/*
    assert (!emptyTree (t));
    return t->name;
*/

/* Get the left tree. precondition: assert (!emptyTree (t))  */
tRoot left( tRoot t );
/*
    assert (!emptyTree (t);
    return t->left;
*/


/* Get the right tree. precondition: assert (!emptyTree (t))  */
tRoot right( tRoot t );
/*
    assert (!emptyTree (t);
    return t->right;
*/
