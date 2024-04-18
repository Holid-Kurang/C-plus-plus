#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	int r, p;
	cout << "panjang segitiga : ";
	cin >> r;
	for(int y=r; y>=-r; y--)
	{
			for(int x=r; x>=-r; x--)
			{
				cout<<setw(2);
//				cout<<setw(4)<<r*r;
				if(x>=y)
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	cout<<endl;
	for(int y=r; y>=-r; y--)
	{
			for(int x=r; x>=-r; x--)
			{
				cout<<setw(2);
				if(x<=y)
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	cout<<endl;
	for(int y=r; y>=-r; y--)
	{
			for(int x=r; x>=-r; x--)
			{
				cout<<setw(2);
				if(x>=-y)
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	cout<<endl;
	for(int y=r; y>=-r; y--)
	{
			for(int x=r; x>=-r; x--)
			{
				cout<<setw(2);
				if(x<=-y)
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
}
