#include <stdio.h>
#include <iostream>
using namespace std;
struct TNode{
	int data;
	TNode *next;
};
TNode *head, *tail;

void init(){
	head = NULL;
	tail = NULL;
}
isEmpty(){
	if(tail == NULL) {
		return 1;
	}else {
		return 0;
	}
}
void insertDepan(int databaru){
	TNode *baru;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	if(isEmpty()==1){
		head=tail;
		tail=baru;
		tail->next=NULL;
	}else {
		baru->next = head;
		head = baru;
	}
	cout<<" Data masuk\n";
}

void insertBelakang(int databaru){
	TNode *baru,*bantu;
	baru = new TNode;
	baru->data = databaru;
	baru->next = NULL;
	if(isEmpty()==1){
		head=baru;
		tail=baru;
		tail->next = NULL;
	}else {
		tail->next = baru;
		tail=baru;
	}
	cout<<" Data masuk\n";
}
void tampil(){
	TNode *bantu;
	bantu = head;
	if(isEmpty()==0){
		while(bantu!=NULL){
			cout<<" "<<bantu->data<<"->";
			bantu=bantu->next;
		}
		cout<<" NULL"<<endl;
	}else cout<<" Masih kosong\n";
}
void hapusDepan(){
	TNode *hapus;
	int d;
	if (isEmpty()==0){
		if(head!=tail){
			hapus = head;
			d = hapus->data;
			head = head->next;
			delete hapus;
		}else{
			d = tail->data;
			head=tail=NULL;
		}
		cout<<d<<" terhapus";
	} else cout<<" Masih kosong\n";
}
void hapusBelakang(){
	TNode *bantu, *hapus;
	int d;
	if (isEmpty()==0){
		bantu = head;
		if(head!=tail){
			while(bantu->next!=tail){
				bantu = bantu->next;
			}
			hapus = tail;
			tail=bantu;
			d = hapus->data;
			delete hapus;
			tail->next = NULL;
		}else {
			d = tail->data;
			head=tail=NULL;
		}cout<<d<<" terhapus\n";
	}else cout<<" Masih kosong\n";
}
void cls(){
	TNode *bantu,*hapus;
	bantu = head;
	while(bantu!=NULL){
		hapus = bantu;
		bantu = bantu->next;
		delete hapus;
	}
	head = NULL;
	printf("CLEAR");
}
int main(){
	int pil, databaru;
	do{
		system("cls");
		cout<<" ========================="<<endl;
		cout<<" = PROGRAM LINKED LIST ="<<endl;
		cout<<" ========================="<<endl;
		cout<<" = 1. Insert Depan ="<<endl;
		cout<<" = 2. Insert Belakang ="<<endl;
		cout<<" = 3. Delete Depan ="<<endl;
		cout<<" = 4. Delete Belakang ="<<endl;
		cout<<" = 5. Clear ="<<endl;
		cout<<" = 6. Exit ="<<endl;
		cout<<" ========================="<<endl;
		tampil();
		cout<<" Masukan Pilihan : ";cin>>pil;
		switch (pil){
			case 1: 
				cout<<" Masukkan Data = ";
				cin>>databaru;
				insertDepan(databaru);
				break;
			case 2: 
				cout<<" Masukkan Data = ";
				cin>>databaru;
				insertBelakang(databaru);
				break;
			case 3: 
				hapusDepan();
				break;
			case 4: 
				hapusBelakang();
				break;
			case 5: 
				cls();
				break;
			case 6: 
				return 0;
				break;
			default : 
				cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
		}
	}while(pil!=7);
}