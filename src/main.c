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
    int len, index = 0;
    l = populateList ( l );
    len = length ( l );
	(void) l;


    printf ("List length =  %d\n", len);

    printList ( l, index );
    
    l = freeList ( l );
    index = 0;
    //printList ( l, index );


    return 0;

}


/* Fill the list with some elements.  */
list *populateList ( list *head )
{
    int i;

    head = makeList(0);

    for (i = 1; i<100; ++i)
        head = cons ( i, head );

    return head;

}
