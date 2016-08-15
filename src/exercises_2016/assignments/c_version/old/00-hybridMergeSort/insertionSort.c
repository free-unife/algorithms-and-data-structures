/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

void
insertionSort (int *array, int startInd, int endInd)
{
  int j;
  int i, key;

  for (j = startInd + 1; j <= endInd; j++)
    {
      key = array[j];
      i = j - 1;

      while (i >= startInd && array[i] > key)
	{
	  array[i + 1] = array[i];
	  i--;
	}
      array[i + 1] = key;
    }
}
