/*
 * libncc.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined LIBNCC_H
#define LIBNCC_H

#define ISOC99_SOURCE
#define _POSIX_C_SOURCE 199309L
#if __STDC_VERSION__ != 199901L
#error "ANSI C99 not available"
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list_base.h"
#include "list_extended.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

typedef _node list;
typedef _node stack;
typedef _node queue;

extern bool list_null (list l);
extern void list_init (list *lRef);
extern void list_append (element e, list *lRef);
extern void list_prepend (element e, list *lRef);
extern element list_head (list l);
extern list list_next (list l);
extern int list_length (list l);
extern bool list_same (list l1, list l2);
extern bool list_equal (list l1, list l2);
extern void list_remove (list *head, list toRemove);
extern void list_destroy (list *lRef);
extern bool stack_null (stack s);
extern void stack_init (stack * sRef);
extern element stack_pop (stack * sRef);
extern void stack_push (element e, stack * sRef);
extern int stack_length (stack s);
extern bool queue_null (queue q);
extern void queue_init (queue * qRef);
extern element queue_dequeue (queue * qRef);
extern void queue_enqueue (element e, queue * qRef);
extern int queue_length (queue q);

#endif
