#include <iostream>
using namespace std;
#define N 100

class Q {
public:
	int value;
	int key;
};

Q q[N];

int front = -1;
int rear = -1;

void addq(Q item) {
	rear = (rear+1) % N;
	if (front == rear)
		return;
	q[rear] = item;
	
}

Q deleteq () {
	if (front == rear)
		return;
	front=(front+1) % N;
	return 
		q[front];
}

int main() {
	int n, i;
	Q item[100];
	printf("원소 개수: ");
	scanf("%d", &n);
	printf("값: ");
	for (i=0; i<n; i++) {
		scanf("%d", &item[i].value);
	}

	printf("키: ");
	for (i=0; i<n; i++) {
		scanf("%d", &item[i].key);
	}

	for (i=0; i<n; i++)
		addq(item[i]);

	for (i=0; i<n; i++)
		printf("%d ", deleteq().value);

	printf("\n");
	return 0;
}

