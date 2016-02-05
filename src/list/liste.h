/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "../adt/adt.h"

/* Definitions.  */

#define EMPTYLIST EMPTY

/* New datatype.  */

/* This struct contains a physical node rappresentation */
typedef struct node physicalNode;

/* nodePointer is a pointer to struct physicalNode */
typedef pointerToNode nodePointer;

/* headPointer is a pointer to type nodePointer */
typedef referenceToNodePointer headPointer;

/* Function Prototypes.  */
boolean null( headPointer hp ) ;
void cons (element el, headPointer hp ) ;
element car ( headPointer hp ) ;
headPointer cdr( headPointer hp ) ;
void initList ( headPointer hp );
int length ( headPointer hp );
void printList ( headPointer hp );
headPointer freeList ( headPointer hp );
