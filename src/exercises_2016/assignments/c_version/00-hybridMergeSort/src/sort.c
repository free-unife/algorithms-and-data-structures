/*
 * sort.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "utils.h"
#include "sort.h"

static void sort_mERGE (int *array, index p, index q, index r);

void
sort_insertion (int *array, index start, index end)
{
  int j, i, key;

  for (j = start + 1; j <= end; j++)
    {
      key = array[j];
      i = j - 1;

      while (i >= start && array[i] > key)
	{
	  array[i + 1] = array[i];
	  i--;
	}
      array[i + 1] = key;
    }
}

static void
sort_mERGE (int *array, index p, index q, index r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int i, j, k;
  int *L = malloc_safe ((n1 + 1) * sizeof (int));
  int *R = malloc_safe ((n2 + 1) * sizeof (int));

  for (i = 0; i < n1; i++)
    L[i] = array[p + i];

  for (j = 0; j < n2; j++)
    R[j] = array[q + 1 + j];

  L[n1] = INF;
  R[n2] = INF;

  i = 0;
  j = 0;
  for (k = p; k <= r; k++)
    {
      if (L[i] <= R[j])
	{
	  array[k] = L[i];
	  i++;
	}
      else
	{
	  array[k] = R[j];
	  j++;
	}
    }

  free (L);
  free (R);
}

void
sort_mergeSort (int *array, index p, index r)
{
  int q;

  if (p < r)
    {
      q = (p + r) / 2;
      sort_mergeSort (array, p, q);
      sort_mergeSort (array, q + 1, r);
      sort_mERGE (array, p, q, r);
    }
}

void
sort_hybrid (int *array, index p, index r, index k)
{
  int q;

  /* When the input array size is less than k, we have the base case
   * that executes insertion sort.
   * Just like in merge sort, r - p represents the current array size.
   */
  if (r - p <= k)
    sort_insertion (array, p, r);
  else if (p < r)
    {
      q = (p + r) / 2;
      sort_hybrid (array, p, q, k);
      sort_hybrid (array, q + 1, r, k);
      sort_mERGE (array, p, q, r);
    }
}
