/**
 * @file main.c
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Implementation file.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

#define M 251
#define KEYCHARMIN 33
#define KEYCHARMAX 126
#define ATTEMPTS 101
#define KEYLENGTH 4

/* miss variables are only referred to the list hash table, since the bst
 * hash table would obtain the same results. */
static double insMiss = 0.0;
static double srcMiss = 0.0;
static double delMiss = 0.0;
static double insSucc = 0.0;

static double runningtime_get (clock_t start, clock_t end);
static char *randomstring_new (int len);
static double *numbersfromprobability_get (int totalOperations,
					   double insProb, double srcProb,
					   double delProb);
static void array_shuffle (char *array, int len);
static bool isInsertAction (char action);
static bool isSearchAction (char action);
static double operations (ht hashTable, char **keys, char *actions,
			  int totalOperations);
static char **keys_new (int quantity, int length);
static void keys_delete (int quantity, char ***keysPtr);

/**
 * @brief Generate an array with each cell containing either 'i' or 's' or 'd'
 * respectively for insert, search and delete operations.
 */
static char *actions_get (int insElements, int srcElements, int delElements);

static double
runningtime_get (clock_t start, clock_t end)
{
  return ((double) ((double) (end - start) / (double) CLOCKS_PER_SEC));
}

static char *
randomstring_new (int len)
{
  int i;
  char *str;
  struct timespec t1;

  str = malloc_safe (sizeof (char) * (len + 1));
  str[len] = '\0';

  /*
   * Seed is set in nanoseconds.
   */
  clock_gettime (CLOCK_MONOTONIC, &t1);
  srand (t1.tv_nsec);

  for (i = 0; i < len; i++)
    {
      /*
       * Strings are len charaters long and each charater is in the domain
       * [KEYCHARMIN - KEYCHARMAX].
       */
      str[i] = (char) (rand () % (KEYCHARMAX - KEYCHARMIN)) + KEYCHARMIN;
      assert ((int) str[i] >= KEYCHARMIN && (int) str[i] <= KEYCHARMAX);
    }

  assert ((int) strlen (str) == len);

  return str;
}

static double *
numbersfromprobability_get (int totalOperations, double insProb,
			    double srcProb, double delProb)
{
  double *numbers;

  assert ((insProb + srcProb + delProb) == 1.000);

  numbers = malloc_safe (sizeof (int) * 3);

  /* Insert */
  numbers[0] = floor (totalOperations * insProb);
  /* Search */
  numbers[1] = floor (totalOperations * srcProb);
  /* Delete */
  numbers[2] = floor (totalOperations * delProb);

  return numbers;
}

/* Fisher yates algorithm:
 * <http://www.dispersiondesign.com/articles/algorithms/shuffle_array_order>
 * This function is used to shuffle the actions array.
 */
static void
array_shuffle (char *array, int len)
{
  int i = len - 1;
  int j, tmp;

  srand (time (NULL));
  while (i > 0)
    {
      j = rand () % (i + 1);
      tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
      i--;
    }
}

static bool
isInsertAction (char action)
{
  return (action == 'i');
}

static bool
isSearchAction (char action)
{
  return (action == 's');
}

    /*
     * Fill the array with the correct number of actions.
     * i = insert
     * s = search
     * d = delete
     */
static char *
actions_get (int insElements, int srcElements, int delElements)
{
  int i = 0;
  char *actions;

  actions = malloc_safe (insElements + srcElements + delElements);

  while (i < insElements + srcElements + delElements)
    {
      if (i < insElements)
	actions[i] = 'i';
      else if (i < insElements + srcElements)
	actions[i] = 's';
      else if (i < insElements + srcElements + delElements)
	actions[i] = 'd';
      i++;
    }

  array_shuffle (actions, insElements + srcElements + delElements);

  return actions;
}

