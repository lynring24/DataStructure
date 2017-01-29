
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

typedef struct DNode* Dptr;
struct DNode {
	DNode() {
		value= rand() % 10;
		next = NULL;
		pre = NULL;
	}
	int value;
	Dptr pre;	// previous node
	Dptr next;	// next node;
};
typedef struct DoubleLink DLL;
struct DoubleLink {
	Dptr head;//the first and the last
	DoubleLink() { // node assign
		head = new DNode();
		head->value = NULL;	head->next = head;	head->pre = head;
	}
	void insert(Dptr pre, Dptr node);
	void del(Dptr node);
};