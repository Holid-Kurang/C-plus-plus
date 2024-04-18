#include <iostream>
using namespace std;

int main(){
	char bil;
	int nilai = 0;

	cout<<"...received law degrees as today."<<endl;
	cout<<"a. Never so many women have"<<endl;
	cout<<"b. Never have so many women"<<endl;
	cout<<"c. The women aren't ever"<<endl;
	cout<<"d. Women who have never"<<endl;
	cout<<"jawaban :";
	cin>>bil;
	switch(bil){
		case 'a': cout<< "jawaban salah"<<endl;break;
		case 'b': cout<< "jawaban benar"<<endl;nilai += 5;break;
		case 'c': cout<< "jawaban salah"<<endl;break;
		case 'd': cout<< "jawaban salah"<<endl;break;
		default : cout<< "bukan pilihan"<<endl;
		case 'A': cout<< "jawaban salah"<<endl;break;
		case 'B': cout<< "jawaban benar"<<endl;nilai += 5;break;
		case 'C': cout<< "jawaban salah"<<endl;break;
		case 'D': cout<< "jawaban salah"<<endl;break;
	}
	
	cout<<"\nThe Eiffel Tower .... Paris, France."<<endl;
	cout<<"a. landmarks"<<endl;
	cout<<"b. is landmarked in"<<endl;
	cout<<"c. is a landmark in"<<endl;
	cout<<"d. is in a landmark"<<endl;
	cout<<"jawaban :";
	cin>>bil;
	switch(bil){
		case 'a': cout<< "jawaban salah"<<endl;break;
		case 'b': cout<< "jawaban salah"<<endl;break;
		case 'c': cout<< "jawaban benar"<<endl;nilai += 5;break;
		case 'd': cout<< "jawaban salah"<<endl;break;
		default : cout<< "bukan pilihan"<<endl;
		case 'A': cout<< "jawaban salah"<<endl;break;
		case 'B': cout<< "jawaban salah"<<endl;break;
		case 'C': cout<< "jawaban benar"<<endl;nilai += 5;break;
		case 'D': cout<< "jawaban salah"<<endl;break;

	}
	cout<<"\nnilai anda: "<<nilai<<endl;
	
	if (nilai>5){
		cout<<"bagus";
	}
	else if (nilai<5){
		cout<<"buruk";
	}
	else {
		cout<<"cukup";
	}

}
