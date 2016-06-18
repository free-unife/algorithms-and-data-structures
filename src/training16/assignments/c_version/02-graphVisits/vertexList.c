/*
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

/* Create a new node for the vertex list. */
VertexListNode
vertexlistnode_new (Vertex connectedVertex, VertexListNode prev,
		    VertexListNode next)
{
  VertexListNode new_vertexlistnode =
    malloc_safe (sizeof (struct VertexListNodeObject));

  new_vertexlistnode->v = connectedVertex;
  new_vertexlistnode->next = next;
  new_vertexlistnode->prev = prev;

  return new_vertexlistnode;
}

void
vertexlistnode_print (VertexListNode vln)
{
  vertex_print (vln->v);
  fprintf (stderr, "%p\n", (void *) vln);
  fprintf (stderr, "%p:%p\n", (void *) vln->prev, (void *) vln->next);
}

void
vertexlistnode_delete (VertexListNode * vlnRef)
{
  vertex_delete (&((*vlnRef)->v));
  free (*vlnRef);
  *vlnRef = NULL;
}

/* Always return the head. */
VertexListNode
vertexlistnode_insert (VertexListNode head, Vertex toBeIns)
{
  unsigned int counter = 0;
  VertexListNode this, current;

  /* No head. */
  if (element_null (head))
    {
      head = vertexlistnode_new (toBeIns, NULL, NULL);
      toBeIns->id = counter;
    }
  else
    {
      this = head;
      counter = 1;
      while (!element_null (this->next))
	{
	  this = this->next;
	  counter++;
	}

      current = vertexlistnode_new (toBeIns, this, NULL);
      this->next = current;
      toBeIns->id = counter;
    }

  return head;
}

/* Our delete criteria is the colour of the vertex. In particular we need to
 * delete white vertices.
 */
VertexListNode
vertexlistnode_removeWhites (VertexListNode head)
{
  VertexListNode this = head, thisn;

  while (!element_null (this))
    {
      if ((this->v)->colour == 'w')
	{
	  fprintf (stderr, "Remove this %p\n", (void *) this);

	  if (element_null (this->prev))
	    {
	      head = this->next;
	      vertexlistnode_delete (&this);
	      head->prev = NULL;
	      this = head;
	    }
	  else if (element_null (this->next))
	    {
	      (this->prev)->next = NULL;
	      vertexlistnode_delete (&this);
	    }
	  else
	    {
	      thisn = this->next;
	      (this->prev)->next = this->next;
	      (this->next)->prev = this->prev;
	      vertexlistnode_delete (&this);
	      this = thisn;
	    }
	}
      else
	this = this->next;
    }

  return head;
}

void
vertexlistnode_printlist (VertexListNode head)
{
  VertexListNode this = head;

  while (!element_null (this))
    {
      vertexlistnode_print (this);
      fprintf (stderr, "\n");
      this = this->next;
    }
}
