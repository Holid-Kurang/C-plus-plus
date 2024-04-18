#include <iostream>
using namespace std;

struct File {
	string name="";
	string type="";
	string size="";
};
struct Folder {
	string nama;
	int silsilahFolder[100];
	int child[100];
	int Angkatan=0;
	int urutanKe=0;
	int nFolder = 0;
	File file[10];
	int nFile=0;
};
int nLahir=0;
Folder Family[100];

int digit(int abjad) {
	int count=0;
	while(abjad!=0) {
		abjad/=10;
		count++;
	}
	return count;
}
int cariUrutIndex(string namaFolder, Folder atFolder);
void buatFolder(string namaFolder, int Parent);
void buatFile (string nama, string type, Folder path);
void rincianfolder(Folder path);
void rincianfile(int urut, string nama, Folder path);
Folder displayFolder(Folder InView);
int main() {
	Folder Home;
	Home.nama = "C:\\";
	Family[0] = Home;
	displayFolder(Home);
}

Folder displayFolder(Folder InView) {
	while(true) {
		system("cls");
//	view current folder header
		string viewHead=InView.nama;
		bool front=true;
		for(int i = viewHead.size(); i<45; i++) {
			if(front) {
				viewHead = "=" + viewHead;
			} else {
				viewHead = viewHead + "=";
			}
			front = !front;
		}
		cout<<viewHead<<"\n";
//	view directory path
		cout<<"C:\\";
		for(int i=1; i<InView.Angkatan; i++) {
			cout<<Family[InView.silsilahFolder[i]].nama<<"\\";
		}
		if(InView.Angkatan!=0) {
			cout<<InView.nama;
		}
		cout<<"\n";
//	view garis batas
		for(int i=0; i<45; i++) {
			cout<<"=";
		}
		cout<<"\n";
//	view isi folder
		int nomer=0;
		for(int i=0; i<InView.nFolder; i++) {
			nomer++;
			cout <<nomer<<". "<<Family[InView.child[i]].nama;
			cout<<endl;
		}
//	view isi file folder
		for(int i=0; i<InView.nFile; i++) {
			nomer++;
			cout<<nomer<<". "<<InView.file[i].name<<"."<<InView.file[i].type;
			for(int j=InView.file[i].size.length(); j<45-(digit(nomer)+2+InView.file[i].name.length()+1+InView.file[i].type.length()+3); j++) {
				InView.file[i].size = " " + InView.file[i].size;
			}
			cout<<InView.file[i].size<<" MB";
			cout<<endl;
		}
//    cout<<"InView.urutanKe "<<InView.urutanKe<<endl;
//    cout<<"InView.nFolder "<<InView.nFolder<<endl;
//    cout<<"InView.Angkatan "<<InView.Angkatan<<endl;
//    cout<<"nLahir : "<<nLahir<<endl;
		cout<<"Command >>>> ";
		string command, subcommand, nama, typefile, sizefile;
		cin>>command;
		if(command=="buat") {
			cin>>subcommand;
			if(subcommand=="folder") {
				cin>>nama;
				buatFolder(nama, InView.urutanKe);
				InView=Family[InView.urutanKe];
			} else if(subcommand=="file") {
				cin>>nama>>sizefile;
				buatFile(nama, sizefile, InView);
				InView=Family[InView.urutanKe];
			} else {
				cout<<"Command Tidak Ada"<<endl<<endl;
				system("pause");
			}
		} else if(command=="buka") {
			cin>>subcommand;
			if(subcommand=="folder") {
				cin>>nama;
				int FolderNum = cariUrutIndex(nama, InView);
				if(FolderNum==-1) {
					cout<<"Folder Tidak Di Temukan Pada Directory Ini"<<endl<<endl;
					system("pause");
				} else {
					displayFolder(Family[InView.child[FolderNum]]);
				}
			} else {
				cout<<"Command Tidak Ada"<<endl<<endl;
				system("pause");
			}
		} else if(command=="rincian") {
			cin>>subcommand;
			if(subcommand=="folder") {
				cin>>nama;
				int FolderNum = cariUrutIndex(nama, InView);
				if(FolderNum==-1) {
					cout<<"Folder Tidak Ada"<<endl<<endl;
					system("pause");
				} else {
					rincianfolder(Family[InView.child[FolderNum]]);
				}
			} else if(subcommand=="file") {
				cin>>nama;
				bool cek=false;
				for(int i=0; i<InView.nFile; i++) {
					if(nama==InView.file[i].name) {
						cek=true;
					}
				}
				if(cek==true) {
					rincianfile(InView.urutanKe, nama, InView);
				} else {
					cout<<"File Tidak ditemukan Pada Directory ini"<<endl<<endl;
					system("pause");
				}
			} else {
				cout<<"Command Tidak Ada"<<endl<<endl;
				system("pause");
			}
		} else if(command=="balik") {
			return InView;
		} else {
			cout<<"Command Tidak Ada"<<endl<<endl;
			system("pause");
		}
	}
}

