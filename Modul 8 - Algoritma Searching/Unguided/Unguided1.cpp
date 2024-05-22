//Ben Waiz Pintus W
//2311102169

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk melakukan binary search pada array karakter
bool binarySearch(const string& arr, char target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Jika target ditemukan
        if (arr[mid] == target) {
            return true;
        }

        // Jika target lebih besar dari nilai tengah, abaikan bagian kiri
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // Jika target lebih kecil dari nilai tengah, abaikan bagian kanan
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    string kalimat;
    char target;

    // Input kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Input huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    // Ubah kalimat menjadi string terurut
    string sorted_kalimat = kalimat;
    sort(sorted_kalimat.begin(), sorted_kalimat.end());

    // Tampilkan kalimat yang sudah diurutkan (untuk verifikasi)
    cout << "Kalimat yang diurutkan: " << sorted_kalimat << endl;

    // Lakukan pencarian binary search
    if (binarySearch(sorted_kalimat, target)) {
        cout << "Huruf '" << target << "' ditemukan dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
