#include <iostream>
using namespace std;

int aldiFauziTersayang(int num1, int num2) {
    return num1 + num2;
}

void penukarCallbyReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void penukarCallbyValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    bool truth = true;
    cout << truth << endl;
    truth = 5 == 7 - 2;
    cout << truth << endl;
    cout << (truth == 3 - 2) << endl;
    truth = (5 % 2 == 1) && truth;
    if (truth) {
        cout << "iya\n";
    }
    else {
        cout << "tidak\n";
    }
    if (true) {
        cout << "iya\n";
    }
    if (truth > 0) {
        cout << "lebih\n";
    }
    else if (truth == 0) {
        cout << "sama\n";
    }
    else {
        cout << "kurang\n";
    }
    if (truth && (5 % 5 == 1)){
        cout << "iya\n";
    }
    else {
        cout << "tidak\n";
    }
    if (truth || (5 % 5 == 1)) {
        cout << "iya\n";
    }
    else {
        cout << "tidak\n";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << truth << endl;
    }
    cout << endl;
    int i = 0;
    while (i < 5) {
        cout << truth << endl;
        i++;
    }
    cout << endl;
    for (int k = 0; k < 5; k++) {
        cout << k * 2 << endl;
    }
    cout << endl;

    int angka = 1;
    for (int j = 1; j <= 5; j++){
        cout << "tampilan ke-" << j << " : ";
        cout << angka << endl;
        angka = angka * 2;
        // angka = angka + angka;
        // angka += angka;

    }
    angka = 1;
    for (int l = 1; l <= 5; l++) {
        cout << (angka + l) << endl;
        angka = (angka * 2);
    }
    cout << endl;

    //nomor 17
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
    cout << endl;

    //nomor 18
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;

    int j;
    i = 1;
    while (i <= 5) {
        int j = 1;
        while (j <= i) {
            cout << i;
            j++;
        }
        cout << endl;
        i++;
    }

    cout << endl;
    int arr[6] = { 2,4,5,6,7,9 };
    //int arrLength = sizeof(arr) / sizeof(int);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    for (int i = 0; i < 6; i+=2) {
        cout << arr[i] << ", ";
    }

    //int aldiFauziTersayang(int num1, int num2) {
    //    return num1 + num2;
    //}
    cout <<endl<< aldiFauziTersayang(arr[1], arr[2]) << endl;

//  void penukarCallbyValue(int a, int b) {
//    int temp = a;
//    a = b;
//    b = temp;
//	}
    penukarCallbyValue(arr[1], arr[2]);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

//	void penukarCallbyReference(int *a, int *b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//	}
    penukarCallbyReference(&arr[1], &arr[2]);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << ", ";
    }

    cout << endl << "variabel truth dengan nilai "<<truth<<" memiliki alamat pada "<< & truth<<endl;
    bool *ptr;
    ptr = &truth;
    cout << ptr << endl;
    cout << *ptr << endl;
    bool **doubleptr;
    doubleptr = &ptr;
    cout << **doubleptr << endl;
}
