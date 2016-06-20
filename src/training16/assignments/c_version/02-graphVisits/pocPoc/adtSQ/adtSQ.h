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
typedef int boolean;

/* This struct contains a physical node rappresentation */
struct nodeSQ {
    struct nodeSQ *next;
    nodePointer el;
    struct nodeSQ *prev;
};

/* nodePointer is a pointer to struct physicalNode */
typedef struct nodeSQ *pointerToNodeSQ;

/* pointerToNodeSQ is a pointer to type nodePointer */
typedef pointerToNodeSQ *referenceToNodePointerSQ;

/* Function Prototypes.  */
boolean nullSQ( referenceToNodePointerSQ ref );
void consSQ( nodePointer el, referenceToNodePointerSQ ref );
void tailConsSQ( nodePointer el, referenceToNodePointerSQ ref );
nodePointer carSQ( referenceToNodePointerSQ ref );
referenceToNodePointerSQ cdrSQ( referenceToNodePointerSQ ref );
void initSQ( referenceToNodePointerSQ ref );
int lengthSQ( referenceToNodePointerSQ ref );
void printAllSQ( referenceToNodePointerSQ ref );
referenceToNodePointerSQ freeAllSQ( referenceToNodePointerSQ ref );
