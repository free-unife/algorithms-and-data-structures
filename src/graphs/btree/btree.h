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

#ifndef MATH
#define MATH
#include <math.h>
#endif

#ifndef ADT_H
#define ADT_H
#include "../adt/adt.h"
#endif


/* Definitions.  */
#define EMPTYTREE EMPTY


/* New datatype.  */

 /* We always return an integer as a vertex value (we use weight) */
typedef char *element;

/* The recursive definition states that each node can be a root of a bin tree.
 */
typedef nodePointer tree;

/* Prototypes. */

/* Check if a tree is empty.  */
boolean emptyTree( tree t );

/* Add node as new root of left and right tree.  */
tree consTree( element e, tree leftTree, tree rightTree );

/* Get the left tree. precondition: assert (!emptyTree (t))  */
tree left( tree t );

/* Get the right tree. precondition: assert (!emptyTree (t))  */
tree right( tree t );

/* root () = car (), preconditions: assert (!emptyTree (t))  */
element root( tree t );

/* Max number of nodes inside a tree */
int findWeight( tree t );

/* Check if newEl is less than rootEl */
boolean lessThan( element newEl, element rootEl );

/* In-order insert */
tree insOrd( element el, tree t );

void printAllNodes( tree t );

tree printRoot( tree t, char direction );
