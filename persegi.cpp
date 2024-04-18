#include <iostream>
using namespace std;

int main(){
	int panjang, lebar;
	cout<<"masukkan panjang ";
	cin>>panjang;
	cout<<"masukkan lebar ";
	cin>>lebar;
	int bantu_lebar;
	while(panjang>0)
	{
		bantu_lebar = lebar;

		while(bantu_lebar>0)
		{
		cout<<bantu_lebar;
		bantu_lebar--;
		}
		cout<<endl;
		panjang--; //panjang=panjang-1
	}

}
