#include <iostream>
using namespace std;

struct game{
	string nama;
	string genre;
	string rating;
	string produksi;
	string penerbit;
	string tahun;
};

struct buyer{
	string nama;
	string hp;
	string ttl;
	int umur;
	game beli[100];
	int nbeli=0;
};
buyer Orang[100];
int nOrang=0;

void datagame(string genre, string rating, string produksi, string penerbit, string tahun){
	Orang[nOrang].nbeli++;
	Orang[nOrang].beli[Orang[nOrang].nbeli].genre=genre;
	Orang[nOrang].beli[Orang[nOrang].nbeli].rating=rating;
	Orang[nOrang].beli[Orang[nOrang].nbeli].produksi=produksi;
	Orang[nOrang].beli[Orang[nOrang].nbeli].penerbit=penerbit;
	Orang[nOrang].beli[Orang[nOrang].nbeli].tahun=tahun;
	if(genre=="AC"){
		
	}else if(genre=="HO"){
		
	}
	
}

void datapembeli(){
	string idgame;
	string game, genre="", rating="", produksi="", penerbit="", tahun="";
	string nama, hp, ttl, umur;
	nOrang++;
	cout<<"masukkan data: "<<endl;
	cout<<"nama pembeli : "; cin>>nama;
	cout<<"nomer hp     : "; cin>>hp;
	cout<<"ttl          : "; cin>>ttl;
	cout<<"umur         : "; cin>>umur;
	cout<<"         game   : "; cin>>game;
	cout<<"         idgame : "; cin>>idgame;
	for(int i=0; i<idgame.size(); i++){
		if(idgame[i]>96){
			idgame[i]-=32;
		}
		if(i==0 || i==1){
			genre+=idgame;
		}else if(i==2 || i==3){
			rating+=idgame;
		}else if(i==4 || i==5){
			produksi+=idgame;
		}else if(i==6 || i==7){
			penerbit+=idgame;
		}else if(i==8 || i==9){
			tahun+=idgame;
		}
	}
	
	datagame(genre, rating, produksi, penerbit, tahun);
}
int main(){
	
}