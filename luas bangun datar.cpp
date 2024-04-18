#include<iostream>
using namespace std;

float luaslingkaran(float r){
	return r*r*3.14;
}
float kelilinglingkaran(float r){
	return 2*3.14*r;
}
float luassegitiga(float alas, float tinggi){
	return alas*tinggi*0.5;
}
float kelilingsegitiga(float a, float b, float c){
	return a+b+c;
}
float luaspersegipanjang(float p, float l){
	return p*l;
}
float kelilingpersegipanjang(float p, float l){
	return 2*(p+l);
}

int main(){
	float L = luaslingkaran(5);
	float a= luaspersegipanjang(5,6);
	cout<<a<<endl;
	float bangun_b = luassegitiga(10,5)+luaspersegipanjang(10,10)+luassegitiga(5,10);
	cout<<bangun_b;
	return 0;
}

