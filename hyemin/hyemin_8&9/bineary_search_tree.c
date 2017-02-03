#include "header.h"

/*
a left null link is connected to the previous node in inorder sequence
a right null is connected to the successor node
*/

node tree_insert(node * ptr, int data) {
	if (*ptr == NULL) {
		*ptr = make_node(data);
	}
	else if ((*ptr)->data == data) {
		printf("�ش� ���� ���� ��尡 �̹� �����մϴ�.\n");
		return *ptr;
	}
	else {
		if ((*ptr)->data > data) {
			(*ptr)->llink = tree_insert(&((*ptr)->llink), data);
		}
		else {
			(*ptr)->rlink = tree_insert(&((*ptr)->rlink), data);
		}
	}

	return *ptr;
}

/*
1. �Է¹��� ���� ���� ��带 ã�´�.
link�� null�ε��� ���� ã�� ������ ��� Ʈ���� �� ���� ����.
2. ���� �ش� ���� ���� ��尡 �ִٸ�
1) �ش� ����� child�� ���� ���
: �ش� ��带 ���� �θ� ����� ��ũ�� null�� �����. �ش� ��带 �����Ѵ�.
2) �ش� ��忡 child�� �ϳ� �ִ� ���
: �ش� ����� child�� �θ� ����� ��ũ�� �����Ѵ�.
3) �ش� ��忡 child�� �� �� �ִ� ���
: �ش� ����� ���� ��� �� ���� ���� ��, �Ǵ� ������ ��� �� ���� ū ���� �ش� ����� ���� �־���
�׸��� �� ���� �ִ� ��� free
*/
void tree_deletion(node * ptr, int data) {
	node parent, child, succ, succ_parent, find_node;

	parent = NULL;
	find_node = *ptr;

	while (find_node != NULL && find_node->data != data) {
		parent = find_node;
		if (data < find_node->data) find_node = find_node->llink;
		else find_node = find_node->rlink;
	}

	if (find_node == NULL) {
		printf("�ش� ���� Ʈ���� �������� �ʽ��ϴ�.\n");
		return;
	}

	if (find_node->llink == NULL && find_node->rlink == NULL) {
		if (parent != NULL) {
			if (parent->llink == find_node) parent->llink = NULL;
			else parent->rlink = NULL;
		}
		else {
			*ptr = NULL;
		}
	}
	else if (find_node->llink == NULL || find_node->rlink == NULL) {
		if (find_node->llink != NULL) child = find_node->llink;
		else child = find_node->rlink;

		if (parent != NULL) {
			if (parent->llink == find_node) parent->llink = child;
			else parent->rlink = child;
		}
		else *ptr = child;
	}
	else {
		succ_parent = find_node;
		succ = find_node->rlink;

		while (succ->llink != NULL) {
			succ_parent = succ;
			succ = succ->llink;
		}

		if (succ_parent->llink == succ) succ_parent->rlink = succ_parent->llink;
		else succ_parent->rlink = succ->rlink;

		find_node->data = succ->data;
		find_node = succ;
	}
	free(find_node);
}

node make_node(int data){
	node temp = (node)malloc(sizeof(struct thread_node));
	temp->llink = NULL;
	temp->rlink = NULL;
	temp->data = data;

	return temp;
}

void inorder(node ptr) {
	while (ptr) {
		inorder(ptr->llink);
		printf("%d ", ptr->data);
		inorder(ptr->rlink);

		return;
	}
}