#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int func(int a, int b){
	return a + b;
}
int main(){
	bool truth = true;
	cout<<truth<<endl;
	truth = 5==7-2;
	cout<<truth<<endl;
	cout<<(truth == 3-2)<<endl;
	truth = 5%2==1 && truth;
	if(truth){
		cout<<"yes"<<endl;
	}else{
		cout <<"no"<<endl;
	}
	
	if(true){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}
	
	if(truth>=1){
		cout<<"lebih"<<endl;
	}else if(truth==1){
		cout<<"sama"<<endl;
	}else{
		cout<<"kurang"<<endl;
	}
	
	if(truth && 5%5 == 1){
		cout<<"ya"<<endl;
	}else{
		cout<<"no"<<endl;
	}
	
	for(int i=0; i<5; i++){
		cout<<truth;
	}cout<<endl;

	int i=0;
	while(i<5){
		cout<<truth;
		i++;
	}cout<<endl;
	
	for(int i=2; i<=10; i+=2 ){
		cout<<i<<" ";
	}cout<<endl;
	
	for(int i=1; i<=16; i*=2){
		cout<<i<<" ";
	}cout<<endl;

	int angka =1;
	for(int j=1; j<=5; j++){
		cout<<"tampilkan ke-"<<j<<" : ";
		cout<<angka<<endl;
		angka+=angka;
	}
	for(int i=1; i<=5; i++){
		for(int j=1; j<=i; j++){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1; i<=5; i++){
		for(int j=1; j<=i; j++){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for(int i=5; i>=1; i--){
		for(int j=1; j<=i; j++){
	 		cout<<j<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1; i<=5; i++){
		for(int j=5; j>=1; j--){
			if(i>=j){
				cout<<j<<" ";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	int arr[6] ={2,4,5,6,7,9};
	for(int i=0; i<=5; i++){
		cout<<arr[i]<<" ";
	}cout<<endl;

	for(int i=0; i<=5; i+=2){
		cout<<arr[i]<<" ";
	}cout<<endl<<endl;
	
	cout<<func(arr[1], arr[4])<<endl;
	
	string txt = "helloo";
	txt[4]='n';
	cout<<txt<<endl;
	cout<<txt.size()<<endl;
	
	

}
