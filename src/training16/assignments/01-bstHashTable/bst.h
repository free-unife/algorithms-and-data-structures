/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


/* Standard libraries.  */
#ifndef M_STDLIB_H
#define M_STDLIB_H
#include <stdlib.h>
#endif

#ifndef M_STDIO_H
#define M_STDIO_H
#include <stdio.h>
#endif

#ifndef M_ASSERT_H
#define M_ASSERT_H
#include <assert.h>
#endif

#ifndef M_LIMITS_H
#define M_LIMITS_H
#include <limits.h>
#endif

#ifndef M_TIME_H
#define M_TIME_H
#include <time.h>
#endif

#ifndef M_SYSTIME_H
#define M_SYSTIME_H
#include <sys/time.h>
#endif

#ifndef M_STRING_H
#define M_STRING_H
#include <string.h>
#endif

#ifndef M_MATH_H
#define M_MATH_H
#include <math.h>
#endif

#ifndef M_GLOBALDEFINES_H
#define M_GLOBALDEFINES_H
#include "../globalDefines.h"
#endif


struct node {
  char *key;
  char *value;
  struct node *left;
  struct node *right;
  struct node *parent;
}

typedef struct node * pointerToNode;
typedef pointerToNode bst;

pointerToNode insert(char *key, char *value, bst root);
/*
pointerToNode search(char *key, bst root);
boolean delete(char *key, bst root);
boolean isBST(bst root);
*/
