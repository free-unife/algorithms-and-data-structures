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


    l = makeList ( 0 );
    l = populateList ( l );
    len = length ( l );
	printf ("%p\n", (void *) l);

    printf ("List length =  %d\n", len);

    printList ( l, index );

	freeList ( l );

	index = 0;
    printList ( l, index );

	printf ("%p\n", (void *) l);

    return 0;

}


/* Fill the list with some elements.  */
list *populateList ( list *head )
{
    int i;


    for (i = 99; i>= 0; i--)
        head = cons ( i, head );

    return head;

}
