#include <iostream>
#include <conio.h>
using namespace std;

int pilihmenu, uang, gajiortu, ukt, grade;
char enter, bea;
string datauser, datapass, user, pass, fakultas, pilihF, nama;

void signup();
void login();
void bayarKuliah();

int main(){
	system("cls");
	cout<<"==========================\n";
	cout<<"===========UNRAM==========\n";
	cout<<"==========================\n";
	cout<<"1. SIGN UP\n";
	cout<<"2. LOG IN\n";
	cout<<"pilih : "; 
	cin>>pilihmenu;
	switch(pilihmenu){
		case 1:
			signup();
			break;
		case 2:
			login();
			break;
	}
}

void signup(){
	system("cls");
	cout<<"=========Sign Up==========\n";
	cout<<"Username : "; getline(cin>>ws, datauser);
	cout<<"Password : "; getline(cin>>ws, datapass);
	cout<<"Tekan enter untuk kembali ke Menu";
	enter=getch();
	if(enter==13) system("cls"); main();
}
void login(){
	system("cls");
	cout<<"=========Log In===========\n";
	cout<<"Username : "; getline(cin>>ws, user);
	cout<<"Password : "; getline(cin>>ws, pass);
	if(user==datauser && pass==datapass){
		cout<<"==========================\n";
		cout<<"login berhasil!!!"<<endl;
		cout<<"Tekan enter untuk lanjut";
		enter=getch();
		if(enter==13) system("cls"); bayarKuliah();
	}else{
		cout<<"==========================\n";
		cout<<"User atau Pass invalid!! LOL"<<endl;
		cout<<"Tekan enter untuk lanjut";
		enter=getch();
		if(enter==13) system("cls"); main();
	}
}
void bayarKuliah(){
	while(true){
		system("cls");
		cout<<"====Program Biaya Pembangunan===="<<endl;
		cout<<"Masukkan nama : "; getline(cin>>ws,nama);
		cout<<"=====Masukkaan Nama Fakultas====="<<endl;
		cout<<"List Nama Fakultas"<<endl;
		cout<<"1. Fakultas Teknik (FT)"<<endl;
		cout<<"2. Fakultas Kedokteran (FK)"<<endl;
		cout<<"3. Fakultas Keguruan dan Ilmu Pendidikan (FKIP)"<<endl;
		cout<<"4. Fakultas Hukum (FH)"<<endl;
		cout<<"5. Fakultas Ekonomi dan Bisnis (FEB)"<<endl;
		cout<<"6. Fakultas Peternakan (FAPET)"<<endl;
		cout<<"pilih = "; getline(cin>>ws, pilihF);
		if(pilihF=="1" || pilihF=="FT" || pilihF=="ft"){
			fakultas="Fakultas Teknik";
			uang=7000000;
			break;
		}else if(pilihF=="2" || pilihF=="FK" || pilihF=="fk"){
			fakultas="Fakultas Kedokteran";
			uang=75000000;
			break;
		}else if(pilihF=="3" || pilihF=="FKIP" || pilihF=="fkip"){
			fakultas="Fakultas Keguruan dan Ilmu Pendidikan";
			uang=7000000;
			break;
		}else if(pilihF=="4" || pilihF=="FH" || pilihF=="fh"){
			fakultas="Fakultas Hukum";
			uang=10000000;
			break;
		}else if(pilihF=="5" || pilihF=="FEB" || pilihF=="feb"){
			fakultas="Fakultas Ekonomi dan Bisnis";
			uang=3500000;
			break;
		}else if(pilihF=="6" || pilihF=="FAPET" || pilihF=="fapet"){
			fakultas="Fakultas Perternakan";
			uang=5000000;
			break;
		}else{
			cout<<endl<<"===ERROR==="<<endl;
			cout<<"Fakultas Belum Terdaftar"<<endl; getch();
		}
	}cout<<endl<<endl;
	
	while(true){
		cout<<"Apakah anda penerima beasiswa? [Y/N] = "; cin>>bea;
		system("cls");
		if(bea=='Y'||bea=='y'){
			while(true){
				system("cls");
				cout<<"===========UNRAM==========\n";
				cout<<"==========================\n";
				cout<<"Nama     : "<<nama<<endl;
				cout<<"Fakultas : "<<fakultas<<endl;
				cout<<"Status   : Bebas biaya kuliah"<<endl;
				cout<<"==========================\n";
				cout<<"Cek Ulang ? [Y/N] : "; cin>>enter;
				if(enter=='Y'||enter=='y'){
					bayarKuliah();
					break;
				}else if(enter=='N'||enter=='n'){
					main();
					break;
				}
			}
		}else if(bea=='N'||bea=='n'){
			while(true){
				system("cls");
				cout<<"Masukkan Gaji Orang Tua : Rp. "; cin>>gajiortu;
				if(gajiortu>=0 && gajiortu<=500000){
					ukt=1;
					grade=500000;
				}else if(gajiortu<=2000000){
					ukt=2;
					grade=850000;
				}else if(gajiortu<=3500000){
					ukt=3;
					grade=1650000;
				}else if(gajiortu<=5000000){
					ukt=4;
					grade=2750000;
				}else if(gajiortu<=10000000){
					ukt=5;
					grade=3850000;
				}else{
					ukt=6;
					grade=5100000;
				}
				cout<<"==========================\n";
				cout<<"===========UNRAM==========\n";
				cout<<"==========================\n";
				cout<<"Nama               : "<<nama<<endl;
				cout<<"Nama Fakultas      : "<<fakultas<<endl;
				cout<<"Grade UKT          : "<<ukt<<endl;
				cout<<"UKT                : Rp. "<<uang<<endl;
				cout<<"Uang Pembangunan   : Rp. "<<grade<<endl;
				cout<<"Total Biaya Kuliah : Rp. "<<grade+uang<<endl;
				cout<<"============================="<<endl;
				cout<<"Cek Ulang ? [Y/N] : "; cin>>enter;
				if(enter=='Y'||enter=='y'){
					bayarKuliah();
					break;
				}else if(enter=='N'||enter=='n'){
					main();
					break;
				}
			}
		}
	}
}