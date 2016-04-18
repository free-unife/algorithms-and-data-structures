/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#ifndef M_GLOBALDEFINES_H
#define M_GLOBALDEFINES_H

#include "definedModules.h"
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

double runningTime( clock_t start, clock_t end );
void initArray( int **arrayPtr );
bool arrayNull ( int *array );
bool arrayEmpty( int *array );
int el( int *array, int index );
int *pt( int *array, int index );
bool eq ( int a, int b );
bool gt ( int a, int b );
bool lt ( int a, int b );
bool ge( int a, int b );
bool le( int a, int b );
bool arrayOrdered( int *array );
void printArray( int *array );
int arrayLength ( int *array );
int arraySum( int *array );
bool arrayEqual( int *a1, int *a2 );
int *allocArray ( int len );
int *copyArray ( int *src );
int *genRandomArray( int len );

void insertionSort( int *array, int startInd, int endInd );

void merge( int *array, int p, int q, int r );

void mergeSort( int *array, int p, int r );

int findK( void );

#endif
