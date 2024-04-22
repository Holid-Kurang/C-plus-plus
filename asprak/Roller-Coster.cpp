#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	float koor = 0;
	int r, orang;
	cout << " -----------------------------------" << endl;
	cout << "/     selamat datang di wahana      \\" << endl;
	cout << "\\       roller-coster 4lpr0         /" << endl;
	cout << " -----------------------------------" << endl;
	cout << "        \\\\  ^__^" << endl;
	cout << "         \\\\ (oo)\\_______" << endl;
	cout << "            (__)\\       )\\/\\" << endl;
	cout << "                ||---WW |  !" << endl;
	cout << "                ||     ||" << endl;
	cout << "+=============================================+" << endl;
	cout << "|  Modifikasi wahana yang ingin kalian naiki  |" << endl;
	cout << "+=============================================+" << endl;
	cout << "Masukkan ukuran wahana roller coster = ";
	cin >> r;
	cout << "Jumlah orang yang menaiki = ";
	cin >> orang;

	while (1) {
		system("cls");
		cout << " -----------------------------------" << endl;
		cout << "/     selamat datang di wahana      \\" << endl;
		cout << "\\       roller-coster 4lpr0         /" << endl;
		cout << " -----------------------------------" << endl;
		cout << "        \\\\  ^__^" << endl;
		cout << "         \\\\ (oo)\\_______" << endl;
		cout << "            (__)\\       )\\/\\" << endl;
		cout << "                ||---WW |  !" << endl;
		cout << "                ||     ||" << endl;
		cout << "+=============================================+" << endl;
		cout << "Ukuran rel wahana roller coster = " << r << endl;
		cout << "Jumlah orang yang menaiki = " << orang << endl;
		if (koor == 6) {
			koor = 0;
		}
		koor += 0.1;
		for (int y = r; y >= -r; y--) {
			for (int x = -r; x <= r; x++)
			{
				cout << setw(2);
				//				c = x*x+y*y;
				//				z = (x-a)*(x-a)+y*y;   x - sin(koor) * r   y - cos(koor) * r
				if (pow(x, 2) + pow(y, 2) <= r * (r - 1) && pow(x, 2) + pow(y, 2) >= r * (r - 3) && pow(x - sin(koor) * r, 2) + pow(y - cos(koor) * r, 2) <= orang * (orang))
					cout << "#";
				else if (x * x + y * y <= r * (r - 1) && (x) * (x)+y * y >= r * (r - 3))
					cout << ".";
				else
					cout << " ";
			}
			cout << endl;
		}
	}
}
