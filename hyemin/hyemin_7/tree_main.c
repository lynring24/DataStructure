#include "tree_header.h"

int main() {
	// start setting a tree!
	tree_ptr ptr = (tree_ptr)malloc(sizeof(struct node));
	tree_ptr copy_tree = (tree_ptr)malloc(sizeof(struct node));
	tree_ptr leaf[TREE_SIZE] = { NULL };

	if (IS_FULL(ptr&&copy_tree)) {
		fprintf(stderr, "The heap is full\n");
		exit(1);
	}

	ptr->data = 1;

	for (int i = 0; i < TREE_SIZE; i++) {
		leaf[i] = (tree_ptr)malloc(sizeof(struct node));

		if (IS_FULL(leaf[i])) {
			fprintf(stderr, "The heap is full\n");
			exit(1);
		}

		leaf[i]->data = i + 2;
		leaf[i]->left_child = NULL;
		leaf[i]->right_child = NULL;
	}

	ptr->left_child = leaf[0];
	ptr->right_child = leaf[1];
	leaf[0]->left_child = leaf[2];
	leaf[0]->right_child = leaf[3];
	leaf[1]->left_child = leaf[4];
	// finish setting a tree!

	// start setting evaluation tree!
	eval_ptr node[NODE] = { NULL };

	for(int i=0; i<NODE; i++){
		node[i] = (eval_ptr)malloc(sizeof(struct evaluation));
		
		node[i]->left_child = NULL;
		node[i]->right_child = NULL;
	}

	node[0]->data = or ;
	node[0]->left_child = node[1];
	node[0]->right_child = node[2];

	node[1]->data = or ;
	node[1]->left_child = node[3];
	node[1]->right_child = node[4];

	node[2]->data = not;
	node[2]->right_child = node[5];

	node[3]->data = and;
	node[3]->left_child = node[6];
	node[3]->right_child = node[7];

	node[4]->data = and;
	node[4]->left_child = node[8];
	node[4]->right_child = node[9];

	node[5]->value = E;

	node[6]->value = A;

	node[7]->data = not;
	node[7]->right_child = node[10];

	node[8]->data = not;
	node[8]->right_child = node[11];

	node[9]->value = D;
	
	node[10]->value = B;

	node[11]->value = C;
	// finish setting evaluation tree!

	printf("\n---------------<Postorder>---------------\n");
	postorder(ptr);
	printf("\n");

	printf("\n---------------<Inorder>-----------------\n");
	inorder(ptr);
	printf("\n");

	printf("\n---------------<Preorder>----------------\n");
	preorder(ptr);
	printf("\n");

	printf("\n--------------<Level order>---------------\n");
	level_order(ptr);
	printf("\n");

	printf("\n--------------<Copy tree(Level order)>---------------\n");
	copy_tree = copyTree(ptr);
	level_order(copy_tree);
	printf("\n");

	printf("\n-----------------<Evaluation>-----------------\n");
	eval_tree(node[0]);
	printf("\nanswer: %d\n\n", node[0]->value);
}

