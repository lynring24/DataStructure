#include"sorts.h"
void MergeSort(int *arr, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(arr, s, m);
		MergeSort(arr, m + 1, e);
		Merge(arr, s, m, e);
	}
}

void Merge(int *arr, int s, int m, int e) { // should sort also 
	int temp[MAX];
	int i = 0; // index runs around the array
	int l = s, r = m+1; // left ,right
	while (l <=m && r <=e ) {
		if (arr[l] <arr[r] )
			temp[i++] = arr[l++];
		if (arr[l] > arr[r])
			temp[i++] = arr[r++];
	}
	while (l <=m) {
		temp[i++] = arr[l++];
	}
	while (r <=e) {
		temp[i++] = arr[r++];
	}

	for (i--; i > -1; i--)
		arr[s + i] = temp[i];
}
