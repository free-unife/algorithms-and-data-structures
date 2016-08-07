/*
 * dfs.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined DFS_H
#define DFS_H

#include <assert.h>
#include <stddef.h>
#include "vertex.h"
#include "graph.h"

extern int dFS (Graph g, Vid sId);
#endif
