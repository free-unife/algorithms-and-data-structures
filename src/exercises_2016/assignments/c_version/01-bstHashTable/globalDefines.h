/**
 * @file globalDefines.h
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Header file containing exportable methods.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#ifndef M_GLOBALDEFINES_H

/**
 * @brief Include the main header.
 */
#define M_GLOBALDEFINES_H

/**
 * @brief Tell the compiler that we want ISO C99 source, and check if the
 * system has ANSI C 99.
 */
#define ISOC99_SOURCE
#define _POSIX_C_SOURCE 199309L
#if __STDC_VERSION__ != 199901L
#error "ANSI C99 not available"
#endif

/*
 * Comment out the following to disable all asserts.
 */
/*#define NDEBUG*/

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief List Node Abstract Data Type.
 *
 * @struct listNode
 */
struct listNode
{
    /**
     * @brief Pointer to the next Node object.
     */
  struct Node *next;

    /**
     * @brief Pointer to the previous Node obkect.
     */
  struct Node *prev;
};

/**
 * @brief Bst Node Abstract Data Type.
 *
 * @struct bstNode
 */
struct bstNode
{
    /**
     * @brief Pointer to the left Node object.
     */
  struct Node *left;

    /**
     * @brief Pointer to the right Node object.
     */
  struct Node *right;

    /**
     * @brief Pointer to the parent Node object.
     */
  struct Node *parent;
};

/**
 * @brief Node Abstract Data Type.
 *
 * @struct Node
 *
 * @note A node should be only of one type (i.e: either listNode or bstNode is
 * set, but not both). If you want you could use both ln and bn pointers at the
 * same time, but keep in mind to change the code appropriately.
 */
struct Node
{
  char *key;
  char *value;

    /**
     * @brief Pointer to a listNode struct which contains listNode information.
     */
  struct listNode *ln;

    /**
     * @brief Pointer to a bstNode struct which contains bstNode information.
     */
  struct bstNode *bn;
};

/**
 * @typedef struct Node *node
 */
typedef struct Node *node;

/**
 * @typedef node *nodePtr
 */
typedef node *nodePtr;

/**
 * @typedef struct bstNode *bnode
 */
typedef struct bstNode *bnode;

/**
 * @typedef struct listNode *lnode
 */
typedef struct listNode *lnode;

/**
 * @brief HashTable Abstract Data Type.
 *
 * @struct HashTable
 *
 * @note Each element in the whole hash table must be unique.
 */
struct HashTable
{
  /**
   * @brief Pointer to the array of nodePtr
   */
  nodePtr *ptr;

  /**
   * @brief Number of slots of the hash table
   */
  unsigned int numberOfSlots;

  /**
   * @brief 'b' or 'l' for either bsts or lists.
   */
  char type;
};

/**
 * @typedef struct HashTable *ht
 */
typedef struct HashTable *ht;

/* ========================================== */

/**
 * @brief Check if any type of pointer is NULL.
 *
 * @param[in] element Any kind of pointer.
 *
 * @retval true element is NULL.
 * @retval false element is not NULL.
 */
extern bool element_null (void *element);

/**
 * @brief Allocate new space in a safe way.
 *
 * @param[in] size Total size to be allocated .
 *
 * @retval dst The pointer to the new instance of data.
 */
extern void *malloc_safe (size_t size);

/* ========================================== */

/**
 * @brief Check if the node is NULL.
 *
 * @param[in] n A pointer to a node instance.
 *
 * @retval true The node is NULL.
 * @retval false The node is not NULL.
 */
extern bool node_null (node n);

/**
 * @brief Get the key from a node.
 *
 * @param[in] n A pointer to a node instance.
 *
 * @retval node->key A memory address corresponding to the key.
 *
 * @warning The return value can be NULL.
 */
extern char *key_get (node n);

/**
 * @brief Store the key inside a node.
 *
 * @param[in] n A pointer to a node instance.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval true The key has been stored correctly.
 * @retval false The key has not been stored because the input node was NULL.
 */
