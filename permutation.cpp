#include <iostream>
using namespace std;

class Permutation {
public:
	void perm (char * list, int i, int n);
};

int main () {
	Permutation p;
	char list[] = {'a', 'b', 'c', 'd'};
	p.perm(list, 0, 3);
}

void Permutation::perm(char *list, int i, int n) {
	int j, temp;
	if (i==n) {
		for (j=0; j<=n; j++) {
			printf("%c", list[j]);
			printf("   ");
		}
		printf("\n");
	}
	else {
		for (j=i; j<=n; j++) {
			temp = list[i];
			list[i]=list[j];
			list[j]=temp;
			perm(list, i+1, n);
			temp = list[i];
			list[i]=list[j];
			list[j]=temp;
		}
	}
}