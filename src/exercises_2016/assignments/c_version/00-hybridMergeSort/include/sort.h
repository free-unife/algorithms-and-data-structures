/*
 * sort.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined SORT_H
#define SORT_H

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INF INT_MAX

typedef int index;

extern void sort_insertion (int *array, index start, index end);
extern void sort_mergeSort (int *array, index p, index r);
extern void sort_hybrid (int *array, index p, index r, index k);
#endif
