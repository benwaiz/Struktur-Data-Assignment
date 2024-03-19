#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    // Input ukuran array tiga dimensi dari pengguna
    cout << "Masukkan jumlah elemen pada dimensi x: ";
    cin >> x;
    cout << "Masukkan jumlah elemen pada dimensi y: ";
    cin >> y;
    cout << "Masukkan jumlah elemen pada dimensi z: ";
    cin >> z;

    // Deklarasi array tiga dimensi
    int array3D[x][y][z];

    // Input elemen array dari pengguna
    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cout << "Masukkan elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D[i][j][k];
            }
        }
    }

    // Menampilkan elemen array tiga dimensi
    cout << "Data array tiga dimensi:" << endl;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cout << array3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
