/*
 * helper.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "vertex.h"
#include "libncc.h"
#include "utils.h"
#include "graph.h"
#include "helper.h"

Vertex
helper_getRandomSource (Graph g)
{
    Vertex v;
    list vertices = g->vertices;
    struct timespec t1;

    assert (!element_null (g));
    clock_gettime (CLOCK_MONOTONIC, &t1);
    srand (t1.tv_nsec);

    /* Loop until v is a valid vertex. */
    v = vertex_getFromId (vertices, rand () % list_length (vertices));
    while (element_null (v))
        v = vertex_getFromId (vertices, rand () % list_length (vertices));

    return v;
}

void
helper_genRandomGraph (Graph *gRef, int size, double edgeProb)
{
    int i, j;
    struct timespec t1;

    assert (size > 0 && edgeProb >= 0 && edgeProb <= 1);
    graph_new (gRef, size);

    clock_gettime (CLOCK_MONOTONIC, &t1);
    srand (t1.tv_nsec);

    /* Set random adjacencies.
     * We can set up to |V|^2 adjacencies.
     * http://stackoverflow.com/questions/20171901/how-to-generate-random-graphs?answertab=votes#tab-top
     * edgeProb is compared with a random number between 0 and 1.
     */
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            if (edgeProb > ((double) rand() / (double) RAND_MAX))
                graph_setAdjacent (*gRef, i, j);
}
