#include<iostream>
using namespace std;

int main(){
	int faktor, nilai;
	cout<<"faktorial ";
	cin>>faktor;
	nilai=faktor;

	while(faktor>1){
		nilai=nilai*(faktor-1);
		faktor=faktor-1;
		cout<<nilai<<endl;

	}
}
