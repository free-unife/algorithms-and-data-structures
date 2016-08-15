/*
 * stack.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "list_base.h"
#include "list_extended.h"

bool
_stack_null (_node s)
{
  return (__list_null (s));
}

void
_stack_init (_node * sRef)
{
  __list_init (sRef);
}

element
_stack_pop (_node * sRef)
{
  element e = __list_car (*sRef);

  *sRef = __list_remove (sRef, *sRef);

  return e;
}

void
_stack_push (element e, _node * sRef)
{
  *sRef = __list_cons (e, *sRef);
}
