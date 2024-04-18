#include <iostream>
#include <string>
using namespace std;

int main(){
	string word;
	int k;
	getline(cin, word);
	for(k=0; k>=0; k++){
		if(word[k]=='\0'){
			break;
		}
	}
	for(int i=k-1; i>=0;i--){
		cout<<word[i];
	}cout<<endl;
//	getline(cin, word);
//	for(int i=word.size()-1; i>=0; i--){
//		cout<<word[i];
//	}

	int pilihrumus, pilihbangun, p,l,s;
	char ulang;
	cout<<"1. luas"<<endl;
	cout<<"2. keliling"<<endl;
	cout<<"pilih : ";
	cin>>pilihrumus;
	switch(pilihrumus){
		case 1:
			cout<<"1. persegi"<<endl;
			cout<<"2. persegi panjang"<<endl;
			cout<<"3. segitiga"<<endl;
			cout<<"pilih : ";
			cin>>pilihbangun;
			switch(pilihbangun){
				case 1:
					while(1){
						system("cls");
						cout<<"sisi persegi :";
						cin>>p;
						cout<<endl<<"luas persegi : "<<p*p;
						cout<<endl<<"hitung ulang? : ";
						cin>>ulang;
						if(ulang=='N' || ulang=='n'){
							return 0;
						}
					}
					break;
				case 2:
					while(1){
						system("cls");
						cout<<"panjang : "; cin>>p;
						cout<<"lebar : "; cin>>l;
						cout<<endl<<"luas persegi panjang : "<<p*l;
						cout<<endl<<"hitung ulang? : ";
						cin>>ulang;
						if(ulang=='N' || ulang=='n'){
							return 0;
						}
					}
					break;
				case 3:
					while(1){
						system("cls");
						cout<<"alas : "; cin>>p;
						cout<<"tinggi : "; cin>>l;
						cout<<endl<<"luas segitiga : "<<(p*l)/2;
						cout<<endl<<"hitung ulang? : ";
						cin>>ulang;
						if(ulang=='N' || ulang=='n'){
							return 0;
						}
					}
					break;
			}
			break;
		case 2:
			cout<<"1. persegi"<<endl;
			cout<<"2. persegi panjang"<<endl;
			cout<<"3. segitiga"<<endl;
			cout<<"pilih : ";
			cin>>pilihbangun;
			switch(pilihbangun){
				case 1:
					while(1){
						system("cls");
						cout<<"sisi persegi :";
						cin>>p;
						cout<<endl<<"keliling persegi : "<<p*4;
						cout<<endl<<"hitung ulang? : ";
						cin>>ulang;
						if(ulang=='N' || ulang=='n'){
							return 0;
						}
					}
					
					break;
				case 2:
					while(1){
						system("cls");
						cout<<"panjang : "; cin>>p;
						cout<<"lebar : "; cin>>l;
						cout<<endl<<"keliling persegi : "<<(p+l)*2;
						cout<<endl<<"hitung ulang? : ";
						cin>>ulang;
						if(ulang=='N' || ulang=='n'){
							return 0;
						}
					}
					
					break;
				case 3:
					while(1){
						system("cls");
						cout<<endl<<"hitung ulang? : ";
						cin>>ulang;
						if(ulang=='N' || ulang=='n'){
							return 0;
						}
					}
					cout<<"sisi 1 : "; cin>>p;
					cout<<"sisi 2 : "; cin>>l;
					cout<<"sisi 3 : "; cin>>s;
					cout<<endl<<"keliling persegi : "<<p+l+s;
					break;
			}
			break;	
	}
}