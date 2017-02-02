#include <iostream>
/*
Max Tree : a tree that each node's value is greater than those of its children
Max heap: a max tree that satisfies the properties of complete binary tree
CBT: Nodes are present in order of left to right from the root to botton with no mission node;
Root : max value;
*/
using namespace std;

typedef struct Node * ptr;
struct Node {

	ptr left;
	int data;
	ptr right;
	Node() {
		left = right = 0;
	}
	Node(int n) {
		left = right = 0;
		data = n;
	}
};

struct Heap{
	ptr root;
	static const int MAX= 8;
	int top;
	Node heap[MAX];
	Heap() {
		top = -1;

		for (int i = 1; i < 34; i += 4)
			insert(i);
		cout << "inserted(): ";
		for (int i = 0; i < MAX; i++)
			cout << heap[i].data << " ";

		cout << endl<< "delele(): ";
		for (int i = 0; i < MAX + 1; i++) {
			Node temp = del();
			if(temp.data > 0) cout << temp.data << " ";
		}

	}
	void insert(int item);
	Node del();// # of nodes;
	void minHeap(int tree);
};