int cariUrutIndex(string nama, Folder directory) {
	int index=-1;
	for(int i=0; i<directory.nFolder; i++) {
		if(Family[directory.child[i]].nama==nama) {
			index=i;
		}
	}
	return index;
}
void buatFolder(string namaFolder, int Parent) {
	Folder newFolder;
	nLahir++;
	newFolder.nama = namaFolder; //alpro
	newFolder.urutanKe = nLahir; //
	//		0				 0
	if(Family[Parent].Angkatan==0) {
		newFolder.Angkatan=1;
		newFolder.silsilahFolder[0]=0;
	} else {
		//			1						2
		newFolder.Angkatan=Family[Parent].Angkatan+1;
		for(int i=0; i<Family[Parent].Angkatan; i++) {
			newFolder.silsilahFolder[i]=Family[Parent].silsilahFolder[i];
		}
		newFolder.silsilahFolder[Family[Parent].Angkatan]=Family[Parent].urutanKe;
	}
	//			1
	Family[nLahir]=newFolder;
	//		0							0				anak ke 1
	Family[Parent].child[Family[Parent].nFolder]=nLahir;
	Family[Parent].nFolder++;
}

void buatFile (string nama, string sizefile, Folder path) {
	if(Family[path.urutanKe].nFile <11) {
		for(int i=0, cek=0; i<nama.length(); i++) {
			if(nama[i]=='.') {
				cek=1;
				continue;
			}
			if(cek==0) {
				Family[path.urutanKe].file[Family[path.urutanKe].nFile].name += nama[i];
			} else {
				Family[path.urutanKe].file[Family[path.urutanKe].nFile].type += nama[i];
			}
		}
		Family[path.urutanKe].file[Family[path.urutanKe].nFile].size = sizefile;
		Family[path.urutanKe].nFile++;
	}
}

void rincianfolder(Folder path) {
	system("cls");
	string viewHead=path.nama;
	bool front=true;
	for(int i = viewHead.size(); i<45; i++) {
		if(front) {
			viewHead = "=" + viewHead;
		} else {
			viewHead = viewHead + "=";
		}
		front = !front;
	}
	cout<<viewHead<<"\n";
	cout<<"Nama      : "<<path.nama<<endl;
	cout<<"Directory : "<<"C:\\";
	for(int i=1; i<path.Angkatan; i++) {
		cout<<Family[path.silsilahFolder[i]].nama<<"\\";
	}
	if(path.Angkatan!=0) {
		cout<<path.nama;
	}
	cout<<endl;
	cout<<"Jumlah Folder : "<<path.nFolder<<endl;
	cout<<"Jumlah File   : "<<path.nFile<<endl;
	for(int i = 0; i<45; i++) {
		cout<<"=";
	}
	cout<<endl;
	system("pause");
}

void rincianfile(int urut, string nama, Folder path) {
	system("cls");
//	view file
	string viewHead;
	int i;
	for(i=0; i<Family[urut].nFile; i++) {
		if(Family[urut].file[i].name==nama) {
			viewHead=nama;
			break;
		}
	}
	bool front=true;
	for(int i = viewHead.size(); i<45; i++) {
		if(front) {
			viewHead = "=" + viewHead;
		} else {
			viewHead = viewHead + "=";
		}
		front = !front;
	}
	cout<<viewHead<<"\n";
//	view rincian file
	cout<<"Nama      : "<<Family[urut].file[i].name<<endl;
	cout<<"Directory : "<<"C:\\";
	for(int i=1; i<path.Angkatan; i++) {
		cout<<Family[path.silsilahFolder[i]].nama<<"\\"<<Family[urut].file[i].name;
	}
	if(path.Angkatan!=0) {
		cout<<path.nama<<"\\"<<Family[urut].file[i].name;
	} else {
		cout<<Family[urut].file[i].name;
	}
	cout<<endl;
	cout<<"Tipe File : "<<Family[urut].file[i].type<<endl;
	cout<<"Size File : "<<Family[urut].file[i].size<<" MB"<<endl;
	for(int i = 0; i<45; i++) {
		cout<<"=";
	}
	cout<<endl<<endl;
	system("pause");
}