#include <stdio.h>
#include <stdlib.h>
#define IS_FULL(rear) (!(rear))

//not complete....;(
//why? 노드에 이어서 삽입하려고 하면 에러 남... 짜증... 왜 노드 앞에 삽입되는 건가..

/*This code operates normally 
only when each polynomial is aligned in descending order..
*/

typedef struct poly_node * poly_ptr;
typedef struct poly_node {
	int coef;
	int expon;
	poly_ptr link;
};

void printp(poly_ptr poly);
void padd(poly_ptr poly1, poly_ptr poly2, poly_ptr * rear);
void attach(int coefficient, int exponent, poly_ptr * ptr);

int main() {
	int count = 0;
	int size = 0;
	int i, coef, expon;
	
	poly_ptr poly1 = NULL;
	poly_ptr poly2 = NULL;
	poly_ptr rear = NULL;

	while (count != 2) {
		printf("\n------------<Polynomial using linked list>--------------\n");
		printf("%d 번째 다항식의 항의 개수를 입력하십시오: ", count + 1);
		scanf_s("%d", &size);

		for (i = 0; i < size; i++) {
			printf("%d 번째 항의 계수를 입력하십시오: ", i + 1);
			scanf_s("%d", &coef);
			printf("%d 번째 항의 승수를 입력하십시오(낮은 값부터 입력): ", i + 1);
			scanf_s("%d", &expon);

			if (count == 0) attach(coef, expon, &poly1);
			else if(count==1) attach(coef, expon, &poly2);
		}
		count++;
	}

	printf("poly1: ");
	printp(poly1);

	printf("poly2: ");
	printp(poly2);

	padd(poly1, poly2, &rear);

	printf("sum: ");
	printp(rear);

	return 0;
}

void printp(poly_ptr poly) {
	for (; poly; poly = poly->link) {
		if (poly->link) {
			if(poly->expon==0)	printf("%d + ", poly->coef);
			else printf("%d x^ %d +	", poly->coef, poly->expon);
		}
		else {
			printf("%d x^ %d ", poly->coef, poly->expon);
		}
	}
	printf("\n");
}

void attach(int coefficient, int exponent, poly_ptr * ptr) {
	poly_ptr temp = (poly_ptr)malloc(sizeof(struct poly_node));

	if (IS_FULL(temp)) {
		fprintf(stderr, "메모리터짐^^\n");
		exit(1);
	}

	temp->coef = coefficient;
	temp->expon = exponent;

	if (*ptr) {
		temp->link = *ptr;
		*ptr = temp;
	}
	else {
		temp->link = NULL;
		*ptr = temp;
	}
}

void padd(poly_ptr poly1, poly_ptr poly2, poly_ptr * rear) {
	int sum;

	while (poly1&&poly2) {
		if (poly1->expon < poly2->expon) {
			attach(poly2->coef, poly2->expon, rear);
			poly2 = poly2->link;
		}
		else if (poly1->expon == poly2->expon) {
			sum = poly1->coef + poly2->coef;
			attach(sum, poly1->expon, rear);
			poly1 = poly1->link;
			poly2 = poly2->link;
		}
		else if (poly1->expon > poly2->expon) {
			attach(poly1->coef, poly1->expon, rear);
			poly1 = poly1->link;
		}
	}

	for (; poly1; poly1 = poly1->link) {
		attach(poly1->coef, poly1->expon, rear);
	}

	for (; poly2; poly2 = poly2->link) {
		attach(poly2->coef, poly2->expon, rear);
	}
}