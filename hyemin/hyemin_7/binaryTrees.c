#include "tree_header.h"

void postorder(tree_ptr ptr) {
	if (ptr) {
		postorder(ptr->left_child);
		postorder(ptr->right_child);
		printf("%d\t", ptr->data);
	}
}

void inorder(tree_ptr ptr){
	if (ptr) {
		inorder(ptr->left_child);
		printf("%d\t", ptr->data);
		inorder(ptr->right_child);
	}
}

void preorder(tree_ptr ptr){
	if (ptr) {
		printf("%d\t", ptr->data);
		preorder(ptr->left_child);
		preorder(ptr->right_child);
	}
}

void level_order(tree_ptr ptr) {
	int front = 0;
	int rear = 0;
	tree_ptr queue[MAX_QUEUE_SIZE];

	if (!ptr) return;
	
	addq(front, &rear, ptr, queue);

	while (1) {
		ptr = deleteq(&front, rear, queue);

		if (ptr) {
			printf("%d\t", ptr->data);
			if (ptr->left_child) addq(front, &rear, ptr->left_child, queue);
			if (ptr->right_child) addq(front, &rear, ptr->right_child, queue);
		}
		else break;
	}
}

void addq(int front, int * rear, tree_ptr ptr, tree_ptr * queue) {
	*rear = (*rear + 1) % MAX_QUEUE_SIZE;

	if (front == *rear) {
		printf("The queue is full!\n");
		reset(rear);
		return;
	}

	queue[*rear] = ptr;
}

tree_ptr deleteq(int * front, int rear, tree_ptr * queue) {
	if (*front == rear) {
		return NULL;
	}

	*front = (*front + 1) % MAX_QUEUE_SIZE;
	return queue[*front];
}

void reset(int * rear) {
	if (*rear > 0) rear--;
	else *rear = MAX_QUEUE_SIZE - 1;
}