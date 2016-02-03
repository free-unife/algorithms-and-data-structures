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


/* Checks if a list is empty.
 * If the head pointer is NULL, the list is empty */
boolean null ( list * head ) { return ( head == NULL ); }

/* It adds an element e in the head of the list,
 * changing the head of the list to the new node that holds the new element.
 */
list * cons (element el, list * head ) {
    list * t;

    t = ( list * ) malloc( sizeof( list ));

    if ( null( t ) ) {
        fprintf( stderr, "Malloc Failed, call your Mom\n" );
        exit( EXIT_FAILURE );
    }

    t -> next = head;
    t -> el = el;

    return t;
}

/* */
element car ( list * head ) {
    assert( ! null( head ));

    return head -> el;
}

list * cdr( list * head ) {
    assert( ! null( head ));

    return head -> next;
}

list * makeList ( element el ) {

    return ( cons( el, EMPTYLIST ) ) ;
}

int length ( list * head ) {

    return ( null( head ) ? 0
                       : 1 + length( cdr( head )) ) ;
}


void printList ( list * head )
{

    list * this;
    int index = 0;


    this = head;
    while ( this != NULL ) {
        printf( "List[%d] -> el ==  %d\n", index, this -> el );
        this = this -> next;
        index = index + 1;
    }
}
