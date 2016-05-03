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
     * @brief Pointer to the next listNode.
     */
    struct listNode *next;

    /**
     * @brief Pointer to the previous listNode.
     */
    struct listNode *prev;

    /**
     * @brief Pointer to the node structure which contains key and value
     * fields of the current listNode instance.
     */
    struct Node *parentStructPtr;
};

/**
 * @brief Bst Node Abstract Data Type.
 *
 * @struct bstNode
 */
struct bstNode
{
    /**
     * @brief Pointer to the left bstNode.
     */
    struct bstNode *left;

    /**
     * @brief Pointer to the right bstNode.
     */
    struct bstNode *right;

    /**
     * @brief Pointer to the parent bstNode.
     */
    struct bstNode *parent;

    /**
     * @brief Pointer to the node structure which contains key and value
     * fields of the current listNode instance.
     */
    struct Node *parentStructPtr;
};

/**
 * @brief Node Abstract Data Type.
 *
 * @struct Node
 *
 * @note A node should be only of one type (i.e: either listNode or bstNode is
 * set, but not both).
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
typedef struct Node * node;

/**
 * @typedef node *nodePtr
 */
typedef node * nodePtr;

/**
 * @typedef struct bstNode *bnode
 */
typedef struct bstNode * bnode;

/**
 * @typedef struct listNode *lnode
 */
typedef struct listNode * lnode;

/**
 * @brief Check if any type of pointer is NULL.
 *
 * @param[in] element Any kind of pointer.
 *
 * @retval true element is NULL.
 * @retval false element is not NULL.
 */
extern bool element_null ( void *element );

/**
 * @brief Allocate new space in a safe way.
 *
 * @param[in] size Total size to be allocated .
 *
 * @retval dst The pointer to the new instance of data.
 */
extern void *malloc_safe ( size_t size );

/* ========================================== */

/**
 * @brief Check if the node is NULL.
 *
 * @param[in] n A pointer to a node instance.
 *
 * @retval true The node is NULL.
 * @retval false The node is not NULL.
 */
extern bool node_null ( node n );

/**
 * @brief Get the key from a node.
 *
 * @param[in] n A pointer to a node instance.
 *
 * @retval node->key A memory address corresponding to the key.
 *
 * @Warning The return value can be NULL.
 */
extern char *key_get ( node n );

/**
 * @brief Store the key inside a node.
 *
 * @param[in] n A pointer to a node instance.
 * @param[in] key A memory address corresponding to the key.
 *
 * @retval true The key has been stored correctly.
 * @retval false The key has not been stored because the input node was NULL.
 */
extern bool key_set ( node n, char *key );

/**
 * @brief Get the value from a node.
 *
 * @param[in] n A pointer to a node instance.
 *
 * @retval node->value A memory address corresponding to the value.
 *
 * @Warning The return value can be NULL.
 */
extern char *value_get ( node n );

/**
 * @brief Store the value inside a node.
 *
 * @param[in] n A pointer to a node instance.
 * @param[in] value A memory address corresponding to the value.
 *
 * @retval true The value has been stored correctly.
 * @retval false The value has not been stored because the input node was NULL.
 */
extern bool value_set ( node n, char *value );

bool keys_equal( char *key1, char *key2 );

bool keys_less( char *key1, char *key2 );

bool keys_greater( char *key1, char *key2 );

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
 * @Warning The return value can be NULL.
 */
extern node node_new ( char *key, char * value, char type);

extern void nodes_connect ( node from, node to );

/* Specific */
extern void node_print ( node n );
extern void list_print ( node l );
extern void bst_print ( node b );

/* ========================================== */

extern void BSTInit( nodePtr rootPtr );

extern node BSTLeft ( node root );

extern node BSTRight ( node root );

extern node BSTParent ( node root );

extern node BSTInsert( nodePtr rootPtr, char *key, char *value );

#endif
