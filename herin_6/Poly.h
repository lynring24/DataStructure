#include<iostream>
using namespace std;
typedef struct PNode* Pptr;
struct PNode {
	float coef;
	int expon;
	Pptr next;
	Pptr head , tail; //rear = last node of the list
	PNode() { head=tail= next = NULL; };
	PNode(float c, int ex) {
		coef = c; expon = ex;
		next = NULL;
	}
	void attach(float coef, int expon);
};
struct Poly {
	Pptr rear;
	void add(Pptr a, Pptr b);
	//void min(Pptr a, Pptr b);
	Poly() { rear = NULL; }
	void print(float coef, int expon);
};

