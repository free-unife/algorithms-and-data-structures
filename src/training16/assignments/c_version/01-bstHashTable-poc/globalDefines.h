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
#define NUMBER_OF_TESTS 200
#define M 997

unsigned int hash( char *input );

/* LIST struct */
struct listNode {
    char *key;
    char *value;
    struct listNode *next;
    struct listNode *prev;
};

/* The following are only used in LIST. */
typedef struct listNode * list;
typedef list * listPtr;

/* The following are only used in LISTHT. */
typedef listPtr * htListSlot;
typedef list listNode;
typedef listPtr listNodePtr;

/* The following are only used in HTLIST. */
typedef listNode listElement;
typedef listNodePtr listElementPtr;

void LISTInit( listPtr headPtr );
bool LISTEmpty( list head );
char *LISTKey( list head );
char *LISTVal( list head );
list LISTInsert( listPtr headPtr, char *key, char *value );
list LISTSearch( list head, char *key );
bool LISTDelete( listPtr headPtr, char *key );
list LISTClear ( list head );

char *LISTHTListNodeKey ( listNode list );
char *LISTHTListNodeVal ( listNode list );
void LISTHTInit( htListSlot * hashTable );
htListSlot LISTHTSlot( htListSlot * hashTable, unsigned int slotId );
bool LISTHTInsert( htListSlot * hashTable, unsigned int slotId, char *key, char *value );
list LISTHTSearch( htListSlot slot, char *key );
bool LISTHTDelete( htListSlot * hashTable, unsigned int slotId, char *key );
bool LISTHTClearSlot ( htListSlot * hashTable, unsigned int slotId );

void HTLISTInit( htListSlot * hashTable );
bool HTLISTInsert( htListSlot * hashTable, char *key, char *value );
listElement HTLISTSearch( htListSlot * hashTable, char *key );
bool HTLISTDelete( htListSlot * hashTable, char *key );
bool HTLISTClearHashTable( htListSlot * hashTable, unsigned int numberOfSlots );

/* BST struct. */
struct bstNode {
    char *key;
    char *value;
    struct bstNode *left;
    struct bstNode *right;
    struct bstNode *parent;
};

/* The following are only used in BST. */
typedef struct bstNode * bst;
typedef bst * bstPtr;

/* The following are only used in BSTHT. */
typedef bstPtr * htTreeSlot;
typedef bst treeNode;
typedef bstPtr treeNodePtr;

/* The following are only used in HTBST. */
typedef treeNode treeElement;
typedef treeNodePtr treeElementPtr;

/* Prototypes. */
void BSTInit( bstPtr rootPtr );
bool BSTEmpty( bst root );
char *BSTKey( bst root );
char *BSTVal( bst root );
bst BSTInsert( bstPtr rootPtr, char *key, char *value );
bst BSTSearch( bst root, char *key );
bool BSTDelete( bstPtr rootPtr, char *key );
bst BSTClear ( bst root );

char *BSTHTTreeNodeKey ( treeNode root );
char *BSTHTTreeNodeVal ( treeNode root );
bool BSTHTClearSlot ( htTreeSlot * hashTable, unsigned int slotId );
treeNode BSTHTClear ( treeNode root );
void BSTHTInit( htTreeSlot * hashTable );
htTreeSlot BSTHTSlot( htTreeSlot * hashTable, unsigned int slotId );
bool BSTHTInsert( htTreeSlot * hashTable, unsigned int slotId, char *key, char *value );
bst BSTHTSearch( htTreeSlot slot, char *key );
bool BSTHTDelete( htTreeSlot * hashTable, unsigned int slotId, char *key );
bool BSTHTClearSlot ( htTreeSlot * hashTable, unsigned int slotId );

void HTBSTInit( htTreeSlot * hashTable );
bool HTBSTInsert( htTreeSlot * hashTable, char *key, char *value );
treeElement HTBSTSearch( htTreeSlot * hashTable, char *key );
bool HTBSTDelete( htTreeSlot * hashTable, char *key );
bool HTBSTClearHashTable( htTreeSlot * hashTable, unsigned int numberOfSlots );

#endif
