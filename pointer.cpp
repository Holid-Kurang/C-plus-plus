#include <iostream>
using namespace std;

int main(){
	int var=75;
	int *ptr=&var;
	int beth=*ptr;
//	ptr = &var;
	cout<<ptr<<endl;
	cout<<&var<<endl;
	cout<<*ptr<<endl;
	cout<<&beth<<endl;
	cout<<var<<endl;
	cout<<&ptr<<endl;
	cout<<&*ptr<<endl;
//	char arr[10]={'a','b','c','d','e','f','g','h','i','j'};
//	char *p=arr;
//	for(int i=0; i<10; i++){
//		cout<<*p<<endl;
//		p++;
//	}
}