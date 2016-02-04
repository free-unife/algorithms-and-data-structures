/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef MAIN_H
#define MAIN_H
    #include "main.h"
#endif


int main ( void )
{

    stack *s;
    /* stack **sPointer; */
    element e;


    /* sPointer = &s; */

    s = initStack (54);
    s = push (6, s);
    s = push (21, s);
    printf ("Stack pointer = %p\n", (void *) s);

    e = pop (&s);
    printf ("Stack pointer = %p\n", (void *) s);

    printf ("Popped element = %d\n", e);

    printf ("Stack height =  %d\n", getStackHeight ( s ));

    printStack (s, 0);

    return 0;

}
