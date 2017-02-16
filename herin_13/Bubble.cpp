#include"sorts.h"

void Bubble(int *arr) {
	cout << "BUBBLE(MIN~MAX): ";
	for (int i = 0; i < MAX-1; i++) {
		for (int j = i + 1; j < MAX; j++) {
			if (arr[i] > arr[j]) 
				swap(arr[i], arr[j]);
		}
	}
}