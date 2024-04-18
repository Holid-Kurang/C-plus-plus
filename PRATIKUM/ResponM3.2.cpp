#include <iostream>
using namespace std;

int main(){
	string angka;
	cin>>angka;
	
	long int n=angka.size();
	long int sum=0;
	long int digit;
	for(int i=0; i<n;i++){
		digit = angka[i] -'0';
		if(i%2==0){
			sum+=digit;
		}else{
			sum-=digit;
		}
	}
	
	long int genap=0,ganjil=0,selisih;
	if(sum%11==0){
		cout<<angka<<" habis dibagi 11";
	}else{
		for(int i=0; i<n; i++){
			digit = angka[i] -'0';
			if(i%2==0){
				genap+=digit;
			}else{
				ganjil+=digit;
			}
		}
		cout<<genap<<" "<<ganjil<<endl;
		if(ganjil>genap){
			selisih=ganjil-genap;
			for(int i=0; i<n; ){
				digit = angka[i] -'0';
				if(digit+selisih>9){
					i+=2;
				}else{
					angka[i]+=selisih;
					break;
				}
			}
		}else if(genap>ganjil){
			selisih=genap-ganjil;
			for(int i=1; i<n; ){
				digit = angka[i] -'0';
				if(digit+selisih>9){
					i+=2;
				}else{
					angka[i]+=selisih;
					break;
				}
			} 
		}
		cout<<selisih<<endl;
		cout<<angka;
	}
}