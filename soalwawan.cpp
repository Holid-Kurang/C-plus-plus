#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <conio.h>
using namespace std;

int main(){
	int n, temp;
	cin>>n;
	int median[n];
	for(int i=0; i<n; i++){
		cin>>median[i];
	}
	for(int i=0; i<n; i++){
		if(median[i] > median[i+1]){
			temp = median[i];
			median[i] = median[i+1];
			median[i+1] = temp;
		}

	}
	for(int i=0; i<n; i++){
		cout<<median[i];
	}
	
//	int x,y;
//	cin>>x>>y;
//	int arr[x][y];
//	for(int i=0; i<x; i++){
//		for(int j=0; j<y; j++){
//			cin>>arr[i][j];
//		}
//	}
//	for(int j=0; j<y; j++){
//		for(int i=x-1; i>=0; i--){
//			cout<<arr[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
//	int x, y, banyak=0, dapat;
//	cout<<"banyak jenis orang : "; cin>>x;
//	int sizeorang[x];
//	for(int i=0; i<x; i++){
//		cin>>sizeorang[i];
//	}
//	cout<<"banyak ukurang baju : "; cin>>y;
//	int jenis[y];
//	for(int i=0; i<y; i++){
//		cin>>jenis[i];
//	}
//	for(int i=0; i<x; i++){
//		for(int j=0; j<y; j++){
//			if(sizeorang[i] == jenis[j]){
//				dapat=1;
//				break;
//			}else{
//				dapat=0;
//			}
//		}
//		if(dapat==0){
//			banyak++;
//		}
//	}
//	cout<<endl<<banyak;
	
//	int n;
//	cin>>n;
//	for(int y=n; y>=1; y--){
//		for(int x=1; x<=n; x++){
//			if(x>=y){
//				if(x==y){
//					cout<<"/";
//				}else if(y==1){
//					cout<<"_";
//				}else{
//					cout<<" ";
//				}
//			}else{
//				cout<<" ";
//			}
//		}
//		for(int x=n; x>=1; x--){
//			if(x>=y){
//				if(x==y){
//					cout<<"\\";	
//				}else if(y==1){
//					cout<<"_";
//				}else{
//					cout<<" ";
//				}
//			}else{
//				cout<<" ";
//			}
//		}
//		cout<<endl;
//	}

//	srand(time(0));
//	string word;
//	string path="words.txt";
//	vector<string>v;
//	ifstream reader(path.c_str());
//	
//	if (reader.is_open()){
//		while(getline(reader, word)){
//			v.push_back(word);
//		}
//		int randomLine = rand() % v.size();
//		word = v.at(randomLine);
//		reader.close();
//	}
//	cout<<v.size();
//	cout<<word;	
	
}
