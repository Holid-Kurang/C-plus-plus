#include <iostream>
using namespace std;

int main(){
	int n, min, nilai, lolos;
	cout<<"peserta yang ikut : ";
	cin>>n;
	cout<<"minimal nilai untuk lanjut ke ronde berikutnya : ";
	cin>>min;
	while(n){
		n--;
		cin>>nilai;
			if(nilai>min){
				lolos++;
			}
	}
	cout<<"peserta yang lolos sebanyak : "<<lolos;
	

//	int n=7, banyak, simpan=0, nilai;
//	while(n){
//		n--;
//		cin>>nilai;
//		if(nilai>simpan){
//			simpan=nilai;
//			banyak=1;
//		}else if(nilai==simpan){
//			banyak++;
//		}
//
//	}
//	cout<<endl;
//	cout<<simpan<<endl;
//	cout<<banyak;
return 0;
}
