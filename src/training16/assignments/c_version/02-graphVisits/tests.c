/*
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

#if defined M_UTILS_C
int
main (void)
{
  int *a = NULL;

  assert (element_null (a));

  a = malloc_safe (sizeof (int) * 10);
  assert (!element_null (a));

  return 0;
}

#elif defined M_POC_C
int
main (void)
{
  Graph G;
  headPointer head = malloc( sizeof( nodePointer * ) );

  G = malloc_safe (sizeof (struct GraphObject));
  assert (!element_null (G));

  G->adjMatrix = NULL;
  G->head = head;

  return 0;
}

#elif defined M_GRAPH_C
int
main (void)
{
    unsigned int i = 0;
    Graph G = graph_new (10, 4);

    nodePointer *searchResult = searchForElement(5, G -> head);
    nodePointer *listOfNeigh= vertexlistnode_getneighbors (G, searchResult[0]);

    for (i = 0; i < G -> leadingDimension; i++)
        fprintf (stderr, "%u\n", listOfNeigh[i] -> el);

    graph_print (G);

/*    vertexlistnode_getneighbors (G, G -> vln -> v);*/

  return 0;
}

#endif
