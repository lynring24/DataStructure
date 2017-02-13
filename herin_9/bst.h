#include "Node.h" 
/*
left sub tree < the root < right sub tree
*/
struct BST {
	ptr root;
	BST() {
		root = NULL;
		for (int i = 0; i < 10; i++)
			insert(i*(-1)+4);
		test_inorder(root);
		cout << endl;
		for (int i = 9; i > -1; i--) {
			del(i*(-1) + 4);
			test_inorder(root);
			cout << endl;
		}
	}
	void insert(int i);
	ptr overlap(int key); // check out overlap 
	void test_inorder(ptr tree);
	void del(int i);
	bool ISLEAF(ptr node);
	ptr LMax(ptr tree);
	ptr RMin(ptr tree);
	ptr fParent(ptr tree);
	ptr fNode(int key);
};
