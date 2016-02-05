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
#define EMPTYLIST NULL


/* New datatype.  */
typedef int boolean ;
typedef int element;

/* This struct contains a physical node rappresentation */
struct physicalNode {
    element el ;
    struct physicalNode *next ;
};

/* nodePointer is a pointer to struct physicalNode */
typedef struct physicalNode *nodePointer;

/* headPointer is a pointer to type nodePointer */
typedef nodePointer *headPointer;

/* Function Prototypes.  */
boolean null( headPointer hp ) ;
void cons (element el, headPointer hp ) ;
element car ( headPointer hp ) ;
headPointer cdr( headPointer hp ) ;
void initList ( headPointer hp );
int length ( headPointer hp );
void printList ( headPointer hp );
headPointer freeList ( headPointer hp );
