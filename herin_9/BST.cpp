#include "bst.h"

void BST::insert(int i) {
	if (!root) {
		root = new Node(i); return;
	}
	ptr spot = overlap(i); //temp for checking overlap
	if (spot) { //no overlap or empty tree
		ptr temp = new Node(i);
		if (i < spot->value)
			spot->left = temp;
		else
			spot->right = temp;
	}
}

ptr BST::overlap(int key) { //check out overlap
	ptr temp = root,spot=temp; // spot for parent tree
	while (temp) {
		spot = temp;
		if (key == temp->value)
			return NULL;
		else if (key < temp->value)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return spot;
}
void BST::test_inorder(ptr tree) {
	if (tree) {
		test_inorder(tree->left);
		cout << tree->value <<" ";
		test_inorder(tree->right);
	}
}

void BST::del(int key) {
	ptr temp = root, par; // parent 
	temp = fNode(key);	//temp == node wanna del
	if (!temp) // do not exist
		cout << "do not exist" << endl;
	else {
		par = fParent(temp); // find the parent 
			if (ISLEAF(temp)) {// if is leaf 
				if (par->left)
					par->left = NULL;
				else
					par->right = NULL;
			}
			else if (ISLEAF(temp->left) || ISLEAF(temp->right)) { // if the child is leaf
					if (temp->value < par->value) { //temp<par
						if (temp->left)
							par->left = temp->left;
						else
							par->left = temp->right;
						}
						else {//par<temp
							if (temp->left)
								par->right = temp->left;
							else
								par->right = temp->right;
							}
						}
			else {
				ptr min = LMax(temp);
				ptr max = RMin(temp);
				ptr to = (min->value < max->value) ? min : max; //change to 
				ptr par_to = fParent(to);
				ptr to_child = (to->left) ? to->left : to->right;
				temp->value = to->value;
				if (to->value < par_to->value)  // if left node
					par_to->left = to_child;
				else
					par_to->right = to_child;
		}
	}
}
bool BST::ISLEAF(ptr node) {
	return (!node->left && !node->right) ? true : false;
}
ptr BST::LMax(ptr tree) {
	ptr  max=tree;
	while (tree) {
		if (max->value < tree->value)
			max = tree;
		else
			tree = tree->right;
	}
	return max;
}
ptr BST::RMin(ptr tree) {
	ptr  min=tree;
	while (tree) {
		if (min->value> tree->value) 
			min = tree;
		else 
			tree = tree->left;
	}
	return min;
}
ptr BST::fParent(ptr tree) {
	ptr temp = root, par=temp; // parent 
	while (temp) {
		if (tree->value == temp->value)
			return par;
		else if (tree->value < temp->value) {
			par = temp;
			temp = temp->left;
		}
		else {
			par = temp;
			temp = temp->right;
		}
	}
	return NULL;
}

ptr BST::fNode(int key) {
	ptr temp = root; // parent 
	while (temp) {
		if (key == temp->value)
			return temp;
		else if (key < temp->value) {
			temp = temp->left;
		}
		else 
			temp = temp->right;
	}
	return NULL;
}