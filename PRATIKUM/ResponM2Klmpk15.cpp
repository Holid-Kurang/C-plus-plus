#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	float bil,jumlah=0;
	cin>>n;
	for(int i=1; i<=n; i++){
		if(i%2==1){
			bil=sqrt(i+1);
		}else{
			bil=1;
			for(int j=1; j<=i; j++){
				bil=bil*j;
			}bil=1/bil;
		}
//		((i-1)/2)%2 == 1		
		if(i==3 || i==4){
			jumlah-=bil;
		}else{
			jumlah+=bil;
		}
	}	
	cout<<jumlah;

//	int n;
//	float bil,div=1, per=1,jumlah=0;
//	cin>>n;
//	for(int i=1; i<=n; i++){
//		if(i%2==0){
//			bil=7/div;
//			div*=10;
//		}else{
//			per+=i;
//			bil=1/per;
//		}
//		if(((i-2)/2)%2==0){
//			jumlah-=bil;
//		}else{
//			jumlah+=bil;
//		}
//	}
//	jumlah+=1;
//	cout<<jumlah;
}