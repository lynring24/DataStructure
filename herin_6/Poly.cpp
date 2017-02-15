#include "Poly.h"
void PNode::attach(float coef, int expon) { // get the list of poly
	Pptr temp = new PNode(coef, expon);
	if (tail == NULL) {//empty{
		tail = head = temp;
	}
	else
	{
		temp->next = head;
		head= temp;
	}
}
void Poly::add(Pptr a, Pptr b) { //smaller comes first
	while (a&&b) {
		if (a->expon > b->expon) {
			print(b->coef, b->expon);
			b = b->next;
		}
		else if (a->expon < b->expon) {
				print(a->coef, a->expon);
			a = a->next;
		}
		else {
			float sum = a->coef + b->coef;
			if (sum)
				print(sum, b->expon);
			a = a->next; b = b->next;
		}
	}
	for (; a; a = a->next) {
		print(a->coef,a->expon);
	}
	for (; b; b = b->next) {
		print(b->coef, b->expon);
	}
}

/*void Poly::min(Pptr a, Pptr b) {
	Pptr front, temp;
	float sum;
	rear = new PNode();
	if (rear != NULL) {
		fprintf(stderr, "The memory is full\n");
	}
	front = rear;
	while (a&&b) {
		if (a->expon < b->expon) {
			attach((-1)*b->coef, b->expon);
			b = b->next;
		}
		else if (a->expon > b->expon) {
			attach(a->coef, a->expon);
			a = a->next;
		}
		else {
			sum = a->coef + b->coef;
			if (sum)
				attach(sum, a->expon);
			a = a->next; b = b->next;
		}
	}
	for (; a; a = a->next) attach(a->coef, a->expon);
	for (; b; b = b->next) attach((-1)*b->coef, b->expon);
	rear->next = NULL;
	temp = front; front = front->next; free(temp);
}*/

void Poly::print(float coef, int expon) {
	
	cout << coef << "x" << expon<< " + ";
	
}