extern bool key_set (node n, char *key);

/**
 * @brief Check if two keys are equal.
 *
 * @param[in] key1 A memory address corresponding to the first key.
 * @param[in] key2 A memory address corresponding to the second key.
 *
 * @retval true The two keys are equal.
 * @retval false The two keys differ.
 */
extern bool keys_equal (char *key1, char *key2);

/**
 * @brief Check if the first key is smaller than the second.
 *
 * @param[in] key1 A memory address corresponding to the first key.
 * @param[in] key2 A memory address corresponding to the second key.
 *
 * @retval true key1 is smaller than key2.
 * @retval false key1 is not smaller than key2.
 */
extern bool keys_less (char *key1, char *key2);

/**
 * @brief Check if the first key is bigger than the second.
 *
 * @param[in] key1 A memory address corresponding to the first key.
 * @param[in] key2 A memory address corresponding to the second key.
 *
 * @retval true key1 is bigger than key2.
 * @retval false key1 is not bigger than key2.
 */
extern bool keys_greater (char *key1, char *key2);

/**
 * @brief Get the value from a node.
 *
 * @param[in] n A pointer to a node instance.
 *
 * @retval node->value A memory address corresponding to the value.
 *
 * @warning The return value can be NULL.
 */
extern char *value_get (node n);

/**
 * @brief Store the value inside a node.
 *
 * @param[in] n A pointer to a node instance.
 * @param[in] value A memory address corresponding to the value.
 *
 * @retval true The value has been stored correctly.
 * @retval false The value has not been stored because the input node was NULL.
 */
extern bool value_set (node n, char *value);

/* ========================================== */

/**
 * @brief Create a generic new node.
 *
 * @param[in] key A memory address corresponding to the key.
 * @param[in] value A memory address corresponding to the value.
 * @param[in] type A character corresponding to the type of node to be
 * created.
 *
 * @note type can either be 'b' or 'l', for either bsts or lists.
 *
 * @retval new_node A memory address corresponding to the new node.
 *
 * @warning The return value can be NULL.
 */
extern node node_new (char *key, char *value, char type);

/**
 * @brief Delete a generic node.
 *
 * @param[in] nPtr A memory address containing the pointer of the node.
 * @param[in] type A character corresponding to the type of node to be
 * deleted.
 *
 * @note type can either be 'b' or 'l', for either bsts or lists.
 */
extern void node_delete (nodePtr nPtr, char type);


/**
 * @brief Set a node object to NULL.
 *
 * @retval npt A memory address corresponding to the new instance of a nodePtr
 * object.
 *
 * @warning The return value can be NULL.
 */
extern nodePtr nodeptr_new (void);

/* ========================================== */

/**
 * @brief Check if the input tree is a BST.
 *
 * @param[in] root A pointer to the BST.
 * @param[in] minKey A memory address corresponding to the minimum key value.
 * @param[in] maxKey A memory address corresponding to the maximum key value.
 *
 * @retval true The input tree is a BST.
 * @retval false The input tree is not a BST.
 */
extern bool BSTIs (node root, char *minKey, char *maxKey);

/**
 * @brief Insert a new node in a specified BST.
 *
 * @param[in] rootPtr A memory address containing the pointer to the root node
 * (BST).
 * @param[in] key A memory address corresponding to the key.
 * @param[in] value A memory address corresponding to the value.
 *
 * @retval new_node A memory address corresponding to the new node.
 *
 * @warning The return value can be NULL.
 */
extern node BSTInsert (nodePtr rootPtr, char *key, char *value);

/**
 * @brief Search for a node with a given key in a specified BST.
 *
 * @param[in] root A pointer to the BST.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval root A memory address corresponding to the searched node.
 *
 * @warning The return value can be NULL.
 */
extern node BSTSearch (node root, char *key);

/**
 * @brief Delete the node with the given key in a specified BST.
 *
 * @param[in] root A pointer to the BST.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval true The node was deleted.
 * @retval false The node was not deleted.
 *
 * @note return value is false if root is empty or the specified element was
 * not found.
 */
