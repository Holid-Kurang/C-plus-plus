#include <iostream>
using namespace std;


int main(){
	
////LATIHAN 1
//	float total, p, s, r,R , n;
//	cout<<"berapa banyak hambatan ";
//	cin>>n;
//	cout<<"masukan hambatan : ";
//	while(n){
//		n--;
//		cin>>R;
//		r+=R;
//		p=p+1/R;
//	}
//	p=1/p;
//	s=r;
//	total = s+p;
//	cout<<"total hambatan seri : "<<s<<endl;
//	cout<<"total hambatan paralel : "<<p<<endl;
//	cout<<"total kedua hambatan : "<<total;

////LATIHAN 2
//	long briM,briI,bcaI,ntbI,mandiriI,bcaT,hI,hM,x;
//	cout<<"Moniq meminta ke ita untuk mentransfer ke BTN : ";cin>>x;
//	cout<<"Saldo BTN ita : ";cin>>ntbI;
//	cout<<"Saldo BRI ita : ";cin>>briI;
//	cout<<"Saldo BCA ita : ";cin>>bcaI;
//	cout<<"Saldo Mandiri ita : ";cin>>mandiriI;
//	cout<<"Yang ditransfer tantenya Moniq : ";cin>>bcaT;
//	bcaI+=bcaT;
//	cout<<"Saldo BCA ita sekarang adalah "<<bcaI<<endl;
//	ntbI=ntbI+bcaI+mandiriI;
//	cout<<"Ita mentransfer uang dari BCA dan Mandiri ke BTN"<<endl;
//	cout<<"Saldo BTN ita sekarang adalah "<<ntbI<<endl;
//	ntbI-=x;
//	cout<<"Lalu ita mentransfer ke BTN yang disuruh Moniq"<<endl;
//	cout<<"Saldo BTN ita setelah transfer ke BTN tujuan adalah "<<ntbI<<endl;
//	hM=x-bcaT;
//	cout<<"Hutang moniq ke ita sejumlah : "<<hM<<endl;
//	cout<<"Hutang ita ke moniq sejumlah : ";cin>>hI;
//	hM-=hI;
//	cout<<"Karena ita mempunyai hutang ke moniq juga ";
//	cout<<"jadi jumlah yang harus diganti moniq ke ita adalah "<<hM<<endl;
//	cout<<"Moniq mentransfer uang yang harus diganti ke BRI ita"<<endl;
//	briI+=hM;
//	cout<<"Saldo BRI ita sekarang adalah "<<briI;

////LATIHAN 3
//	int j ,m , d;
//	cin>>d;
//	if(d>=0 && d<=86400){
//		if(d>3599){
//			j=d/3600;
//			d=d%3600;
//		}else{
//			j=0;
//		}
//
//		if(d>59){
//			m=d/60;
//			d=d%60;
//		}else{
//			m=0;
//		}
//		cout<<j<<" jam, "<<m<<" menit, "<<d<<" detik.";
//	}else{
//		cout<<"program tidak berjalan";
//	}

////LATIHAN 4
//	int input, bulan, hari;
////	string list_hari[7] = {"minggu","Senin","Selasa","Rabu","kamis","Jumat","sabtu"};
//	int list_hari[7] = {7,1,2,3,4,5,6};
//	cin>>input;
//	if(input<=31){
//		bulan=1;
//		hari=list_hari[input%7 -1];
//	}else if(input>=32 && input<=59){
//		bulan=2;
//  		hari=list_hari[input%7-1];
//		input=input-31;
//	}else if(input>=60 && input<=90){
//		bulan=3;
//		hari=list_hari[input%7-1];
//		input=input-59;
//	}else if(input>=91 && input<=120){
//		bulan=4;
//		hari=list_hari[input%7-1];
//		input=input-90;
//	}else if(input>=121 && input<=151){
//		bulan=5;
//		hari=list_hari[input%7-1];
//		input=input-120;
//	}else if(input>=152 && input<=181){
//		bulan=6;
//		hari=list_hari[input%7-1];
//		input=input-151;
//	}else if(input>=182 && input<=212){
//		bulan=7;
//		hari=list_hari[input%7-1];
//		input=input-181;
//	}else if(input>=213 && input<=243){
//		bulan=8;
//		hari=list_hari[input%7-1];
//		input=input-212;
//	}else if(input>=244 && input<=273){
//		bulan=9;
//		hari=list_hari[input%7-1];
//		input=input-243;
//	}else if(input>=274 && input<=304){
//		bulan=10;
//		hari=list_hari[input%7-1];
//		input=input-273;
//	}else if(input>=305 && input<=334){
//		bulan=11;
//		hari=list_hari[input%7-1];
//		input=input-304;
//	}else if(input>=335 && input<=365){
//		bulan=12;
//		hari=list_hari[input%7-1];
//		input=input-334;
//	}
//	
//	cout<<"hari = "<<hari<<", tanggal = "<<input<<", bulan = "<<bulan;
	
////LATIHAN 5
//    int nominal, uang, jumlah;
//    cout << "uang: ";
//    cin >> nominal;
//
//    uang = nominal / 100000;
//    jumlah = uang;
//    if(jumlah>0){
//		cout << "lembar seratus ribu: " << jumlah << endl;
//	}
//
//    nominal %= 100000;
//    uang = nominal / 50000;
//    jumlah = uang;
//    if(jumlah>0){
//		cout << "lembar lima puluh ribu: " << jumlah << endl;
//	}
//
//    nominal %= 50000;
//    uang = nominal / 20000;
//    jumlah = uang;
//    if(jumlah>0){
//		cout << "lembar dua puluh ribu: " << jumlah << endl;
//	}
//
//    nominal %= 20000;
//    uang = nominal / 10000;
//    jumlah = uang;
//    if(jumlah>0){
//		cout << "lembar sepuluh ribu: " << jumlah << endl;
//	}
//
//    nominal %= 10000;
//    uang = nominal / 5000;
//    jumlah = uang;
//    if(jumlah>0){
//		cout << "lembar lima ribu: " << jumlah << endl;
//	}
//
//    nominal %= 5000;
//    uang = nominal / 2000;
//    jumlah = uang;
//    if(jumlah>0){
//		cout << "lembar dua ribu: " << jumlah << endl;
//	}
//
//    nominal %= 2000;
//    uang = nominal / 1000;
//    jumlah = uang;
//    if(jumlah>0){
//		cout << "lembar seribu: " << jumlah << endl;
//	}
//
//    nominal %= 1000;
//    uang = nominal / 500;
//    jumlah = uang;
//	if(jumlah>0){
//		cout << "lembar lima ratus: " << jumlah << endl;
//	}
//
//    nominal %= 500;
//    uang = nominal / 100;
//    jumlah = uang;
//    if(jumlah>0){
//		cout << "lembar seratus: " << jumlah << endl;
//	}

//LATIHAN 6
	float jeruk, diskon=0.05, harga;
	cout<<"jeruk satuan kilo : ";
	cin>>jeruk;
	harga = jeruk*5000;
	cout<<"harga sebelum diskon : "<<harga<<endl;
	cout<<"diskon : 5%"<<endl;
	cout<<"harga setelah diskon : "<<harga-harga*diskon;

}
