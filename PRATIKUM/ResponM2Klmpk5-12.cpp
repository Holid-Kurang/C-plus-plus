#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int banyak, batas;
	cin>>batas;
	for(int i=1; i<=10;i++){
		batas=pow(batas%10,2);
		if(batas==1){
			cout<<batas<<" ";
		}
	}
		
}