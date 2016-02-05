#include "stack.h"

void pushStack ( element el, stackPointer sp ) {
  cons( el, sp );
}

element popStack ( stackPointer sp ) {
  element el = car( sp );
  nodePointer toDelete = *sp;
  *sp = ( *sp )->next;
  free( toDelete );
  return el;
}


boolean isStackEmpty( stackPointer sp ) {
  return null( sp );
}


/* Initializes the stackPointer to NULL node ( EMPTYLIST )*/
void initStack( stackPointer sp ) {
  initList( sp );
  return;
}


void printStack( stackPointer sp ) {
  printList( sp );
  return;
}


stackPointer freeStack( stackPointer sp ) {
  return freeList( sp );
}
