#include <iostream>
using namespace std;

int main(){
	int tl, bl, hl;
	int ts, bs, hs;
	cout<<"tanggal lahir : "; cin>>hl;
	cout<<"bulan lahir : "; cin>>bl;
	cout<<"tahun lahir : "; cin>>tl;
	cout<<endl;
	cout<<"tanggal sekarang : "; cin>>hs;
	cout<<"bulan sekarang : "; cin>>bs;
	cout<<"tahun sekarang : "; cin>>ts;

	cout<<"\nUmur anda saat ini : "<<endl;

		 if(ts-tl ==1 && bl == bs && hs<hl ){
		cout<<0<<" tahun "<<12-1<<" bulan "<<30-(hl-hs)<<" hari";
	}
	else if(ts == tl && bl <= bs && hs > hl){
		cout<<0<<" tahun "<<bs-bl<<" bulan "<<hs-hl<<" hari";
	}
	else if(ts == tl && bl <= bs && hs < hl){
		cout<<0<<" tahun "<<bs-bl<<" bulan "<<hl-hs<<" hari";
	}
	else if(ts > tl && bl <= bs && hl <= hs){
		cout<<ts-tl<<" tahun "<<bs-bl<<" bulan "<<hs-hl <<" hari";
	}
	else if(ts > tl && bl >= bs && hl >= hs){
		cout<<ts-tl-1<<" tahun "<<12-(bl-bs)<<" bulan "<<hl-hs <<" hari";
	}
	else if(ts > tl && bl >= bs && hl <= hs){
		cout<<ts-tl-1<<" tahun "<<12-(bl-bs)<<" bulan "<<hs-hl <<" hari";
	}
	else if(ts > tl && bl <= bs && hl >= hs){
		cout<<ts-tl<<" tahun "<<bs-bl<<" bulan "<<hl-hs <<" hari";
	}

}
