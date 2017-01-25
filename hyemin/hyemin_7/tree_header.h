#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
#define TREE_SIZE 5
#define TRUE 1
#define FALSE 0
#define NODE 12
#define IS_FULL(ptr) (!(ptr))

typedef struct node * tree_ptr;
typedef struct node {
	int data;
	tree_ptr left_child;
	tree_ptr right_child;
};

typedef enum{A=0, B=1, C=1, D=0, E=1} term;
typedef enum{not, and, or, true, false} logical;
typedef struct evaluation * eval_ptr;
typedef struct evaluation {
	eval_ptr left_child;
	logical data;
	int value;
	eval_ptr right_child;
};

void postorder(tree_ptr ptr);
void inorder(tree_ptr ptr);
void preorder(tree_ptr ptr);
void level_order(tree_ptr ptr);
void addq(int front, int * rear, tree_ptr ptr, tree_ptr * queue);
tree_ptr deleteq(int * front, int rear, tree_ptr * queue);
void reset(int * rear);

tree_ptr copyTree(tree_ptr tree);

void eval_tree(eval_ptr node);