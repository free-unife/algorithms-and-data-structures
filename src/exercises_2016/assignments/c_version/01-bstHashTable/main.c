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

/*
 * sum ( i = 1:ATTEMPS of ( i * CHUNK ) ) = totalOperations.
 * ATTEMPTS = number of tests.
 * CHUNK = initial number of samples.
 */

/**
 * @brief NUmber of buckets of the hash tables.
 */
#define M 997
#define KEYCHARMIN 33
#define KEYCHARMAX 126
#define ATTEMPTS 50
#define CHUNK 800
#define KEYLENGTH 8
#define INSPROB 0.750
#define SRCPROB 0.125
#define DELPROB 0.125

/**
 * @brief Get the delta of two clocks (i.e: the running time).
 *
 * @param[in] start A clock corresponding to the start time.
 * @param[in] end A clock corresponding to the end time.
 *
 * @retval end-start The time difference between two clocks.
 */
static double runningtime_get (clock_t start, clock_t end);

/**
 * @brief Generate a random string with a specified length.
 *
 * @param[in] len The length of the random string.
 *
 * @retval str The random string.
 *
 * @note The domain of characters of the random string is given by KEYCHARMIN
 * and KEYCHARMAX macros.
 */
static char *randomstring_new (int len);

/**
 * @brief Get the number of operations of each type, given their probability.
 *
 * @param[in] totalOperations The overall number of operations.
 * @param[in] insProb Probability of insertion operations.
 * @param[in] srcProb Probability of search operations.
 * @param[in] delProb Probability of delete operations.
 *
 * @retval numbers An array of three integers where: index 0 = insert
 * operations, index 1 = search operations, index 2 = delete operations.
 *
 * @note Probabilities are expressed in the following domain: [0, 1].
 *
 * @warning sum(numbers) may be different than totalOperations due to
 * approximations.
 */
static int *numbersfromprobability_get (int totalOperations,
					double insProb, double srcProb,
					double delProb);

/**
 * @brief Shuffle a char array of a given length using Fisher-Yates algorithm.
 *
 * @param[in] array The array to be shuffled.
 * @param[in] len The length of the array.
 */
static void array_shuffle (char *array, int len);

/**
 * @brief Check if input corresponds to an insert action.
 *
 * @param[in] action A character in the following domain: {'i', 's', 'd'}.
 *
 * @retval true Input actions is an insert action.
 * @retval false Input actions is not an insert action.
 */
static bool isInsertAction (char action);

/**
 * @brief Check if input corresponds to a search action.
 *
 * @param[in] action A character in the following domain: {'i', 's', 'd'}.
 *
 * @retval true Input actions is a search action.
 * @retval false Input actions is not a search action.
 */
static bool isSearchAction (char action);

/**
 * @brief Simulate insert, search and delete operations on a hash table, and
 * gather statistics.
 *
 * @param[in] ht A pointer to the hash table.
 * @param[in] keys The array of keys.
 * @param[in] actions The array of actions.
 * @param[in] totalOperations The overall number of search, insert and delete
 * operations to be done.
 * @param[in] succIns A pointer to a variable containing the number of
 * successful insertion operations.
 * @param[in] succDel A pointer to a variable containing the number of
 * successful deletion operations.
 *
 * @retval totalTime The running time for a series of operations on the hash
 * table.
 * @retval succIns The number of successful insertion operations.
 * @retval succDel The number of successful deletion operations.
 */
static double operations (ht hashTable, char **keys, char *actions,
			  int totalOperations, int *succIns, int *succDel);

/**
 * @brief Generate a new array of keys.
 *
 * @param[in] quantity The number of keys.
 * @param[in] length The length of each key.
 *
 * @retval keys The pointer to the array of keys.
 */
static char **keys_new (int quantity, int length);

/**
 * @brief Delete an array of keys.
 *
 * @param[in] quantity The number of keys.
 */
static void keys_delete (int quantity, char ***keysPtr);

/**
 * @brief Generate a random array corresponding to the type of operations that
 * needs to be done.
 *
 * @param[in] insElements The number of insert operations.
 * @param[in] srcElements The number of search operations.
 * @param[in] delElements The number of delete operations.
 *
 * @retval actions The array of actions.
 *
 * @note Possible actions are {'i', 's', 'd'} respectively for insert, search
 * and delete operations.
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

static int *
numbersfromprobability_get (int totalOperations, double insProb,
			    double srcProb, double delProb)
{
  int *numbers;

  assert ((insProb + srcProb + delProb) == 1.000);

  numbers = malloc_safe (sizeof (int) * 3);

  /* Insert */
  numbers[0] = (int) floor (totalOperations * insProb);
  /* Search */
  numbers[1] = (int) floor (totalOperations * srcProb);
  /* Delete */
  numbers[2] = (int) floor (totalOperations * delProb);

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
operations (ht hashTable, char **keys, char *actions, int totalOperations, int
	    *succIns, int *succDel)
{
  int i;
  double totalTime;
  clock_t startClock, endClock;
  bool retval;

  totalTime = 0.0;
  for (i = 0; i < totalOperations; i++)
    {
      if (isInsertAction (actions[i]))
	{
	  startClock = clock ();
	  retval = HTInsert (hashTable, keys[i], keys[i]);
	  endClock = clock ();
	  if (retval == true)
	    (*succIns)++;
	}
      else if (isSearchAction (actions[i]))
	{
	  startClock = clock ();
	  HTSearch (hashTable, keys[i]);
	  endClock = clock ();
	}
      else
	{
	  startClock = clock ();
	  retval = HTDelete (hashTable, keys[i]);
	  endClock = clock ();
	  if (retval == true)
	    (*succDel)++;
	}
      totalTime += runningtime_get (startClock, endClock);
    }

  (void) *succIns, (void) *succDel;

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
  int i, totalOperations, *realOperations, succIns, succDel, *succInsPtr,
    *succDelPtr, currentElementsInHashTable = 0, trash;
  char **keys, *actions;
  double listTime, bstTime, loadFactor;
  ht hashTableList, hashTableBst;

  succInsPtr = &succIns;
  succDelPtr = &succDel;
  hashTableList = HTInit (M, 'l');
  hashTableBst = HTInit (M, 'b');

  fprintf (stdout, "totalOperations    list    bst    loadFactor\n");
  for (i = 1; i <= ATTEMPTS; i++)
    {
      succIns = 0;
      succDel = 0;

      totalOperations = CHUNK * i;
      keys = keys_new (totalOperations, KEYLENGTH);

      /* The sum of realOperations could be an approximation of
       * totalOperations because of floating point probabilities that lead to
       * non integer number of operations.
       */
      realOperations = numbersfromprobability_get (totalOperations, INSPROB,
						   SRCPROB, DELPROB);
      actions = actions_get (realOperations[0], realOperations[1],
			     realOperations[2]);

      listTime = operations (hashTableList, keys, actions, totalOperations,
			     succInsPtr, succDelPtr);
      bstTime = operations (hashTableBst, keys, actions, totalOperations,
			    &trash, &trash);

      currentElementsInHashTable += succIns - succDel;
      loadFactor =
	(double) ((double) currentElementsInHashTable / (double) M);

      fprintf (stdout, "%d    %f    %f    %f\n", totalOperations,
	       listTime, bstTime, loadFactor);

      free (actions);
      free (realOperations);
      keys_delete (totalOperations, &keys);
    }

  HTClear (&hashTableList);
  HTClear (&hashTableBst);

}
