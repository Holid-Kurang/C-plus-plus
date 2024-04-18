#include<iostream>
#include<conio.h>
using namespace std;

int main (){
	/* A = Harga makanan/harga bayar*/

	float A;
	cout << "Harga makanan       = Rp.";

	cin >> A;
	 cin.get();

  /* rumus
	 pajak = hargabayar*9/99;
		hargaasli = hargabayar-pajak; */
  /* rumus menu berdua
	 hargaberdua = (hargabayar*2)-(hargabayar*2*1/10);
		menuberdua = hargaberdua - hargaberdua*9/99; */
  /* rumus menu berempat
	 hargaberempat = (hargaberdua*2)-(hargaberdua*2*1/00;
		menuberempat = hargaberempat - (hargaberempat*9/99) */

	cout
	 << "Harga Menu          = Rp." << A - (A/(99/9))
	 << " dengan PPN sebesar : Rp." << A/(99/9) << endl
	 << "Harga Menu Berdua   = Rp." << ((A/0.5)-(A/5))-((A/0.5)-(A/5))/(99/9)
	 << " dengan PPN sebesar : Rp." << (((A/0.5)-(A/5))-((A/0.5)-(A/5))/(99/9))/10 << endl
	 << "Harga Menu Berempat = Rp." << ((((A/0.5)-(A/5))/0.5) - (((A*2)-(A/5))/0.5)/10) - ((((A/0.5)-(A/5))/0.5) - (((A/0.5)-(A/5))/0.5)/10)/(99/9)
	 << " dengan PPN sebesar : Rp." << (((((A/0.5)-(A/5))/0.5) - (((A*2)-(A/5))/0.5)/10) - ((((A/0.5)-(A/5))/0.5) - (((A/0.5)-(A/5))/0.5)/10)/(99/9))/10;

	 getch();
	 return 0;
}
