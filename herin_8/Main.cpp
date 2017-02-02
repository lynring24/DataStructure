#include "Thread.h"
#include "Heap.h"
void main() {
	/*
		-Threaded Binary Tree
		- Heap(Max, Min, Insertion, Deletion)*/
	cout << "1.Threaded Binary Tree"<<endl;
	TBT * thread = new TBT();
	thread->InOrder(thread->head);
	cout << "\n2.Heap Tree" << endl;
	new Heap();
}