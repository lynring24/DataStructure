#include "header.h"

int main() {
	int select = 0;
	int data = 0;
	
	node ptr = NULL;

	do {
		printf("\n---------<Binary Search Tree>---------\n\n");
		printf("1. insertion\n");
		printf("2. deletion\n");
		printf("3. inorder print\n");
		printf("0. exit\n\n");
		printf("원하시는 작업의 번호를 입력하십시오: ");
		scanf_s("%d", &select);

		switch (select) {
		case 0:
			break;
		case 1:
			printf("삽입할 data 값을 입력하십시오: ");
			scanf_s("%d", &data);
			tree_insert(&ptr, data);
			break;
		case 2:
			printf("삭제할 data 값을 입력하십시오: ");
			scanf_s("%d", &data);
			tree_deletion(&ptr, data);
			break;
		case 3:
			printf("inorder tree: ");
			inorder(ptr);
			printf("\n");
			break;
		default:
			printf("번호를 잘못 입력하셨습니다.\n");
			break;
		}
	} while (select);

	return 0;
}