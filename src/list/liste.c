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

/* Init with an EMPTYLIST as a nodePointer */
void initList ( headPointer hp ) {
  init( hp );
  return;
}


/* Prints the whole list */
void printList ( headPointer hp ) {
  printAll( hp );
  return;
}

/* Free the list.*/
headPointer freeList ( headPointer hp ) {
  return freeAll( hp );
}
