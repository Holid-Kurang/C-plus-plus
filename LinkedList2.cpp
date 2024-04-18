#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
struct node{
	long data;
	node* next; //tipe data bertipe sama untuk menunjuk ke node lain
	node* prev;
};
node* head;
node* tail;
node* print;
node* del;


void inisialisasi(){
	head = NULL;
	tail = NULL;
}

//int isEmpty(){
//	if(head == NULL) return 1;
//	else return 0;
//}

void input(int *dta){
	node* entry;
	entry = new node;
	entry->data = *dta;
	entry->next = NULL;
	entry->prev = NULL;
	if(head==NULL){
		head = entry;
		head->next = NULL;
		head->prev = NULL;
		tail=head;
	}else{
		tail->next = entry;
		entry->prev = tail;
		tail = entry;
	}
}

//penghapusan data di belakang melalui head
void hapus(){
	int simpan;
	if(head!=NULL){ //jika hanya kondisi ini saja maka akan terjadi error karena disana ada syntax head->prev = NULL
		if(head->next != NULL){
			del=head;
			simpan = head->data;
			cout<<"\n"<<simpan<<" telah dihapus"<<endl;
			head = head->next;
			head->prev = NULL;
			delete del;
		}else{
			simpan = head->data;
			cout<<"\n"<<simpan<<" telah dihapus"<<endl;
			head = NULL;
		}
	}else cout<<"\nLinked List kosong penghapusan tidak dapat dilakukan"<<endl;
}

void cetak(){
	print = head;
	if(head!=NULL){
		while(print!=NULL){
			cout<<" "<<print->data<<"->";
			print = print->next;
		}
	}else cout<<"Tidak ada data dalam linked list"<<endl;
}
void menu(){
	char pilih, ulang;
	int data;
	bool stop=true;
	do{
		system("cls");
		cout<<"DOUBLE LINKED LIST NONCIRCULAR"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"Menu: ";
		cout<<"\n1. Entry Data";
		cout<<"\n2. Hapus Data";
		cout<<"\n3. Keluar\n"<<endl;
//		cout<<"is empty : "<<isEmpty()<<endl;
		cetak();
		cout<<"\nMasukkan pilihan Anda : ";
		cin>>pilih;
		switch(pilih){
			case '1' :
				cout<<"Masukkan Data : ";
				cin>>data;
				input(&data);
				cout<<data<<" telah ditambahkan"<<endl;
				break;
			case '2' :
				hapus();
				break;
			case '3' :
				cout<<"\nTerima kasih telah menggunakan program ini"<<endl;
				stop=false;
				break;
		}
	}while(stop);
}
int main(){
	inisialisasi();
	menu();
}