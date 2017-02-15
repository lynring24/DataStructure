#include "header.h"

void heap_insertion(element item, int *count) {
	int i, temp;

	if (HEAP_FULL(*count)) {
		fprintf(stderr, "The heap is full\n");
		exit(1);
	}

	i = (*count)++;

	while (i != 0 && item.key > heap[i / 2].key) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

void heap_deletion(int *count, element * root) {
	int i, temp;

	if (HEAP_EMPTY(*count)) {
		fprintf(stderr, "The heap is empty\n");
		exit(1);
	}

	(*root).key = heap[--(*count)].key;//root 자리에 마지막 heap 값 넣음 && count 감소
	i = 0;

	while (i != *count && (*root).key < heap[i*2].key || (*root).key<heap[(i*2+1)].key) {
		if (heap[i * 2].key > heap[(i * 2 + 1)].key) {//자식 노드 중 큰 값을 루트에 넣음
			temp = (*root).key;
			(*root).key = heap[i * 2].key;
			heap[i * 2].key = temp;
		}
		else {
			temp = (*root).key;
			(*root).key = heap[(i * 2 + 1)].key;
			heap[(i * 2 + 1)].key = temp;
		}
		i++;
	}
}

bool heap_find(int key, int front, int rear) {
	if (front != rear) {
		if (heap[(front + rear) / 2].key > key) {
			front = (front + rear) / 2 + 1;
			heap_find(key, front, rear);
		}
		else if (heap[(front + rear) / 2].key < key) {
			rear = (front + rear) / 2;
			heap_find(key, front, rear);
		}
		else {
			return true;
		}
	}
	else return false;
}