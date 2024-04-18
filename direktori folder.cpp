#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n, i, k, quota, catat=1;
struct folder {
	char nama[100];
	folder *induk;
} berkas[50], direktori[50], *jin;
void dalam(int index, int tab);
int search(char nama[100]);
int move();
int change();
main() {
	do {
		cout << "Masukkan total folder dalam Local Disk (D:) : ";
		cin >> n;
	} while(n<1);
	do {
		cout << "Masukkan jumlah folder dalam Local Disk (D:) : ";
		cin >> i;
	} while((i<1) || (i>n));
	quota=i;
	while(i>0) {
		cout << "Masukkan nama folder ke - "<< (i) << " dalam Local Disk (D:) : ";
		cin.ignore();
		gets(berkas[catat].nama);
		berkas[catat].induk=&berkas[0];
		catat++;
		i--;
		dalam(catat-1,1);
	}
back :
	for(int c=1; c<=n; c++) {
		cout << "\nDirektori folder " << berkas[c].nama << " :";
		catat=0;
		for(jin = &berkas[c]; jin != &berkas[0]; jin = jin ->
		        induk) {
			if(jin == &berkas[c])continue;
			strcpy(direktori[catat].nama, jin -> nama);
			catat++;
		}
		cout << "D:/";
		for(int x=(catat-1); x>=0; x--) {
			cout << direktori[x].nama << "/";
		}
		cout << berkas[c].nama;
	}
	do {
		cout << "\nPilih Aksi: \n \n1. Pindah Berkas \n2. Ganti Nama Berkas \n3. Direktori Berkas \n0. Keluar\n \nMasukkan Aksi: ";
		cin >> quota;
		switch(quota) {
			case 1 :
				move();
				break;
			case 2 :
				change();
				break;
			case 3 :
				goto back;
				break;
		}
	} while(quota!=0);
}
void dalam(int ibu, int tab) {
	int i;
	if(quota<n) {
		do {
repeat :
			for(int t=0; t<tab; t++) cout << "\t";
			cout << "Masukkan jumlah folder dalam folder " << berkas[ibu].nama << " : ";
			cin >> i;
			if((i==0) && (catat==(quota+1))) {
				goto repeat;
			}
		} while((i<0) || (i>(n-quota)));
		quota += i;
		while(i>0) {
			for(int z=0; z<tab; z++)cout << "\t";
			cout << "Nama folder ke - "<< (i) << " dalam folder "<< berkas[ibu].nama << " : ";
			cin.ignore();
			gets(berkas[catat].nama);
			berkas[catat].induk = &berkas[ibu];
			catat++;
			i--;
			dalam(catat-1, tab+1);
		}
	}
}
int search(char nama[100]) {
	for(int q=1; q<=n; q++) {
		if(strcmp(nama, berkas[q].nama) == 0) {
			return q;
		}
	}
	return -1;
}
int move() {
	do {
		cout << "Masukkan nama file yang akan dipindahkan : ";
		gets(berkas[0].nama);
		catat=search(berkas[0].nama);
	} while(i==-1);
	do {
		cout << "Pindahkan ke dalam folder : ";
		gets(berkas[0].nama);
		i=search(berkas[0].nama);
	} while(i==-1);
	berkas[catat].induk = &berkas[i];
	cout << "File berhasil dipindahkan";
}
int change() {
	do {
		cout << "Masukkan nama file yang akan diganti namanya : ";
		gets(berkas[0].nama);
		catat = search(berkas[0].nama);
	} while(catat==-1);
	cout << "Masukkan nama baru file : ";
	gets(berkas[0].nama);
	strcpy(berkas[catat].nama, berkas[0].nama);
	cout << "Nama file berhasil diganti\n";
}