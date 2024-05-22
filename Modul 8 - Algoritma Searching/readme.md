# <h1 align="center">Laporan Praktikum Modul 8 - Algoritma Searching</h1>
<p align="center">Ben Waiz Pintus W - 2311102169</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Pengertian
 Algoritma pencarian (searching algorithm) adalah algoritma yang menerima sebuah kata kunci dan dengan  langkah-langkah tertentu akan mencari rekaman dengan kata kunci tersebut.  
 Setelah proses pencarian dilaksanakan, akan diperoleh salah satu dari dua kemungkinan, yaitu data yang dicari ditemukan atau tidak ditemukan. [1]
 
 ### Sequential Search
 Algoritma sequential search termasuk kedalam algoritma pencarian yang paling sederhana. Sequential search disebut juga pencarian lurus (linear search). 
 Pada dasarnya, algoritma pencarian beruntun adalah proses membandingkan setiap elemen larik secara beruntun satu persatu, mulai dari elemen pertama, sampai elemen yang dicari ditemukan, atau seluruh elemen sudah diperiksa. 
 Atau singkatnya sequential search ini menemukan data dari awal sampai ketemu, setelah ketemu pencarian dihentikan. [1]
 
 ### Binary Search
Jenis algoritma ini sangat berguna untuk menemukan posisi nilai tertentu dalam larik yang diurutkan. Algoritma pencarian biner dianggap sebagai salah satu algoritma pencarian paling efisien, karena memiliki tingkat kecepatan kerja yang tinggi.
Algoritma pencarian biner bekerja dengan mulai mencari di tengah array, kemudian turun ke bagian bawah atau atas dari urutan yang diberikan. Apabila nilai median lebih rendah dari nilai target, pencarian akan lebih tinggi. Jika sebaliknya, algoritma akan melihat ke bagian yang menurun dari larik. [2]

## Guided 

### 1. Guided I

```C++
#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout<< "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu){
        cout << "\n angka " << cari << " ditemukan pada indeks ke - " << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    
    return 0;

}
```

#### Output :
![Screenshot 2024-05-22 145951](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/2a7157b2-5c66-4301-9821-bae64ff858cc)

Program ini adalah implementasi sederhana dari algoritma Sequential Search dalam bahasa C++. Program bertujuan untuk mencari apakah suatu angka (dalam hal ini angka 10) terdapat dalam array berisi 10 elemen (data). 
Program mengiterasi setiap elemen array dan memeriksa apakah elemen tersebut sama dengan angka yang dicari. Jika ditemukan, program mengatur variabel boolean ketemu menjadi true dan menghentikan pencarian, kemudian menampilkan indeks di mana angka tersebut ditemukan.

### 2. Guided II

```C++
#include <iostream>
#include <iomanip>

using namespace std;

// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

// Fungsi selection sort untuk mengurutkan array
void selectionSort(int arr[], int n) {
    int temp, minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Fungsi binary search untuk mencari data dalam array yang telah diurutkan
void binarySearch(int arr[], int n, int target) {
    int start = 0, end = n - 1, middle, found = 0;

    while (start <= end && found == 0) {
        middle = (start + end) / 2;

        if (arr[middle] == target) {
            found = 1;
        } else if (arr[middle] < target) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    if (found == 1) {
        cout << "\nData ditemukan pada indeks ke-" << middle << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH" << endl;

    cout << "\nData awal: ";
    // Menampilkan data awal
    for (int i = 0; i < 7; i++) {
        cout << setw(3) << arrayData[i];
    }
    cout << endl;

    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;

    // Mengurutkan data dengan selection sort
    selectionSort(arrayData, 7);

    cout << "\nData diurutkan: ";
    // Menampilkan data setelah diurutkan
    for (int i = 0; i < 7; i++) {
        cout << setw(3) << arrayData[i];
    }
    cout << endl;

    // Melakukan binary search
    binarySearch(arrayData, 7, cari);

    return 0;
}  
```

#### Output :
![Screenshot 2024-05-22 150704](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/b98f2dc6-9763-41ec-a3ca-37418218a138)

Program ini mengimplementasikan algoritma Selection Sort dan Binary Search dalam bahasa C++. Program bertujuan untuk mengurutkan array yang berisi 7 elemen menggunakan algoritma Selection Sort, 
kemudian mencari elemen tertentu (input dari pengguna) dalam array yang telah diurutkan menggunakan algoritma Binary Search.

## Unguided 

### 1. Unguided I

Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
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
```

#### Output:
![Screenshot 2024-05-22 151221](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/3a2fecf1-42c1-4529-9175-4bba1cc158b7)

Mengimplementasikan algoritma Binary Search untuk mencari sebuah huruf dalam sebuah kalimat yang diinput oleh pengguna. Program menerima input berupa kalimat dan huruf yang ingin dicari.
Setelah itu, program melakukan pencarian huruf yang diinginkan menggunakan algoritma Binary Search.

### 2. Unguided II

Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
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
```

#### Output:
![Screenshot 2024-05-22 151708](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/612acb96-3e0f-4217-8bf7-727e3f0bd793)

Program ini bertujuan untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang diinput oleh pengguna. Program meminta pengguna untuk memasukkan sebuah kalimat, kemudian menggunakan fungsi hitungVokal untuk menghitung jumlah huruf vokal dalam kalimat tersebut. 
Fungsi ini iterasi melalui setiap karakter dalam kalimat dan memeriksa apakah karakter tersebut adalah huruf vokal. Setelah menghitung, program menampilkan jumlah huruf vokal yang ditemukan kepada pengguna.

### 3. Unguided III

Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
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
```

#### Output:
![Screenshot 2024-05-22 152307](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/a8b828f8-c60f-4ced-b481-07c8253e4400)

Program ini bertujuan untuk menghitung jumlah kemunculan angka 4 dalam sebuah array menggunakan algoritma Sequential Search. Program dimulai dengan mendefinisikan sebuah array berisi 10 elemen.
Fungsi hitungAngka kemudian digunakan untuk mengiterasi setiap elemen dalam array dan menghitung berapa kali angka 4 muncul. Setelah perhitungan selesai, program menampilkan jumlah kemunculan angka 4 tersebut kepada pengguna.

## Kesimpulan
Algoritma pencarian merupakan metode yang digunakan untuk menemukan rekaman data berdasarkan kata kunci tertentu. Terdapat berbagai jenis algoritma pencarian, di antaranya adalah Sequential Search dan Binary Search, yang masing-masing memiliki karakteristik dan cara kerja yang berbeda.
Dengan demikian, pemilihan algoritma pencarian yang tepat bergantung pada kondisi dan karakteristik data yang akan dicari, serta kebutuhan efisiensi dari proses pencarian tersebut. Sequential Search cocok untuk dataset kecil atau tidak terurut, sementara Binary Search lebih efektif untuk dataset besar yang sudah terurut.

## Referensi
[1] tirago4, "Pencarian (searching) Didalam Algortima", 2016. https://tirago4.wordpress.com/2016/10/11/pencarian-searching-didalam-algoritma/

[2] Soffya Ranti, "Pengertian Algoritma Pencarian dan Jenis-jenisnya", kompas.com, 2022. https://tekno.kompas.com/read/2022/12/02/17150037/pengertian-algoritma-pencarian-dan-jenis-jenisnya?page=all
