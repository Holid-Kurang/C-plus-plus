#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	int f;
	cout<<"pohon ditarik dengan total gaya : ";
	cin>>f;
	
	for(int i=2; i<=f; i++){
		if(f%i==0){
			cout<<"\ndapat berdiri jika ditarik "<<i<<" orang dengan gaya "<<f/i;
		}
	}
}