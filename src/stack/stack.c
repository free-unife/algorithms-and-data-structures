/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef STACK_H
#define STACK_H
    #include "stack.h"
#endif


stack * push ( element el, stack * head ) {
    return cons( el, head );
}

/* The following is still functional programming because **head corresponds to
 * &s, so the input value is not modified alike what it points to. */
element pop ( stack **head )
{
    element e;


    printf ("Pop operation\n");
    e = car( *head );
    *head = cdr( *head );

    return e;
}

boolean isStackEmpty( stack * head ) {
    return null( head );
}

stack * initStack( element el ){
    return makeList( el );
}

int getStackHeight (stack * head)
{
    return length ( head );

}

void printStack (stack *head, int index)
{
    printList (head, index);
}
