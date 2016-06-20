/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "../adtSQ/adtSQ.h"

typedef pointerToNodeSQ nodePointerSQ;
typedef referenceToNodePointerSQ stackPointer;

void pushStack( nodePointer el, stackPointer sp );
nodePointer popStack( stackPointer sp );
boolean isStackEmpty( stackPointer sp );
void initStack( stackPointer sp );
void printStack( stackPointer sp );
stackPointer freeStack( stackPointer sp );
