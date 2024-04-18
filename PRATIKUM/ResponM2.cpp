#include <iostream>
#include <iomanip>
using namespace std;

int main(){
//	 3, 4, 26, 28, 50, 53
//	 3, 6, 28, 30, 52, 53
//	int banyak, batas, dec;
//	cin>>batas;
//	cin>>banyak;
//	dec=batas;
//	for(int i=0;i<banyak; i++){
//		if(i==0){
//			cout<<batas<<" ";
//		}else if(i%2!=0){
//			batas=batas+dec;
//			cout<<batas<<" ";
//			dec--;
//		}else{
//			batas=batas+22;
//			cout<<batas<<" ";
//		}
//	}
	
	int n;
	cout<<"Masukkan jumlah baris : ";
	cin>>n;
	char huruf='A';
	for(int i = 1; i<=(n+1)/2; i++){
		for(int j = 1; j<=(n+1)/2; j++){
			if(j<=i){
				if(huruf=='['){
					huruf='A';
				}else if(huruf=='X'){
					huruf='*';
				}
				cout<<huruf<<" ";
				if(huruf=='*'){
					huruf='X';
				}
				huruf++;
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	for(int i = (n+1)/2; i>=1; i--){
		for(int j = 1; j<=(n+1)/2; j++){
			if(j<i){
				if(huruf=='['){
					huruf='A';
				}else if(huruf=='X'){
					huruf='*';
				}
				cout<<huruf<<" ";
				if(huruf=='*'){
					huruf='X';
				}
				huruf++;
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}


//	int i,k;
//	cout<<"Masukkan n Pola : ";
//	cin>>i;
//	cout<<endl;
//	for(int y=i; y>=1; y--){
//		for(int x=1; x<=i; x++){
//			k=x-y+1;
//			if(k<=0){
//				k=k*-1;
//				k+=2;
//				if(k==2){
//					k=0;
//				}
//			}else if(k==2){
//				k=0;
//			}
//			cout<<setw(2);
//			cout<<k;
//		}
//		cout<<endl;
//	}
}
