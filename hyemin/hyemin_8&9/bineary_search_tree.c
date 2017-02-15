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
		printf("해당 값을 가진 노드가 이미 존재합니다.\n");
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
1. 입력받은 값을 가진 노드를 찾는다.
link가 null인데도 값을 찾지 못했을 경우 트리에 그 값이 없음.
2. 만약 해당 값을 가진 노드가 있다면
1) 해당 노드의 child가 없는 경우
: 해당 노드를 가진 부모 노드의 링크를 null로 만든다. 해당 노드를 해제한다.
2) 해당 노드에 child가 하나 있는 경우
: 해당 노드의 child에 부모 노드의 링크를 연결한다.
3) 해당 노드에 child가 둘 다 있는 경우
: 해당 노드의 왼쪽 노드 중 가장 작은 값, 또는 오른쪽 노드 중 가장 큰 값을 해당 노드의 값에 넣어줌
그리고 그 값이 있던 노드 free
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
		printf("해당 값이 트리에 존재하지 않습니다.\n");
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