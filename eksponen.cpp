#include<iostream>
using namespace std;

int main(){
	int a, b, c, d;
	cout<<"angka   : "; cin>>a;
	cout<<"pangkat : "; cin>>b;
	c=a;
	d=1;
	while(d<=b){
		cout<<a<<endl;
		a=a*c;
		d=d+1;
	}
	
	return 0;
}
