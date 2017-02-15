#include<iostream>
using namespace std;
typedef struct {
	float coef;
	int expon;
}Poly;										//structure for polynimial
Poly *db = (Poly*)malloc(sizeof(Poly)*20);	//assign array of structure
int a1=0,a2,b1,b2,avail;					//start&end of 1st,2nd and result;
void attach(float coef, int expon);
void padd( int a1, int a2, int b1, int b2);
void pmin(int a1, int a2, int b1, int b2);
void print(int strt, int end);				//더하기 함수와 빼기 함수에서 값을 출력할때

void main(){
	cout<<"n차,m차 연산(n+m<20)"<<endl;
	cout<<"첫 번째 n차식:";
	int max=0;
	cin>>max;
	for(int i=0;(avail<20)&&(i<=max);i++){
		cout<<"aX"<<(max-i)<<" :";
		cin>>db[avail].coef;	db[avail++].expon=(max-i);
	}
	a2=avail-1;
	
	cout<<"두 번째 n차식:"; 
	b1=avail;
	cin>>max;
	for(int i=0;(avail<20)&&(i<=max);i++){
		cout<<"aX"<<(max-i)<<" :";
		cin>>db[avail].coef;	db[avail++].expon=(max-i);
	}
	int i=b2=avail-1;
	cout<<endl;
	padd(a1,a2,b1,b2);
	avail=b2+1;
	pmin(a1,a2,b1,b2);
}
void padd( int a1, int a2, int b1, int b2){
	float temp;		//구조체에서 값을 가져오면 불안해서 다른 값이 들어가므로 temp를 사용해야 함
	while(a1<=a2&&b1<=b2){
		if(db[a1].expon>db[b1].expon){
			temp=db[a1].coef;				
			attach(temp,db[a1++].expon);
		}
		else if(db[a1].expon<db[b1].expon){
			temp=db[b1].coef;
			attach(temp,db[b1++].expon);
		}
		else {
			temp=db[a1].coef+db[b1].coef;
			if(temp)	
				attach(temp,db[a1].expon);
			a1++,b1++;
		}
	}
	for(;a1<=a2;a1++)attach(db[a1].coef,db[a1++].expon);
	for(;b1<=b2;b1++)attach(db[b1].coef,db[b1++].expon);
	cout<<"덧셈:	";
	print(b2+1, avail);
}
void attach(float coef, int expon){
	db[avail].coef=coef;
	db[avail++].expon=expon;
}
void pmin(int a1, int a2, int b1, int b2){
	int max;float temp;
	while(a1<=a2&&b1<=b2){
		if(db[a1].expon>db[b1].expon){
			 temp=db[a1].coef;
			attach(temp,db[a1++].expon);
		}
		else if(db[a1].expon<db[b1].expon){
			temp=(-1)*db[b1].coef;
			attach(temp,db[b1++].expon);
		}
		else {
			temp=db[a1].coef-db[b1].coef;
			if(temp)
				attach(temp,db[a1].expon);
			a1++,b1++;
		}
	}
	for(;a1<=a2;a1++)attach(db[a1].coef,db[a1++].expon);
	for(;b1<=b2;b1++)attach(db[b1].coef,db[b1++].expon);
	cout<<"뺄셈:	";
	print(b2+1, avail);
}
void print(int strt, int end){
	if(strt==end)
		cout<<0<<endl;
	else{

		for(int i=strt;i<end;i++){
			
			if(db[i].coef<0)
				cout<<"("<<db[i].coef<<")";
			else
				cout<<db[i].coef;

			if((i+1)!=end)
				cout<<"x"<<db[i].expon<<"+";
			else 
				if(db[i].expon!=0) 
					cout<<"x"<<db[i].expon<<endl;
				else 
					cout<<endl;
			}
	}
}
