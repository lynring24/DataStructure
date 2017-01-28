#include <stdio.h>
#include <stdlib.h>
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(temp) (!(temp))
#define MAX_STACKS 100

typedef struct {
	int key;
} element;

typedef struct stack * stack_ptr;
typedef struct stack {
	element item;
	stack_ptr link;
};

stack_ptr top[MAX_STACKS];

void add_stack(stack_ptr *top, element item, int index);
void delete_stack(stack_ptr *top, int index);
void print_stack(stack_ptr top, int index);

int main() {
	element item;

	int select = 0;
	int key;
	int index;

	do {
		printf("\n--------<Multiple stack using linked list>-------\n");
		printf("1. insert\n");
		printf("2. delete\n");
		printf("3. print stack list\n");
		printf("0. exit\n");
		printf("원하시는 항목의 번호를 입력하십시오: ");
		scanf_s("%d", &select);

		switch (select) {
		case 0:
			break;
		case 1:
			printf("값을 넣을 스택의 인덱스 값을 입력하세요: ");
			scanf_s("%d", &index);
			printf("삽입할 노드의 값을 입력하세요: ");
			scanf_s("%d", &key);
			item.key = key;
			add_stack(&top[index], item, index);
			break;
		case 2:
			printf("삭제할 노드가 있는 스택의 인덱스 값을 입력하세요: ");
			scanf_s("%d", &index);
			delete_stack(&top[index], index);
			break;
		case 3:
			printf("리스트를 출력할 스택의 인덱스 값을 입력하세요: ");
			scanf_s("%d", &index);
			print_stack(top[index], index);
			break;
		default:
			printf("잘못된 입력 값입니다.");
			break;
		}
	} while (select != 0);
}

void add_stack(stack_ptr *top, element item, int index) {
	stack_ptr temp = (stack_ptr)malloc(sizeof(stack_ptr));

	if (IS_FULL(temp)) {
		fprintf(stderr, "The stack is full!\n");
		exit(1);
	}

	temp->item = item;
	temp->link = *top;
	*top = temp;

	print_stack(*top, index);
}

void delete_stack(stack_ptr *top, int index) {
	element item;
	stack_ptr temp = *top;

	if (IS_EMPTY(temp)) {
		printf("The stack is empty!\n");
		return;
	}

	item = temp->item;
	*top = temp->link;

	temp = NULL;
	free(temp);

	print_stack(*top, index);
}

void print_stack(stack_ptr top, int index) {
	if (top) {
		printf("\n%d번째 인덱스에 있는 스택 리스트는\n", index);
		while (top) {
			printf("%d	", top->item.key);
			top = top->link;
		}
		printf("입니다.\n");
	}
}