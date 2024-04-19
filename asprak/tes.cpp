#include <iostream>
using namespace std;

void incrementByPointer(int *ptr) {
    (*ptr)++;
}
void incrementByReference(int &ref) {
    ref++;
}

int main() {
    // int var = 5;
    // // store address of var
    // int* point_var = &var;
    // // print value of var
    // cout << "var = " << var << endl;
    // // print address of var
    // cout << "Address of var (&var) = " << &var << endl << endl;
    // // print pointer point_var
    // cout << "point_var = " << point_var << endl;
    // // print the content of the address point_var points to
    // cout << "Content of the address pointed to by point_var (*point_var) = " << *point_var << endl;

    // float arr[3];
    // // declare pointer variable
    // float* ptr;
    // cout << "Displaying address using arrays: " << endl;
    // // use for loop to print addresses of all array elements
    // for (int i = 0; i < 3; ++i) {
    //     cout << "&arr[" << i << "] = " << &arr[i] << endl;
    // }
    // // ptr = &arr[0]
    // ptr = arr;
    // cout << "\nDisplaying address using pointers: " << endl;
    // // use for loop to print addresses of all array elements
    // // using pointer notation
    // for (int i = 0; i < 3; ++i) {
    //     cout << "ptr + " << i << " = " << ptr + i << endl;
    // }

    // float arr[5];
    // // Insert data using pointer notation
    // cout << "Enter 5 numbers: ";
    // for (int i = 0; i < 5; ++i) {
    //     // store input number in arr[i]
    //     cin >> *(arr + i); // cin >> arr[i]; are equivalent
    // }
    // // Display data using pointer notation
    // cout << "Displaying data: " << endl;
    // for (int i = 0; i < 5; ++i) {
    //     // display value of arr[i]
    //     cout << *(arr + i) << endl;
    // }


    // int x = 10;
    // int& refX = x; // Referensi untuk variabel x

    // cout << "Nilai x: " << x << endl;   // Output: Nilai x: 10
    // cout << "Nilai refX: " << refX << endl; // Output: Nilai refX: 10

    // refX = 20; // Mengubah nilai melalui referensi
    // cout << "Nilai x setelah diubah melalui refX: " << x << endl; // Output: Nilai x setelah diubah melalui refX: 20


    int num = 5;
    incrementByReference(num);
    cout << "Nilai setelah penambahan: " << num << endl;
    incrementByPointer(&num);
    cout << "Nilai setelah penambahan: " << num << endl;
    return 0;
}