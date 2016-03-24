/* Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */


#ifndef M_DEFINEDMODULES_H
#define M_DEFINEDMODULES_H
#include "definedModules.h"
#endif

#ifndef M_STDLIB_H
#define M_STDLIB_H
#include <stdlib.h>
#endif

#ifndef M_STDIO_H
#define M_STDIO_H
#include <stdio.h>
#endif

#ifndef M_ASSERT_H
#define M_ASSERT_H
#include <assert.h>
#endif

#ifndef M_LIMITS_H
#define M_LIMITS_H
#include <limits.h>
#endif

#ifndef M_TIME_H
#define M_TIME_H
#include <time.h>
#endif

#ifndef M_SYSTIME_H
#define M_SYSTIME_H
#include <sys/time.h>
#endif

#ifndef M_STRING_H
#define M_STRING_H
#include <string.h>
#endif

#ifndef M_MATH_H
#define M_MATH_H
#include <math.h>
#endif

/* Global.  */
#define false 0
#define true 1
#define INF INT_MAX
typedef int boolean;

/* ****************
 * ****************
 * ****************
 * ****************
 */
/* Hash.  */

/* FIXME: THIS NEED TO BE CHANGED ACCORDINGLY WITH graphElement struct AND 
TYPEDEFS  */
typedef char* bstPointer;

/* FIXME: Number of buckets to be defined better.  */
#define M 997

size_t hash( char *input );
bstPointer *initHashTable( void );
void printHashTable( bstPointer * hash );



/* ****************
 * ****************
 * ****************
 * ****************
 */
/* BST.  */

typedef struct node * bst;

#define EMPTY NULL

struct node {
  char *key;
  char *value;
  struct node *left;
  struct node *right;
  struct node *parent;
};


void BSTinit( bst * root );
boolean BSTEmpty( bst root );
char *BSTKey( bst root );
char *BSTVal( bst root );
bst BSTLeft( bst root );
bst BSTRight( bst root );
boolean BSTKeyEqual (char *key1, char *key2 );
boolean BSTKeyLess( char *key1, char *key2 );
boolean BSTKeyGreater( char *key1, char *key2 );
void BSTNewNode( bst * ptree, char *key, char *value );
void BSTNonEmptyInsert( bst root, char *key, char *value );
void BSTinsert( bst * ptree, char *key, char *value );
bst BSTMinElement (bst root);
bst BSTMaxElement (bst root);
bst BSTSearch(bst root, char *key);

