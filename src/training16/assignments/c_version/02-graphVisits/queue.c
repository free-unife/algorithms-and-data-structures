/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#include "globalDefines.h"

void initQueue( first f, last l )
{
initSQ( f );
initSQ( l );
return;
}


boolean isQueueEmpty( first f )
{
return nullSQ( f );
}


void insertQueue( nodePointer el, first f, last l )
{
tailConsSQ( el, l );
if ( isQueueEmpty( f ) )
*f = *l;
else
*l = ( *l )->next;

return;
}


nodePointer extractQueue( first f )
{
nodePointer el = carSQ( f );
nodePointerSQ toDelete = *f;
*f = ( *f )->next;
free( toDelete );
return el;
}


void printQueue( first f )
{
printAllSQ( f );
return;
}


first freeQueue( first f )
{
return freeAllSQ( f );
}

int lenQueue( first f )
{
    return lengthSQ( f );
}
