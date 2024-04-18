#include <iostream>
using namespace std;

void penjabaran(int input[], int n){
	int max=0, min=0, temp, banyak=n;
	cout<<"penjabaran sebelum proses : ";
	for(int i=0; i<n; i++){
		cout<<input[i]<<" ";
	}cout<<endl;
	if(n%2==0){
		n=(n-2)/2;
	}else{
		n=n/2;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<banyak; j++){
			if(input[j]>max){
				max=input[j];
			}
		}
		if(max>min){
			min=max;
		}
		for(int k=0; k<banyak; k++){
			if(input[k]==max){
				input[k]=0;
				max=0;
			}
		}
	}temp=min;
	for(int i=0; i<n; i++){
		for(int j=0; j<banyak; j++){
			if(input[j]==0){
				continue;
			}
			if(input[j]<min){
				min=input[j];
			}
		}
		for(int k=0; k<banyak; k++){
			if(input[k]==min){
				input[k]=0;
				min=temp;
			}
		}
	}
	cout<<"penjabaran setelah proses : ";
	for(int i=0; i<banyak; i++){
		cout<<input[i]<<" ";
	}
}

void median(int input[], int n, float &jumlah){ // pass by reference
	for(int i=0; i<n; i++){
		jumlah+=input[i];
	}
	if(n%2==0) jumlah/=2;
	cout<<endl<<"median : "<<jumlah;
}
int max(int input[], int n){
	int max=0;
	for(int i=0; i<n; i++){
		if(input[i]>max){
			max=input[i];
		}
	}
	return max;
}

int min(int input[], int n){
	int min;
	for(int i=0; i<n; i++){
		if(input[i]>0){
			min=input[i];
		}
	}
	for(int i=0; i<n; i++){
		if(input[i]<min){
			min=input[i];
		}
	}
	return min;
}

int main(){
	int banyak; 
	float sum=0;
	cout<<"banyak indeks : ";
	cin>>banyak;
	int arr[banyak], arrAFT[banyak];
	for(int i=0 ; i<banyak; i++){
		cout<<"Indeks ke-"<<i+1<<" : "; 
		cin>>arr[i];
		arrAFT[i]=arr[i];
	}
	penjabaran(arr, banyak);
	median(arr, banyak, sum); // sum di pass by reference
	cout<<endl<<"maks   : "<<max(arrAFT, banyak); // pass by value
	cout<<endl<<"min    : "<<min(arrAFT, banyak); // pass by value
}