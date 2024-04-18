#include <iostream>
using namespace std;

int main() {
//	2 1 3 9 8 10 30 29 31
//	int batas, banyak, sum=0, con=0;
//	cin>>batas>>banyak;
//	for(int i=1; i<=banyak; i++){
//		if(i==1 ||i%3==1){
//			cout<<batas<<" ";
//			sum+=batas;
//			batas--;
//		}
//		else if(i==2+con){
//			cout<<batas<<" ";
//			sum+=batas;
//			batas+=2;
//			con+=3;
//		}
//		else if(i==3||i%3==0){
//			cout<<batas<<" ";
//			sum+=batas;
//			batas*=3;
//		}
//	}
	
////	POLA PERTMA  (i-1)*3+i-2  3i+i-2-3
	char a='A', b;
	int i;
	cin>>i;
	b=(4*i-5)%26+66; //b=i+i+(i-2)+(i-2); // b=b%26; // b=b+64;
	for(int y=1; y<=i; y++){
		for(int x=1; x<=i; x++){
				if(y==1 || x==i){
					cout<<a<<" ";
					a++;
					if(a=='['){
						a='A';
					}
				}else if(y==i || x==1){
					b--;
					if(b=='@'){
						b='Z';
					}
					cout<<b<<" ";
				}else{
					cout<<"  ";
				}
		}
		cout<<endl;
	}
	
}
