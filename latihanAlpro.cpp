#include <iostream>
#include <cmath>
using namespace std;

int main(){
//LATIHAN NO 1
	int bil;
	string angka="prima";
	cin>>bil;
	if(bil>1){
  	for(int i=2; i<bil; i++){
			if(bil % i ==0){
				angka = "bukan prima";
			}
		}
	}else{
 		angka="bukan prima";
	}
 	cout<<angka<<endl;

//LATIHAN NO 2
	int cm, mm;
	if(bil>30){
		cm=30;
		mm=(bil-30)*10;
		cout<<cm<<" cm "<<mm<<" mm"<<endl;
	}else{
		cm=bil;
		cout<<cm<<" cm "<<endl;
	}

//LATIHAN NO 3
	int n=1, j=2;
	char opsi;

//LATIHAN NO 4
	float suhu, suhuTinggi;
	do{
	cin>>suhu;
	if(suhu>suhuTinggi){
		suhuTinggi=suhu;
		}
	}while(suhu>37.5);
	if(suhuTinggi>37.5){
		cout<<"anak sudah sembuh"<<endl;
		cout<<"suhu tertinggi anak selama demam "<<suhuTinggi;
	}else if(suhuTinggi<37.5 && suhuTinggi>35.5){
		cout<<"suhu anak dalam keadaan normal "<<suhu;
	}else{
		cout<<"robot tidak berjalan karena diluar \ndari perintah program yang dijalankan";
	}
	cout<<endl;

// LATIHAN NO 5
	int faktor = 5, hasil;
	hasil=faktor;
	while(faktor>1){
		hasil = hasil*(faktor-1);
		faktor--;
	}
	cout<<hasil;
}
