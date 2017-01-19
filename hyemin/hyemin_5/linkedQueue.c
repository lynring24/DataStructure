#include <stdio.h>
#include <stdlib.h>
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(temp) (!(temp))
#define MAX_QUEUES 100

typedef struct {
	int key;
} element;

typedef struct queue * queue_ptr;
typedef struct queue {
	element item;
	queue_ptr link;
};

queue_ptr front[MAX_QUEUES];
queue_ptr rear;

void add_queue(queue_ptr *front, queue_ptr *rear, element item, int index);
void delete_queue(queue_ptr *front, int index);
void print_queue(queue_ptr front, int index);

int main() {
	element item;

	int select = 0;
	int key;
	int index;

	do {
		printf("\n--------<Multiple queue using linked list>-------\n");
		printf("1. insert\n");
		printf("2. delete\n");
		printf("3. print queue list\n");
		printf("0. exit\n");
		printf("원하시는 항목의 번호를 입력하십시오: ");
		scanf_s("%d", &select);

		switch (select) {
		case 0:
			break;
		case 1:
			printf("값을 넣을 큐의 인덱스 값을 입력하세요: ");
			scanf_s("%d", &index);
			printf("삽입할 노드의 값을 입력하세요: ");
			scanf_s("%d", &key);
			item.key = key;
			add_queue(&front[index], &rear, item, index);
			break;
		case 2:
			printf("삭제할 노드가 있는 큐의 인덱스 값을 입력하세요: ");
			scanf_s("%d", &index);
			delete_queue(&front[index], index);
			break;
		case 3:
			printf("리스트를 출력할 큐의 인덱스 값을 입력하세요: ");
			scanf_s("%d", &index);
			print_queue(front[index], index);
			break;
		default:
			printf("잘못된 입력 값입니다.");
			break;
		}
	} while (select != 0);
}

void add_queue(queue_ptr *front, queue_ptr *rear, element item, int index) {
	queue_ptr temp = (queue_ptr)malloc(sizeof(queue_ptr));

	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full!\n");
		exit(1);
	}

	temp->item = item;
	temp->link = NULL;

	if (*front) {
		(*rear)->link = temp;
	}
	else {
		*front = temp;
	}

	*rear = temp;

	print_queue(front[index], index);
}

void delete_queue(queue_ptr *front, int index) {
	queue_ptr temp = *front;
	element item;

	if (IS_EMPTY(temp)) {
		printf("The queue is empty!\n");
		return ;
	}

	item = temp->item;
	*front = temp->link;

	temp = NULL;
	free(temp);

	print_queue(front[index], index);
}

void print_queue(queue_ptr front, int index) {
	if (front) {
		printf("\n%d번째 인덱스에 있는 큐 리스트는\n", index);
		while (front) {
			printf("%d	", front->item.key);
		front = front->link;
		}
		printf("입니다.\n");
	}
}