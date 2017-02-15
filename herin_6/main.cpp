#include"Node.h"
#include"DNode.h"
#include"Poly.h"

void main() {
	srand((unsigned)time(NULL)); // can use srand only in main();
	cout << "1.Polynomial" << endl;
	Pptr p1=new PNode(), p2 = new PNode();
	float coef; int expon;
	cout << "[PolyA]"<<endl;
	do {
		cout << "[C*x^E]:";
		cin >> coef >> expon;
		p1->attach(coef, expon);
	} while (expon != 0);

	cout <<endl<<"[PolyB]"<<endl;
	do {
		cout << "[C*x^E]:";
		cin >> coef >> expon;
		p2->attach(coef, expon);
	} while (expon != 0);
	
	cout << endl << ">>add:";
	Poly * poly = new Poly();
	poly->add(p1->head, p2->head);
	
	cout << endl << endl << "2.Circular" << endl;
	CLL cll=new Circular();//Circular Linked List
	for (int i = 0; i < 10; i++)
		cll->insert(new Node());

	int i = 0; 
	for (ptr temp = cll->strt ; i<18; temp = temp->next,i++) {
		cout << temp->value <<" ";
		if (i == 9)cout << " --- ";
	}

	cout << endl << endl<<"3.Double LInked List" << endl;
	DLL dll;
	cout << "insert:";
	for (int i = 0; i < 12; i++)
		dll.insert(NULL,new DNode());
	cout << endl;
	Dptr temp = dll.head;
	do {
		if (temp != dll.head) cout << temp->value << "-";
		else
			cout << " H :" << " (";
		temp = temp->next;
	} while (temp!=dll.head);
	cout << ")" << endl << "del:";

	for (int i = 0; i < 13; i++)
		dll.del(dll.head->pre);
	cout << endl;
}
