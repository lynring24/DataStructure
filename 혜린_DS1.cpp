#include<iostream>
#include<string>
using namespace std;
struct DS1{
	int key,end; 
	void select(int n[],int s);
	int  binary(int key,int n[],int l,int r);
	int rbin(int key,int n[],int l,int r);
	void perm(int n[],int o,int e); // end : size
	void swap(int &o,int &c);
};
void main(){
	DS1 ds;
	int num[]={40,30,50,10,80,20};
	ds.key=50, ds.end = sizeof(num)/4;
	ds.select(num,ds.end);
	cout<<"Ãâ·Â"<<endl;
	for(int i=0;i<ds.end;i++)
		cout<<" "<<num[i];
	cout<<endl;
	cout<<"ÀÎµ¦½º : "<<ds.binary(ds.key ,num,0,ds.end-1)<<endl;
	cout<<"ÀÎµ¦½º : "<<ds.rbin(ds.key,num,0,ds.end-1)<<endl;
	ds.perm(num,0,4);
}
void DS1::select(int n[],int s){
	int min=0,temp;
	for(int i=0;i<s-1;i++){
		min=i;
		for(int j=i+1;j<s;j++)
			if(n[min]>n[j]) 
				min=j;
		temp = n[i]; n[i]= n[min]; n[min] = temp;
	}
}
int  DS1::binary(int key,int n[],int l,int r){
	int mid;
	while(l<=r){
		 mid = (l+r)/2;
		 if(n[mid]==key)
			return mid;
		 else if(n[mid]<key)
			 l=mid+1;
		 else
			 r=mid-1;
	}
	return -1;
}
int DS1::rbin(int key,int n[],int l,int r){
	int mid =(l+r)/2;
	if(l>r) return -1;
	else{
		if(n[mid]==key)
			return mid;
		else if(n[mid]<key)
			rbin(key,n,mid+1,r);
		else 
			rbin(key,n,l,mid-1);
	}
}
void DS1::perm(int n[],int o,int e){ //origin/change/size
	static int count=1;
			if(o==e)
			{
				cout<<" "<<(count++)<<": ";
				for(int t=0;t<e;t++)
					cout<<n[t]<<" ";
				cout<<endl;
			}
			else{
				for(int j=o;j<e;j++){
					swap(n[o],n[j]);
					perm(n,o+1,e);
					swap(n[o],n[j]);
			}
		}
}
void DS1::swap(int &o,int &c){
	int temp;
	temp =o;o=c;c=temp;
}