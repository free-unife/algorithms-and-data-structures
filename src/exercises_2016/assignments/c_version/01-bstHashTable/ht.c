/**
 * @file ht.c
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Hash table functions.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

/**
 * @brief Get the type of hash table.
 *
 * @param[in] hashTable A pointer to the hash table.
 *
 * @retval hashTable->type 'b' = BST, 'l' = LIST.
 */
static char HTType (ht hashTable);

/**
 * @brief Get the number of slots of the hash table.
 *
 * @param[in] hashTable A pointer to the hash table.
 *
 * @retval hashTable->numberOfSlots
 */
static unsigned int HTNumOfSlots (ht hashTable);

/**
 * @brief Get the pointer corresponding to the array of slots (i.e: the array
 * of nodePtr)
 *
 * @param[in] hashTable A pointer to the hash table.
 *
 * @retval hashTable->ptr
 *
 * @warning The return value can be NULL.
 */
static nodePtr *HTPtr (ht hashTable);

/**
 * @brief Get the slot number for a given string. This is also known as the
 * hash function.
 *
 * @param[in] input A pointer to the string that needs to be hashed.
 * @param[in] hashTable A pointer to the hash table.
 *
 * @retval key%HTNumOfSlots(hashTable)
 */
static unsigned int slotid_get (char *input, ht hashTable);

/**
 * @brief Get the first nodePtr of the slot corresponding to the input key.
 *
 * @param[in] hashTable A pointer to the hash table.
 * @param[in] key A pointer to the key.
 *
 * @retval (HTPtr(hashTable))[slotid_get(key,hashTable)]
 *
 * @warning The return value can be NULL.
 */
static nodePtr slot_get (ht hashTable, char *key);

/**
 * @brief Delete the struct (and its members) corresponding to the input hash
 * table.
 *
 * @param[in] hashTable A pointer to the memory address of the hash table.
 */
static void HTFreeStruct (ht * hashTablePtr);

static char
HTType (ht hashTable)
{
  assert (!element_null (hashTable));
  return (hashTable->type);
}

static unsigned int
HTNumOfSlots (ht hashTable)
{
  assert (!element_null (hashTable));
  return (hashTable->numberOfSlots);
}

static nodePtr *
HTPtr (ht hashTable)
{
  assert (!element_null (hashTable));
  return (hashTable->ptr);
}

/* http://www.cse.yorku.ca/~oz/hash.html djb2
 * The slot id is returned.
 * Output is unsigned because we have buckets from 0 to M - 1.
 * This is also known as the hash function.
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

  return (key % HTNumOfSlots (hashTable));
}

static nodePtr
slot_get (ht hashTable, char *key)
{
  return ((HTPtr (hashTable))[slotid_get (key, hashTable)]);
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

  /* Set every slot to NULL. */
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

  if (HTType (hashTable) == 'b')
    return (!node_null (BSTInsert (slot_get (hashTable, key), key, value)));
  else
    return (!node_null (LISTInsert (slot_get (hashTable, key), key, value)));
}

node
HTSearch (ht hashTable, char *key)
{
  if (element_null (slot_get (hashTable, key)))
    return NULL;

  if (HTType (hashTable) == 'b')
    return (BSTSearch (*(slot_get (hashTable, key)), key));
  else
    return (LISTSearch (*(slot_get (hashTable, key)), key));
}

bool
HTDelete (ht hashTable, char *key)
{
  if (element_null (slot_get (hashTable, key)))
    return false;

  if (HTType (hashTable) == 'b')
    return (BSTDelete (slot_get (hashTable, key), key));
  else
    return (LISTDelete (slot_get (hashTable, key), key));
}

bool
HTClear (ht * hashTablePtr)
{
  int i = 0;

  if (HTType (*hashTablePtr) == 'b')
    {
      for (i = 0; i < (int) HTNumOfSlots (*hashTablePtr); i++)
	if (!element_null (((*hashTablePtr)->ptr[i])))
	  if (!node_null (BSTClear (*(((*hashTablePtr)->ptr)[i]))))
	    return false;
    }
  else
    {
      for (i = 0; i < (int) HTNumOfSlots (*hashTablePtr); i++)
	if (!element_null (((*hashTablePtr)->ptr[i])))
	  if (!node_null (LISTClear (*(((*hashTablePtr)->ptr)[i]))))
	    return false;
    }

  HTFreeStruct (hashTablePtr);

  return true;
}

void
HTPrint (ht hashTable)
{
  int i;

  assert (!element_null (hashTable));

  if (HTType (hashTable) == 'b')
    {
      for (i = 0; i < (int) HTNumOfSlots (hashTable); i++)
	if (!element_null ((hashTable->ptr)[i]))
	  BSTPrint (*((hashTable->ptr)[i]));
    }
  else
    {
      for (i = 0; i < (int) HTNumOfSlots (hashTable); i++)
	if (!element_null ((hashTable->ptr)[i]))
	  LISTPrint (*((hashTable->ptr)[i]));
    }
}
