#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int r=9, p;
	cout << "panjang sparkle : "<<endl;
//	cin >> r;
	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
				int c = x*x*y*y;
					cout <<setw(2);
				if(c<=r*(r-8))
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}

	return 0;
}
