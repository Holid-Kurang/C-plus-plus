#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

int main(){
	float r;
	cout<<"\t\tFASE BULANNYA BARU KELIATAN JELAS, KETIKA JARI JARI NYA DIINPUT 10-15\n";
	cout<<"masukkan jari jari bulan : ";
	cin>>r;

		//new moon
   	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
//				r*r*p*p = 2025
//				cout <<setw(4)<<x*x+y*y;
//				cout <<setw(4)<<r*r*p*p;
//				cout <<setw(4)<<p*p*x*x+r*r*y*y;
				cout <<setw(2);
				int c = x*x+y*y;
				if(c<=r*(r-1) && c>=r*(r-2))
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	
	//1/4 moon
   	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
// 				cout <<setw(4)<<x*x+y*y;
				cout <<setw(2);
				int c = x*x+y*y;
				if(c<r*(r-1) &&  c>r*(x+r-1))
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	
	//half moon
   	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
				cout <<setw(2);
				int c = x*x+y*y;
				if(c<=r*(r-1) && x<=0)
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	
		//3/4 moon
   	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
//	 			cout <<setw(4)<<x*x+y*y;
				cout <<setw(2);
				int c = x*x+y*y;
				if(c<r*(r-1) && c<-r*(x-r+1))
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	
	//full moon
   	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
				cout <<setw(2);
				int c = x*x+y*y;
				if(c<=r*(r-1))
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	
	//3/4 moon reversed
   	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
// 				cout <<setw(4)<<x*x+y*y;
				cout <<setw(2);
				int c = x*x+y*y;
				if(c<r*(r-1) &&  c<r*(x+r+1))
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}

	//half moon reversed
   	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
				cout <<setw(2);
				int c = x*x+y*y;
				if(c<=r*(r-1) && x>=0)
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	// 1/4 moon reversed
	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
//	 			cout <<setw(4)<<x*x+y*y;
				cout <<setw(2);
				int c = x*x+y*y;
				if(c<r*(r-1) && c>-r*(x-r+2))
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	
		//new moon
   	for(int y=r; y>=-r; y--)
	{
			for(int x=-r; x<=r; x++)
			{
				cout <<setw(2);
				int c = x*x+y*y;
				if(c<=r*(r-1) && c>=r*(r-2))
					cout<<"*";
				else
					cout<<" ";
			}
		cout<<endl;
	}
	getch();
return 0;
}
