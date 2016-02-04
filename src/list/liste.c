/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef LISTE_H
#define LISTE_H
    #include "liste.h"
#endif


/* NATIVE FUNCTIONS.  */


/* Checks if a list is empty.
 * If the head pointer is NULL, the list is empty */
boolean null ( list * head ) { return ( head == EMPTYLIST ); }

/* It adds an element e in the head of the list,
 * changing the head of the list to the new node that holds the new element.
 */
list * cons (element el, list * head ) {
    list *t;

    t = malloc (sizeof (list));

    if (null (t)) {
        fprintf( stderr, "The new node cannot be allocated.\n" );
        exit( EXIT_FAILURE );
    }

    t -> next = head;
    t -> el = el;

    return t;
}

/* Get value of the first node's element field.  */
element car ( list * head ) {
    assert( ! null( head ));

    return head -> el;
}

/* Get all the list except the first node.  */
list * cdr( list * head ) {
    assert (! null( head ));

    return head -> next;
}

/* Make a new list with the element el in the first node.  */
list * makeList ( element el ) {

    return ( cons ( el, EMPTYLIST ) ) ;
}


/* END OF NATIVE FUNCTIONS.  */


/* Calculate the length of the list using the native functions.  */
int length ( list * head ) {

    return ( null( head ) ? 0
                       : 1 + length ( cdr ( head )) ) ;
}


void printList (list *head, int index)
{

    if (null (head))
    {
        printf("No more elements in struct.\n");
        return;
    }
    else
    {
        printf ("Struct [%d] -> el == %d\n", index, car (head));
        index ++;
        printList (cdr (head), index);
    }
}

/* Free the list.  */
list * freeList ( list * head )
{

    list *tmp;

    if (null (head))
        return EMPTYLIST;

    tmp = head;
    head = cdr (head);
    tmp -> next = NULL;
    free (tmp);
    return freeList (head);
}
