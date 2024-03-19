# <h1 align="center">Laporan Praktikum Modul 2 - Array</h1>
<p align="center">Ben Waiz Pintus W - 2311102169</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori
Array merupakan struktur data yang paling dasar. Sebelum mempelajari struktur data lainnya, alangkah baiknya, kita perlu mempelajari Array terlebih dahulu. 
Berikut ini adalah beberapa jenis array :
1) Array Satu Dimensi

  Array satu dimensi adalah tipe variabel yang terdiri dari kumpulan data
  dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi. Setiap
  elemen di dalam array memiliki sebuah indeks atau nomor yang digunakan
  untuk mengakses elemen tersebut. Indeks dimulai dari 0 dan berakhir pada
  jumlah elemen dikurangi satu.

  Contohnya, sebuah array satu dimensi yang berisi bilangan bulat {1, 2,
  3, 4, 5} memiliki lima elemen dan indeksnya dimulai dari 0. Indeks 0 merujuk
  pada elemen pertama, indeks 1 merujuk pada elemen kedua, dan seterusnya
  hingga indeks 4 merujuk pada elemen kelima.
    
2) Array Dua Dimensi

  Array dua dimensi adalah variable yang terdiri dari kumpulan array
  satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom.
  Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks
  baris dan indeks kolom. Indeks baris menunjukkan posisi elemen dalam baris,
  sementara indeks kolom menunjukkan posisi elemen dalam kolom.

3) Array Multidimensi

  Array multidimensi memiliki kesamaan dengan array satu dimensi dan
  dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini
  digunakan untuk merepresentasikan array dengan dimensi lebih dari dua atau
  array yang memiliki lebih dari dua indeks, seperti array tiga dimensi, array
  empat dimensi, array lima dimensi, dan seterusnya.

4) Array Empat dimensi
  ```C++
int arr [3][2][4][4];
```

5) Array Lima Dimensi
  ```C++
int arr [2][4][4][3][3];
```
  
## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>

