/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


/* Standard libraries.  */
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

#ifndef LIMITS
#define LIMITS
#include <limits.h>
#endif

#ifndef TIME
#define TIME
#include <time.h>
#endif

#ifndef SYSTIME
#define SYSTIME
#include <sys/time.h>
#endif


/* Function prototypes.  */
void genRandom( int *V, int n );
double insertionSort( int *V, int n );
