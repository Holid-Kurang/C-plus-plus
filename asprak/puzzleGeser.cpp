#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

void printpuzzle(int puzzle[3][4]) {
	system("cls");
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {
			cout << setw(2);
			if (puzzle[y][x] == 12) {
				cout << " -" << puzzle[y][x] << "- ";
			}
			else {
				if (puzzle[y][x] < 10) {
					cout << " [ " << puzzle[y][x] << "] ";
				}
				else {
					cout << " [" << puzzle[y][x] << "] ";
				}
			}
		}
		cout << endl;
	}cout << "tekan enter kalo nyerah!!\n";
}
void lokasi(int puzzle[3][4], int& pX, int& pY) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {
			if (puzzle[y][x] == 12) {
				pY = y, pX = x;
			}
		}
	}
}
int lokasiX(int puzzle[3][4]) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {
			if (puzzle[y][x] == 12) {
				return x;
			}
		}
	}
	return 0;
}
int lokasiY(int puzzle[3][4]) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {
			if (puzzle[y][x] == 12) {
				return y;
			}
		}
	}
	return 0;
}
void gerak(int puzzle[3][4], char slide, int kX, int kY) {
	int temp, stop;
	if (slide == 72) { //atas
		stop = kY - 1;
		if (stop < 0) stop = 0;
		temp = puzzle[stop][kX];
		puzzle[stop][kX] = puzzle[kY][kX];
		puzzle[kY][kX] = temp;
	}
	else if (slide == 75) { //kiri
		stop = kX - 1;
		if (stop < 0) stop = 0;
		temp = puzzle[kY][stop];
		puzzle[kY][stop] = puzzle[kY][kX];
		puzzle[kY][kX] = temp;
	}
	else if (slide == 77) { //kanan
		stop = kX + 1;
		if (stop > 3) stop = 3;
		temp = puzzle[kY][stop];
		puzzle[kY][stop] = puzzle[kY][kX];
		puzzle[kY][kX] = temp;
	}
	else if (slide == 80) { //bawah
		stop = kY + 1;
		if (stop > 2) stop = 2;
		temp = puzzle[stop][kX];
		puzzle[stop][kX] = puzzle[kY][kX];
		puzzle[kY][kX] = temp;
	}
}
bool checkWin(int puzzle[3][4]) {
	if (puzzle[0][0] == 1 && puzzle[0][1] == 2 && puzzle[0][2] == 3 && puzzle[0][3] == 4 && 
		puzzle[1][0] == 5 && puzzle[1][1] == 6 && puzzle[1][2] == 7 && puzzle[1][3] == 8 && 
		puzzle[2][0] == 9 && puzzle[2][1] ==10 && puzzle[2][2] ==11 && puzzle[2][3] ==12 ) {
		return true;
	}
	return false;
}
int main() {
	char a;
	int puzzle[3][4] = { {1,8,3,10},{7,5,6,11},{4,9,2,12} };
	int kY, kX;
	while (1) {
		printpuzzle(puzzle);
		// lokasi(puzzle, kX, kY);
		kX = lokasiX(puzzle);
		kY = lokasiY(puzzle);
		if (checkWin(puzzle)) {
			cout << endl << "menang!";
			break;
		}
		a = getch();
		if (a == 13) break; //enter
		gerak(puzzle, a, kX, kY);
	}
}