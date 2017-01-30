#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define IS_FULL(node) (!(node))

typedef struct thread_node * node;
typedef struct thread_node {
	int data;
	node llink;
	node rlink;
};

node tree_insert(node * ptr, int data);
void tree_deletion(node * ptr, int data);
node make_node(int data);
void inorder(node ptr);