#include <iostream>
using namespace std;

struct playlist{
	string judul;
	string artist;
	string durasi;
	string tahun;
	string genre;
	playlist *next;
	playlist *prev;
};
playlist *head=NULL, *tail=NULL;

void addSong(string orang, string lagu, string waktu, string year, string jenis){
	playlist *masuk;
	masuk = new playlist;
	masuk->artist = orang;
	masuk->judul = lagu;
	masuk->durasi = waktu;
	masuk->tahun = year;
	masuk->genre = jenis;
	masuk->next = NULL;
	masuk->prev = NULL;
	if(head == NULL){
		tail = masuk;
		head = tail;
	}else{
		tail->next = masuk;
		masuk->prev = tail;
		tail = masuk;
	}
}
void cetak(){
	int nomor=1;
	playlist *print;
	if(head!=NULL){
		for(print=head;	print!=NULL; print = print->next){
			cout<<"   "<<nomor<<"|"<<print->artist<<" - "<<print->judul<<" ("<<print->tahun<<")"<<endl;
			cout<<"    |"<<print->durasi;
			for(int i=print->durasi.size(); i<13; i++) cout<<" ";
			cout<<""<<"Genre : "<<print->genre<<endl<<endl;
			nomor++;
		}
	}else{
		cout<<endl<<"  Let's find something for your playlist"<<endl<<endl;
	}
}
void hapus(string lagu){
	playlist *del;
	del=head;
	if(head!=NULL){
		while(del!=NULL){
			if(del->artist==lagu || del->judul==lagu){
				if(del==head){
					head=del->next;
				}
				else if(del->prev!=NULL){
					del->prev->next=del->next;
				}
				else if(del->next!=NULL){
					del->next->prev=del->prev;
				}
				delete del;
			}
			del=del->next;
		}
	}else{
		cout<<endl<<"playlist mu emg kosong, tai. mau apus apaan"<<endl<<endl;
		system("pause");
	}
}

void tukar(playlist *a, playlist *b){
	string temp;
	temp=a->judul;
	a->judul=b->judul;
	b->judul=temp;
	
	temp=a->artist;
	a->artist=b->artist;
	b->artist=temp;
	
	temp=a->durasi;
	a->durasi=b->durasi;
	b->durasi=temp;
	
	temp=a->tahun;
	a->tahun=b->tahun;
	b->tahun=temp;
	
	temp=a->genre;
	a->genre=b->genre;
	b->genre=temp;
}
void sortJudul(playlist *otak){
	int swap;
	playlist *ptr;
	playlist *help = NULL;
	if(otak==NULL){
		return;
	}
	do{
		swap=0;
		ptr = otak;
		while(ptr->next!=help){
			if(ptr->judul > ptr->next->judul){
				tukar(ptr, ptr->next);
				swap=1;
			}
			ptr=ptr->next;
		}
		help=ptr;
	}while(swap);
}
void sortArtist(playlist *otak){
	int swap;
	playlist *ptr;
	playlist *help = NULL;
	if(otak==NULL){
		return;
	}
	do{
		swap=0;
		ptr = otak;
		while(ptr->next!=help){
			if(ptr->artist > ptr->next->artist){
				tukar(ptr, ptr->next);
				swap=1;
			}
			ptr=ptr->next;
		}
		help=ptr;
	}while(swap);
}
void sortTahun(playlist *otak){
	int swap;
	playlist *ptr;
	playlist *help = NULL;
	if(otak==NULL){
		return;
	}
	do{
		swap=0;
		ptr = otak;
		while(ptr->next!=help){
			if(ptr->tahun > ptr->next->tahun){
				tukar(ptr, ptr->next);
				swap=1;
			}
			ptr=ptr->next;
		}
		help=ptr;
	}while(swap);
}
void sortGenre(playlist *otak){
	int swap;
	playlist *ptr;
	playlist *help = NULL;
	if(otak==NULL){
		return;
	}
	do{
		swap=0;
		ptr = otak;
		while(ptr->next!=help){
			if(ptr->genre > ptr->next->genre){
				tukar(ptr, ptr->next);
				swap=1;
			}
			ptr=ptr->next;
		}
		help=ptr;
	}while(swap);
}
void sortDurasi(playlist *otak){
	int swap;
	playlist *ptr;
	playlist *help = NULL;
	if(otak==NULL){
		return;
	}
	do{
		swap=0;
		ptr = otak;
		while(ptr->next!=help){
			if(ptr->durasi > ptr->next->durasi){
				tukar(ptr, ptr->next);
				swap=1;
			}
			ptr=ptr->next;
		}
		help=ptr;
	}while(swap);
}

