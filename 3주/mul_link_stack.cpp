#include <iostream>
using namespace std;

#define MAX 10
 
class Element {
public:
	int key;
};

typedef class Stack {
public:
	Element item;
	Stack * link;
};

Stack * top[MAX];

void add(Stack * *top, Element item) {
	Stack * temp = (Stack *) new Stack;
	if (!temp)
		return;

	temp->item = item;
	temp->link = *top;
	*top = temp;
}

Element del_stack(Stack* *top) {
	Element item;
	Stack * temp = *top;
	if (*top==NULL) {
		item.key = -1;
		return item;
	}
	
	item = temp->item;
	*top = temp->link;
	delete temp;
	return item;
}


int main () {
	int i;
	for (i=0; i<MAX; i++)
		top[i] = NULL;

	int k=1, n;
	cout<<"°³¼ö: ";
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>k;
		Element item;
		item.key = k;
		add(&top[0], item);
	}

	for (i=0; i<n; i++) {
		cout<<del_stack(&top[0]).key;
	}
}