#include "Heap.h"
void Heap::insert(int item){
	if(top==MAX-1) 
	{
		cout << "< full >" << endl; return;
	}
	int i= ++top;
	while (i && (item > heap[i / 2].data)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i].data = item;
}
Node Heap::del() {
	int parent=0, child=1;
	Node temp,item;
	if (top == -1) {
		cout << "< empty > " << endl; return NULL;
	}
	item = heap[0];
	temp = heap[top--]; // last node;
	// suppose : heap[root].data= lastnode.data; 
	// need to find the right place to fit max heap;
	while (child <= top) {
		if (child < top&&heap[child].data < heap[child + 1].data) // if the right node data if bigger, compare with that one
			child++;
		if (temp.data >= heap[child].data) break; // found the right place to put last node's data;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

/*description of delete()

method for get the max number from heap (root).
after taking the element, it will be replaced with the last node of tree.
(temp) 

starting from the root, while() is finding the right place to stuck the last node.

after replacing, parent will be at the spot of last node, replace temp there.
return the element. 
*/

void Heap::minHeap(int tree) // not finished yet
{
	if (tree>top/2) { return; }
	if (tree == 0) {
		Node temp = heap[0]; // changed the root and top node ( max & min  )
		heap[0] = heap[top-1];
		heap[top-1] = temp;
	}
	int child = tree*2+1;
	minHeap(child);
	minHeap(child + 1);
	if (heap[child].data > heap[child + 1].data) {
		child++;
	}
	if (heap[child].data < heap[tree].data) {
		Node temp = heap[child]; 
		heap[child] = heap[tree];
		heap[tree] = temp;
	}
}