#include <iostream>
using namespace std;

class BS {
public:
	int search(int s[], int key, int low, int high);
private:
	int mid;
};

int BS::search(int s[], int key, int low, int high) {
		while (low<=high) {
		mid = (low+high)/2;
		if (key < s[mid])
			high = mid-1;
		else if (key > s[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;
}


int main() {
	int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int k;
	BS bs;

	cout<<"키 입력(1~10): ";
	cin>>k;

	int result = bs.search(list, k, list[0], list[9]);
	cout<<"키의 인덱스는 "<<result<<endl;
	
	return 0;
}