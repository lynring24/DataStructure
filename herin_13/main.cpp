#include"sorts.h"
#include<math.h>

/*	Bubble Sort
-	Insertion Sort
-	Quick Sort
-	Heap Sort
-	Merge Sort(Downward/Upward pass for partition)
*/
void main() {
	int arr[MAX];
	generator(arr);
	print(arr);

	Bubble(arr);
	print(arr);

	Insert(arr);
	print(arr);

	cout <<"MergeSort(MIN~MAX):";
	MergeSort(arr, 0, MAX-1);
	print(arr);

	cout << "QuickSort(MAX~MIN):";
	Quick(arr, 0, MAX - 1);
	print(arr);


}
void swap(int & a, int & b) {
	int temp = a; a = b; b = temp;
}
void print(int * arr) {
	for (int i = 0; i < MAX; i++)
		cout << arr[i] << " ";
	cout << endl<<endl;
}
void generator(int * arr) {
	cout << "ORIGINAL : ";
	for (int i = 0; i < MAX; i++)
		arr[i] = rand() % 100 + 1;
}