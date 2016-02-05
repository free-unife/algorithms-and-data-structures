/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef ADT_H
#define ADT_H
    #include "adt.h"
#endif


/* NATIVE FUNCTIONS.  */

/* Checks if a list is empty.
 * If the head pointer is NULL, the list is empty */
boolean null( referenceToNodePointer ref ) {
  return *ref == EMPTY;
}


/* It adds an element e in the head of the list,
 * changing the head of the list to the new node that holds the new element.
 */
void cons (element el, referenceToNodePointer ref ) {
  pointerToNode np = malloc( sizeof( struct node ) );
  np->el = el;
  np->next = *ref;
  * ref = np;
  return;
}

void tailCons (element el, referenceToNodePointer ref ) {
  referenceToNodePointer refNew;

  if ( null( ref ) ) {
    cons( el, ref );
  }
  else {
    while( length( ref ) > 1 ){
      ref = cdr( ref );
    }
    refNew = malloc(sizeof( pointerToNode * ));
    cons(el, refNew );
    (*ref)->next = *refNew;
  }
  return;
}

/* Get value of the first node's element field.  */
element car ( referenceToNodePointer ref ) {
  assert( ! null( ref ) );
  return ( * ref )->el;
}


/* Changes the referenceToNodePointer one step over */
referenceToNodePointer cdr( referenceToNodePointer ref ) {
  assert ( ! null( ref ) );
  return &(( *ref )->next);
}


/* Init with an EMPTY as a nodePointer */
void init ( referenceToNodePointer ref ) {
  *ref = malloc( sizeof( pointerToNode ) );
  *ref = EMPTY;
  return;
}


/* Calculate the length of the list using the native functions.  */
int length ( referenceToNodePointer ref ) {
  return ( null( ref ) ? 0
                      : 1 + length( cdr ( ref ) ) );
}


/* Prints the whole list */
void printAll ( referenceToNodePointer ref ) {
  int index = 0;

  if( null( ref ) ){
    printf("EMPTY\n");
  }
  else{
    while( length( ref ) > 0 ){
      printf ("Node [%d] -> el == %d\n", index, car( ref ) );
      index = index + 1;
      ref = cdr(ref);
    }
  }

  return;
}


/* Free the list.*/
referenceToNodePointer freeAll ( referenceToNodePointer ref ) {
  while( ! null( ref ) ) {
    pointerToNode toDelete = *ref;
    ref = cdr( ref );
    free( toDelete );
  }
  return ref;
}
