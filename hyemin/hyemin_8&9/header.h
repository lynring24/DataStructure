#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define IS_FULL(node) (!(node))
#define MAX_ELEMENTS 10
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct thread_node * node;
typedef struct thread_node {
	int data;
	node llink;
	node rlink;
};

typedef struct {
	int key;
}element;
element heap[MAX_ELEMENTS];

node tree_insert(node * ptr, int data);
void tree_deletion(node * ptr, int data);
node make_node(int data);
void inorder(node ptr);
void heap_insertion(element key, int *n);
void heap_deletion(int *n, element * root);
bool heap_find(int key, int front, int rear);