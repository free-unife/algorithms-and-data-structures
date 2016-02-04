#include "../lists/liste.h"

typedef list stack;

stack * push ( element el, stack * head );
element pop ( stack * head );
boolean isStackEmpty( stack * head );
stack * initStack( element el );
