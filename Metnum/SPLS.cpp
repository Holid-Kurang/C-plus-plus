#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;

double NIM = 14;
double matrixB[] = {1, -1, 1, -1, 1, -1, 1, -1, 1, -NIM};
double matrixA[10][10];
double** aug;
//	{6,1,8,7,8,7,9,0,2,3},
//	{2,2,1,8,7,8,7,9,0,0},
//	{1,1,1,0,8,7,9,0,0,0},
//	{0,0,0,8,7,8,6,1,8,0},
//	{7,6,1,8,8,6,1,8,0,1},
//	{0,0,8,7,6,1,8,1,8,7},
//	{0,8,7,9,0,8,7,6,1,8},
//	{0,1,8,7,6,1,8,9,0,0},
//	{7,6,1,8,7,8,6,1,8,0},
//	{0,0,8,7,9,8,7,1,8,7},

//fungsi untuk menyusun dua matrix menjadi augmented matrix
double** augmentedMatrix(double a[][10], double b[]) {
	double** matrixAug = new double*[10];
	for (int i = 0; i < 10; i++) {
		matrixAug[i] = new double[11];
		for (int j = 0; j < 11; j++) {
			if (j == 10) {
				matrixAug[i][10] = b[i];
			} else {
				matrixAug[i][j] = a[i][j];
			}
		}
	}
	return matrixAug;
}
//fungsi untuk mengecek apakah ada nilai nol pada diagonal
bool cekZero() {
	for (int i = 0; i < 10; i++) {
		if (aug[i][i] == 0) {
			return true;
		}
	}
	return false;
}

//fungsi untuk menentukan indeks nilai nol pada diagonal
int locateZero() {
	int i;
	for(i=0; i<10; i++) {
		if(aug[i][i]==0) {
			return i;
		}
	}
	return 0;
}

// fungsi untuk menukarkan baris pada matrix
void swapBaris(int dari, int ke) {
	double temp;
	for(int j=0; j<11; j++) {
		temp = aug[dari][j];
		aug[dari][j] = aug[ke][j];
		aug[ke][j] = temp;
	}
}

// fungsi penukaran baris apabila terdapat nilai nol pada diagonal
void swap() {
	int i=0;
	while(cekZero()) {
		if(i==10) {
			i=0;
		}
		int locate = locateZero();
		if(aug[i][i] != 0 && aug[i][locate] != 0) {
			swapBaris(i, locate);
		} else {
			i++;
		}
	}
}
void print() {
	for(int i=0; i<10; i++) {
		for(int j=0; j<11; j++) {
			if(j==9) {
				cout<<setw(7)<<fixed<<setprecision(3)<<aug[i][j]<<"  | ";
			} else {
				cout<<setw(7)<<fixed<<setprecision(3)<<aug[i][j];
			}
		}
		cout<<endl;
	}
}

void obe() {
	for(int i=0; i<10; i++) {

		for(int j=i+1; j<10; j++) {
			double factor = aug[j][i]/aug[i][i];

			for(int k = 1; k<11; k++) {
				aug[j][k] = aug[j][k] - factor*aug[i][k];
			}
		}
	}
}
void hasil() {
	double x[10];
	for(int i=9; i>=0; i--) {
		x[i]= aug[i][10];
		for(int j = i+1; j<10; j++) {
			x[i] -= aug[i][j]*x[j];
		}
		x[i] /= aug[i][i];
	}
	for(int i=0; i<10; i++) {
		cout<<"x["<<i<<"] = "<<fixed<<setprecision(5)<<x[i]<<endl;
	}
}
//	00 01 02 03 04 05 06 07 08 09   {6,1,8,7,8,7,9,0,2,3},
//  10 11 12 13 14 15 16 17 18 19 	{2,2,1,8,7,8,7,9,0,0},
//  20 21 22 23 24 25 26 27 28 29 	{1,1,1,0,8,7,9,0,0,0},
//  30 31 32 33 34 35 36 37 38 39	{0,0,0,8,7,8,6,1,8,0},
//  40 41 42 43 44 45 46 47 48 49	{7,6,1,8,8,6,1,8,0,1},
//  50 51 52 53 54 55 56 57 58 59	{0,0,8,7,6,1,8,1,8,7},
//  60 61 62 63 64 65 66 67 68 69	{0,8,7,9,0,8,7,6,1,8},
//  70 71 72 73 74 75 76 77 78 79	{0,1,8,7,6,1,8,9,0,0},
//  80 81 82 83 84 85 86 87 88 89	{7,6,1,8,7,8,6,1,8,0},
//  90 91 92 93 94 95 96 97 98 99	{0,0,8,7,9,8,7,1,8,7},
int main() {
	srand(time(0));
	//men-generate matrix_A 10x10 dengan random
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			//Menghasilkan bilangan acak antara 0 hingga 10
			matrixA[i][j] = rand() % 11;
		}
	}
	//menyusun matrix a dan b menjadi augmented matrix
	aug = augmentedMatrix(matrixA,matrixB);
	cout<<"\t\t\t\t[A]\t\t\t\t\t|    [B]"<<endl;
	for(int i=0; i<83; i++){cout<<"=";}cout<<endl;
	print();
	for(int i=0; i<83; i++){cout<<"=";}cout<<endl;
	cout<<"\t\t\tmatrix setelah melakukan penukaran baris"<<endl;
	swap();
	print();
	obe();
	hasil();
}