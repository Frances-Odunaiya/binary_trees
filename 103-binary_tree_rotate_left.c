#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate left
 * @tree: binary tree
 * Return: pointer to new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *aux;

	if (!tree || !tree->right)
		return (tree);

	aux = tree->right;
	tree->parent = aux;
	aux->parent = tree->parent;

	tree->right = aux->left;
	if (tree->right)
		tree->right->parent = tree;

	aux->left = tree;

	return (aux);
}
