#include <iostream>
#include <string>
using namespace std;

// Contoh class: Mahasiswa
class Mahasiswa {
private:
    string nama;
    int umur;

public:
    // Constructor
    Mahasiswa(string nama, int umur) : nama(nama), umur(umur) {}

    // Method untuk menampilkan informasi mahasiswa
    void displayInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
    }
};

// Contoh struct: Poin
struct Poin {
    int x;
    int y;
};

int main() {
    // Menggunakan class
    Mahasiswa mhs1("Ben Waiz", 19);
    cout << "Informasi Mahasiswa:" << endl;
    mhs1.displayInfo();
    cout << endl;

    // Menggunakan struct
    Poin p = {5, 10};
    cout << "Koordinat Poin: (" << p.x << ", " << p.y << ")" << endl;

    return 0;
}
