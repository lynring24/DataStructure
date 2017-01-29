#include "DNode.h"

void DoubleLink::insert(Dptr pre, Dptr node) {
	if (head->next == head) {// empty list
		node->pre = head;	node->next = head;
		head->next = node;	head->pre = node;
	}

	else if (pre==NULL)//not a specific node, get header
	{
		node->next = head->next;
		node->pre = head;
		head->next->pre = node;
		head->next = node;
	}
	else
	{
		node->pre = pre;
		node->next = pre->next;
		pre->next->pre = node;
		pre->next = node; 
	}
	cout << node->value<< " ";
}
void DoubleLink::del(Dptr node){
	 if (node == head) {
		fprintf(stderr, "[warning] cannot access");
	}
	else {
		node->next->pre = node->pre;
		node->pre->next = node->next;
		cout << node->value <<" ";
		free(node);
	}
}
