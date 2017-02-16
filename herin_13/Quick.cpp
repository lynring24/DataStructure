#include"sorts.h"
void Quick(int * arr, int s, int e) {
	if (s >= e) return;
	int mid = (s + e) / 2;
	int left = s, right = e;
	while (left < right) {
		while (arr[left] > arr[mid]) left++;
		while (arr[right] < arr[mid]) right--;
		if (left<right) {
			swap(arr[left], arr[right]);
			left++, right--;
		}
	}

	Quick(arr, s, mid);
	Quick(arr,mid+1,e);
}
