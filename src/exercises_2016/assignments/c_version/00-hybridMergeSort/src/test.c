/*
 * test.c
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
#include "test.h"

#if defined SORT_C
static void newReversedArray (int **arrRef, int size);
static void printArray (int *arr, int size);

static void
newReversedArray (int **arrRef, int size)
{
  int i;

  *arrRef = malloc_safe (size * sizeof (int));
  for (i = size - 1; i >= 0; i--)
    (*arrRef)[size - i - 1] = i;
}

static void
printArray (int *arr, int size)
{
  int i;

  assert (!element_null (arr));
  fprintf (stderr, "[ ");
  for (i = 0; i < size; i++)
    fprintf (stderr, "%d ", arr[i]);
  fprintf (stderr, " ]\n");

}

int
main (void)
{
  int n = 10;
  int *arr = NULL;

  newReversedArray (&arr, n);
  printArray (arr, n);

  fprintf (stderr, "Sorted arrays\n");
  sort_insertion (arr, 0, n - 1);
  printArray (arr, n);
  free (arr);

  newReversedArray (&arr, n);
  sort_mergeSort (arr, 0, n - 1);
  printArray (arr, n);
  free (arr);

  newReversedArray (&arr, n);
  sort_hybrid (arr, 0, n - 1, n / 2);
  printArray (arr, n);
  free (arr);

  return 0;
}

#elif defined HELPER_C
int
main (void)
{
  int n = 1000;
  int *arr = malloc_safe (n * sizeof (int));
  int *tmp = malloc_safe (n * sizeof (int));

  helper_genRandomArray (arr, n);
  helper_arrayCopy (tmp, arr, n);
  assert (helper_arraysEqual (arr, tmp, n));

  sort_insertion (tmp, 0, n - 1);
  assert (helper_arraySorted (tmp, n));
  free (tmp);

  tmp = malloc_safe (n * sizeof (int));
  helper_arrayCopy (tmp, arr, n);
  sort_mergeSort (tmp, 0, n - 1);
  assert (helper_arraySorted (tmp, n));
  free (tmp);

  tmp = malloc_safe (n * sizeof (int));
  sort_hybrid (tmp, 0, n - 1, n / 2);
  assert (helper_arraySorted (tmp, n));
  free (tmp);

  free (arr);

  return 0;
}

#elif defined FINDK_C
int
main (void)
{
  fprintf (stderr, "Possible k = %d\n", findk_find ());
  return 0;
}

#endif
