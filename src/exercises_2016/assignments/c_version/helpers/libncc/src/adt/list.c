/*
 * list.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "list_base.h"
#include "list_extended.h"
#include "queue.h"
#include "stack.h"

bool
_list_null (_node l)
{
    return (__list_null (l));
}

void
_list_init (_node * lRef)
{
  __list_init (lRef);
}

void
_list_append (element e, _node *lRef)
{
  _queue_enqueue (e, lRef);
}

void
_list_prepend (element e, _node *lRef)
{
  _stack_push (e, lRef);
}

element
_list_head (_node l)
{
    return (__list_car (l));
}

_node
_list_next (_node l)
{
    return (__list_cdr (l));
}

int
_list_length (_node l)
{
    return (__list_length (l));
}

bool
_list_same (_node l1, _node l2)
{
    return (__list_same (l1, l2));
}

bool
_list_equal (_node l1, _node l2)
{
    return (__list_equal (l1, l2));
}

void
_list_remove (_node *head, _node toRemove)
{
    *head = __list_remove (head, toRemove);
}

void
_list_destroy (_node *lRef)
{
    __list_destroy (lRef);
}
