/*
 * @file adt.c
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Header file containing exportable methods.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

bool
node_null (node n)
{
  return (n == NULL);
}

char *
key_get (node n)
{
  return (node_null (n) ? NULL : n->key);
}

bool
key_set (node n, char *key)
{
  if (node_null (n))
    return false;
  else
    {
      n->key = key;
      return true;
    }
}

char *
value_get (node n)
{
  return (node_null (n) ? NULL : n->value);
}

bool
value_set (node n, char *value)
{
  if (node_null (n))
    return false;
  else
    {
      n->value = value;
      return true;
    }
}

bool
keys_equal (char *key1, char *key2)
{
  assert ((key1 != NULL) && (key2 != NULL));
  return ((strcmp (key1, key2) == 0) ? true : false);
}

bool
keys_less (char *key1, char *key2)
{
  assert ((key1 != NULL) && (key2 != NULL));
  return ((strcmp (key1, key2) < 0) ? true : false);
}

bool
keys_greater (char *key1, char *key2)
{
  assert ((key1 != NULL) && (key2 != NULL));
  return ((strcmp (key1, key2) > 0) ? true : false);
}


node
node_new (char *key, char *value, char type)
{
  node new_node;
  struct listNode *l;
  struct bstNode *b;

  new_node = malloc_safe (sizeof (struct Node));

  /* BST */
  if (type == 'b')
    {
      b = malloc_safe (sizeof (struct bstNode));
      new_node->ln = NULL;
      new_node->bn = b;
    }
  /* LIST */
  else
    {
      l = malloc_safe (sizeof (struct listNode));
      new_node->ln = l;
      new_node->bn = NULL;
    }

  /* Copy the content instead of the pointer. */
  new_node->key = malloc_safe (sizeof (char) * (strlen (key) + 1));
  new_node->value = malloc_safe (sizeof (char) * (strlen (value) + 1));
  new_node->key[strlen (key)] = '\0';
  new_node->value[strlen (value)] = '\0';

  strcpy (new_node->key, key);
  strcpy (new_node->value, value);

  return new_node;
}


void
node_delete (nodePtr nPtr, char type)
{
  if (element_null (nPtr) || node_null (*nPtr))
    return;

  if (type == 'b')
    free ((*nPtr)->bn);
  else
    free ((*nPtr)->ln);

  free (key_get (*nPtr));
  free (value_get (*nPtr));
  (*nPtr)->key = NULL;
  (*nPtr)->value = NULL;

  free (*nPtr);
  *nPtr = NULL;
}

nodePtr
nodeptr_new (void)
{
  nodePtr npt;

  npt = malloc_safe (sizeof (node));
  if (element_null (npt))
    return NULL;

  *npt = NULL;

  return npt;
}
