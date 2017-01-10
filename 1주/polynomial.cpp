#include <iostream>
using namespace std;

int avail;

class Polynomial {
public:
	int exp;
	float coef;
	void padd(int a1, int a2, int b1, int b2, int *d1, int *d2);
	void attach (float coeff, int expo);
};

Polynomial terms[50];

void Polynomial::padd(int a1, int a2, int b1, int b2, int *d1, int *d2) {
	float coeffcient=0;
	avail = b2+1;
	*d1 = avail;
	while (a1<=a2 && b1<b2) {
		if (terms[a1].exp < terms[b1].exp) {
			attach(terms[b1].coef, terms[b1].exp);
			b1++;
		}
		else if (terms[a1].exp > terms[b1].exp) {
			attach(terms[a1].coef, terms[a1].exp);
			a1++;
		}
		if (terms[a1].exp == terms[b1].exp) {
			coeffcient = terms[a1].coef+terms[b1].coef;
		}
		if (coeffcient) {
			attach(coeffcient, terms[a1].exp);
			a1++;
			b1++;
		}
	}
	for (; a1 <= a2; a1++)
		attach(terms[a1].coef, terms[a1].exp);
	for (; b1 <= b2; b1++)
		attach(terms[b1].coef, terms[b1].exp);

	*d2 = avail-1;
}

void Polynomial::attach(float coeff, int expo) {
	if (avail >= 50) {
		printf("too many terms");
		exit(1);
	}
	terms[avail].coef = coeff;
	terms[avail].exp = expo;
	avail++;
}

int main () {
	Polynomial p;
	int i, an, bn;
	cout<<"a(x)의 항의 개수: ";
	cin>>an;
	cout<<"b(x)의 항의 개수: ";
	cin>>bn;

	cout<<"a(x)의 계수: ";
	for (i=0; i<an; i++)
		cin>>terms[i].coef;

	cout<<"a(x)의 차수: ";
	for (i=0; i<an; i++)
		cin>>terms[i].exp;

	cout<<"b(x)의 계수: ";
	for (i=an; i<an+bn; i++)
		cin>>terms[i].coef;

	cout<<"b(x)의 차수: ";
	for (i=an; i<an+bn; i++)
		cin>>terms[i].exp;

	int d1=0, d2=0;
	p.padd(0, 1, 2, 5, &d1, &d2);

	for (i=an+bn; i<avail; i++) {
		cout<<terms[i].coef<<" ";
	}
	cout<<endl;

	for (i=an+bn; i<avail; i++) {
		cout<<terms[i].exp<<" ";
	}
	cout<<endl;

}