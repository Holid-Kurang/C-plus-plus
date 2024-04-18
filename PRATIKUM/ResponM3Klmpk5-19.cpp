#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	char arr[10][10]={{'+','-','-','-','-','-','-','-','-','+'},
					  {'|','-','-','-','-','-','H','-','-','|'},
					  {'|','-','-','#','#','#','#','-','-','|'},
					  {'|','-','-','#','-','-','-','-','-','|'},
					  {'|','-','-','#','#','#','-','-','-','|'},
					  {'|','-','-','-','-','#','-','-','-','|'},
					  {'|','-','#','#','#','#','-','-','-','|'},
					  {'|','-','#','-','-','-','-','-','-','|'},
					  {'|','-','#','#','#','#','#','#','#','|'},
					  {'+','-','-','-','-','-','-','-','#','+'}};
	char gerak;
	int kX, kY, temp;
	
	while(true){
		system("cls");
		for(int i=0; i<10; i++){
			for(int j=0 ; j<10; j++){
				cout<<arr[i][j]<<" ";
				if(arr[i][j]=='H'){
					kX=i; kY=j;
				}
			}
			cout<<endl;
		}
		
		if(arr[9][8]=='H'){
			cout<<endl<<"YEAAAAAAA";
			break;
		}		
		
		gerak=getch();
		if(gerak==72){
			temp=arr[kX-1][kY];
			arr[kX-1][kY]=arr[kX][kY];
			arr[kX][kY]=temp;
		}else if(gerak==75){
			temp=arr[kX][kY-1];
			arr[kX][kY-1]=arr[kX][kY];
			arr[kX][kY]=temp;
		}else if(gerak==77){
			temp=arr[kX][kY+1];
			arr[kX][kY+1]=arr[kX][kY];
			arr[kX][kY]=temp;
		}else if(gerak==80){
			temp=arr[kX+1][kY];
			arr[kX+1][kY]=arr[kX][kY];
			arr[kX][kY]=temp;
		}
		
		if(temp=='-'||temp=='|'||arr[kX][kY]=='-'||arr[kX][kY]=='|'){
			cout<<endl<<"AAAGGHHHHH";
			break;
		}
	
	}
}