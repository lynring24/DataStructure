#include<iostream>
#include<time.h>
#include<stdlib.h>
typedef struct Node* ptr;
struct Node {
	int value;
	ptr next;	//next node
	Node() {
		value = rand() % 10;
		next = NULL;
	}
};
struct Circular {
	static const int max = 10;//max size of memory;
	 ptr strt=NULL;
	 ptr avail=NULL;				//recycle_func
	ptr getNode();					//recycle_func
	void recycle(ptr ptr);			//recyle_func
	void insert(ptr node);
};
typedef struct Circular* CLL;
using namespace std;
