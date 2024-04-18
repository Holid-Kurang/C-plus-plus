#include<iostream>
using namespace std;

int fib(int n){
	if(n<=1){
		return n;
		}
		return fib(n-1) +fib (n-2);
}
int main(){
	int n, i;
	cin>>n;
	for(int i=1; n>=i; i++){
		cout<<fib(i)<<", ";
	}
	return 0;
}
