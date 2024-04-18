#include<iostream>
#include<string.h>
using namespace std;

int main(){
	struct orang{
		string nama="holil";
		int usia;
		char jk;
		orang *ayah;
	} holil, axel;
	axel.ayah = &holil;
	cout<<axel.ayah -> nama;
	cout<<holil.ayah -> nama;
	holil.ayah = &axel;
}

