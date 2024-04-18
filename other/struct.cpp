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
	} holil;
	
//	cin>>holil.nama;
//	cin>>holil.tinggi;
//	cin>>holil.berat;
//	cin>>holil.tl>>holil.bl>>holil.thl;
//	cin>>holil.usia;
//	cin>>holil.kelamin;
//	cin>>holil.goldar;
//	cout<<endl;
	holil.nama = "holil";
	holil.tinggi = 168;
	holil.berat = 49;
	holil.tl = 13;
	holil.bl = 02;
	holil.thl = 2004;
	holil.kelamin = 'L';
	holil.goldar = "O";


	cout<<"nama : "<<
	holil.nama<<endl<<"tinggi : "<<
	holil.tinggi<<endl<<"berat : "<<
	holil.berat<<endl<<"tanggal lahir : "<<
	holil.tl<<"-"<<
	holil.bl<<"-"<<
	holil.thl<<endl<<"usia : "<<
	holil.usia<<endl<<"kelamin : "<<
	holil.kelamin<<endl<<"golongan darah : "<<
	holil.goldar;
}
