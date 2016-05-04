/*
 * @file utils.c
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

static char ht_type (ht hashTable);
static unsigned int ht_numofslots (ht hashTable);
static nodePtr *ht_ptr (ht hashTable);
/* This is also known as the hash function. */
static unsigned int slotid_get (char *input, ht hashTable);
static nodePtr slot_get (ht hashTable, char *key);
static void HTFreeStruct (ht * hashTablePtr);

static char
ht_type (ht hashTable)
{
  assert (!element_null (hashTable));
  return (hashTable->type);
}

static unsigned int
ht_numofslots (ht hashTable)
{
  assert (!element_null (hashTable));
  return (hashTable->numberOfSlots);
}

static nodePtr *
ht_ptr (ht hashTable)
{
  assert (!element_null (hashTable));
  return (hashTable->ptr);
}

/* http://www.cse.yorku.ca/~oz/hash.html djb2
 * The slot id is returned.
 * Output is unsigned because we have buckets from 0 to M - 1.
 */
static unsigned int
slotid_get (char *input, ht hashTable)
{
  unsigned int key = 5381, i;

  i = 0;
  while (input[i] != '\0')
    {
      key = (key << 5) + key + ((unsigned int) input[i]);
      i++;
    }

  return (key % ht_numofslots (hashTable));
}

static nodePtr
slot_get (ht hashTable, char *key)
{
  return ((ht_ptr (hashTable))[slotid_get (key, hashTable)]);
}

static void
HTFreeStruct (ht * hashTablePtr)
{
  /* Clear the structure. */
  (*hashTablePtr)->numberOfSlots = 0;
  (*hashTablePtr)->ptr = NULL;
  (*hashTablePtr)->type = '\0';

  free (*hashTablePtr);

  /* Avoid dangling reference. */
  *hashTablePtr = NULL;
}

ht
HTInit (unsigned int numberOfSlots, char type)
{
  int i;
  ht hashTable;

  hashTable = malloc_safe (sizeof (struct HashTable));
  hashTable->ptr = malloc_safe (sizeof (nodePtr) * numberOfSlots);
  hashTable->numberOfSlots = numberOfSlots;
  hashTable->type = type;

  assert ((type == 'b') || (type == 'l'));

  for (i = 0; i < (int) numberOfSlots; i++)
    (hashTable->ptr)[i] = NULL;

  return hashTable;
}

bool
HTInsert (ht hashTable, char *key, char *value)
{
  /* If the slot is empty -> allocate a new node pointer. */
  if (element_null (slot_get (hashTable, key)))
    (hashTable->ptr)[slotid_get (key, hashTable)] = nodeptr_new ();

  if (ht_type (hashTable) == 'b')
    return (!node_null (BSTInsert (slot_get (hashTable, key), key, value)));
  else
    return false;
}

node
HTSearch (ht hashTable, char *key)
{
  /* If the slot is empty -> allocate a new node pointer. */
  if (element_null (slot_get (hashTable, key)))
    return NULL;

  if (ht_type (hashTable) == 'b')
    return (BSTSearch (*(slot_get (hashTable, key)), key));
  else
    return NULL;
}

bool
HTDelete (ht hashTable, char *key)
{
  if (ht_type (hashTable) == 'b')
    return (BSTDelete (slot_get (hashTable, key), key));
  else
    return false;
}

bool
HTClear (ht * hashTablePtr)
{
  int i = 0;

  for (i = 0; i < (int) ht_numofslots (*hashTablePtr); i++)
    {
      if (!element_null (((*hashTablePtr)->ptr[i])))
	{
	  if (ht_type (*hashTablePtr) == 'b')
	    {
	      if (!node_null (BSTClear (*(((*hashTablePtr)->ptr)[i]))))
		return false;
	    }
	  else
	    {
	    }
	}
    }

  HTFreeStruct (hashTablePtr);

  return true;
}

void
HTPrint (ht hashTable)
{
  int i;

  assert (!element_null (hashTable));

  for (i = 0; i < (int) ht_numofslots (hashTable); i++)
    {
      if (!element_null ((hashTable->ptr)[i]))
	{
	  if (ht_type (hashTable) == 'b')
	    BSTPrint (*((hashTable->ptr)[i]));
	  else
	    fprintf (stderr, "exit\n");
	}
    }
}