using namespace std;
// program input array 3 dimensi
int main()
{
    // deklarasi array
    int arr[2][3][3];
    // input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "]: ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Array[" << x << "][" << y << "][" << z << "]: " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
```

#### Output :
<img width="177" alt="Screenshot 2024-03-19 174743" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/cdc695d1-bc92-4251-b9b4-dda61b7c0167">

Program di atas adalah sebuah contoh program C++ yang mendemonstrasikan penggunaan array tiga dimensi. 
Program ini meminta pengguna untuk memasukkan nilai ke dalam array tiga dimensi dengan ukuran 2x3x3, kemudian mencetak nilai-nilai tersebut.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;

int main (){
    int maks, a, i=1, lokasi;
    cout << "Masukkan panjang array : ";
    cin >> a;
    int array [a];
    cout << "Masukkan " << a << " angka\n";
    for (i=0;i < a;i++)
    {
        cout << "Array ke- " << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i=0;i < a;i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```

#### Output :
<img width="317" alt="Screenshot 2024-03-19 191705" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/3e30e553-cbbd-4b69-b766-1dea5f78c784">

Program di atas adalah contoh program C++ yang bertujuan untuk mencari nilai maksimum dari sebuah array yang diinputkan pengguna.
Program meminta pengguna untuk memasukkan panjang array. Setelah panjang array dimasukkan, program membuat array dengan ukuran yang sesuai.
Selanjutnya, program meminta pengguna untuk memasukkan angka sebanyak panjang array yang telah ditentukan.
Program melakukan iterasi melalui setiap elemen array dan mencari nilai maksimum.
Ketika nilai maksimum ditemukan, program juga menyimpan lokasi (indeks) dimana nilai maksimum tersebut berada.
Setelah iterasi selesai, program mencetak nilai maksimum beserta lokasinya dalam array.

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
<img width="361" alt="Screenshot 2024-03-19 193725" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/f15b4a54-0406-4e3f-b261-359615a42e13">


```C++
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
```

#### Output:
<img width="639" alt="Screenshot 2024-03-19 194249" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/ef792661-dd81-49cc-9c43-c55e4b1519e8">

Program di atas adalah contoh program C++ yang meminta pengguna untuk memasukkan sejumlah angka ke dalam array, 
 kemudian mencetak array tersebut serta memisahkan angka-genap dan angka-ganjil ke dalam dua kelompok terpisah.
 Program meminta pengguna untuk memasukkan jumlah angka yang akan dimasukkan ke dalam array. Setelah jumlah angka dimasukkan, program membuat array dengan ukuran sesuai input pengguna.
 Program meminta pengguna untuk memasukkan angka sejumlah yang telah ditentukan. Setelah semua angka dimasukkan, program mencetak seluruh isi array.
 Program kemudian mencetak angka-angka genap yang ada dalam array. Terakhir, program mencetak angka-angka ganjil yang ada dalam array.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
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

```
#### Output:
<img width="629" alt="Screenshot 2024-03-19 195347" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/da7087c1-6fdf-4943-8c30-a5325396df0d">

Program di atas adalah contoh program C++ yang memungkinkan pengguna untuk memasukkan elemen-elemen ke dalam array tiga dimensi dan kemudian menampilkan isi array tersebut. 
 Program meminta pengguna untuk memasukkan jumlah elemen dalam masing-masing dimensi dari array tiga dimensi.
 Setelah ukuran array ditentukan, program mendeklarasikan array tiga dimensi dengan ukuran sesuai input pengguna.
 Pengguna diminta untuk memasukkan elemen-elemen array tiga dimensi melalui looping.
 Setiap elemen array diminta secara terurut sesuai dimensi x, y, dan z, dan kemudian disimpan di dalam array.
 Setelah semua elemen dimasukkan, program menampilkan isi array tiga dimensi dengan cara menelusuri setiap elemen dan mencetak nilainya.
 Setelah selesai menampilkan, program selesai.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
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
```

#### Output:
<img width="636" alt="Screenshot 2024-03-19 200609" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/2b7848a3-a3fe-4853-a394-cf56faeac6fb">

Program di atas adalah sebuah program C++ sederhana yang memungkinkan pengguna untuk memasukkan elemen-elemen ke dalam sebuah array, kemudian memilih opsi untuk mencari nilai maksimum, minimum, atau rata-rata dari elemen-elemen tersebut.
Program meminta pengguna untuk memasukkan jumlah elemen array.
Setelah jumlah elemen array ditentukan, program mendeklarasikan array dengan ukuran yang sesuai.
Pengguna diminta untuk memasukkan nilai-nilai elemen array melalui looping.
Setelah semua elemen dimasukkan, program menampilkan menu yang berisi pilihan operasi yang dapat dilakukan, yaitu mencari nilai maksimum, minimum, atau rata-rata.
Pengguna diminta untuk memilih salah satu dari pilihan tersebut.
Program melakukan operasi sesuai pilihan pengguna menggunakan switch case.
Hasil operasi ditampilkan ke layar.


## Kesimpulan
Array merupakan struktur data yang fundamental dalam pemrograman, dan penting untuk dipelajari sebelum memahami struktur data lainnya.
Ada beberapa jenis array yang umum digunakan. Pertama, array satu dimensi adalah kumpulan data dengan tipe yang sama yang disusun dalam satu baris
Setiap elemen memiliki indeks yang dimulai dari 0 hingga jumlah elemen dikurangi satu. Kemudian, array dua dimensi adalah kumpulan array satu dimensi yang disusun dalam baris dan kolom.
Setiap elemen dalam array dua dimensi memiliki dua indeks: indeks baris dan indeks kolom. erakhir, array multidimensi memperluas konsep array dengan menyediakan dimensi lebih dari dua atau lebih dari dua indeks, seperti array tiga dimensi, empat dimensi, dan seterusnya.
Pemahaman yang baik tentang jenis-jenis array ini akan membantu dalam mengorganisir dan mengelola data dengan lebih efisien dalam pengembangan perangkat lunak.
Dengan menguasai konsep-konsep dasar array, pemrogram dapat membangun fondasi yang kuat untuk mempelajari struktur data yang lebih kompleks.

## Referensi
[1] Asisten Praktikum, "Modul 2 Array", Learning Management System, 2024.
