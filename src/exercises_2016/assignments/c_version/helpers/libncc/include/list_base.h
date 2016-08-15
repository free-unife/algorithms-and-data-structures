/*
 * list_base.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined LIST_BASE_H
#define LIST_BASE_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/* Include test struct header only if necessary. */
#if defined SIMPLE_TEST || defined EXTENDED_TEST
#include "test_struct.h"
#endif

#define EMPTYLIST NULL

typedef elementObject *element;

struct __listNodeObject
{
  element el;
  struct __listNodeObject *next;
};

typedef struct __listNodeObject *__listNode;

/* Interface for the ADT. */
typedef __listNode _node;

extern bool __list_null (__listNode l);
extern void __list_init (__listNode * lRef);
extern element __list_car (__listNode l);
extern __listNode __list_cdr (__listNode l);
extern __listNode __list_cons (element e, __listNode l);

#endif
