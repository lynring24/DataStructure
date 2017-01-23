
#include "Node.h"
ptr Circular::getNode() {
	ptr node;
	if(avail){
		node = avail;
		avail = avail->next;
	}
	else
	{
		node = new Node();
		if (node==NULL) {
			fprintf(stderr, "[warning] full heap\n");
		}
	}
	return node;
}
void Circular::recycle(ptr e) {
	if (e) {
		ptr temp = e->next;
		e->next = avail;
		avail = temp;
		e = NULL;
	}
}
void Circular::insert(ptr node) {
	if (strt == NULL)//empty
	{
		strt = node;
		strt->next = strt;
	}
	else {
		node->next = strt->next;
		strt->next = node;
	}
}