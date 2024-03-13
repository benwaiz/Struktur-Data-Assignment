#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fungsi untuk mengalikan angka dengan faktor
int multiply_by_factor(int num, int factor) {
    return num * factor;
}

int main() {
    // Vektor input
    vector<int> numbers = {1, 2, 3, 4, 5};

    // Faktor untuk perkalian
    int factor = 2;

    // Membuat vektor baru untuk menyimpan hasil perkalian
    vector<int> result(numbers.size());

    // Menggunakan std::transform untuk mengalikan setiap elemen dalam vektor dengan faktor
    transform(numbers.begin(), numbers.end(), result.begin(),
                   [factor](int num) { return multiply_by_factor(num, factor); });

    // Menampilkan hasil
    cout << "Vektor awal:";
    for (int num : numbers) {
        cout << " " << num;
    }
    cout << endl;

    cout << "Vektor setelah dikalikan dengan faktor " << factor << ":";
    for (int num : result) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
