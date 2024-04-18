#include <iostream>
using namespace std;

int perpangkatan(int basis, int pangkat){
	int hasil=1;
	for(int i=1; i<=pangkat; i++){
		hasil*=basis;
	}
	return hasil;
}

void deretfibo(int banyak){
	int t1=0, t2=1, next;
	for(int i=0; i<banyak; i++){
		cout<<t1<<" ";
		next = t1 + t2;
		t1 = t2;
		t2 = next;
	}
}

int permutasi(int n, int r){
	int hasil=1;
	for(int i=n; i>n-r; i--){
		hasil*=i;
	}
	return hasil;
}

int kombinasi(int n, int r){
	int pembilang=1, penyebut1=1, penyebut2=1;
	for(int i=1; i<=n; i++){
		pembilang*=i;
	}
	for(int j=1; j<=r; j++){
		penyebut1*=j;
	}
	for(int k=1; k<=n-r; k++){
		penyebut2*=k;
	}
	return pembilang/(penyebut1*penyebut2);
}

int euclid(int m, int n){
	int bantu;
	while(n!=0){
		bantu= m%n;
		m=n;
		n=bantu;
	}
	return m;
}
int mod(int bil, int mod){
	return (bil%mod+mod)%mod;
}

int main(){
	system("cls");
	cout<<"1. perpangkatan "<<endl;
	cout<<"2. deret fibonacci "<<endl;
	cout<<"3. permutasi "<<endl;
	cout<<"4. kombinasi "<<endl;
	cout<<"5. euclidean "<<endl;
	cout<<"6. aritmatika modulo "<<endl;
	int pilih;
	cout<<"masukkan pilihan (1/2/3/4) : "; cin>>pilih;
	switch(pilih){
		case 1:
			int basis, pangkat;
			cout<<"basis   : "; cin>>basis;
			cout<<"pangkat : "; cin>>pangkat;
			cout<<perpangkatan(basis, pangkat);
			break;
		case 2:
			int banyak;
			cout<<"masukkan banyak bilangan fibonacci : "; cin>>banyak;
			deretfibo(banyak);
			break;
		case 3:
			int nP, rP;
			cout<<"n pada permutasi nPr : "; cin>>nP;
			cout<<"r pada permutasi nPr : "; cin>>rP;
			cout<<"hasil permutasi : "<<permutasi(nP,rP);
			break;
		case 4:
			int nC, rC;
			cout<<"n pada permutasi nCr : "; cin>>nC;
			cout<<"r pada permutasi nCr : "; cin>>rC;
			cout<<"hasil permutasi : "<<kombinasi(nC,rC);
			break;
		case 5:
			int pertama, kedua;
			cout<<"bilangan pertama  : "; cin>>pertama;
			cout<<"bilangan kedua    : "; cin>>kedua;
			cout<<"FPB dari "<<pertama<<" dan "<<kedua<<" adalah : "<<euclid(pertama, kedua);
			break;
		case 6:
			int bil, modulo;
			cout<<"bilangan : "; cin>>bil;
			cout<<"modulo   : "; cin>>modulo;
			cout<<"hasil modulo : "<<mod(bil,modulo);
			break;
		default:
			main();
			break;
	}
}