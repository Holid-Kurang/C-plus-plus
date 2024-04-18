#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	printf("segitiga 1");
	cout<<endl;
	for(int y=1; y<=5; y++){
		for(int x=1; x<=5; x++){
			if(x<y){
				cout<<x<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
	
	printf("segitiga 2");
	cout<<endl;
	for(int y=1; y<=5; y++){
		for(int x=1; x<=5; x++){
			if(x<=y){
				cout<<y<<" ";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl;

	printf("segitiga 3");
	cout<<endl;
	for(int y=1; y<=5; y++){
		for(int x=1; x<=5; x++){
			if(x>=y){
				cout<<x<<" ";
			}else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
	
	printf("segitiga 4");
	cout<<endl;
	for(int y=1; y<=5; y++){
		for(int x=1; x<=5; x++){
			if(x>=y){
				cout<<y<<" ";
			}else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	cout<<endl;

 	printf("segitiga 5");
	cout<<endl;
	for(int y=5; y>=1; y--){
		for(int x=1; x<=5; x++){
			if(x>=y){
				cout<<x<<" ";
			}else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	cout<<endl;

	printf("segitiga 6");
	cout<<endl;
	for(int y=1; y<=5; y++){
		for(int x=5; x>=1; x--){
			if(x<=y){
				cout<<y<<" ";
			}else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
	
	printf("segitiga 8");
	cout<<endl;
	for(int y=1; y<=5; y++){
		for(int x=1; x<=5; x++){
			if(x>=y){
				cout<<"*";
			}else{
				cout<<"  ";
			}
		}
		for(int x=5; x>=1; x--){
			if(x<=y){
				cout<<"*";
			}else{
				cout<<"   ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
	
	for(int i = 6; i>=1; i--){
		for(int j = 1; j<=6; j++){
			if(j<=i){
				cout<<" ";
			}else{
				cout<<"* ";
			}
		}
	cout<<endl;
	}
}
