/*
 * test.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "list_base.h"
#include "list_extended.h"
#include "list.h"
#include "libncc.h"
#include "queue.h"
#include "stack.h"
#include "test.h"
#include "utils.h"

#define n TEST_ITERATIONS

#if defined SIMPLE_TEST
static int *array_set (int length);

static int *
array_set (int length)
{
  int i;
  int *arr = malloc_safe (sizeof (int) * length);

  for (i = 0; i < length; i++)
    arr[i] = i;

  return arr;
}

#if defined LIST_BASE_C
int
main (void)
{
  int *aPointer, *bPointer, theSourceZero = 10, theSourceOne = 28;
  __listNode l = NULL;

  aPointer = &theSourceZero;
  l = __list_cons (aPointer, l);

  bPointer = &theSourceOne;
  l = __list_cons (bPointer, l);

  assert (__list_car (l) == bPointer);
  assert (__list_car (__list_cdr (l)) == aPointer);

  /* Dummy. */
  array_set (0);

  return 0;
}


#elif defined LIST_EXTENDED_C
static __listNode fakeList_new (int length, int *arr);
static void fakeList_print (__listNode this);

static __listNode
fakeList_new (int length, int *arr)
{
  int i;
  __listNode this;

  __list_init (&this);
  for (i = 0; i < length; i++)
	this = __list_cons ((arr + i), this);

  return this;
}

static void
fakeList_print (__listNode this)
{
  while (!__list_null (this))
    {
      fprintf (stderr, "%d ", *(__list_car (this)));
      this = __list_cdr (this);
    }
  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  int *arr;
  __listNode this, tmp;

  for (i = 0; i <= n; i++)
    {
      /* Allocation of an int array corresponding to __listNode -> el. */
      arr = array_set (i);

      /* Create a list and remove an element. */
      __list_init (&this);
      this = fakeList_new (i, arr);
      fakeList_print (this);
      assert (__list_length (this) == i);
      if (i >= 2)
	{
	  __list_remove (&this, this);
	  assert (__list_length (this) == i - 1);
	}
      __list_destroy (&this);

      /* State that given a same input, the two generated lists are equal. */
      __list_init (&this);
      __list_init (&tmp);
      this = fakeList_new (i, arr);
      tmp = fakeList_new (i, arr);
      assert (__list_equal (this, tmp));
      __list_destroy (&this);
      __list_destroy (&tmp);

      free (arr);
    }

  return 0;
}

#elif defined STACK_C
static void fakeStack_new (int length, int *arr, _node * sRef);
static void fakeStack_print (_node * this);

static void
fakeStack_new (int length, int *arr, _node * sRef)
{
  int i;

  for (i = 0; i < length; i++)
    _stack_push ((arr + i), sRef);
}

static void
fakeStack_print (_node * this)
{
  while (!_stack_null (*this))
    fprintf (stderr, "%d ", *(_stack_pop (this)));

  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  int *arr;
  _node s;

  for (i = 0; i <= n; i++)
    {
      arr = array_set (i);
      _stack_init (&s);
      fakeStack_new (i, arr, &s);
      fakeStack_print (&s);
      assert (_stack_null (s));

      free (arr);
    }

  return 0;
}

#elif defined QUEUE_C
static void fakeQueue_new (int length, int *arr, _node * qRef);
static void fakeQueue_print (_node * this);

static void
fakeQueue_new (int length, int *arr, _node * qRef)
{
  int i;

  for (i = 0; i < length; i++)
    _queue_enqueue ((arr + i), qRef);
}

static void
fakeQueue_print (_node * this)
{
  while (!_queue_null (*this))
    fprintf (stderr, "%d ", *(_queue_dequeue (this)));

  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  int *arr;
  _node q;

  for (i = 0; i <= n; i++)
    {
      arr = array_set (i);
      _queue_init (&q);
      fakeQueue_new (i, arr, &q);
      fakeQueue_print (&q);
      assert (_queue_null (q));

      free (arr);
    }

  return 0;
}

