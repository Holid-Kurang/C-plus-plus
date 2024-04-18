#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

void acakslide(int puzzle[3][3]){
	int acak=rand() % 4; 
	for(int y=0; y<3; y++){
		for(int x=0; x<3; x++){
			puzzle[y][x] = puzzle[y][x] + acak;
			if(puzzle[y][x]>9){
				puzzle[y][x]++; 
				puzzle[y][x] %= 10;
			}
		}
	}
}
void printpuzzle(int puzzle[3][3]){
	system("cls");
		for(int y=0; y<3; y++){
			for(int x=0; x<3; x++){
				if(puzzle[y][x]==9){
					cout<<"  "<<puzzle[y][x]<<"  ";
				}else{
					cout<<" ["<<puzzle[y][x]<<"] ";
				}
			}
			cout<<endl;
		}cout<<"tekan enter kalo nyerah!!\n";
}
void lokasi(int puzzle[3][3],int &pX, int &pY){
	for(int y=0; y<3; y++){
		for(int x=0; x<3; x++){
			if(puzzle[y][x]==9){
				pY=y,pX=x;
			}
		}
	}
}
void gerak(int puzzle[3][3], char slide, int kX, int kY){
	int temp, stop;
	if(slide==72){ //atas
		stop=kY-1;
		if(stop<0) stop=0;
		temp=puzzle[stop][kX];
		puzzle[stop][kX]=puzzle[kY][kX];
		puzzle[kY][kX]=temp;
	}
	else if(slide==75){ //kiri
		stop=kX-1;
		if(stop<0) stop=0;
		temp=puzzle[kY][stop];
		puzzle[kY][stop]=puzzle[kY][kX];
		puzzle[kY][kX]=temp;
	}
	else if(slide==77){ //kanan
		stop=kX+1;
		if(stop>2) stop=2;
		temp=puzzle[kY][stop];
		puzzle[kY][stop]=puzzle[kY][kX];
		puzzle[kY][kX]=temp;
	}
	else if(slide==80){ //bawah
		stop=kY+1;
		if(stop>2) stop=2;
		temp=puzzle[stop][kX];
		puzzle[stop][kX]=puzzle[kY][kX];
		puzzle[kY][kX]=temp;
	}
}
int main(){
	srand(time(0));
	char a;
	int puzzle[3][3] ={{1,8,3},{7,5,6},{4,9,2}};
	int kY,kX; 
	acakslide(puzzle);
	while(1){
		printpuzzle(puzzle);
		lokasi(puzzle, kX, kY);
		if(puzzle[0][0]==1&&puzzle[0][1]==2&&puzzle[0][2]==3&&puzzle[1][0]==4&&puzzle[1][1]==5&&puzzle[1][2]==6&&puzzle[2][0]==7&&puzzle[2][1]==8&&puzzle[2][2]==9){
			cout<<endl<<"menang!";
			break;
		}
		a=getch();
		if(a==13) break;
		gerak(puzzle, a, kX, kY);	
	}		
}