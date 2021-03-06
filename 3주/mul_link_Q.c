#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct element {
	int key;
} Element;

typedef struct queue * qptr;
typedef struct queue {
	Element item;
	qptr link;
} Q;

qptr front[MAX];
qptr rear[MAX];

void addq(qptr *front, qptr *rear, Element item);
Element deleteq(qptr *front);

int main() {
	int n, k, i;
	Element item;

	printf("����: ");
	scanf("%d", &n);

	for (i=0; i<n; i++) {
		scanf("%d", &k);
		item.key = k;
		addq(&front[0], &rear[0], item);
	}

	for (i=0; i<n; i++) {
		printf("%d ", deleteq(&front[0]).key);
	}
	printf("\n");

	return 0;
}

void addq(qptr *front, qptr *rear, Element item) {
	qptr temp = (qptr) malloc(sizeof(Q));
	if (!temp)
		return;

	temp->item=item;
	temp->link=NULL;

	if (*front)
		(*rear)->link = temp;
	else
		*front = temp;

	*rear = temp;
}

Element deleteq(qptr *front) {
	qptr temp = *front;
	Element item;
	if (!(*front))
		return;

	item = temp->item;
	*front = temp->link;
	free(temp);

	return item;
}
