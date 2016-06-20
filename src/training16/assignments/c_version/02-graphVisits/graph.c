/*
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

static unsigned int *adjmatrix_new (unsigned int dimension);
/*static VertexListNode vertexlistnodeset_new (unsigned int numberOfNodes);*/
static void adjmatrix_randomize (Graph g, double vertexConnectionProbability);

/* It is a square matrix so we only need the dimension of one side. */
static unsigned int *adjmatrix_new (unsigned int dimension)
{
    unsigned int *new_adjMatrix = malloc_safe (dimension * dimension * sizeof (unsigned int));

    return new_adjMatrix;
}

/* Only set certain elements to 1. */
static void adjmatrix_randomize (Graph g, double vertexConnectionProbability)
{
    (void) vertexConnectionProbability;
    unsigned int i, j, flag;
  struct timespec t1;

  clock_gettime (CLOCK_MONOTONIC, &t1);
  srand (t1.tv_nsec);

  for (i = 0; i < g->leadingDimension; i++)
      for (j = 0; j < g->leadingDimension; j++)
      {
          /* flag is either 1 or 0. */
          flag = (unsigned int) rand() % (unsigned int) (vertexConnectionProbability + 1);
          if( flag == 0 ){
           g->adjMatrix[(i * g->leadingDimension) + j] = 1;
          }
          else{
           g->adjMatrix[(i * g->leadingDimension) + j] = 0;
          }
      }
}

/* eq 0 == connected, ne 0 != connected. */
bool adjmatrix_areverticesconnected(Graph g, unsigned int src_id, unsigned int 
dst_id)
{
    if (g->adjMatrix[(src_id * g->leadingDimension) + dst_id] != 0)
        return true;
    else
        return false;
}


nodePointer *vertices_iterate (Graph g)
{
    unsigned int i, j = 0;
    nodePointer *list, *searchRes;
    nodePointer **toReturn;

    list = malloc_safe (g -> leadingDimension * sizeof (nodePointer));

    for (i = 0; i < g -> leadingDimension; i++)
        list[i] = NULL;

    toReturn = &list;

    for (i = 0; i < g -> leadingDimension; i++)
    {
        searchRes = searchForElement (i, g -> head);
        list[j] = searchRes[0];
        j++;
    }

    return *toReturn;
}


nodePointer *vertexlistnode_getneighbors (Graph g, nodePointer vertex)
{
    unsigned int i, j = 0;
    nodePointer *list, *searchRes;
    nodePointer **toReturn;

    list = malloc_safe ((g -> leadingDimension + 1) * sizeof (nodePointer));

    /* Check if the vertex is present in the vertex list. */
    searchRes = searchForElement (vertex -> el, g -> head);
    assert (!element_null (searchRes[0]));

    for (i = 0; i <= g -> leadingDimension; i++)
        list[i] = NULL;

    toReturn = &list;

    for (i = 0; i < g -> leadingDimension; i++)
    {
        if (g ->adjMatrix [ (i * g -> leadingDimension) + vertex -> el] == 1)
        {
            searchRes = searchForElement (i, g -> head);
            list[j] = searchRes[0];
            j++;
        }
    }

    return *toReturn;
}

Graph
graph_new (unsigned int numberOfNodes, double vertexConnectionProbability)
{
    unsigned int i;

    /* Gen graph. */
    Graph new_graph = malloc_safe (sizeof (struct GraphObject));

    /* Gen matrix. */
    unsigned int *matrix =adjmatrix_new (numberOfNodes);

    /* Gen nodes */
    headPointer head = malloc_safe ( sizeof (nodePointer *));
    initDoubleLinkedList (head);

    new_graph -> head = head;

    for (i = 0; i < numberOfNodes; i++)
        insertNodeInQueue (i, "WHITE", NULL, 0, 0, new_graph -> head);

  new_graph -> leadingDimension = numberOfNodes;
  new_graph ->adjMatrix = matrix;

   adjmatrix_randomize (new_graph, vertexConnectionProbability);

  return new_graph;
}

void
graph_print (Graph g)
{
    unsigned int i, j;

    printDoubleLinkedList (g -> head);

    /* Print theadj matrix. */
    for (i = 0; i < g -> leadingDimension; i++)
    {
        for (j = 0; j < g -> leadingDimension; j++)
            fprintf (stderr, "%u ", (g ->adjMatrix)[(i * g -> leadingDimension) + j]);
        fprintf(stderr, "\n");
    }

    fprintf (stderr, "====\n");
}

nodePointer s_getRandomSource (Graph g)
{
    int i = 0, j = 0;
    int listLen = lengthDoubleLinkedList (g -> head);
    int id;
    struct timespec t1;
    nodePointer *vertexArray;

    clock_gettime (CLOCK_MONOTONIC, &t1);
    srand (t1.tv_nsec);

    id = rand() % listLen;

    vertexArray = vertices_iterate (g);
    j = 0;
    for (i = 0; i < listLen; ++i){
        if( i == id){
            return vertexArray[i];
        }
    } 
    return NULL;
}
