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

typedef struct elementList {
    element el ;
    struct elementList * next ;
} list;


/* Function Prototypes.  */
boolean null( list * head ) ;
list * cons (element el, list * head ) ;
element car ( list * head ) ;
list * cdr( list * head ) ;
list * makeList ( element el );
int length ( list * head );
void printList (list *head, int index);
void freeList ( list * head );
