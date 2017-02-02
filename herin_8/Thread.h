#include<iostream>
#include<stdbool.h>
using namespace std;

typedef struct Thread* thrd;
struct Thread {
	bool leftThrd; // whether or not thread child is null
	thrd left;
	char data;
	thrd right;
	bool rightThrd;
	Thread(char c) {
		leftThrd = rightThrd = true;
		left = right = 0;
		data = c;
	}
};
struct TBT { // Inital struct for trees
	 thrd head;
	 TBT() {
		head = new Thread('-');
		head->right = head;
		thrd A = head->left=new Thread('A');
		set(head);
		thrd B = A->left = new Thread('B');
		thrd C = A->right = new Thread('C');
		set(A);
		thrd D = B->left = new Thread('D');
		thrd E = B->right= new Thread('E');
		set(B);
		thrd F = C->left = new Thread('F');
		thrd G = C->right = new Thread('G');
		set(C);
		thrd H = D->left = new Thread('H');
		thrd I = D->right = new Thread('I'); 
		set(D);
		//leaf thread
		
		H->left = head;		H->right = D;
		I->left = D;		I->right = B;
		E->left = B;		E->right = A;
		F->left = A;		F->right = C;
		G->left = C;		G->right = head;
		//connection test
		/*
		H->left = H->right = NULL;
		I->left = I->right = NULL;
		E->left = E->right = NULL;
		F->left = F->right = NULL;
		G->left = G->right = NULL;
		*/
	}
	void set(thrd node); 
	void InOrder(thrd head);
	thrd post(thrd node);
	void TBT::Test(thrd tree);
};