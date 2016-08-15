/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
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
  int *array, array1[6] = { 2, 3, 5, 7, 11, ARRAY_NULL_NUM };
  clock_t start, end;

  fprintf (stderr, "\n\nInitializing array\n");
  initArray (&array);
  if (arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nGenerating random array of %d elements\n", 100);
  array = genRandomArray (100);

  fprintf (stderr, "\n\nIs array still empty?\n");
  if (!arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is not empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nPrinting array\n");
  printArray (array);


  fprintf (stderr, "\n\nPrinting array 1\n");
  printArray (array1);

  fprintf (stderr, "\n\nChecking array length\n");
  if (eq (arrayLength (array), 100))
    fprintf (stderr, "[ OK ] length of array is %d\n", 100);
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");
  if (eq (arrayLength (array1), 5))
    fprintf (stderr, "[ OK ] length of array is %d\n", 5);
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nIs array 1 ordered?\n");
  if (arrayOrdered (array1))
    fprintf (stderr, "[ OK ] Array is ordered\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nCopy array 1\n");
  if (eq (arrayLength (copyArray (array1)), 5))
    fprintf (stderr,
	     "[ OK ] Array 1 copy has the correct length of %d \n", 5);
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nTesting array copy and array equal\n");
  if (arrayEqual (array1, (copyArray (array1))))
    fprintf (stderr, "[ OK ] Array copy and array equal works\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  free (array);


  fprintf (stderr,
	   "\n\nGenerating random array of %d elements and counting the running time\n",
	   100);
  start = clock ();
  array = genRandomArray (100);
  end = clock ();
  fprintf (stderr, "Measured running time is: %f s\n",
	   runningTime (start, end));


  fprintf (stderr, "\n\nTesting array sum on array 1\n");
  if (eq
      (array1[0] + array1[1] + array1[2] + array1[3] + array1[4],
       arraySum (array1)))
    fprintf (stderr, "[ OK ] Array sum of array 1 returned %d\n",
	     arraySum (array1));
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  free (array);
  return 0;
}

#elif defined M_INSERTIONSORT_C
int
main (void)
{
  int *array;
  clock_t start, end;

  fprintf (stderr, "\n\nInitializing array\n");
  initArray (&array);
  if (arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nGenerating random array of %d elements\n", 100);
  array = genRandomArray (100);


  fprintf (stderr, "\n\nIs array still empty?\n");
  if (!arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is not empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nInsertion sort test\n");
  start = clock ();
  insertionSort (array, 0, 100 - 1);
  end = clock ();
  if (arrayOrdered (array))
    fprintf (stderr, "[ OK ] Array has been ordered in %f s\n",
	     runningTime (start, end));
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");

  free (array);

  return 0;
}

#elif defined M_MERGE_C
int
main (void)
{
  int *array;
  clock_t start, end;

  fprintf (stderr, "\n\nInitializing array\n");
  initArray (&array);
  if (arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nGenerating random array of %d elements\n", 100);
  array = genRandomArray (100);


  fprintf (stderr, "\n\nIs array still empty?\n");
  if (!arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is not empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nMerge test\n");
  start = clock ();
  merge (array, 0, ((100 - 1) / 2), 100 - 1);
  end = clock ();
  fprintf (stderr, "[ OK ] Merge has taken %f s\n", runningTime (start, end));

  free (array);

  return 0;
}

#elif defined M_MERGESORT_C
int
main (void)
{
  int *array;
  clock_t start, end;

  fprintf (stderr, "\n\nInitializing array\n");
  initArray (&array);
  if (arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nGenerating random array of %d elements\n", 100);
  array = genRandomArray (100);


  fprintf (stderr, "\n\nIs array still empty?\n");
  if (!arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is not empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nMerge sort test\n");
  start = clock ();
  mergeSort (array, 0, 100 - 1);
  end = clock ();
  if (arrayOrdered (array))
    fprintf (stderr, "[ OK ] Array has been ordered in %f s\n",
	     runningTime (start, end));
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");

  free (array);

  return 0;
}

#elif defined M_FINDK_C
int
main (void)
{
  int k;

  k = findK ();

  fprintf (stderr, "\n\nAvg of possible k is %d\n", k);

  return 0;
}

#elif defined M_HYBRIDSORT_C
int
main (void)
{
  int *array;
  clock_t start, end;
  int k;

  fprintf (stderr, "\n\nInitializing array\n");
  initArray (&array);
  if (arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nGenerating random array of %d elements\n", 100);
  array = genRandomArray (100);


  fprintf (stderr, "\n\nIs array still empty?\n");
  if (!arrayEmpty (array))
    fprintf (stderr, "[ OK ] Array is not empty\n");
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");


  fprintf (stderr, "\n\nHybrid sort test\n");
  k = findK ();
  start = clock ();
  hybridSort (array, 0, 100 - 1, k);
  end = clock ();
  if (arrayOrdered (array))
    fprintf (stderr,
	     "[ OK ] Array has been ordered in %f s, with k = %d\n",
	     runningTime (start, end), k);
  else
    fprintf (stderr, "[ ERR ] This message should not be shown\n");

  free (array);

  return 0;
}
#endif