extern bool BSTDelete (nodePtr rootPtr, char *key);

/**
 * @brief Delete the BST starting from the specified point.
 *
 * @param[in] root A pointer to the BST.
 *
 * @retval NULL
 *
 * @note Usually this function is used to delete the whole tree.
 */
extern node BSTClear (node root);

/**
 * @brief Print a BST in pre-order criteria.
 *
 * @param[in] root A pointer to the BST.
 */
extern void BSTPrint (node root);

/* ========================================== */

/**
 * @brief Insert a new node in a specified LIST.
 *
 * @param[in] headPtr A memory address containing the pointer to the head node
 * (BST).
 * @param[in] key A memory address corresponding to the key.
 * @param[in] value A memory address corresponding to the value.
 *
 * @retval new_node A memory address corresponding to the new node.
 *
 * @warning The return value can be NULL.
 */
extern node LISTInsert (nodePtr headPtr, char *key, char *value);

/**
 * @brief Search for a node with a given key in a specified LIST.
 *
 * @param[in] head A pointer to the LIST.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval head A memory address corresponding to the searched node.
 *
 * @warning The return value can be NULL.
 */
extern node LISTSearch (node head, char *key);

/**
 * @brief Delete the node with the given key in a specified LIST.
 *
 * @param[in] head A pointer to the LIST.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval true The node was deleted.
 * @retval false The node was not deleted.
 *
 * @note return value is false if head is empty or the specified element was
 * not found.
 */
extern bool LISTDelete (nodePtr headPtr, char *key);

/**
 * @brief Delete the LIST starting from the specified point.
 *
 * @param[in] head A pointer to the LIST.
 *
 * @retval NULL
 *
 * @note Usually this function is used to delete the whole list.
 */
extern node LISTClear (node head);

/**
 * @brief Print a LIST element by element with the same order as when they
 * were inserted.
 *
 * @param[in] head A pointer to the LIST.
 */
extern void LISTPrint (node head);

/* ========================================== */

/**
 * @brief Create a new hash table.
 *
 * @param[in] numberOfSlots The total number of slots of the hash table.
 * @param[in] type A character corresponding to the type of hash table to be
 * created.
 *
 * @retval hashTable A memory address corresponding to the hash table just
 * created.
 *
 * @note type can either be 'b' or 'l', for either bsts or lists.
 */
extern ht HTInit (unsigned int numberOfSlots, char type);

/**
 * @brief Insert a new key value tuple in the specified hash table.
 *
 * @param[in] hashTable A memory address corresponding to the hash table.
 * @param[in] key A memory address corresponding to the key.
 * @param[in] value A memory address corresponding to the value.
 *
 * @retval true The tuple was inserted.
 * @retval false The tuple was not inserted.
 */
extern bool HTInsert (ht hashTable, char *key, char *value);

/**
 * @brief Search for a node with a given key in a specified hash table.
 *
 * @param[in] ht A pointer to the hash table.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval node A memory address corresponding to the searched node.
 *
 * @warning The return value can be NULL.
 */
extern node HTSearch (ht hashTable, char *key);

/**
 * @brief Delete the node with the given key in a specified hash table.
 *
 * @param[in] head A pointer to the hash table.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval true The node was deleted.
 * @retval false The node was not deleted.
 *
 * @note return value is false if the computed slot is empty or the specified
 * element was not found.
 */
extern bool HTDelete (ht hashTable, char *key);

/**
 * @brief Delete the whole hash table.
 *
 * @param[in] hashTAble A memory address corresponding to the pointer of the
 * hash table .
 *
 * @retval true The whole hash table has been deleted correctly.
 * @retval false Some problem occurred while deleting a slot.
 */
extern bool HTClear (ht * hashTable);

/**
 * @brief Print the hash table, slot by slot, starting from slot 0 to slot
 * M - 1.
 *
 * @param[in] hashTable A pointer to the hash table.
 */
extern void HTPrint (ht hashTable);
#endif
