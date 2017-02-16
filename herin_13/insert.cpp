#include"sorts.h"

void Insert(int * arr){
	cout << "INSERT(MAX~MIN): ";
	for (int i = 0; i < MAX; i++) {
		int temp = arr[i], j = i - 1;
			for (; j>-1 && arr[j] < temp; j--){
				arr[j+1] = arr[j];
			}
			arr[j+1] = temp;
	}
}