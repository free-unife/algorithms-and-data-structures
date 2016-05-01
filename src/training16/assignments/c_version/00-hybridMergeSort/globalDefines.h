/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#ifndef M_GLOBALDEFINES_H
#define M_GLOBALDEFINES_H

#define ISOC99_SOURCE
#define _POSIX_C_SOURCE 199309L
#if __STDC_VERSION__ != 199901L
#error "ANSI C99 not available"
#endif

/* Comment out the following to disable all asserts.  */
/*#define NDEBUG*/

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INF INT_MAX
#define EMPTY NULL
#define ARRAY_NULL_NUM INT_MIN

#define MIN_RAND 0
#define MAX_RAND INT_MAX

#define ATTEMPTS 10
#define MIN_SIZE 20
#define MAX_SIZE 150

#define MIN_K 0
#define MAX_K 80

#define COMPARISON_SIZE 5000

extern double runningTime( clock_t start, clock_t end );
extern void initArray( int **arrayPtr );
extern bool arrayNull ( int *array );
extern bool arrayEmpty( int *array );
extern int el( int *array, int index );
extern int *pt( int *array, int index );
extern bool eq ( int a, int b );
extern bool gt ( int a, int b );
extern bool lt ( int a, int b );
extern bool ge( int a, int b );
extern bool le( int a, int b );
extern bool arrayOrdered( int *array );
extern void printArray( int *array );
extern int arrayLength ( int *array );
extern int arraySum( int *array );
extern bool arrayEqual( int *a1, int *a2 );
extern int *allocArray ( int len );
extern int *copyArray ( int *src );
extern int *genRandomArray( int len );

extern void insertionSort( int *array, int startInd, int endInd );

extern void merge( int *array, int p, int q, int r );

extern void mergeSort( int *array, int p, int r );

extern int findK( void );

extern void hybridSort( int *array, int p, int r, int k );

#endif