#elif defined LIST_C
static void fakeList_new (int length, int *arr, _node * lRef);
static void fakeList_print (_node this);

static void
fakeList_new (int length, int *arr, _node * lRef)
{
  int i;

  for (i = 0; i < length; i++)
    {
    _list_prepend ((arr + i), lRef);
    _list_append ((arr + i), lRef);
    }
}

static void
fakeList_print (_node this)
{

  while (!_list_null (this))
  {
    fprintf (stderr, "%d ", *(_list_head (this)));
    this = _list_next (this);
  }

  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  int *arr;
  _node l;

  for (i = 0; i <= n; i++)
    {
      arr = array_set (i);
      _list_init (&l);
      fakeList_new (i, arr, &l);
      fakeList_print (l);

      _list_destroy (&l);

      assert (_list_null (l));

      free (arr);
    }

  return 0;
}

#elif defined API
int
main (void)
{
  int i, j;
  int *arr;
  list l, *lHead;
  stack s;
  queue q;

  for (i = 0; i <= n; i++)
    {
      arr = array_set (i);
      list_init (&l);
      stack_init (&s);
      queue_init (&q);

      for (j = 0; j < i; j++)
	{
	  list_append (arr + j, &l);
	  stack_push (arr + j, &s);
	  queue_enqueue (arr + j, &q);
	}

      assert (list_length (l) == i);
      assert (list_length (s) == i);
      assert (list_length (q) == i);

      lHead = &l;
      for (j = 0; j < i; j++)
	{
	  list_remove (lHead, *lHead);
	  stack_pop (&s);
	  queue_dequeue (&q);
	}

      assert (list_null (l) && stack_null (s) && queue_null (q));

      free (arr);
    }

  return 0;
}

#endif

#elif defined EXTENDED_TEST
static struct VertexObject **array_new (int length);
static void array_clean (struct VertexObject ***vArr, int length);

static struct VertexObject **
array_new (int length)
{

  struct VertexObject **vArr =
    malloc_safe (sizeof (struct VertexObject *) * length);
  char *color;
  int i;

  for (i = 0; i < length; i++)
    {
      vArr[i] = malloc_safe (sizeof (struct VertexObject));
      color = malloc_safe (sizeof (char) * 16);
      vArr[i]->id = i;
      vArr[i]->d = i - 32;
      vArr[i]->f = i * 2;
      ((i % 2) == 0 ? strcpy (color, "WHITE") : strcpy (color, "BLACK"));
      vArr[i]->color = color;
    }

  return vArr;
}

static void
array_clean (struct VertexObject ***vArr, int length)
{
  int i;

  for (i = 0; i < length; i++)
    {
      free ((*vArr)[i]->color);
      free ((*vArr)[i]);
    }

  free (*vArr);
}

#if defined LIST_EXTENDED_C
static __listNode fakeList_new (int length, struct VertexObject **vArr);
static __listNode fakeList_search (__listNode l, char *color);
static void fakeList_print (__listNode this);

static __listNode
fakeList_new (int length, struct VertexObject **vArr)
{
  int i;
  __listNode this;

  __list_init (&this);
  for (i = 0; i < length; i++)
    this = __list_cons (vArr[i], this);

  return this;
}

/* Return a list of all the __listNodes with the input colour. */
static __listNode
fakeList_search (__listNode l, char *color)
{
  __listNode head;

  __list_init (&head);
  while (!__list_null (l))
    {
      if (strcmp (l->el->color, color) == 0)
	head = __list_cons (__list_car (l), head);
      l = __list_cdr (l);
    }

  return head;
}

