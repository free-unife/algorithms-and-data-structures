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

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>


/* Global.  */
#define INF INT_MAX

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

#define EMPTY NULL

struct node {
  char *key;
  char *value;
  struct node *left;
  struct node *right;
  struct node *parent;
};

typedef struct node * bst;
typedef bst * bstPtr;


void BSTinit( bstPtr rootPtr );
bool BSTEmpty( bst root );
char *BSTKey( bst root );
char *BSTVal( bst root );
bst BSTinsert( bstPtr rootPtr, char *key, char *value );
bst BSTSearch( bst root, char *key );
bool BSTDelete( bstPtr rootPtr, char *key );

