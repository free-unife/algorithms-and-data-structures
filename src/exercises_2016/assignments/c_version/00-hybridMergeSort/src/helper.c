/*
 * helper.c
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "helper.h"
#include "utils.h"

/* Ascending sort. */
bool
helper_arraySorted (int *arr, int size)
{
  int i;

  assert (!element_null (arr));
  for (i = 1; i < size; i++)
    if (arr[i - 1] > arr[i])
      return false;
  return true;
}

bool
helper_arraysEqual (int *arr1, int *arr2, int size)
{
  int i;

  assert (!element_null (arr1) || !element_null (arr2));
  for (i = 0; i < size; i++)
    if (arr1[i] != arr2[i])
      return false;
  return true;
}

/* Arr must be allocated from the caller. */
void
helper_genRandomArray (int *arr, int size)
{
  int i;
  struct timespec t1;

  clock_gettime (CLOCK_MONOTONIC, &t1);
  srand (t1.tv_nsec);
  for (i = 0; i < size; i++)
    {
      arr[i] = (rand () % (NUM_DOMAIN_MAX - NUM_DOMAIN_MIN)) + NUM_DOMAIN_MIN;
      assert (arr[i] >= NUM_DOMAIN_MIN && arr[i] <= NUM_DOMAIN_MAX);
    }
}

/* Dest must be allocated from the caller. */
void
helper_arrayCopy (int *dest, int *src, int size)
{
  int i;

  assert (!element_null (dest) || !element_null (src));
  for (i = 0; i < size; i++)
    dest[i] = src[i];
}

double
helper_getRunningTime (clock_t start, clock_t end)
{
  return (((double) (end - start) / (double) CLOCKS_PER_SEC));
}
