/*
 * list_extended.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "list_base.h"
#include "list_extended.h"
#include "utils.h"

static __listNode __list_gETpREVnODE (__listNode lHead, __listNode nextNode);
static __listNode __list_dESTROY (__listNode * lRef, __listNode l);

int
__list_length (__listNode l)
{
  return (__list_null (l) ? 0 : 1 + __list_length (__list_cdr (l)));
}

/* Equivalence function for two elements. */
bool
__list_same (__listNode l1, __listNode l2)
{
  element e1 = __list_car (l1), e2 = __list_car (l2);

  return (memcmp (e1, e2, sizeof (elementObject)) == 0);
}

bool
__list_equal (__listNode l1, __listNode l2)
{
  return (__list_null (l1) && __list_null (l2) ?
	  true
	  : (__list_null (l1) && !__list_null (l2)) || (!__list_null (l1)
						      && __list_null (l2)) ?
	  false : __list_same (l1, l2) ? __list_equal (__list_cdr (l1),
						     __list_cdr (l2)) : false);
}

/* Given the head of a list and a generic node of that same list, this
 * function finds the previous node of nextNode.
 */
static __listNode
__list_gETpREVnODE (__listNode lHead, __listNode nextNode)
{
  __listNode prevNode = lHead;

  while (!__list_null (__list_cdr (lHead)))
    {
      if (__list_same (__list_cdr (lHead), nextNode))
	prevNode = lHead;

      lHead = __list_cdr (lHead);
    }

  return prevNode;
}

/* Given the head of the list and the node to remove, that node gets removed.
 * This is not a functional language procedure (i.e: it affects the state of
 * other lists if these have shared elements with the input one), so be careful
 * when using it.
 */
__listNode
__list_remove (__listNode * lHeadRef, __listNode toRemove)
{
  __listNode toBeDel;
  __listNode prevNode;

  assert (!element_null (*lHeadRef));
  prevNode = __list_gETpREVnODE (*lHeadRef, toRemove);

  /* If there is only one element in the list and needs to be deleted. */
  if (toRemove == *lHeadRef)
    {
      toBeDel = *lHeadRef;
      *lHeadRef = __list_cdr (*lHeadRef);
    }
  else
    {
      toBeDel = __list_cdr (prevNode);
      prevNode->next = __list_cdr (__list_cdr (prevNode));
    }

  free (toBeDel);
  toBeDel = NULL;

  return *lHeadRef;
}

/* Remove the whole list. This is a wrapper that avoids having two input
 * arguments.
 */
__listNode
__list_destroy (__listNode * lRef)
{
  return (__list_dESTROY (lRef, *lRef));
}

static __listNode
__list_dESTROY (__listNode * lRef, __listNode l)
{
  return (__list_null (l) ? EMPTYLIST
	  : __list_dESTROY (lRef, __list_remove (lRef, l)));
}
