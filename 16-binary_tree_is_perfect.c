#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @node: pointer to node to measure the depth
 *
 * Return: depth of node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth;

	depth = 0;
	while (node != NULL)
	{
		depth++;
		node = node->left;
	}

	return (depth);
}

/**
 * isPerfectTree - checks if a bianry treee is perfect
 * @tree: pointer to root node of the tree to count the number of leaves
 * @depth: the depth of the given node
 * @level: node level
 *
 * Return: 1 SUCCESS, otherwise 0 (incl if tree is NULL)
 */

int isPerfectTree(const binary_tree_t *tree, int depth, int level)
{
	binary_tree_t *r = tree->right, *l = tree->left;

	if (tree == NULL)
		return (0);

	if (l == NULL && r == NULL)
	{
		return (1);
	}
	if (binary_tree_depth(l) != binary_tree_depth(r))
		return (0);
	if (l == NULL || r == NULL)
		return (0);

	return (isPerfectTree(tree->left, depth, level + 1) &&
			isPerfectTree(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - check if the node is perfect or not
 * @tree: pointer to the root of the binary tree
 * Return: 1 SUCCESS, otherwise 0 (incl if tree is NULL)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);
	depth = binary_tree_depth(tree);

	return (isPerfectTree(tree, depth, 0));
}
