/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "../adt/adt.h"

typedef pointerToNode nodePointer;
typedef referenceToNodePointer first;
typedef referenceToNodePointer last;

void insertQueue ( element el, first f, last l );
element extractQueue ( first f );
boolean isQueueEmpty( first f );
void initQueue( first f, last l );
void printQueue( first f );
first freeQueue( first f );
