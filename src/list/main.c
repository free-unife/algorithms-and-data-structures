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

    list *l;


    l = NULL;
    l = populateList ( l );

    printf ("List length =  %d\n", length ( l ));

    l = freeList ( l );

    printf ("List length after free =  %d\n", length ( l ));

    return 0;

}


/* Fill the list with some elements.
 * Since we are working with C to make functional programs (as in functional
 * programming), the input to a function is not modified but only read. The
 * following example show how this is done.  */
list *populateList ( list *head )
{
    int i;
    list * newList;

    head = makeList(0);

    for (i = 1; i<5; ++i)
        head = cons ( i, head );

    newList = cons (5, head);

    printList (newList, 0);
    printList (head , 0);

    return head;

}
