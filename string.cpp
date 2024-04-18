#include <iostream>
#include <conio.h>
using namespace std;

// char kelamin  > kelamin = getch()   1 huruf
// char nama[25] > gets(nama)          char dalam bentuk larik/array
// string nama   > getline(cin, nama)  string nama = char nama[2][4] (2 dimensi)

// int main(){
//	char nama[50], tl[50], nim[50];
//		cout<<"masukkan nama : ";
//		gets(nama);
//
//		cout<<"masukkan tanggal lahir : ";
//		gets(tl);
//
//		cout<<"masukkan NIM : ";
//		gets(nim);
//
//		cout<<"\n\n      --BIODATA MAHASISWA--";
//		cout<<"\nNAMA          : ";
//		cout<<nama;
//
//		cout<<"\nTANGGAL LAHIR : ";
//		cout<<tl;
//
//		cout<<"\nNIM           : ";
//		cout<<nim;
//
// }
int main(){
	int n= 3;
	int larik[n][2]={{5,4},
					 {3,2},
					 {7,6}};
	int array[n]= {1,2,4};
	cout<<array[3];
}
