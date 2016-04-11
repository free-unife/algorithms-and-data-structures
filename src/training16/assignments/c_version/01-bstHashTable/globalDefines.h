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
#define EMPTYKEY ""
#define EMPTYVAL ""
#define KEYLENGTH 16
#define KEYCHARMIN 33
#define KEYCHARMAX 126
#define MAINLOOPTESTS 8
#define M 997

/* LIST struct */
struct listNode {
    char *key;
    char *value;
    struct listNode *next;
    struct listNode *prev;
};

typedef struct listNode * list;
typedef list * listPtr;

void LISTInit( listPtr headPtr );
bool LISTEmpty( list head );
char *LISTKey( list head );
char *LISTVal( list head );
list LISTInsert( listPtr headPtr, char *key, char *value );
list LISTSearch( list head, char *key );
bool LISTDelete( listPtr headPtr, char *key );

/* BST struct. */
struct bstNode {
    char *key;
    char *value;
    struct bstNode *left;
    struct bstNode *right;
    struct bstNode *parent;
};

typedef struct bstNode * bst;
typedef bst * bstPtr;

/* The following are only used in HT. */
typedef bstPtr * htSlot;
typedef bst treeNode;
typedef bstPtr treeNodePtr;

/* The following are only used in HTBST. */
typedef treeNode element;
typedef treeNodePtr elementPtr;

/* Prototypes. */
void BSTInit( bstPtr rootPtr );
bool BSTEmpty( bst root );
char *BSTKey( bst root );
char *BSTVal( bst root );
bst BSTInsert( bstPtr rootPtr, char *key, char *value );
bst BSTSearch( bst root, char *key );
bool BSTDelete( bstPtr rootPtr, char *key );

char *HTTreeNodeKey ( treeNode root );
char *HTTreeNodeVal ( treeNode root );
void HTInit( htSlot * hashTable );
htSlot HTSlot( htSlot * hashTable, unsigned int slotId );
bool HTInsert( htSlot * hashTable, unsigned int slotId, char *key, char *value);
bst HTSearch( htSlot slot, char *key );
bool HTDelete( htSlot * hashTable, unsigned int slotId, char *key );

void HTBSTInit( htSlot * hashTable );
bool HTBSTInsert( htSlot * hashTable, char *key, char *value );
element HTBSTSearch( htSlot * hashTable, char *key );
bool HTBSTDelete( htSlot * hashTable, char *key );

#endif