static void
fakeList_print (__listNode this)
{
  while (!__list_null (this))
    {
      fprintf (stderr, "%d ", (__list_car (this))->id);
      this = __list_cdr (this);
    }
  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  struct VertexObject **vArr;
  __listNode this, that;

  for (i = 0; i <= n; i++)
    {
      vArr = array_new (i);

      __list_init (&this);
      fakeList_print (this);
      __list_init (&that);
      this = fakeList_new (i, vArr);
      that = fakeList_search (this, "WHITE");
      assert ((__list_length (this) == __list_length (that) * 2)
	      || (__list_length (this) == (__list_length (that) * 2) - 1));

      __list_destroy (&that);
      __list_destroy (&this);
      array_clean (&vArr, i);
    }

  return 0;
}
#elif defined STACK_C
static void fakeStack_new (int length, struct VertexObject **vArr,
			   _node * sRef);
static void fakeStack_search (_node * sRef, _node * nRef,
			      char *color);
static void fakeStack_print (_node * sRef);

static void
fakeStack_new (int length, struct VertexObject **vArr, _node * sRef)
{
  int i;

  for (i = 0; i < length; i++)
    _stack_push (vArr[i], sRef);
}

/* Return a list of all the _nodes with the input colour. */
static void
fakeStack_search (_node * sRef, _node * nRef, char *color)
{
  element el;

  while (!_stack_null (*sRef))
    {
      el = _stack_pop (sRef);
      if (strcmp (el->color, color) == 0)
	_stack_push (el, nRef);
    }
}

static void
fakeStack_print (_node * sRef)
{
  element el;

  /* Print all the fields. */
  while (!_stack_null (*sRef))
    {
      el = _stack_pop (sRef);

      fprintf (stderr, "%d ", el->id);
      fprintf (stderr, "%s ", el->color);
      fprintf (stderr, "%d ", el->d);
      fprintf (stderr, "%d ", el->f);
      fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  struct VertexObject **vArr;
  _node s, newStack;

  for (i = 0; i <= n; i++)
    {
      vArr = array_new (i);
      _stack_init (&s);
      _stack_init (&newStack);
      fakeStack_new (i, vArr, &s);
      fakeStack_search (&s, &newStack, "WHITE");
      assert (_stack_null (s));
      assert (__list_length (newStack) <= i);
      fakeStack_print (&newStack);

      array_clean (&vArr, i);
    }

  return 0;
}
#elif defined QUEUE_C
static void fakeQueue_new (int length, struct VertexObject **vArr,
			   _node * qRef);
static void fakeQueue_search (_node * qRef, _node * nRef,
			      char *color);
static void fakeQueue_print (_node * qRef);

static void
fakeQueue_new (int length, struct VertexObject **vArr, _node * qRef)
{
  int i;

  for (i = 0; i < length; i++)
    _queue_enqueue (vArr[i], qRef);
}

/* Return a list of all the _nodes with the input colour. */
static void
fakeQueue_search (_node * qRef, _node * nRef, char *color)
{
  element el;

  while (!_queue_null (*qRef))
    {
      el = _queue_dequeue (qRef);
      if (strcmp (el->color, color) == 0)
	_queue_enqueue (el, nRef);
    }
}

static void
fakeQueue_print (_node * qRef)
{
  element el;

  /* Print all the fields. */
  while (!_queue_null (*qRef))
    {
      el = _queue_dequeue (qRef);

      fprintf (stderr, "%d ", el->id);
      fprintf (stderr, "%s ", el->color);
      fprintf (stderr, "%d ", el->d);
      fprintf (stderr, "%d ", el->f);
      fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
}

int
main (void)
{
  int i;
  struct VertexObject **vArr;
  _node q, newQueue;

  for (i = 0; i <= n; i++)
    {
      vArr = array_new (i);
      _queue_init (&q);
      _queue_init (&newQueue);
      fakeQueue_new (i, vArr, &q);
      fakeQueue_search (&q, &newQueue, "WHITE");
      assert (_queue_null (q));
      assert (__list_length (newQueue) <= i);
      fakeQueue_print (&newQueue);

      array_clean (&vArr, i);
    }

  return 0;
}
#endif

#endif
