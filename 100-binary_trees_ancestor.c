#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: The depth of the node, if tree is NULL return 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *tmp;

	if (!tree)
		return (0);

	tmp = tree;
	while (tmp->parent)
		depth += 1, tmp = tmp->parent;
	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor (LCA) of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: A pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found return NULL.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t depth_first = 0, depth_second = 0;

	if (!first || !second)
		return (NULL);
	/*Finds depth of each node */
	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	/*Set pointers in the same level to compare them*/
	while (depth_first > depth_second)
		first = first->parent, depth_first -= 1;
	while (depth_first < depth_second)
		second = second->parent, depth_second -= 1;

	/*Compare the nodes going up the tree*/
	while (first)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	/*If any node makes match return null*/
	return (NULL);
}
