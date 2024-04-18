#include <iostream>
using namespace std;
int lok = 0, maks = 0, depth = 0, choice; string direktori;
struct File {
	string fileName;
	string type;
	string size;
};
struct Direc {
	string name;
	int parent;
	string folder[11];
	File file[11];
	int fol;
	int fil;
}direc[40] = {{"C:/"}};
void menu(), command(), rinciFolder(int a), rinciFile(int a); inline int Digit(int angka);
int main() {
	menu(); return 0;
}
inline int Digit(int angka) {
	int count = 1;
	while(angka > 9) angka /= 10, count++;	
	return count; 
}
void menu() {
	int nomor = 0; direktori = "";
	cout << "=============================" << direc[lok].name << "=============================\n";
	for(int j = lok, k = depth; k >= 0; k--) {
		direktori = direc[j].name + direktori;
		if(k > 1) direktori = "/" + direktori;
		j = direc[j].parent;
	}
	cout << direktori << "\n==========================================================";
	for(int i = 0; i < direc[lok].name.length(); i++) cout << "="; cout << endl;
	for(int i = 0; i < direc[lok].fol; i++) nomor++, cout << nomor << ". " << direc[lok].folder[i] << endl;
	for(int i = 0; i < direc[lok].fil; i++) {
		nomor++;
		cout << nomor << ". " << direc[lok].file[i].fileName << "." << direc[lok].file[i].type;
		for(int j = 0; j < 49 - direc[lok].file[i].fileName.length() - direc[lok].file[i].type.length(); j++) cout << " ";
		cout << direc[lok].file[i].size << " Mb\n";
	}
	cout << "command >>>> "; command();
}
void command() {
	string a, b, c, d;
	cin >> a;
	if(a != "kembali") {
		cin >> b >> c;
		if(a == "buat" && b == "folder") {
			for(int i = 0; i < direc[lok].fol; i++) {
				if(c == direc[lok].folder[i]) cout << "Folder Dengan Nama Yang Sama Sudah Ada Dalam Directory Ini", system("pause"), system("cls"), menu();
			}
			if(direc[lok].fol > 10) cout << "Jumlah Folder Maksimum Pada Directory Ini Telah Tercapai", system("pause"), system("cls"), menu();
			else direc[lok].folder[direc[lok].fol] = c, direc[lok].fol++, maks++, direc[maks].name = c, direc[maks].parent = lok, system("cls"), menu();
		}
		else if(a == "buka" && b == "folder") {
			for(int i = 0; i < direc[lok].fol; i++) {
				if(c == direc[lok].folder[i]) {
					for(int j = lok + 1; j < maks + 1; j++) {
						if(c == direc[j].name && lok == direc[j].parent) lok = j, depth++, system("cls"), menu();
					} 
				}
			}
			cout << "Folder Tidak Ditemukan Dalam Directory Ini", system("pause"), system("cls"), menu();
		}
		else if(a == "rincian" && b == "folder") {
			for(int i = 0; i < direc[lok].fol; i++) {
				if(c == direc[lok].folder[i]) {
					for(int j = lok + 1; j < maks + 1; j++) {
						if(c == direc[j].name && lok == direc[j].parent) system("cls"), rinciFolder(j);
					}
				}
			}
			cout << "Folder Tidak Ditemukan Dalam Directory Ini", system("pause"), system("cls"), menu();
		}
		else if(a == "buat" && b == "file") {
			cin >> d;
			for(int i = 0; i < direc[lok].fil; i++) {
				if(c == direc[lok].file[i].fileName) cout << "File Dengan Nama Yang Sama Sudah Ada Dalam Directory Ini", system("pause"), system("cls"), menu();
			}
			if(direc[lok].fil > 10) cout << "Jumlah File Maksimum Pada Directory Ini Telah Tercapai", system("pause"), system("cls"), menu();
			else {
				for(int i = 0, cek = 1; i < c.length(); i++) {
					if(c[i] == '.') {
						cek = 0;
						continue;
					}
					if(cek == 1) {
						direc[lok].file[direc[lok].fil].fileName += c[i];
					}else{
						direc[lok].file[direc[lok].fil].type += c[i];
					}
				}
				direc[lok].file[direc[lok].fil].size = d, direc[lok].fil++, system("cls"), menu();
			}
		}
		else if(a == "rincian" && b == "file") {
			for(int i = 0; i < direc[lok].fil; i++) {
				if(c == direc[lok].file[i].fileName) system("cls"), rinciFile(i);
			}
			cout << "File Tidak Ditemukan Dalam Directory Ini", system("pause"), system("cls"), menu();
		}
		else cout << "Command Yang Dimasukkan Salah", system("pause"), system("cls"), menu();
	}
	else {
		if(lok == direc[lok].parent) cout << "Tidak Ada Directory Sebelum Ini", system("pause"), system("cls"), menu();
		else lok = direc[lok].parent, depth--, system("cls"), menu();
	}
}
void rinciFolder(int a) {
	string lokasi; int digitfol = Digit(direc[a].fol), digitfil = Digit(direc[a].fil);
	if(depth == 0) lokasi = direktori + direc[a].name;
	else lokasi = direktori + "/" + direc[a].name;
	cout << "=================" << direc[a].name << "=================";
	cout << "\n|  Nama : " << direc[a].name; for(int i = 0; i < 23; i++) cout << " "; cout << "|";
	cout << "\n|  Directory : " << lokasi; for(int i = 0; i < 18 + direc[a].name.length() - lokasi.length(); i++) cout << " "; cout << "|";
	cout << "\n|  Jumlah folder : " << direc[a].fol; for(int i = 0; i < 14 + direc[a].name.length() - digitfol; i++) cout << " "; cout << "|";
	cout << "\n|  Jumlah file : " << direc[a].fil; for(int i = 0; i < 16 + direc[a].name.length() - digitfil; i++) cout << " "; cout << "|";
	cout << "\n==================================";
	for(int i = 0; i < direc[a].name.length(); i++) cout << "="; system("pause"), system("cls"), menu();
}
void rinciFile(int a) {
	string lokasi;
	if(depth == 0) lokasi = direktori + direc[lok].file[a].fileName;
	else lokasi = direktori + "/" + direc[lok].file[a].fileName;
	cout << "=================" << direc[lok].file[a].fileName << "=================";
	cout << "\n|  Nama : " << direc[lok].file[a].fileName; for(int i = 0; i < 23; i++) cout << " "; cout << "|";
	cout << "\n|  Directory : " << lokasi; for(int i = 0; i < 18 + direc[lok].file[a].fileName.length() - lokasi.length(); i++) cout << " "; cout << "|";
	cout << "\n|  Tipe File : " << direc[lok].file[a].type; for(int i = 0; i < 18 + direc[lok].file[a].fileName.length() - direc[lok].file[a].type.length(); i++) cout << " "; cout << "|";
	cout << "\n|  Besar file : " << direc[lok].file[a].size << " Mb"; for(int i = 0; i < 14 + direc[lok].file[a].fileName.length() - direc[lok].file[a].size.length(); i++) cout << " "; cout << "|";
	cout << "\n==================================";
	for(int i = 0; i < direc[lok].file[a].fileName.length(); i++) cout << "="; system("pause"), system("cls"), menu();
}
