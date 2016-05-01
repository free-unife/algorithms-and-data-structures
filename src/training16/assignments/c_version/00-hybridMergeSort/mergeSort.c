/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

void
mergeSort (int *array, int p, int r)
{
  int q;

  if (lt (p, r))
    {
      q = (p + r) / 2;
      mergeSort (array, p, q);
      mergeSort (array, q + 1, r);
      merge (array, p, q, r);
    }
}
