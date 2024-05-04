#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	int banyak;
	cout << "banyak bom (max = 26) : ";
	cin >> banyak;
	while (banyak > 26) {
		system("cls");
		cout << "banyak bom (max = 26) : ";
		cin >> banyak;
	}
	int bom[banyak];

	cout << endl;
	for (char i = 'A'; i < 'A' + banyak; i++) {
		cout << "(" << i << ")";
	}
	cout << endl;
	for (int i = 0; i < banyak; i++) {
		bom[i] = getch(); // Membaca karakter tanpa menunggu tombol "Enter"
		bom[i] -= 48;     // Mengubah karakter ke integer
		cout << " " << bom[i] << " ";
	}
	char indexBom;
	cout << endl << endl << "Bom yang diledakkan (nama bom) : ";
	cin >> indexBom;

	if (indexBom >= 'A' && indexBom <= 'Z') {
		indexBom -= 65;
	}
	else if (indexBom >= 'a' && indexBom <= 'z') {
		indexBom -= 97;
	}

	if (bom[(int)(indexBom)] == 0) {
		bom[(int)(indexBom)] = -1;
	}
	else {
		int rangeKanan = (int)(indexBom)+bom[(int)(indexBom)];
		int rangeKiri = (int)(indexBom)-bom[(int)(indexBom)];
		int bomYangDiledakkan = bom[(int)(indexBom)];
		int i = (int)(indexBom);
		while (i <= rangeKanan) {
			if (rangeKanan - i < bom[i]) {
				rangeKanan = bom[i] + i;
			}
			if (i - rangeKiri < bom[i]) {
				rangeKiri = i - bom[i];
			}

			bom[i] = -1;
			i++;
			if (rangeKanan > banyak - 1) {
				rangeKanan = banyak - 1;
			}
		}

		bom[(int)(indexBom)] = bomYangDiledakkan;
		i = indexBom;
		while (i >= rangeKiri) {
			if (i - rangeKiri < bom[i]) {
				rangeKiri = i - bom[i];
			}
			bom[i] = -1;
			i--;
			if (rangeKiri < 0) {
				rangeKiri = 0;
			}
		}
	}
	cout << "Bom yang tersisa : " << endl;
	// print bom
	cout << endl;
	for (char i = 'A'; i < 'A' + banyak; i++) {
		if (bom[i - 65] != -1) {
			cout << "(" << i << ")";
		}
	}
	cout << endl;
	for (char i = 'A'; i < 'A' + banyak; i++) {
		if (bom[i - 65] != -1) {
			cout << " " << bom[i - 65] << " ";
		}
	}
}