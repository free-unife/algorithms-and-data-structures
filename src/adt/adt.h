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


/* Definitions.  */

#define false 0
#define true  1
#define EMPTY NULL


/* New datatype.  */
typedef int boolean ;
typedef int element;

/* This struct contains a physical node rappresentation */
struct node {
    element el ;
    struct node *next ;
};

/* nodePointer is a pointer to struct physicalNode */
typedef struct node *pointerToNode;

/* pointerToNode is a pointer to type nodePointer */
typedef pointerToNode *referenceToNodePointer;

/* Function Prototypes.  */
boolean null( referenceToNodePointer ref ) ;
void cons (element el, referenceToNodePointer ref ) ;
void tailCons (element el, referenceToNodePointer ref ) ;
element car ( referenceToNodePointer ref ) ;
referenceToNodePointer cdr( referenceToNodePointer ref ) ;
void init ( referenceToNodePointer ref );
int length ( referenceToNodePointer ref );
void printAll ( referenceToNodePointer ref );
referenceToNodePointer freeAll ( referenceToNodePointer ref );
