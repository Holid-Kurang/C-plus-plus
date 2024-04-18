#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int r, a;
	cin>>r;
	a=r*2;
	while(1){
		system("cls");
		if(a==-r*2){
			a=r*2;
		}
		a--;
		
		for(int y=r; y>=-r; y--){
			for(int x=-r; x<=r; x++){
				cout <<setw(2);
//				c = x*x+y*y;
//				z = (x-a)*(x-a)+y*y;
				if(x*x+y*y<=r*(r-1) &&  (x-a)*(x-a)+y*y>=r*(r-2))
					cout<<"*";
				else
					cout<<" ";
			}
			cout<<endl;
		}
	}
}