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
    int len;


    l = NULL;
    l = populateList ( l );
    len = length ( l );


    printf ("List length =  %d\n", len);

    
    l = freeList ( l );


    return 0;

}


/* Fill the list with some elements.  */
list *populateList ( list *head )
{
    int i;
    list * newList;
    int index = 0;

    head = makeList(0);

    for (i = 1; i<100; ++i)
        head = cons ( i, head );

    newList = cons (101, head);

    index = 0;
    printList (newList, index);
    index = 0;
    printList ( head , index );

    return head;

}
