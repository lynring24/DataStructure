#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
} element;

typedef struct node * node_ptr;
typedef struct node {
	node_ptr left_link;
	element item;
	node_ptr right_link;
};

node_ptr findDLL(int key);
void insertFirst(int key);
void deleteDLL(node_ptr head, node_ptr node);
void insertDLL(int key);

node_ptr head;

int main() {
	int select = 0;
	int key;
	node_ptr node;
	node_ptr temp = (node_ptr)malloc(sizeof(struct node));//head °ª »ý¼º
	node_ptr ptr;
	
	temp->left_link = NULL;
	temp->item.key = 0;
	temp->right_link = NULL;

	head = temp;

	do {
		printf("\n------------------<Doubly linked list>------------------\n");
		printf("1. insert\n");
		printf("2. delete\n");
		printf("3. print\n");
		printf("0. exit\n");
		printf("input the number what do you want to perform: ");
		scanf_s("%d", &select);

		switch (select) {
		case 0:
			break;
		case 1:
			printf("input a value for new node(integer): ");
			scanf_s("%d", &key);
			if(head->right_link!=NULL&&head->left_link!=NULL)	insertDLL(key);
			else insertFirst(key);
			break;
		case 2:
			if (head->right_link != NULL) {
				printf("input a value what do you want to find(integer): ");
				scanf_s("%d", &key);
				node = findDLL(key);

				if (node != head)	deleteDLL(head, node);
			}
			else printf("the list is empty!\n");
			break;
		case 3:
			if (head->right_link != NULL) {
				for (ptr = head->right_link; ptr != head; ptr = ptr->right_link) {
					if (ptr->right_link != head)	printf("%d -> ", ptr->item.key);
					else printf("%d\n", ptr->item.key);
				}
			}
			else printf("the list is empty!\n");
			break;
		}
	} while (select != 0);
}

node_ptr findDLL(int key) {
	node_ptr ptr = head;

	for (; ptr->right_link!=head; ptr = ptr->right_link) {
		if (ptr->item.key == key) return ptr;
	}

	printf("we can not find the value..\n");
	return head;
}

void insertFirst(int key) {
	node_ptr newnode = (node_ptr)malloc(sizeof(struct node));

	newnode->item.key = key;
	
	newnode->right_link = head;
	newnode->left_link = head;

	head->right_link = newnode;
	head->left_link = newnode;
}

void deleteDLL(node_ptr head, node_ptr node) {
	if (head == node) printf("You can not delete Head node! o.<\n");
	else {
		node->left_link->right_link = node->right_link;
		node->right_link->left_link = node->left_link;
		free(node);
	}
}

void insertDLL(int key) {
	node_ptr newnode = (node_ptr)malloc(sizeof(struct node));
	
	newnode->item.key = key;

	newnode->left_link = head;
	newnode->right_link = head->right_link;

	head->right_link = newnode;
	head->left_link->left_link = newnode;
}