//Ben Waiz Pintus W
//2311102169

#include <iostream>

using namespace std;

// Fungsi untuk menghitung jumlah angka 4 dalam array menggunakan Sequential Search
int hitungAngka(const int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    // Data array yang diberikan
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 4;

    // Hitung jumlah angka 4 dalam array
    int count = hitungAngka(data, size, target);

    // Tampilkan hasilnya
    cout << "Jumlah angka " << target << " dalam array: " << count << endl;

    return 0;
}
