#include <stdio.h>
#include <stdlib.h>
#define IS_FULL(node) (!(node))

typedef struct circle * circle_ptr;
typedef struct circle {
	int value;
	circle_ptr link;
};

void insert(circle_ptr * ptr, int value);
void recycle_node(circle_ptr * ptr);
void print_list(circle_ptr ptr);
circle_ptr get_node();

circle_ptr avail = NULL;

int main() {
	int select = 0;
	int value = 0;
	circle_ptr ptr = NULL;
	
	do {
		printf("\n------------<Circular and Recycle list>-------------\n");
		printf("1. insert\n");
		printf("2. delete list(recycle)\n");//delete all list
		printf("3. print list\n");
		printf("0. exit\n");
		printf("select a number what do you want to perform: ");
		scanf_s("%d", &select);

		switch (select) {
		case 0:
			break;
		case 1:
			printf("input a value(integer): ");
			scanf_s("%d", &value);
			insert(&ptr, value);
			break;
		case 2:
			recycle_node(&ptr);
			break;
		case 3:
			print_list(ptr);
			break;
		}
	} while (select != 0);
}

void print_list(circle_ptr ptr) {
	if (!ptr) {
		printf("This list is empty!\n");
		return ;
	}

	for (circle_ptr head = ptr; ptr; ptr = ptr->link) {
		if (ptr->link != head)	printf("%d-> ", ptr->value);
		else {
			printf("%d", ptr->value);
			return ;
		}
	}
}

void insert(circle_ptr * ptr, int value) {
	circle_ptr rear = NULL;
	circle_ptr temp = get_node();

	if (IS_FULL(temp)) {
		fprintf(stderr, "heap is fulled!\n");
		exit(1);
	}

	temp->value = value;

	if (*ptr) {
		for (rear = *ptr; rear->link != *ptr; rear = rear->link);//����Ʈ�� �� ������ �̵�

		temp->link = *ptr;//temp ��� �տ� ����
		*ptr = temp;//*ptr �ڸ� �� ������ ��ü
		rear->link = *ptr;//����Ʈ �ǳ� ��忡 �Ǿ� ��� ��������
	}
	else {
		temp->link = *ptr;
		*ptr = temp;
		(*ptr)->link = temp;
	}

}

circle_ptr get_node() {
	circle_ptr node;

	if (avail) {
		node = avail;
		avail = avail->link;
	}
	else node = (circle_ptr)malloc(sizeof(struct circle));

	if (IS_FULL(node)) {
		fprintf(stderr, "heap is full!\n");
		exit(1);
	}

	return node;
}

void recycle_node(circle_ptr * ptr) {
	circle_ptr front = *ptr;
	circle_ptr rear = NULL;

	if (!ptr) {
		printf("This list is empty!\n");
		return ;
	}

	for (rear = *ptr; rear->link!=*ptr; rear = rear->link);//�� ������ ���� �̵�
	
	*ptr = (*ptr)->link;//ù ��� �������� *ptr �̵�

	front->link = avail;//������ ��� �����ص� �� avail�� ��ũ��
	avail = front;//avail�� �� ������ �̵�
	rear->link = *ptr;//�� ������ ����� ��ũ�� *ptr�� �̵�
}

