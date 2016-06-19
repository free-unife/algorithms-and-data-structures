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
  Vertex first, second;
  VertexListNode aNode, bNode;
  Graph G;

  first = malloc_safe (sizeof (struct VertexObject));
  assert (!element_null (first));
  second = malloc_safe (sizeof (struct VertexObject));
  assert (!element_null (first));

  first->id = 0;
  first->colour = 'w';
  first->distance = 0;
  first->parent = NULL;

  first->id = 1;
  second->colour = 'b';
  second->distance = 3;
  second->parent = first;

  aNode = malloc_safe (sizeof (struct VertexListNodeObject));
  assert (!element_null (aNode));
  bNode = malloc_safe (sizeof (struct VertexListNodeObject));
  assert (!element_null (bNode));

  aNode->v = first;
  aNode->next = bNode;
  aNode->prev = bNode;

  bNode->v = second;
  bNode->next = aNode;
  bNode->prev = aNode;

  G = malloc_safe (sizeof (struct GraphObject));
  assert (!element_null (G));

  G->adjacencyMatrix = NULL;
  G->vl = aNode;

  return 0;
}

#elif defined M_VERTEX_C
int
main (void)
{
  Vertex v = vertex_new (0, 'b', 3, NULL);
  Vertex w = vertex_new (1, 'b', 7, v);

  vertex_print (v);
  vertex_print (w);
  vertex_delete (&v);
  assert (element_null (v));

  return 0;
}

#elif defined M_VERTEXLIST_C
int
main (void)
{

  VertexListNode head =
    vertexlistnode_insert (NULL, vertex_new (9, 'w', 3, NULL));

  assert (!element_null (head));

  vertexlistnode_insert (head, vertex_new (0, 'w', 9, NULL));
  vertexlistnode_insert (head, vertex_new (0, 'w', 5, NULL));
  vertexlistnode_insert (head, vertex_new (0, 'g', 2, NULL));
  vertexlistnode_insert (head, vertex_new (0, 'g', 65, NULL));
  vertexlistnode_insert (head, vertex_new (0, 'g', 653, NULL));
  vertexlistnode_insert (head, vertex_new (0, 'g', 124, NULL));

  vertexlistnode_printlist (head);

  head = vertexlistnode_removeWhites (head);

  vertexlistnode_printlist (head);

  return 0;
}

#elif defined M_GRAPH_C
int
main (void)
{

    Graph G = graph_new (10, 0.75);

    graph_print (G);

  return 0;
}

#endif
