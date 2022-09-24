#include "binary_trees.h"

/**
 * nodeNumber - count the nodes of binary tree
 * @tree: pointer to the root of the tree
 * Return: numbers of the tree
 */
int nodeNumber(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + nodeNumber(tree->left) + nodeNumber(tree->right));
}

/**
 * isComplete - check if the tree is complete
 * @tree: pointer to the root of the tree
 * @index: index
 * @count: numbers of node
 * Return: 1 if success otherwise return 0
 */
int isComplete(const binary_tree_t *tree, int index, int count)
{
	if (tree == NULL)
		return (1);
	if (index >= count)
		return (0);
	return (isComplete(tree->left, 2 * index + 1, count) &&
			isComplete(tree->right, 2 * index + 2, count));
}

/**
 * binary_tree_is_complete - check if a binary tree is complete
 * @tree: pointer to the root of the tree
 * Return: 1 success, otherwise return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0;
	int count;

	count = nodeNumber(tree);
	if (tree == NULL)
		return (0);
	return (isComplete(tree, index, count));
}
