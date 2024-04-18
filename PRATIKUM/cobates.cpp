#include <iostream>
using namespace std;

int main()
{
    int suhuAwal;
    cout << "Suhu awal: ";
    cin >> suhuAwal;
    cout << "Suhu awal kamar Holil: " << endl;
    cout << "1. " << suhuAwal << " C" << endl;
    cout << "2. " << (float)suhuAwal * (9.0 / 5.0) + 32 << " F" << endl;
    cout << "3. " << (float)suhuAwal + 273.15 << " K" << endl;

    cout << endl;
    cout << "Setelah 15 menit" << endl;
    cout << "Suhu kamar Holil berkurang menjadi " << (((float)suhuAwal - ((float)suhuAwal * 0.25)) * (9.0 / 5.0)) + 32.0 << " F ";
    cout << "dengan pengurangan sebesar " << ((float)suhuAwal * 0.25) + 273.15 << " K "; // berkurang setelah 15 menit
    cout << endl;

    cout << "Setelah 45 menit" << endl;
    cout << "Suhu kamar Holil berkurang menjadi " << ((float)suhuAwal - ((float)suhuAwal * 0.65)) + 273.15 << " K ";
    cout << "dengan pengurangan sebesar " << (float)suhuAwal * 0.65 << " C" << endl;
    cout << "\nSuhu awal kamar Holil: " << suhuAwal << " C" << endl;
    float suhuDingin = (float)suhuAwal - (float)suhuAwal * 0.65;
    cout << "Suhu kamar Holil saat ini: " << suhuDingin << " C" << endl;

    cout << "\nHolil mematikan pendingin...\n\n";

    cout << "Setelah 25 menit" << endl;
    cout << "Suhu kamar Holil naik menjadi " << suhuDingin + suhuDingin * 0.35 << " C" << endl;
    cout << "\nHasil perbandingan :\n";
    cout << "1:" << (float)suhuAwal / (suhuDingin + (suhuDingin * 0.35)) << " untuk suhu saat ini" << endl;
    cout << "1:" << (float)suhuAwal / (suhuDingin) << " untuk suhu terdingin" << endl;
    cout << "1:" << (float)suhuAwal / ((float)suhuAwal - ((float)suhuAwal * 0.25)) << " untuk suhu 15 menit setelah pendingin" << endl;

    // cout << "\n--------------------------------\n";
    system("pause");
    return 0;
}