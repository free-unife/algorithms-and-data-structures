/*
 * graph.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined GRAPH_H
#define GRAPH_H

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libncc.h"
#include "vertex.h"

#define INF INT_MAX

struct GraphObject
{
    int totalVertices;
    /* list has (struct VertexObject *) elements. */

    /* adjacencies is always |V| long.
     * Each cell of adjacencies points to a list which has (struct VertexObject *) 
     * elements.
     */
    list *adjacencies;

    /* Global vertices list. */
    list vertices;
};

typedef struct GraphObject *Graph;

/* Allocates a GraphObject, its adjacency list and the vertices list in 
 * numberOfVertices number, by giving them default values.
 */
extern Graph graph_new (Graph *gRef, int numberOfVertices);
extern bool graph_setAdjacent (Graph g, Vid from, Vid to);
extern void graph_destroy (Graph *gRef);
extern void graph_destroyVertex (Graph g, Vid id);
extern void graph_print (Graph g);

#endif
