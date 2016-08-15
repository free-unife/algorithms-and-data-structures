/*
 * findK.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "utils.h"
#include "sort.h"
#include "helper.h"
#include "findk.h"

static int findk_gETmINiNDEX (double *array, int len);
static int findk_aRRAYsUM (int *arr, int size);

static int
findk_gETmINiNDEX (double *array, int len)
{
  int i, minInd;
  double min;

  min = array[0];
  minInd = 0;
  for (i = 1; i < len; i++)
    if (array[i] < min)
      {
	min = array[i];
	minInd = i;
      }

  return minInd;
}

static int
findk_aRRAYsUM (int *arr, int size)
{
  int i, sum = 0;

  for (i = 0; i < size; i++)
    sum += arr[i];

  return sum;
}

/* k corresponds to the maximum array size where insertion sort
 * performs like merge sort.
 * With values less than k, insertion sort performs better,
 * and with values greater than k merge sort performs better ).
 */
int
findk_find (void)
{
  int attempt, size;
  int *array, *arrayInsertionSort, *arrayMergeSort;
  clock_t start, end;
  double insertionSortTime, mergeSortTime, diffTime;
  double *diffTimes;
  int *possibleK;
  int k, i;

#if defined FINDK_C
  fprintf (stdout, "%s    %s    %s    %s    %s\n", "attempt",
	   "arraySize", "insertionSortTime", "mergeSortTime", "diffTime");
#elif defined MAIN_C
  fprintf (stderr, "%s    %s    %s    %s    %s\n", "attempt",
	   "arraySize", "insertionSortTime", "mergeSortTime", "diffTime");
#endif

  possibleK = malloc_safe (ATTEMPTS * sizeof (int));
  for (attempt = 0; attempt < ATTEMPTS; attempt++)
    {
      diffTimes = malloc_safe ((MAX_ARRAY_SIZE - MIN_ARRAY_SIZE) * sizeof
			       (double));

      for (size = MIN_ARRAY_SIZE; size <= MAX_ARRAY_SIZE; size++)
	{
	  array = malloc_safe (size * sizeof (int));
	  arrayInsertionSort = malloc_safe (size * sizeof (int));
	  arrayMergeSort = malloc_safe (size * sizeof (int));

	  helper_genRandomArray (array, size);

	  /*
	   * Get copies of the original array. 
	   */
	  helper_arrayCopy (arrayInsertionSort, array, size);
	  helper_arrayCopy (arrayMergeSort, array, size);
	  assert (helper_arraysEqual (array, arrayInsertionSort, size));
	  assert (helper_arraysEqual (array, arrayMergeSort, size));

	  start = clock ();
	  sort_insertion (arrayInsertionSort, 0, size - 1);
	  end = clock ();
	  insertionSortTime = helper_getRunningTime (start, end);

	  start = clock ();
	  sort_mergeSort (arrayMergeSort, 0, size - 1);
	  end = clock ();
	  mergeSortTime = helper_getRunningTime (start, end);

	  /*
	   * Check that the arrays are ordered. 
	   */
	  assert (helper_arraysEqual
		  (arrayInsertionSort, arrayMergeSort, size));
	  assert (helper_arraySorted (arrayInsertionSort, size));
	  assert (helper_arraySorted (arrayMergeSort, size));

	  diffTime = fabs (insertionSortTime - mergeSortTime);

	  /*
	   * Save times. 
	   */
	  diffTimes[size - MIN_ARRAY_SIZE] = diffTime;

	  free (arrayMergeSort);
	  free (arrayInsertionSort);
	  free (array);

	  /*
	   * Print the results so that gnuplot can catch and use them. 
	   */
#if defined FINDK_C
	  fprintf (stdout, "%d    %d    %f    %f    %f\n", attempt, size,
		   insertionSortTime, mergeSortTime, diffTime);
#elif defined MAIN_C
	  fprintf (stderr, "%d    %d    %f    %f    %f\n", attempt, size,
		   insertionSortTime, mergeSortTime, diffTime);
#endif
	}
      possibleK[attempt] = MIN_ARRAY_SIZE +
	findk_gETmINiNDEX (diffTimes, MAX_ARRAY_SIZE - MIN_ARRAY_SIZE);

      free (diffTimes);
    }

  /*
   * Average of all possible ks.
   */
  k = findk_aRRAYsUM (possibleK, ATTEMPTS) / ATTEMPTS;

  fprintf (stderr, "\n\nPossible k for each one of the %d attempts\n",
	   ATTEMPTS);
  for (i = 0; i < ATTEMPTS; i++)
    fprintf (stderr, "%d\n", possibleK[i]);

  free (possibleK);

  return k;
}
