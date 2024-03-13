#include <iostream>
using namespace std;

// Fungsi untuk menghitung luas persegi
int hitungLuasPersegi(int sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung keliling persegi
int hitungKelilingPersegi(int sisi) {
    return 4 * sisi;
}

int main() {
    // Input dari pengguna
    int sisi;
    cout << "Masukkan panjang sisi persegi: ";
    cin >> sisi;

    // Memanggil fungsi untuk menghitung luas dan keliling
    int luas = hitungLuasPersegi(sisi);
    int keliling = hitungKelilingPersegi(sisi);

    // Menampilkan hasil
    cout << "Luas persegi: " << luas << endl;
    cout << "Keliling persegi: " << keliling << endl;

    return 0;
}
