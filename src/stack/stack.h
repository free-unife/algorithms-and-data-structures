#include "../lists/liste.h"

typedef headPointer stackPointer;

void pushStack ( element el, stackPointer sp);
element popStack ( stackPointer sp );
boolean isStackEmpty( stackPointer sp );
void initStack( stackPointer sp );
void printStack( stackPointer sp );
stackPointer freeStack( stackPointer sp );
