#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

class Node {
public:
	int data;
	Node * link;
};
Node * ptr = NULL;

void insert(Node* *ptr, Node * node, int d) {
	Node * temp;
	temp = (Node *) new Node;
	if (!temp) //full
		return;

	temp->data = d;
	if (*ptr) {
		if (node) {
			temp->link = node->link;
			node->link = temp;
		}
		else {
			temp->link = *ptr;
			*ptr = temp;
		}
	}
	else { //empty
		temp->link = NULL;
		*ptr = temp;
	}
}

void delNode(Node* *ptr, Node * trail, Node * node) {
	if (trail)
		trail->link = node->link;
	else
		*ptr = (*ptr)->link;

	delete node;
}

void print_List(Node * ptr) {
	for (; ptr; ptr=ptr->link)
		cout<<ptr->data<<" ";

	cout<<endl;
}

int main () {
	int d;
	Node * prev = (Node *) new Node;

	cout<<"노드의 값을 입력: ";
	cin>>d;
	insert(&ptr, ptr, d);
	prev = ptr;

	while (true) {
		cout<<"노드의 값을 입력: ";
		cin>>d;
		if (d==0)
			break;

		insert(&ptr, NULL, d);
		prev = ptr->link;

	}

	print_List(ptr);

	prev = ptr;
	while (prev) {
		delNode(&ptr, prev, prev->link);
		ptr = ptr->link;
		prev = ptr;
	}

	return 0;
}