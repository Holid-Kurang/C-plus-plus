#include <iostream>
using namespace std;

int main(){
	int n;
	int count=1;
	char a='a', A='A'; 
	cin>>n;
	if(n%2==0){
		for(int y=1; y<=n; y++){
			for(int x=1; x<=n; x++){
				if(y==n/2 && x%2==0 && x<n){
					if(x==(n/2)){
						cout<<"+";
					}else{
						cout<<"-";
					}
				}else if(y==(n/2)+1 && x%3==0 && x<n){
					if(x==(n/2)+2){
						cout<<"#";
					}else{
						cout<<"*";
					}
				}else if(y%2==0 && (x==1 || x==n)){
					cout<<A;
					A+=3;
					if(A>90){
						A='A';
					}				
				}else if(x==y){
					if(y==(n/2)+1 || y==(n/2)+1){
						cout<<" ";
					}else{
						cout<<count;
						count++;
					}
					if(count>9){
						count=1;
					}
				}else if(x+y==n+1){
					if(y==(n/2) || y==(n/2)+1){
						cout<<" ";
					}else{
						cout<<a;
						a+=2;
					}
					if(a>122){
						a='a';
					}
				}else{
					cout<<" ";
				}
			}
			cout<<endl;
		}
	}else{
		for(int y=1; y<=n; y++){
			for(int x=1; x<=n; x++){
				if(y==(n/2)+1){
					cout<<A;
					A++;
					if(A>90){
						A='A';
					}
				}else if(x==y || x+y==n+1){
					cout<<a;
					a++;
					if(a>122){
						a='a';
					}
				}else if(x==(n/2)+1){
					if(y==(n/2)+1){
					}else{
						cout<<count;
						count++;
					}
					if(count>9){
						count=1;
					}
				}else{
					cout<<" ";
				}
			}
			cout<<endl;
		}
	}
}