int main(){
	string command, subcommand, sort, lagu;
	string artist, judul, durasi, tahun, genre;
	playlist *already;
//	add Duster,Constellations,3:43,1998,Slowcore 
//	add Have a Nice Life,Bloodhail,5:38,2008,Alternative/Indie 
//	add Carissa's Wierd,Ignorant Piece of Shit,3:15,2002,Alternative/Indie 
//	add Home,Resonance,5:18,2014,Synthwave 
//	add Delta Sleep,Dustbusters,6:37,2013,Alternative/Indie 
//	add Horse Jumper of Love,Sun Poisoning,5:38,2016,Alternative/Indie 
//	add Aruarian Dance,Nujabes,2:50,2004,Jazz 
	while(1){
		cout<<"-------------------------------------------"<<endl;
		cout<<"               Your Playlist               "<<endl;
		cout<<"-------------------------------------------"<<endl;	
		cetak();
		cout<<"-------------------------------------------"<<endl;	
//		cout<<"<artist>,<judul>,<durasi>,<tahun>,<genre>"<<endl;
		cout<<"command >>>> ";
		cin>>command;
		if(command=="add"||command=="Add"){
			getline(cin>>ws, lagu);
			int rincian=0;
			for(int i=0; i<lagu.size(); i++){
				if(lagu[i]==','){
					rincian++;
					continue;
				}
				if(rincian==0){
					artist+=lagu[i];	
				}else if(rincian==1){
					judul+=lagu[i];
				}else if(rincian==2){
					durasi+=lagu[i];
				}else if(rincian==3){
					tahun+=lagu[i];
				}else if(rincian==4){
					genre+=lagu[i];
				}
			}
			bool cek=true;
			already=head;
			while(already!=NULL){
				if(artist==already->artist && judul==already->judul && durasi==already->durasi && tahun==already->tahun && genre==already->genre){
					cek=false;
				}
				already=already->next;
			}
			if(cek==true){
				addSong(artist, judul, durasi, tahun, genre);
				system("cls");
				cout<<"Song added Successfully!!"<<endl;
			}else{
				system("cls");
				cout<<"Song already added"<<endl;
			}
			artist="", judul="", durasi="", tahun="", genre="";
		}else if(command=="sort"||command=="Sort"){
			cin>>subcommand;
			if(subcommand=="by"||subcommand=="By"){
				cin>>sort;
				if(sort=="artist"){
					sortArtist(head);
					system("cls");
					cout<<"Sorted by artist"<<endl;
				}else if(sort=="judul"||sort=="title"){
					sortJudul(head);
					system("cls");
					cout<<"Sorted by title"<<endl;
				}else if(sort=="durasi"||sort=="duration"){
					sortDurasi(head);
					system("cls");
					cout<<"Sorted by duration"<<endl;
				}else if(sort=="tahun"||sort=="year"){
					sortTahun(head);			
					system("cls");
					cout<<"Sorted by year"<<endl;
				}else if(sort=="genre"||sort=="jenis"){
					sortGenre(head);
					system("cls");
					cout<<"Sorted by genre"<<endl;
				}
			}
		}else if(command=="delete"||command=="Delete"){
			getline(cin>>ws, lagu);
			hapus(lagu);
			system("cls");
			cout<<"Song Deleted"<<endl;
		}else if(command=="tutup" || command=="exit"){
			break;
		}else{
			system("cls");
		}
	}
}
