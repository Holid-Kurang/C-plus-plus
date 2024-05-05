#include <iostream>
#include <conio.h>
using namespace std;

void printpuzzle(int puzzle[4][4]) {
	system("cls");
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cout << setw(2);
			if (puzzle[y][x] == 16) {
				cout << " <" << puzzle[y][x] << "> ";
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
	}
	cout << "tekan enter kalo nyerah!!"<<endl;
	cout << "tekan r/esc untuk restart"<<endl;
}
int lokasiX(int puzzle[4][4]) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (puzzle[y][x] == 16) {
				return x;
			}
		}
	}
	return 0;
}
int lokasiY(int puzzle[4][4]) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (puzzle[y][x] == 16) {
				return y;
			}
		}
	}
	return 0;
}
void gerak(int puzzle[4][4], char slide, int kX, int kY) {
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
		if (stop > 3) stop = 3;
		temp = puzzle[stop][kX];
		puzzle[stop][kX] = puzzle[kY][kX];
		puzzle[kY][kX] = temp;
	}
}
bool checkWin(int puzzle[4][4]) {
	if (puzzle[0][0] == 1 && puzzle[0][1] == 2 && puzzle[0][2] == 3 && puzzle[0][3] == 4 &&
		puzzle[1][0] == 5 && puzzle[1][1] == 6 && puzzle[1][2] == 7 && puzzle[1][3] == 8 &&
		puzzle[2][0] == 9 && puzzle[2][1] ==10 && puzzle[2][2] ==11 && puzzle[2][3] ==12 &&
		puzzle[3][0] ==13 && puzzle[3][1] ==14 && puzzle[3][2] ==15 && puzzle[3][3] ==16 ) {
		return true;
	}
	return false;
}
void resetPuzzle(int puzzle[4][4]) {
    int resetValues[4][4] = { {1,8,4,15},{2,5,16,10},{9,6,3,11},{14,12,13,7} };
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            puzzle[i][j] = resetValues[i][j];
        }
    }
}
int main() {
	char a;
	int puzzle[4][4] = { {1,8,4,15},{2,5,16,10},{9,6,3,11},{14,12,13,7} };
	int kY, kX;
	while (1) {
		printpuzzle(puzzle);
		kX = lokasiX(puzzle);
		kY = lokasiY(puzzle);
		if (checkWin(puzzle)) {
			cout << endl << "menang!";
			break;
		}
		a = getch();
		if (a == 13) 
			break; //enter
		else if (a == 'R' || a == 'r'|| a==27) 
			resetPuzzle(puzzle); // Restart
		gerak(puzzle, a, kX, kY);
	}
}