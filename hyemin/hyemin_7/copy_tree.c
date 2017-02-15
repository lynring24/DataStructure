#include "tree_header.h"

tree_ptr copyTree(tree_ptr tree) {
	tree_ptr temp;
	if (tree) {
		temp = (tree_ptr)malloc(sizeof(struct node));

		if (IS_FULL(temp)) {
			fprintf(stderr, "The memory is full\n");
			exit(1);
		}

		temp->left_child = copyTree(tree->left_child);
		temp->right_child = copyTree(tree->right_child);
		temp->data = tree->data;

		return temp;
	}
	return NULL;
}