/*
 * helper.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined HELPER_H
#define HELPER_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define NUM_DOMAIN_MIN 0
#define NUM_DOMAIN_MAX INT_MAX

extern bool helper_arraySorted (int *arr, int size);
extern bool helper_arraysEqual (int *arr1, int *arr2, int size);
extern void helper_genRandomArray (int *arr, int size);
extern void helper_arrayCopy (int *dest, int *src, int size);
extern double helper_getRunningTime (clock_t start, clock_t end);
#endif
