/*
 * helper.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined HELPER_H
#define HELPER_H

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "vertex.h"
#include "graph.h"

extern Vertex helper_getRandomSource (Graph g);
extern void helper_genRandomGraph (Graph *gRef, int size, double edgeProb);
extern void helper_setMaxBreadth (Graph g, Vertex s);
extern void helper_setMaxDepth (Graph g);
#endif
