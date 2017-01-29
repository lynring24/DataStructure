#include <stdio.h>
#define LEN 100
#define MAX 10

typedef struct element {
	int value;
} Element;

Element memory[LEN];
int top[MAX];
int boundary[MAX];

void add(int i, Element item) {
	if (top[i]==boundary[i+1])
		return;

	memory[++top[i]]=item;
}

Element delet(int i) {
	if (top[i]==boundary[i])
		return;
	
	return memory[top[i]--];
}

int main () {
	int i, n;

	top[0] = boundary[0] = -1;

	for (i=1; i<MAX; i++) 
		top[i] = boundary[i]= LEN/MAX*i-1;

	boundary[n]=LEN-1;
}