/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "stack.h"

void pushStack( nodePointer el, stackPointer sp )
{
    cons( el, sp );
}

nodePointer popStack( stackPointer sp )
{
    nodePointer el = car( sp );
    nodePointerSQ toDelete = *sp;
    *sp = ( *sp )->next;
    free( toDelete );
    return el;
}


boolean isStackEmpty( stackPointer sp )
{
    return null( sp );
}


/* Initializes the stackPointer to NULL node ( EMPTYLIST )*/
void initStack( stackPointer sp )
{
    init( sp );
    return;
}


void printStack( stackPointer sp )
{
    printAll( sp );
    return;
}


stackPointer freeStack( stackPointer sp )
{
    return freeAll( sp );
}
