//Ben Waiz Pintus W
//2311102169

#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int hitungVokal(const string& kalimat) {
    int count = 0;
    for (char c : kalimat) {
        // Periksa apakah karakter saat ini adalah huruf vokal
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat;

    // Input kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Hitung jumlah huruf vokal
    int vocalCount = hitungVokal(kalimat);

    // Tampilkan hasilnya
    cout << "Jumlah huruf vokal dalam kalimat: " << vocalCount << endl;

    return 0;
}
