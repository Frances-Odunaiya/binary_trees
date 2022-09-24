#include "binary_trees.h"

/**
 * binary_tree_sibling - find all sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: a pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}


/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to node to find uncle
 * Return: pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (node == NULL || node->parent == NULL)
		return (0);

	uncle = binary_tree_sibling(node->parent);
	return (uncle);
}
