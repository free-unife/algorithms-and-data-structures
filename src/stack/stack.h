#ifndef LISTE_H
#define LISTE_H
    #include "../list/liste.h"
#endif

typedef list stack;

stack * push ( element el, stack * head );
element pop ( stack ** head );
boolean isStackEmpty( stack * head );
stack * initStack( element el );
int getStackHeight (stack * head);
void printStack (stack *head, int index);
