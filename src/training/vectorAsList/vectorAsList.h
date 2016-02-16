/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif

#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

#ifndef ASSERT
#define ASSERT
#include <assert.h>
#endif

typedef int element;

struct list {
    element el;
    struct list *next;
};

typedef struct list *node;
typedef node *vector;

vector createEmptyVector( void );

vector createInitializedVector( int numEl, element e );

int vectorLength( vector v );

element getElementValue( vector v, int index );

vector setElementValue( vector v, int index, element val );

vector tailExtendVector( vector v, element e );

vector tailTrimVector( vector v );

vector insertElement( vector v, int index, element e );

vector removeElement( vector v, int index );
