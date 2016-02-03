/* Standard libraries */

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


/* Definitions */

#define false 0
#define true  1
#define EMPTYLIST NULL


/* New datatype */

typedef int boolean ;
typedef int element;

typedef struct elementList {
    element el ;
    struct elementList * next ;
} list;


/* Function Prototypes */

boolean null( list * head ) ;
list * cons (element el, list * head ) ;
element car ( list * head ) ;
list * cdr( list * head ) ; 
list * makeList ( element el );
int length ( list * head );
void printList ( list * head ) ;
