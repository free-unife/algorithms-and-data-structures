/*
 * @file tests.c
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Tests file.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
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

#elif defined M_NODE_C
int
main (void)
{
  node first, second, third;

  first = node_new ("01", "hallo", 'l');
  second = node_new ("02", "hi", 'l');
  third = node_new ("03", "halala", 'l');

  assert (!element_null (first) && !element_null (second) && !element_null
	  (third));
  fprintf (stderr, "%s %s %s\n", key_get (first), key_get
	   (second), key_get (third));
  fprintf (stderr, "%s %s %s\n", value_get (first), value_get
	   (second), value_get (third));

  return 0;
}

#elif defined M_BST_C
int
main (void)
{
  nodePtr rootRef;

  rootRef = nodeptr_new ();

  assert (!node_null (BSTInsert (rootRef, "01", "hallo"))
	  && !node_null (BSTInsert (rootRef, "02", "hohoho"))
	  && !node_null (BSTInsert (rootRef, "00", "ciao"))
	  && !node_null (BSTInsert (rootRef, "04", "hi"))
	  && !node_null (BSTInsert (rootRef, "03", "hola"))
	  && !node_null (BSTInsert (rootRef, "05", "bonjour"))
	  && node_null (BSTInsert (rootRef, "02", "bonjour")));

  BSTPrint (*rootRef);

  assert (!node_null (BSTSearch (*rootRef, "05"))
	  && !node_null (BSTSearch (*rootRef, "03"))
	  && !node_null (BSTSearch (*rootRef, "04"))
	  && !node_null (BSTSearch (*rootRef, "00"))
	  && !node_null (BSTSearch (*rootRef, "02"))
	  && !node_null (BSTSearch (*rootRef, "01"))
	  && node_null (BSTSearch (*rootRef, "10")));

  assert (BSTIs (*rootRef, "00", "99"));

  assert (BSTDelete (rootRef, "05")
	  && BSTDelete (rootRef, "03")
	  && BSTDelete (rootRef, "04")
	  && BSTDelete (rootRef, "00")
	  && BSTDelete (rootRef, "02")
	  && BSTDelete (rootRef, "01")
	  && !BSTDelete (rootRef, "10") && node_null (*rootRef));

  assert (!BSTDelete
	  (rootRef,
	   "bst is now empty and you cannot delete an empty entity"));

  assert (!node_null (BSTInsert (rootRef, "01", "hallo"))
	  && !node_null (BSTInsert (rootRef, "02", "hohoho"))
	  && !node_null (BSTInsert (rootRef, "00", "ciao"))
	  && !node_null (BSTInsert (rootRef, "04", "hi"))
	  && !node_null (BSTInsert (rootRef, "03", "hola"))
	  && !node_null (BSTInsert (rootRef, "05", "bonjour"))
	  && node_null (BSTInsert (rootRef, "02", "bonjour")));

  assert (BSTIs (*rootRef, "00", "99"));

  assert (node_null (BSTClear (*rootRef)));

  return 0;
}

#elif defined M_LIST_C
int
main (void)
{
  nodePtr headRef;

  headRef = nodeptr_new ();

  assert (!node_null (LISTInsert (headRef, "01", "hallo"))
	  && !node_null (LISTInsert (headRef, "02", "hohoho"))
	  && !node_null (LISTInsert (headRef, "00", "ciao"))
	  && !node_null (LISTInsert (headRef, "04", "hi"))
	  && !node_null (LISTInsert (headRef, "03", "hola"))
	  && !node_null (LISTInsert (headRef, "05", "bonjour"))
	  && node_null (LISTInsert (headRef, "02", "bonjour")));

  LISTPrint (*headRef);

  assert (!node_null (LISTSearch (*headRef, "05"))
	  && !node_null (LISTSearch (*headRef, "03"))
	  && !node_null (LISTSearch (*headRef, "04"))
	  && !node_null (LISTSearch (*headRef, "00"))
	  && !node_null (LISTSearch (*headRef, "02"))
	  && !node_null (LISTSearch (*headRef, "01"))
	  && node_null (LISTSearch (*headRef, "10")));

  assert (LISTDelete (headRef, "05")
	  && LISTDelete (headRef, "03")
	  && LISTDelete (headRef, "04")
	  && LISTDelete (headRef, "00")
	  && LISTDelete (headRef, "02")
	  && LISTDelete (headRef, "01")
	  && !LISTDelete (headRef, "10") && node_null (*headRef));

  assert (!LISTDelete
	  (headRef,
	   "LIST is now empty and you cannot delete an empty entity"));

  assert (!node_null (LISTInsert (headRef, "01", "hallo"))
	  && !node_null (LISTInsert (headRef, "02", "hohoho"))
	  && !node_null (LISTInsert (headRef, "00", "ciao"))
	  && !node_null (LISTInsert (headRef, "04", "hi"))
	  && !node_null (LISTInsert (headRef, "03", "hola"))
	  && !node_null (LISTInsert (headRef, "05", "bonjour"))
	  && node_null (LISTInsert (headRef, "02", "bonjour")));

  assert (node_null (LISTClear (*headRef)));

  return 0;
}

#elif defined M_HT_C
int
main (void)
{
  ht hashTableBst, hashTableList;
  char **keys;
  int i, iterations = 2048;

  hashTableBst = HTInit (997, 'b');
  hashTableList = HTInit (997, 'l');

  keys = malloc_safe (sizeof (char *) * iterations);
  for (i = 0; i < iterations; i++)
    {
      keys[i] = malloc_safe (sizeof (char) * 256);
      sprintf (keys[i], "%d", i);
      assert (HTInsert (hashTableBst, keys[i], keys[i]));
      assert (HTInsert (hashTableList, keys[i], keys[i]));
    }

  assert (keys_equal (key_get (HTSearch (hashTableBst, "123")), "123"));
  assert (keys_equal (key_get (HTSearch (hashTableList, "123")), "123"));

  HTPrint (hashTableBst);
  HTPrint (hashTableList);

  assert (HTDelete (hashTableBst, "0"));
  assert (HTDelete (hashTableBst, "1"));
  assert (!HTDelete (hashTableBst, "0"));
  assert (!HTDelete (hashTableBst, "1"));
  assert (HTDelete (hashTableList, "0"));
  assert (HTDelete (hashTableList, "1"));
  assert (!HTDelete (hashTableList, "0"));
  assert (!HTDelete (hashTableList, "1"));

  assert (HTClear (&hashTableBst));
  assert (HTClear (&hashTableList));

  return 0;
}

#endif
