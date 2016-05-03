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

#elif defined M_ADT_C
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

#endif
