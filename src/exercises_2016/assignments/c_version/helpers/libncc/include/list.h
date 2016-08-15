/*
 * list.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined LIST_H
#define LIST_H

#include <stdbool.h>

bool _list_null (_node l);
void _list_init (_node *lRef);
void _list_append (element e, _node *lRef);
void _list_prepend (element e, _node *lRef);
element _list_head (_node l);
_node _list_next (_node l);
int _list_length (_node l);
bool _list_same (_node l1, _node l2);
bool _list_equal (_node l1, _node l2);
void _list_remove (_node *head, _node toRemove);
void _list_destroy (_node *lRef);

#endif
