/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

void
hybridSort (int *array, int p, int r, int k)
{
  int q;

  /* When the input array size is less than k we, have the base case
   * that executes insertion sort. */
  if (le ((r - p), k))
    insertionSort (array, p, r);
  else if (lt (p, r))
    {
      q = (p + r) / 2;
      hybridSort (array, p, q, k);
      hybridSort (array, q + 1, r, k);
      merge (array, p, q, r);
    }
}
