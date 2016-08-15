/*
 * extra.c
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
#include "extra.h"

int
main (void)
{
  int attempt, k, i = 0;
  int *array, *arrayMergeSort, *arrayHybridSort;
  clock_t start, end;
  double mergeSortTime, hybridSortTime;
  int ks[3] = { 10, 20, 35 };

  fprintf (stdout, "%s    %s    %s    %s    %s\n", "attempt", "K",
	   "arraySize", "mergeSortTime", "hybridSortTime");

  for (attempt = 0; attempt < ATTEMPTS; attempt++)
    {
      array = malloc_safe (COMPARISON_SIZE * sizeof (int));

      i = 0;
      while (i < 3)
	{
	  k = ks[i];
	  arrayHybridSort = malloc_safe (COMPARISON_SIZE * sizeof (int));
	  arrayMergeSort = malloc_safe (COMPARISON_SIZE * sizeof (int));

	  helper_genRandomArray (array, COMPARISON_SIZE);

	  /*
	   * Get copies of the original array. 
	   */
	  helper_arrayCopy (arrayMergeSort, array, COMPARISON_SIZE);
	  helper_arrayCopy (arrayHybridSort, array, COMPARISON_SIZE);
	  assert (helper_arraysEqual
		  (array, arrayMergeSort, COMPARISON_SIZE));
	  assert (helper_arraysEqual
		  (array, arrayHybridSort, COMPARISON_SIZE));

	  start = clock ();
	  sort_mergeSort (arrayMergeSort, 0, COMPARISON_SIZE - 1);
	  end = clock ();
	  mergeSortTime = helper_getRunningTime (start, end);

	  start = clock ();
	  sort_hybrid (arrayHybridSort, 0, COMPARISON_SIZE - 1, k);
	  end = clock ();
	  hybridSortTime = helper_getRunningTime (start, end);

	  /*
	   * Check if the arrays are ordered. 
	   */
	  assert (helper_arraysEqual
		  (arrayMergeSort, arrayHybridSort, COMPARISON_SIZE));
	  assert (helper_arraySorted (arrayMergeSort, COMPARISON_SIZE));
	  assert (helper_arraySorted (arrayHybridSort, COMPARISON_SIZE));

	  free (arrayMergeSort);
	  free (arrayHybridSort);

	  /*
	   * Print the results so that gnuplot can catch and use them. 
	   */
	  fprintf (stdout, "%d    %d    %d    %f    %f\n", attempt, k,
		   COMPARISON_SIZE, mergeSortTime, hybridSortTime);

	  i++;
	}
      free (array);
    }

  return 0;
}
