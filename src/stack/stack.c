#include "stack.h"

stack * push ( element el, stack * head ) {
  return( cons( el, head ) );
}

element pop ( stack * head ){
  element e = car( head );
  
  *head = *(cdr( head ))
  car( head );
  return e;
}

boolean isStackEmpty( stack * head ) {
  return null( head );
}

stack * initStack( element el ){
  return makeList( element el );
}
