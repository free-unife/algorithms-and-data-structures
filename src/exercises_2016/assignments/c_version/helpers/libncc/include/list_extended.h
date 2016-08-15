/*
 * list_extended.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined LIST_EXTENDED_H
#define LIST_EXTENDED_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

extern __listNode __list_append (__listNode l1, __listNode l2);
extern __listNode __list_copy (__listNode l);
extern __listNode __list_reverse (__listNode l);
extern int __list_length (__listNode l);
extern __listNode __list_tailCons (element e, __listNode l);
extern bool __list_same (__listNode l1, __listNode l2);
extern bool __list_equal (__listNode l1, __listNode l2);
extern __listNode __list_remove (__listNode * lHeadRef, __listNode toRemove);
extern __listNode __list_destroy (__listNode * lRef);
#endif
