/*
 * queue.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "list_base.h"
#include "list_extended.h"
#include "list_extras.h"

bool
_queue_null (_node q)
{
  return (__list_null (q));
}

void
_queue_init (_node * qRef)
{
  __list_init (qRef);
}

element
_queue_dequeue (_node * qRef)
{
  element e = __list_car (*qRef);

  *qRef = __list_remove (qRef, *qRef);

  return e;
}

void
_queue_enqueue (element e, _node * qRef)
{
  *qRef = __list_tailCons (e, *qRef);
}

