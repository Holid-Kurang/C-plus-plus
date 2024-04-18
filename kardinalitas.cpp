#include <iostream>
using namespace std;

int main(){
	int i, n, k;
	cout<<"bilangan bulat antara : ";
	cin>>i;
	cout<<"sampai : ";
	cin>>n;
	for(i; i<=n; i++){
		if(i%11==0 ||i%7==0){
			k++;
		}
	}
	cout<<"n(p) : "<<k;

return 0;
}
