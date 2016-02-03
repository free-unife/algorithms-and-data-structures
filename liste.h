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

typedef int boolean;
#define false 0
#define true  1

typedef int element;

typedef struct elementList{
    element el;
    struct elementList *next;
}list;

boolean null( list * head );
list * cons (element e, list * head );
element car ( list * head );
list * cdr( list * head ); 
void printList ( list * head );
