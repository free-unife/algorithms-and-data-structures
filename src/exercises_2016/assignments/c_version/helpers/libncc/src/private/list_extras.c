/*
 * list_extras.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "list_base.h"

__listNode
__list_copy (__listNode l)
{
  return (__list_null (l) ? EMPTYLIST
	  : __list_cons (__list_car (l), __list_copy (__list_cdr (l))));
}

/* Return a new list with l1 followed by l2. */
__listNode
__list_append (__listNode l1, __listNode l2)
{
  return (__list_null (l1) ? __list_copy (l2)
	  : __list_cons (__list_car (l1), __list_append (__list_cdr (l1), l2)));
}

/* Return a new reversed list of the input one. */
__listNode
__list_reverse (__listNode l)
{
  return (__list_null (l) ? l
	  : __list_append (__list_reverse (__list_cdr (l)),
			  __list_cons (__list_car (l), EMPTYLIST)));
}

/* This function creates a whole new list equal to the original one, plus the
 * new element in the tail. To avoid memory leaks, please assign the new list
 * to a new variable, and then destroy the old list.
 */
#if defined RECURSIVE_VERSION
__listNode
__list_tailCons (element e, __listNode l)
{
  return (__list_null (l) ? __list_cons (e, EMPTYLIST)
	  : __list_cons (__list_car (l), __list_tailCons (e, __list_cdr (l))));
}

#else
__listNode
__list_tailCons (element e, __listNode l)
{
  __listNode head = l, tmp;

  if (__list_null (l))
    head = __list_cons (e, EMPTYLIST);
  else
    {
      while (!__list_null (__list_cdr (l)))
	l = __list_cdr (l);

      tmp = __list_cons (e, EMPTYLIST);
      l->next = tmp;
    }

  return head;
}
#endif

