/**
 * @file bst.c
 * @author Franco Masotti
 * @date 02 May 2016
 * @brief Bst functions.
 * @copyright Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 *                  Danny Lessio
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#include "globalDefines.h"

/**
 * @brief Get the left node of the input node.
 *
 * @param[in] root A pointer to the BST.
 *
 * @retval root->bn->left A memory address corresponding to the left node.
 *
 * @warning The return value can be NULL.
 */
static node BSTLeft (node root);

/**
 * @brief Get the right node of the input node.
 *
 * @param[in] root A pointer to the BST.
 *
 * @retval root->bn->right A memory address corresponding to the right node.
 *
 * @warning The return value can be NULL.
 */
static node BSTRight (node root);

/**
 * @brief Get the parent node of the input node.
 *
 * @param[in] root A pointer to the BST.
 *
 * @retval root->bn->parent A memory address corresponding to the parent node.
 *
 * @warning The return value can be NULL.
 */
static node BSTParent (node root);

/**
 * @brief Get the node with the maximum root starting from the input node.
 *
 * @param[in] key A pointer to the BST.
 *
 * @retval BSTMaxElement A memory address corresponding to the maximum node in
 * value.
 *
 * @warning The return value can be NULL if the input tree is NULL.
 */
static node BSTMaxElement (node root);

/**
 * @brief Get the predecessor node of the input node.
 *
 * @param[in] root A pointer to the BST.
 *
 * @retval BSTPredecessor A memory address corresponding to the parent node.
 *
 * @warning The return value can be NULL if the input tree is NULL.
 */
static node BSTPredecessor (node root);

/**
 * @brief Check if the input node is a leaf.
 *
 * @param[in] root A pointer to the BST.
 *
 * @retval true Input node is a leaf.
 * @retval false Input node is not a leaf.
 */
static bool BSTIsLeaf (node root);

/**
 * @brief Check if the input node has a left child only.
 *
 * @param[in] root A pointer to the BST.
 *
 * @retval true Input node has a left child only.
 * @retval true Input node has not a left child only.
 */
static bool BSTHasLeftOnly (node root);

/**
 * @brief Check if the input node has a right child only.
 *
 * @param[in] root A pointer to the BST.
 *
 * @retval true Input node has a right child only.
 * @retval true Input node has not a right child only.
 */
static bool BSTHasRightOnly (node root);

/**
 * @brief Function that creates a new node with the specified values in the
 * position pointed by rootPtr.
 *
 * @param[in] rootPtr A memory address containing the pointer to the BST.
 * @param[in] parentNode A pointer to the parent node of the one to be
 * inserted.
 * @param[in] key A pointer to the key.
 * @param[in] key A pointer to the value.
 *
 * @retval *rootPtr A pointer to the new node.
 *
 * @warning The return value can be NULL.
 */
static node BSTNewNode (nodePtr rootPtr, node parentNode, char *key,
			char *value);
/**
 * @brief Function that looks for the correct position where to insert a new 
 * node.
 *
 * @param[in] root A pointer to the BST.
 * @param[in] key A pointer to the key.
 * @param[in] value A pointer to the value.
 *
 * @retval BSTNewNode A pointer to the new node.
 *
 * @note This function is called only if the original BST is not empty.
 *
 * @warning The return value can be NULL.
 */
static node BSTNonEmptyInsert (node root, char *key, char *value);

/**
 * @brief Function that looks (and deletes) for the correct position where to 
 * delete a specified node.
 *
 * @param[in] root A pointer to the BST.
 * @param[in] key A pointer to the key.
 * @param[in] key A pointer to the value.
 *
 * @retval true The node has been deleted.
 * @retval true The node has not deleted.
 *
 * @note return value is false if root is empty or the specified element was
 * not found.
 */
static bool BSTNonEmptyDelete (nodePtr rootPtr, node root, char *key);

static node
BSTLeft (node root)
{
  return (node_null (root) ? NULL : root->bn->left);
}

static node
BSTRight (node root)
{
  return (node_null (root) ? NULL : root->bn->right);
}

static node
BSTParent (node root)
{
  return (node_null (root) ? NULL : root->bn->parent);
}

static node
BSTMaxElement (node root)
{
  if (node_null (root))
    return NULL;
  else
    return (!node_null (BSTRight (root)) ?
	    BSTMaxElement (BSTRight (root)) : root);
}

static node
BSTPredecessor (node root)
{
  return (node_null (root) ? NULL : BSTMaxElement (BSTLeft (root)));
}

static bool
BSTIsLeaf (node root)
{
  assert (!node_null (root));
  return ((node_null (BSTLeft (root))) && (node_null (BSTRight (root))));
}

static bool
BSTHasLeftOnly (node root)
{
  assert (!node_null (root));
  return ((node_null (BSTLeft (root))) && (!node_null (BSTRight (root))));
}

static bool
BSTHasRightOnly (node root)
{
  assert (!node_null (root));
  return ((!node_null (BSTLeft (root))) && (node_null (BSTRight (root))));
}

