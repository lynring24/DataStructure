#include<iostream>
using namespace std;

void main(){
int x=8,y=4;
cout<<x<<" "<<y<<endl;
x=x^y^(y=x);
cout<<x<<" "<<y<<endl;
}
//a=3,b=5;
//a=a^6; //x= x^(y^(y=x))
//b=b^6
//
//a^=b; a=a^b
//b^=a; b=b^a // b=a;
//a^=b;  a=a^b; // a=b

//x^=(y^=(x^=y));
