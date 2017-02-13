#include<iostream>
using namespace std;
typedef struct Node * ptr;

struct Node {
	ptr left;
	int value;
	ptr right;

	Node() { left = right = 0; }
	Node(int v) { left = right = NULL; value = v; }
};