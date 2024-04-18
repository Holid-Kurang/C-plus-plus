#include<iostream>
#include<string.h>
using namespace std;

int main(){
	struct nama{
		string nama;
		float tinggi, berat;
		int tl, bl, thl, usia;
		char kelamin;
		string goldar;
	}holil[3];
	for(int i=0; i<=3; i++){
		cout<<
		"nama"<<" | "<<"tinggi"<<" | "<<"berat"<<" | "<<"tanggal lahir"<<" | "<<"jenis kelamin"<<" | "<<"goldar"<<endl<<
		"-------------------------------------------------------------------------------------------------------";
		cout<<holil.nama<<" | "<<holil.tinggi<<" | "<<holil.berat<<" | "<<holil.tl<<"-"<<holil.bl<<"-"<<holil.thl<<" | "<<holil.kelamnin<<" | "<<holil.goldar<<endl;
	}
}
