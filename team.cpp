#include<string.h>
#include<iostream>
using namespace std;

int main(){
	int n, a,b,c, s;
	cin>>n;
	for(int i; i<=n ;n--){
	cin>>a>>b>>c;
		if(a+b+c >=2){
			s++;
		}
	}
	cout<<s;
return 0;
}
