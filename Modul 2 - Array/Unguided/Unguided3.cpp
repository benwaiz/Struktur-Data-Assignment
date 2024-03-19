#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    // Deklarasi array
    int arr[n];

    // Input elemen array dari pengguna
    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Menampilkan menu
    cout << "Menu:" << endl;
    cout << "1. Cari nilai maksimum" << endl;
    cout << "2. Cari nilai minimum" << endl;
    cout << "3. Cari nilai rata-rata" << endl;

    int choice;
    cout << "Pilih menu (1/2/3): ";
    cin >> choice;

    // Proses sesuai dengan pilihan pengguna
    switch (choice) {
        case 1: {
            // Cari nilai maksimum
            int max = arr[0];
            for (int i = 1; i < n; ++i) {
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
            cout << "Nilai maksimum: " << max << endl;
            break;
        }
        case 2: {
            // Cari nilai minimum
            int min = arr[0];
            for (int i = 1; i < n; ++i) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }
            cout << "Nilai minimum: " << min << endl;
            break;
        }
        case 3: {
            // Cari nilai rata-rata
            double sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += arr[i];
            }
            double average = sum / n;
            cout << "Nilai rata-rata: " << average << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}
