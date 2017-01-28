#include <stdio.h>
#include <stdlib.h>
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(temp) (!(temp))

typedef struct list_node * list_ptr;

typedef struct list_node {
	int data;
	list_ptr link;
};

void insert(list_ptr * ptr, int data);
void delete_node(list_ptr * ptr, int data);
void print_list(list_ptr ptr);

int main() {
	list_ptr ptr = NULL;

	int select = 0;
	int data;

	do {
		printf("\n--------<Singly linked list>-------\n");
		printf("1. insert\n");
		printf("2. delete\n");
		printf("3. print list\n");
		printf("0. exit\n");
		printf("���Ͻô� �׸��� ��ȣ�� �Է��Ͻʽÿ�: ");
		scanf_s("%d", &select);

		switch (select) {
		case 0:
			break;
		case 1:
			printf("������ ����� ���� �Է��ϼ���: ");
			scanf_s("%d", &data);
			insert(&ptr, data);
			break;
		case 2:
			printf("������ ����� ���� �Է��ϼ���: ");
			scanf_s("%d", &data);
			delete_node(&ptr, data);
			break;
		case 3:
			print_list(ptr);
			break;
		default:
			printf("�߸��� �Է� ���Դϴ�.");
			break;
		}
	} while (select != 0);
}

void insert(list_ptr * ptr, int data) {
	list_ptr temp;
	temp = (list_ptr)malloc(sizeof(struct list_node));

	if (IS_FULL(temp)) {
		fprintf(stderr, "The heap memory is full!\n");
		exit(1);
	}

	temp->data = data;//�Է¹��� ������ �� temp ��忡 ����

	if (*ptr) {//��尡 �����Ѵٸ�
		temp->link = *ptr;
		*ptr = temp;
	}
	else {//����Ʈ�� ��尡 �ƹ��͵� ���ٸ�
		temp->link = NULL;
		*ptr = temp;
	}

	print_list(*ptr);
}

void delete_node(list_ptr * ptr, int data) {
	
	list_ptr temp, prev;

	temp = *ptr;//temp�� ptr �� ����

	while (temp&&temp->data!=data) {//temp�� �����ϰ�, ã�����ϴ� �����Ͱ� ������
		temp = temp->link;
	}

	if (!temp) {//�� ã������ �����Ͱ� ���ٸ�
		printf("The data is not exist\n");
		return ;
	}
	else {//�����͸� ã�Ҵٸ�
		prev = *ptr;//prev�� ptr�� ����
		
		if (prev != NULL&&temp!=*ptr) {//������ ����� ���� ��尡 �ְ�, ������ ��尡 ù��° ���X
			while (prev->link != temp) {
				prev = prev->link;
			}

			if (temp->data == data) {//ã�� ���� ����� �����Ͱ� ���ٸ�
				prev->link = temp->link;//���� ����� ��ũ�� ������ ����� ��ũ�� �����.
			}
			
		}
		else {//������ ����� ���� ��尡 ���ٸ�
			*ptr = (*ptr)->link;
		}
	}

	free(temp);

	print_list(*ptr);
}

void print_list(list_ptr ptr){
	if (ptr) {
		for (; ptr; ptr = ptr->link) {
			printf("%d	", ptr->data);
		}
		printf("\n");
	}
	else {
		printf("The list is empty!\n");
	}
}