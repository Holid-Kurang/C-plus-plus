#include <iostream>
using namespace std;
int main(){
	int a=0;
	string word, grup;
	getline(cin,word);
	system("cls");
	for(int i=0; i<word.size(); i++){
		if(word[i]>96) word[i]-=32;
		if(word[i]!=' '){
			grup+=word[i];
		}
	}
	for(int y=1; y<=7; y++){
		for(int i=0; i<word.size(); i++){
			if(word[i]=='A'){
				for(int x=1; x<=5; x++){
					if(y==1&&x<5&&x>1 || y>1&&x==1 || y>1&&x==5 || y==4){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='B'){
				for(int x=1; x<=5; x++){
					if(y==4&&x<5||y==7&&x<5||y==1&&x<5||x==1||x==5&&y<=6&&y>1){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='C'){
				for(int x=1; x<=5; x++){
					if(y==7&&x>1||y==1&&x>1||x==1&&y>1&&y<7){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='D'){
				for(int x=1; x<=5; x++){
					if(y==7&&x<5||y==1&&x<5||x==1||x==5&&y<=6&&y>1){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='E'){
				for(int x=1; x<=5; x++){
					if(y==1||y==4||y==7||x==1){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='F'){
				for(int x=1; x<=5; x++){
					if(y==1||y==4||x==1){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='G'){
				for(int x=1; x<=5; x++){
					if(y==7&&x>1||y==1&&x>1||x==1&&y>1&&y<7 || x==5&&y<7&&y>4 || y==4&&x>3){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='H'){
				for(int x=1; x<=5; x++){
					if(y==4||x==1||x==5){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='I'){
				for(int x=1; x<=5; x++){
					if(x==3||y==1||y==7){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='J'){
				for(int x=1; x<=5; x++){
					if(y==7&&x<5&&x>1||x==1&&y<7&&y>4||x==5&&y<7){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='K'){
				for(int x=1; x<=5; x++){
					if(x==1||x==y-2||x+y==6){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='L'){
				for(int x=1; x<=5; x++){
					if(y==7|| x==1){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='M'){
				for(int x=1; x<=5; x++){
					if(x==1 || x==5 || x==y-1&&y<5 || x+y==7&&y<5){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='N'){
				for(int x=1; x<=5; x++){
					if(x==1 || x==5 || x==y-1){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='O'){
				for(int x=1; x<=5; x++){
					if(y==7&&x<5&&x>1||y==1&&x<5&&x>1||x==1&&y>1&&y<7||x==5&&y<7&&y>1){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='P'){
				for(int x=1; x<=5; x++){
					if(y==4&&x<5||y==1&&x<5||x==1||x==5&&y<=3&&y>1){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='Q'){
				for(int x=1; x<=5; x++){
					if(y==7&&x<5&&x>1||y==1&&x<5&&x>1||x==1&&y>1&&y<7||x==5&&y<7&&y>1||x==y-2&&y>4){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='R'){
				for(int x=1; x<=5; x++){
					if(y==4&&x<5||y==1&&x<5||x==1||x==5&&y<=3&&y>1||y==x+2&&y>3){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='S'){
				for(int x=1; x<=5; x++){
					if(y==7&&x<5 || y==1&&x>1|| y==4 ||x==1&&y>1&&y<4||x==5&&y>4&&y<7){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='T'){
				for(int x=1; x<=5; x++){
					if(y==1 || x==3){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='U'){
				for(int x=1; x<=5; x++){
					if(y==7&&x<5&&x>1||x==1&&y<7||x==5&&y<7){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='V'){
				for(int x=1; x<=7; x++){
					if(x==y-3||x+y==11||x==1&&y<4||x==7&&y<4){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='W'){
				for(int x=1; x<=7; x++){
					if(x==1&&y<7 || x==7&&y<7 || x==4&&y>3&&y<7 ||y==7&&x>1&&x<4 ||y==7&&x>4&&x<7){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='X'){
				for(int x=1; x<=7; x++){
					if(x==y||x+y==8){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='Y'){
				for(int x=1; x<=7; x++){
					if(y==x&&y<5 || x+y==8&&y<5 || x==4&&y>4){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]=='Z'){
				for(int x=1; x<=7; x++){
					if(y==7||x+y==8 ||y==1){
						cout<<grup[a];
						a++;
						if(a==grup.size()){
							a=0;
						}
					}
					else cout<<" ";
				}cout<<"  ";
			}else if(word[i]==' '){
            	for(int x=1; x<=5; x++){
					cout<<" ";
				}
         	}
		}
		cout<<endl;
	}
}