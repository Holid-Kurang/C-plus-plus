#include<iostream>
using namespace std;

int main(){
	char pti, logif, sisdig, kap, kwh, pancasila, kalkulus, pai;
	float n1,n2,n3,n4,n5,n6,n7,n8;
	float mean;
	cout<<"pti 		= "; cin>>pti;
	cout<<"logif 		= "; cin>>logif;
	cout<<"sisdig 		= "; cin>>sisdig;
	cout<<"kap 		= "; cin>>kap;
	cout<<"kwh 		= "; cin>>kwh;
	cout<<"pancasila 	= "; cin>>pancasila;
	cout<<"kalkulus	= "; cin>>kalkulus;
	cout<<"pai		= "; cin>>pai;
	cout<<endl;
	n1=69-pti;
	n2=69-logif;
	n3=69-sisdig;
	n4=69-kap;
	n5=69-kwh;
	n6=69-pancasila;
	n7=69-kalkulus;
	n8=69-pai;

	cout<<"pti		: "<<n1<<endl;
	cout<<"logif 		: "<<n2<<endl;
	cout<<"sisdig		: "<<n3<<endl;
	cout<<"kap		: "<<n4<<endl;
	cout<<"kwh		: "<<n5<<endl;
	cout<<"pancasila	: "<<n6<<endl;
	cout<<"kalkulus	: "<<n7<<endl;
	cout<<"pai		: "<<n8<<endl<<endl;

	mean=(n1+n2+n3+n4+n5+n6+n7+n8)/8;
	cout<<"rata-rata : "<<mean<<endl<<endl;

	int jamMID,menitMID,detikMID;
	float km;
	cout<<"waktu tempuh (km) : "; cin>>km;

	detikMID=(km/1235)*3600;
	jamMID = km/1235;
	menitMID = detikMID / 60;
	cout<<"waktu tempuh ke midgard : "<<endl;
	cout<<jamMID<<" jam "<<menitMID%60<<" menit "<<detikMID%60<<" detik."<<endl<<endl;

	jamMID = jamMID/5;
	menitMID = menitMID/5;
	detikMID = detikMID/5;
	cout<<"waktu tempuh ke asgard : "<<endl;
	cout<<jamMID<<" jam "<<menitMID%60<<" menit "<<detikMID%60<<" detik.";
	
}
