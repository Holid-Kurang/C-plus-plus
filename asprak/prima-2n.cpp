#include <iostream>
using namespace std;

int main() {
    int banyakBil;
    int prima = 2;
    int banyak2n = 0;
    int sum=0;
    cin >> banyakBil;
    for (int i = 0; i < banyakBil; i++) {
        if (i % 2 == 0) {
            while (true) {
                if (prima == 2) {
                    cout << prima << " ";
                    sum+=prima;
                    prima++;
                    break;
                }
                bool isPrima = true;
                for (int j = 2; j < prima; j++) {
                    if (prima % j == 0) {
                        isPrima = false;
                        break;
                    }
                }
                if (isPrima) {
                    cout << prima << " ";
                    sum+=prima;
                    prima++;
                    break;
                }
                prima++;
            }
        }
        else {
            cout << (1 << banyak2n) << " ";
            sum+=(1 << banyak2n);
            banyak2n++;
        }
    }
    cout << endl << "total : " <<sum;
}