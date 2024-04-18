#include <iostream>
#include <string.h>
using namespace std;

void polindrom (string kata){
	int i = 0, j = kata.length()-1;
	while(i<=kata.length()){
		if(kata[i]!=kata[j]){
			cout<<"bukan polindrom!";
			return;
		}
		i++;j--;
 	}
	cout<<"polindrom!";
}
int main(){
	string kata;
	cout<<"masukkan kata : ";
	getline(cin, kata);
	polindrom(kata);
	return 0;
}
