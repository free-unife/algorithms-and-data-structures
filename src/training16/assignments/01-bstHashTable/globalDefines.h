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
#define EMPTY NULL
/* FIXME: Number of buckets to be defined better.  */
#define M 997

struct node {
  char *key;
  char *value;
  struct node *left;
  struct node *right;
  struct node *parent;
};

typedef struct node * bst;
typedef bst * bstPtr;
typedef bstPtr * htSlot;

/* Protoypes.  */
void BSTInit( bstPtr rootPtr );
bool BSTEmpty( bst root );
char *BSTKey( bst root );
char *BSTVal( bst root );
bst BSTInsert( bstPtr rootPtr, char *key, char *value );
bst BSTSearch( bst root, char *key );
bool BSTDelete( bstPtr rootPtr, char *key );

void HTinit ( htSlot *hashTable );
bool HTEmptySlot ( htSlot slot );
htSlot HTNewSlot ( htSlot *hashTable, unsigned int slotInd );
unsigned int HTHash( char *input );
void HTPrint( bstPtr * hash );
