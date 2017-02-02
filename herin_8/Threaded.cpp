#include  "Thread.h"

void TBT::set(thrd node){
	node->leftThrd = false;
	node->rightThrd = false;
}
void TBT::InOrder(thrd tree) {
	thrd temp = tree;
	while (true) {
		temp = post(temp);
		if (temp == head) break;
		cout << " [" << temp->data << "] ";
	}
}
thrd TBT::post(thrd tree) {
	thrd temp;
	temp = tree->right;
	if (!tree->rightThrd)
	while (!(temp->leftThrd))//find left leaf
	{
		temp = temp->left;
	}
	return temp;
}
/* Test
thrd TBT::post(thrd node) {
	thrd temp;
	if (node->rightThrd)
		return node->right;
	temp = node->right;
	while (!(temp->leftThrd))//find left leaf
	{
			temp = temp->left;
	}
	return temp;
}*/