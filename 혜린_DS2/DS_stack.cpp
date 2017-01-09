#include<iostream>
using namespace std;

#define MAXSIZE 20
struct Stack{
	int top;
	int stack[MAXSIZE];
	void put(int a);
	int get();
};
void Stack::put(int a){
		if(top<MAXSIZE){ 
			cout<<a<<" ";
			stack[top++]=a;}
		else
			cout<<"full stack"<<endl;
	}
int Stack::get(){
		if(top<0)  // if empty
			return -1;
		else
			return stack[--top];
	}
void main(){
	Stack data; data.top=0;
	int temp;

	for(int i=0,temp=0;i<MAXSIZE+1;temp++,i++){
		data.put(temp);
	}
	cout<<endl;
	while(data.top>-1){
		if((temp=data.get())!=-1)
			cout<<temp<<" ";
		else 
			cout<<"empty stack";
	}
	cout<<endl;
}