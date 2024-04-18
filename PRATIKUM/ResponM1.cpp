#include <iostream>
using namespace std;

int main() {
	cout<<"RESPON modul 1"<<endl;
	cout<<"Nomer1"<<endl;
	int i;
	cin>>i;
	cout<<((i%1000)%100)%10<<((i%1000)%100)/10<<(i%1000)/100<<i/1000<<endl<<endl;

	cout<<"Nomer2"<<endl;
	int harga;
	cin>>harga;
	cout<<"dollar : "<<(harga/25)*0.00166<<endl;
	cout<<"euro : "<<(harga/25)*0.00153<<endl;
	cout<<"yuan : "<<(harga/25)*0.0114<<endl;
	cout<<"pounds : "<<(harga/25)*0.00135<<endl;
	cout<<"yen : "<<(harga/25)*0.220<<endl<<endl;

	cout<<"Nomer3"<<endl;
	char a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	cout<<a+b+c+d+e+f<<a<<b<<c<<d<<e<<f<<endl;
	a=a+32;
	b=b-32;
	c=c-32;
	d=d-32;
	e=e-32;
	f=f-32;
	cout<<f<<e<<d<<c<<b<<a<<(a+b+c+e+d+f)/2<<endl<<endl;


}

