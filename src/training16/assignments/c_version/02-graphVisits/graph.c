/*
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

static unsigned int *adjacencymatrix_new (unsigned int dimension);
static VertexListNode vertexlistnodeset_new (unsigned int numberOfNodes);
static void adjacencymatrix_randomize (Graph g, double vertexConnectionProbability);

/* It is a square matrix so we only need the dimension of one side. */
static unsigned int *adjacencymatrix_new (unsigned int dimension)
{
    unsigned int *new_adjacencymatrix = malloc_safe (dimension * dimension * sizeof (unsigned int));

    return new_adjacencymatrix;
}

/* A graph is a seet of vertices and edges. Here we generate the vertices which
 * by default are all white.
 */
static VertexListNode vertexlistnodeset_new (unsigned int numberOfNodes)
{
    unsigned int i;

    VertexListNode head = vertexlistnode_insert (NULL, vertex_new (0, 'w', 0, NULL));
    for (i = 1; i < numberOfNodes; i++)
        vertexlistnode_insert (head, vertex_new (0, 'w', 0, NULL));

    return head;
}

/* Only set certain elements to 1. */
static void adjacencymatrix_randomize (Graph g, double vertexConnectionProbability)
{
    (void) vertexConnectionProbability;
    unsigned int i, j, flag;
  struct timespec t1;

  clock_gettime (CLOCK_MONOTONIC, &t1);
  srand (t1.tv_nsec);

  for (i = 0; i < g->matrixDimension; i++)
      for (j = 0; j < g->matrixDimension; j++)
      {
          /* flag is either 1 or 0. */
          flag = (unsigned int) rand () % 2;

          g->adjacencyMatrix[(i * g->matrixDimension) + j] = flag;
      }
}

/* eq 0 == connected, ne 0 != connected. */
bool adjacencymatrix_areverticesconnected(Graph g, unsigned int src_id, unsigned int dst_id)
{
    if (g->adjacencyMatrix[(src_id * g->matrixDimension) + dst_id] != 0)
        return true;
    else
        return false;
}

Graph
graph_new (unsigned int numberOfNodes, double vertexConnectionProbability)
{
    /* Gen graph. */
    Graph new_graph = malloc_safe (sizeof (struct GraphObject));

    /* Gen matrix. */
    unsigned int *matrix = adjacencymatrix_new (numberOfNodes);

    /* Gen nodes */
    VertexListNode head = vertexlistnodeset_new (numberOfNodes);

  new_graph -> matrixDimension = numberOfNodes;
  new_graph -> adjacencyMatrix = matrix;
  new_graph -> vln = head;

    adjacencymatrix_randomize (new_graph, vertexConnectionProbability);

  return new_graph;
}

void
graph_print (Graph g)
{
    unsigned int i, j;

    fprintf (stderr, "%p\n====\n", (void *) g);
    vertexlistnode_printlist (g -> vln);

    /* Print the adjacency matrix. */
    for (i = 0; i < g -> matrixDimension; i++)
    {
        for (j = 0; j < g -> matrixDimension; j++)
            fprintf (stderr, "%u ", (g -> adjacencyMatrix)[(i * g -> matrixDimension) + j]);
        fprintf(stderr, "\n");
    }

    fprintf (stderr, "====\n");
}