static double
operations (ht hashTable, char **keys, char *actions, int totalOperations)
{
  int i;
  double totalTime;
  clock_t startClock, endClock;
  node tmp;
  bool retval;

  totalTime = 0.0;
  for (i = 0; i < totalOperations; i++)
    {
      if (isInsertAction (actions[i]))
	{
	  startClock = clock ();
	  retval = HTInsert (hashTable, keys[i], keys[i]);
	  endClock = clock ();
	  if (retval == false && hashTable -> type == 'l' )
	    insMiss++;
      else if (retval == true && hashTable -> type == 'l')
        insSucc++;
	}
      else if (isSearchAction (actions[i]))
	{
	  startClock = clock ();
	  tmp = HTSearch (hashTable, keys[i]);
	  endClock = clock ();
	  if (node_null (tmp) && hashTable -> type == 'l')
	    srcMiss++;
	}
      else
	{
	  startClock = clock ();
	  retval = HTDelete (hashTable, keys[i]);
	  endClock = clock ();
	  if (retval == false && hashTable -> type == 'l')
	    delMiss++;
	}
      totalTime += runningtime_get (startClock, endClock);
    }

  return totalTime;
}

static char **
keys_new (int quantity, int length)
{
  char **keys;
  int i;

  /* Generate a new set of keys. */
  keys = malloc_safe (sizeof (char *) * quantity);
  for (i = 0; i < quantity; i++)
    keys[i] = randomstring_new (length);

  return keys;
}

static void
keys_delete (int quantity, char ***keysPtr)
{
  int i;

  for (i = 0; i < quantity; i++)
    {
      free ((*keysPtr)[i]);
      (*keysPtr)[i] = NULL;
    }

  free (*keysPtr);
  *keysPtr = NULL;
}

int
main (void)
{
  int i;
  double insProb = 0.75, srcProb = 0.125, delProb = 0.125;
  double *numbers;
  char *actions, **keys;
  int totalOperations = 0;
  int currentOperations = 0;
  double listTime, bstTime;
  double loadFactor = 0.0;
  int insOperations, srcOperations, delOperations;
  int totalInsElements = 0;
  double prevInsMiss = 0.0;
  ht hashTableList, hashTableBst;

  fprintf (stdout,
	   "currentOperations    totalOperations    totalInsertedElements    loadFactor    list    bst\n");

  hashTableList = HTInit (M, 'l');
  hashTableBst = HTInit (M, 'b');

  for (i = 1; i <= ATTEMPTS; i++)
    {
      currentOperations = M * i;

      keys = keys_new (currentOperations, KEYLENGTH);
      numbers = numbersfromprobability_get (currentOperations, insProb, srcProb, delProb);

      /* Number of operations based on currentOperations variable. */
      insOperations = numbers[0];
      srcOperations = numbers[1];
      delOperations = numbers[2];
      currentOperations =
	(int) (insOperations + srcOperations + delOperations);
      totalOperations += currentOperations;

      actions =
	actions_get ((int) insOperations, (int) srcOperations,
		     (int) delOperations);

      prevInsMiss = insMiss;

      /* Running time calculation is based on currentOperation variables. */
      listTime = operations (hashTableList, keys, actions, currentOperations);
      bstTime = operations (hashTableBst, keys, actions, currentOperations);

      /* Calculate the real number of elements in the hash tables. */
      totalInsElements += (insOperations - (insMiss - prevInsMiss));

      assert ( insSucc == ( totalInsElements ));

      loadFactor = (double) totalInsElements / M;

      fprintf (stdout, "%d    %d    %d    %f    %f    %f\n",
	       currentOperations, totalOperations, totalInsElements,
	       loadFactor, listTime, bstTime);

      keys_delete (currentOperations, &keys);
      free (actions);
    }

/*
      HTPrint ( hashTableList );
      HTPrint ( hashTableBst );
*/

  HTClear (&hashTableList);
  HTClear (&hashTableBst);

  return 0;
}