static node
BSTNewNode (nodePtr rootPtr, node parentNode, char *key, char *value)
{
  (*rootPtr) = node_new (key, value, 'b');
  (*rootPtr)->bn->left = NULL;
  (*rootPtr)->bn->right = NULL;

  if (node_null (parentNode))
    (*rootPtr)->bn->parent = NULL;
  else
    (*rootPtr)->bn->parent = parentNode;

  return *rootPtr;
}


static node
BSTNonEmptyInsert (node root, char *key, char *value)
{
  /*
   * since &(right(root)) and &(left(root)) cannot be done, we can't use the
   * ADT functions and we can't use an extra variable.
   * http://stackoverflow.com/questions/11397818/using-unary-operator-on-function-return-value
   * Moreover the compound literal trick doesn't work (assertion failed).
   */

  if (keys_less (key, key_get (root)))
    {
      if (!node_null (BSTLeft (root)))
	return (BSTNonEmptyInsert (BSTLeft (root), key, value));

      else
	return (BSTNewNode (&(root->bn->left), root, key, value));

    }
  else if (keys_greater (key, key_get (root)))
    {
      if (!node_null (BSTRight (root)))
	return (BSTNonEmptyInsert (BSTRight (root), key, value));

      else
	return (BSTNewNode (&(root->bn->right), root, key, value));
    }
  /*
   * Key equal (i.e. element already in tree.)
   */
  else
    return NULL;
}

node
BSTInsert (nodePtr rootPtr, char *key, char *value)
{
  /*
   * Since random elements are generated, we can't use the following assert:
   * assert (key is not present in tree).
   * assert (node_null (BSTSearch (*ptree, key)));
   * Instead of this, we return NULL if a key is already present in the
   * tree.
   */
  if (element_null (key) || element_null (value))
    return NULL;
  else if (node_null (*rootPtr))
    return (BSTNewNode (rootPtr, NULL, key, value));
  else
    return (BSTNonEmptyInsert (*rootPtr, key, value));
}

node
BSTSearch (node root, char *key)
{
  if (node_null (root))
    return NULL;
  else if (keys_equal (key_get (root), key))
    return root;
  else if (keys_greater (key_get (root), key))
    return (BSTSearch (BSTLeft (root), key));
  else
    return (BSTSearch (BSTRight (root), key));
}

static bool
BSTNonEmptyDelete (nodePtr rootPtr, node root, char *key)
{
  if (!keys_equal (key, key_get (root)))
    {
      if (keys_less (key, key_get (root)))
	{
	  if (node_null (BSTLeft (root)))
	    return false;
	  else
	    return (BSTNonEmptyDelete
		    (&(root->bn->left), BSTLeft (root), key));
	}
      else
	{
	  if (node_null (BSTRight (root)))
	    return false;
	  else
	    return (BSTNonEmptyDelete
		    (&(root->bn->right), BSTRight (root), key));
	}
    }
  /*
   * key == root -> key.
   */
  else
    {
      if (BSTIsLeaf (root))
	{
	  *rootPtr = NULL;
	  node_delete (&root, 'b');
	}
      else if (!BSTHasLeftOnly (root))
	{
	  *rootPtr = BSTRight (root);
	  node_delete (&root, 'b');
	}
      else if (!BSTHasRightOnly (root))
	{
	  *rootPtr = BSTLeft (root);
	  node_delete (&root, 'b');
	}
      /*
       * Two sons.
       */
      else
	{
	  root->key = key_get (BSTPredecessor (root));
	  root->value = value_get (BSTPredecessor (root));
	  root->bn->parent = BSTParent (root);
	  return (BSTNonEmptyDelete
		  (&(root->bn->left), BSTLeft (root), key_get (root)));
	}
    }

  return true;
}

bool
BSTDelete (nodePtr rootPtr, char *key)
{
  /*
   * An empty tree cannot be deleted.
   */
  if (node_null (*rootPtr))
    return false;
  else
    return (BSTNonEmptyDelete (rootPtr, *rootPtr, key));
}

/* Pre order visit to delete the whole tree.
 * we don't care about repositioning nodes or saving pointers.
 */
node
BSTClear (node root)
{
  if (node_null (root))
    return NULL;

  BSTClear (BSTLeft (root));
  BSTClear (BSTRight (root));
  node_delete (&root, 'b');

  return NULL;
}

bool
BSTIs (node root, char *minKey, char *maxKey)
{
  if (node_null (root))
    return true;
  if (keys_less (key_get (root), minKey)
      || keys_greater (key_get (root), maxKey))
    return false;

  return (BSTIs (BSTLeft (root), minKey, key_get (root))
	  && BSTIs (BSTRight (root), key_get (root), maxKey));
}

void
BSTPrint (node root)
{
  if (node_null (root))
    return;

  fprintf (stderr, "%s %s\n", key_get (root), value_get (root));
  BSTPrint (BSTLeft (root));
  BSTPrint (BSTRight (root));
}
