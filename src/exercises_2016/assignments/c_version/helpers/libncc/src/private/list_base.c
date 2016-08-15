/*
 * list_base.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "utils.h"
#include "list_base.h"

bool
__list_null (__listNode l)
{
  return (l == EMPTYLIST);
}

void
__list_init (__listNode * lRef)
{
  *lRef = EMPTYLIST;
}

element
__list_car (__listNode l)
{
  assert (!__list_null (l));
  return l->el;
}

__listNode
__list_cdr (__listNode l)
{
  assert (!__list_null (l));
  return l->next;
}

__listNode
__list_cons (element e, __listNode l)
{
  __listNode n = malloc_safe (sizeof (struct __listNodeObject));

  n->el = e;
  n->next = l;

  return n;
}
