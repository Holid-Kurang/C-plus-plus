#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
//	int m3, biayaadmin=10000, totalbiaya;
//	cin>>m3;
//	if(m3>=1 && m3<=10){
//		if(m3==8){
//			m3=m3*2000;
//			m3=m3-1000;
//		}else{
//			m3=m3*2000;
//		}
//	}else if(m3>=11 && m3<=20){
//		if(m3==13){
//			m3=m3*3000;
//			m3=m3-1500;
//		}else{
//			m3=m3*3000;
//		}
//	}else if(m3>=21 && m3<= 30){
//		if(m3==25){
//			m3=m3*4000;
//			m3=m3-2000;
//		}else{
//			m3=m3*4000;
//		}
//	}else{
//		if(m3==50){
//			m3=m3*5000;
//			m3=m3-3000;
//		}else{
//			m3=m3*5000;
//		}
//	}
//	totalbiaya= m3+biayaadmin;
//	cout<<totalbiaya;

// int n, cek;
//	cin>>n;
////	setiap bilangan i di cek
//	for(int i=n; i>1; i--){
//		if(i>1){
//			cek=1;
////			cek apakah tiap bilangan i prima
//			for(int j=2; j<=i/2; j++){
//				if(i%j == 0){
//					cek=0;
//				}
//			}
//		}
//		if(cek){
//			cout<<i<<" ";
//		}
//	}

//	cout<<endl;
	int t1=0,t2=1,bantu,banyak,batas,sum,cek;
	cout<<"batas akhir : "; cin>>batas;
	cout<<"banyak: "; cin>>banyak;
	
	bantu = batas+2*banyak;
	for(int i=1; i<=banyak; i++){
		bantu-=2;
		cout<<bantu<<" ";
	}cout<<"\n\n";

	for(int n=0; n<banyak;){
		if(t1>=batas){
			n++;
		}
		bantu = t1 + t2;
		t1 = t2;
      	t2 = bantu;
	}for(int i=t1; i>=0; i--){
		t1=0; t2=1;
		for(int j=0; j<i; j++){
			bantu = t1 + t2;
			t1 = t2;
			t2 = bantu;
			if(bantu==i){
				if(t1>=batas){
					cout<<t1<<" ";
				}
			}
		}
	}cout<<"\n\n";
	
	for(int i=0; 0<banyak; i++){
		cek=0;
		for(int j=2; j<i; j++){
			if(i%j==0){
				cek=1;
				break;
			}
		}
		if(cek==0 && i>1){
			if(i>=batas){
				bantu=i;
				banyak--;
			}
		}
	}for(int i=bantu; i>0; i--){
		cek=0;
		for(int j=2; j<i; j++){
			if(i%j==0){
				cek=1;
				break;
			}
		}
		if(cek==0){
			if(i>=batas){
				cout<<i<<" ";
			}
		}
	}

//	cin>>n;
//	for(int i=n; i>=1; i--){
//		t1=0;
//		t2=1;
//		for(int j=1; j<=i; j++){
//			bantu=t1+t2;
//			t1=t2;
//			t2=bantu;
//			if(bantu==i){
//				cout<<bantu<<" ";
//				if(bantu==1){
//				cout<<bantu<<" ";
//				}
//			}
//		}
//	}
}

