#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel
    int b_169;
    // Meminta pengguna untuk memasukkan jumlah array
    cout << "Masukkan jumlah array: ";
    cin >> b_169;
    // Deklarasi array dengan ukuran b_169
    int arr[b_169];

    // Input array
    cout << "Masukkan " << b_169 << " angka\n";
    for (int a = 0; a < b_169; a++)
    {
        cout << "Array ke - " << a << ": ";
        cin >> arr[a];
    }
    cout << endl;

    // Output data array
    cout << "Data Array : ";
    for (int a = 0; a < b_169; a++)
    {
        cout << arr[a] << " ";
    }
    cout << endl;

    // Output nomor genap
    cout << "Nomor Genap : ";
    for (int a = 0; a < b_169; a++)
    {
        if (arr[a] % 2 == 0)
        {
            cout << arr[a] << ", ";
        }
    }
    cout << endl;

    // Output nomor ganjil
    cout << "Nomor Ganjil : ";
    for (int a = 0; a < b_169; a++)
    {
        if (arr[a] % 2 != 0)
        {
            cout << arr[a] << ", ";
        }
    }
}