/*
 * @file utils.c
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Header file containing exportable methods.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

bool
element_null (void *element)
{
  return (element == NULL);
}

void *
malloc_safe (size_t size)
{
  void *dst;

  dst = malloc (size);
  if (element_null (dst))
    {
      if (errno)
	perror (strerror (errno));
      exit (EXIT_FAILURE);
    }

  return dst;
}
