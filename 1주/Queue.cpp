#include <iostream>
using namespace std;

class Element {
public:
	int key;
	int value;
};

Element queue[100];
int rear = -1;
int front = -1;

int isEmptyQ() {return front==rear? 1: 0;}
int isFullQ() {return rear==99? 1 : 0; }

void addq(Element item);
Element deleteq();

int main () {
	int n, i;
	Element item[100];
	printf("���� ����: ");
	cin>>n;
	printf("��: ");
	for (i=0; i<n; i++) {
		cin>>item[i].value;
	}

	printf("Ű: ");
	for (i=0; i<n; i++) {
		cin>>item[i].key;
	}

	for (i=0; i<n; i++)
		addq(item[i]);

	for (i=0; i<n; i++)
		cout<<deleteq().value<<" ";

	cout<<endl;
	return 0;
}

void addq(Element item) {
	if (isFullQ()) {
		return;
	}
	queue[++rear] = item;
}

Element deleteq() {
	Element empty;
	if (isEmptyQ()) {
		empty.value = -1;
		return empty;
	}
	return queue[++front];
}