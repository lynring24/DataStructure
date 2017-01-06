#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Selection {
public:
	Selection();
	void sort(int list[], int n);
	void swap(int x, int y, int t);
	int list[50];
	int n;
};

Selection::Selection() {
	int i;
	srand(time(0));
	n=50;
	for (i=0; i<50; i++)
		list[i]=rand()%n;
}

void Selection::sort(int list[], int n) {
	int i, j, least, temp;
	for (i=0; i<n-1; i++) {
		least = i;
		for (j=i+1; j<n; j++) {
			if (list[j]<list[least])
				least=j;
		}
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}
}

void main() {
	Selection s;
	s.sort(s.list, s.n);
	int i;
	for (i=0; i<s.n; i++)
		cout<<s.list[i]<<endl;
}