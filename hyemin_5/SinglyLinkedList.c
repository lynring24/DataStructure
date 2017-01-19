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
		printf("원하시는 항목의 번호를 입력하십시오: ");
		scanf_s("%d", &select);

		switch (select) {
		case 0:
			break;
		case 1:
			printf("삽입할 노드의 값을 입력하세요: ");
			scanf_s("%d", &data);
			insert(&ptr, data);
			break;
		case 2:
			printf("삭제할 노드의 값을 입력하세요: ");
			scanf_s("%d", &data);
			delete_node(&ptr, data);
			break;
		case 3:
			print_list(ptr);
			break;
		default:
			printf("잘못된 입력 값입니다.");
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

	temp->data = data;//입력받은 데이터 값 temp 노드에 전달

	if (*ptr) {//노드가 존재한다면
		temp->link = *ptr;
		*ptr = temp;
	}
	else {//리스트에 노드가 아무것도 없다면
		temp->link = NULL;
		*ptr = temp;
	}

	print_list(*ptr);
}

void delete_node(list_ptr * ptr, int data) {
	
	list_ptr temp, prev;

	temp = *ptr;//temp에 ptr 값 복사

	while (temp&&temp->data!=data) {//temp가 존재하고, 찾고자하는 데이터가 없으면
		temp = temp->link;
	}

	if (!temp) {//다 찾았지만 데이터가 없다면
		printf("The data is not exist\n");
		return ;
	}
	else {//데이터를 찾았다면
		prev = *ptr;//prev에 ptr값 복사
		
		if (prev != NULL&&temp!=*ptr) {//삭제할 노드의 이전 노드가 있고, 삭제할 노드가 첫번째 노드X
			while (prev->link != temp) {
				prev = prev->link;
			}

			if (temp->data == data) {//찾는 값과 노드의 데이터가 같다면
				prev->link = temp->link;//이전 노드의 링크에 삭제할 노드의 링크를 덮어쓴다.
			}
			
		}
		else {//삭제할 노드의 이전 노드가 없다면
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