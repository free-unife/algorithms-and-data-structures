/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "queue.h"

void initQueue( first f, last l ) {
  init( f );
  init( l );
  return;
}


boolean isQueueEmpty( first f ){
  return null( f );
}


void insertQueue ( element el, first f, last l ) {
  tailCons( el, l );
  if( isQueueEmpty( f ) ) {
      *f = *l;
  }
  else {
    *l = (*l)->next;
  }

  return;
}


element extractQueue ( first f ) {
  element el = car( f );
  nodePointer toDelete = *f;
  *f = ( *f )->next;
  free( toDelete );
  return el;
}


void printQueue( first f ) {
  printAll( f );
  return;
}


first freeQueue( first f ) {
  return freeAll( f );
}
