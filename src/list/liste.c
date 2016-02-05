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
boolean null( headPointer hp ) {
  return *hp == EMPTYLIST;
}


/* It adds an element e in the head of the list,
 * changing the head of the list to the new node that holds the new element.
 */
void cons (element el, headPointer hp ) {
  nodePointer np = malloc( sizeof( struct physicalNode ) );
  np->el = el;
  np->next = *hp;
  * hp = np;
  return;
}


/* Get value of the first node's element field.  */
element car ( headPointer hp ) {
  assert( ! null( hp ) );
  return ( * hp )->el;
}


/* Changes the headPointer one step over */
headPointer cdr( headPointer hp ) {
  assert ( ! null( hp ) );
  return &(( *hp )->next);
}


/* Init with an EMPTYLIST as a nodePointer */
void initList ( headPointer hp ) {
  *hp = malloc( sizeof( nodePointer ) );
  *hp = EMPTYLIST;
}


/* Calculate the length of the list using the native functions.  */
int length ( headPointer hp ) {
  return ( null( hp ) ? 0
                      : 1 + length( cdr ( hp ) ) );
}


/* Prints the whole list */
void printList ( headPointer hp ) {
  int index = 0;

  if( null( hp ) ){
    printf("EMPTY\n");
  }
  else{
    while( length( hp ) > 0 ){
      printf ("Node [%d] -> el == %d\n", index, car( hp ) );
      index = index + 1;
      hp = cdr(hp);
    }
  }

  return;
}


/* Free the list.*/
headPointer freeList ( headPointer hp ) {
  while( ! null( hp ) ) {
    nodePointer toDelete = *hp;
    hp = cdr( hp );
    free( toDelete );
  }
  return hp;
}
