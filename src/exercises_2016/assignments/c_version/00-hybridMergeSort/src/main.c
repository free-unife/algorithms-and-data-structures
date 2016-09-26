/*
 * main.c
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
#include "main.h"

int
main (void)
{
  int attempt, k;
  int *array, *arrayMergeSort, *arrayHybridSort;
  clock_t start, end;
  double mergeSortTime, hybridSortTime;

  fprintf (stdout, "%s    %s    %s    %s    %s\n", "attempt", "K",
	   "arraySize", "mergeSortTime", "hybridSortTime");

    /* Set k == 43*/
    k = 43;

  /* Test for different array sizes. */
  for (attempt = 0; attempt <= COMPARISON_SIZE; attempt++)
    {
      array = malloc_safe (COMPARISON_SIZE * sizeof (int));

    /* We have decided that k was 43 */
	  arrayHybridSort = malloc_safe (attempt * sizeof (int));
	  arrayMergeSort = malloc_safe (attempt * sizeof (int));

	  helper_genRandomArray (array, attempt);

	  /*
	   * Get copies of the original array. 
	   */
	  helper_arrayCopy (arrayMergeSort, array, attempt);
	  helper_arrayCopy (arrayHybridSort, array, attempt);
	  assert (helper_arraysEqual
		  (array, arrayMergeSort, attempt));
	  assert (helper_arraysEqual
		  (array, arrayHybridSort, attempt));

	  start = clock ();
	  sort_mergeSort (arrayMergeSort, 0, attempt - 1);
	  end = clock ();
	  mergeSortTime = helper_getRunningTime (start, end);

	  start = clock ();
	  sort_hybrid (arrayHybridSort, 0, attempt - 1, k);
	  end = clock ();
	  hybridSortTime = helper_getRunningTime (start, end);

	  /*
	   * Check if the arrays are sorted. 
	   */
	  assert (helper_arraysEqual
		  (arrayMergeSort, arrayHybridSort, attempt));
	  assert (helper_arraySorted (arrayMergeSort, attempt));
	  assert (helper_arraySorted (arrayHybridSort, attempt));

	  free (arrayMergeSort);
	  free (arrayHybridSort);

	  /*
	   * Print the results so that gnuplot can catch and use them. 
	   */
	  fprintf (stdout, "%d    %d    %d    %f    %f\n", attempt, k,
		   attempt, mergeSortTime, hybridSortTime);
      free (array);
    }

  return 0;
}
