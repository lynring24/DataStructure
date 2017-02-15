#include "tree_header.h"

void eval_tree(eval_ptr node) {
	if (node) {
		eval_tree(node->left_child);
		eval_tree(node->right_child);

		switch (node->data) {
		case not:
			printf("not\t");
			node->value = !(node->right_child->value);
			break;
		case and:
			printf("and\t");
			node->value = (node->left_child->value) && (node->right_child->value);
			break;
		case or :
			printf("or\t");
			node->value = (node->left_child->value) || (node->right_child->value);
			break;
		case true:
			printf("true\t");
			node->value = TRUE;
			break;
		case false:
			printf("false\t");
			node->value = FALSE;
			break;
		default:
			return;
		}
	}
}