# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>
<p align="center">Ben Waiz Pintus W - 2311102169</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

Tipe data adalah adalah sebuah pengklasifikasian data berdasarkan jenis data tersebut. Tipe data dibutuhkan agar kompiler dapat mengetahui bagaimana sebuah data akan digunakan. Adapun tipe data yang akan dipelajari, sebagai berikut :
1. Tipe data Primitif
2. Tipe data Abstrak
3. Tipe data Koleksi

1. Tipe data Primitif
Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem, tipe data primitif ini disediakan oleh banyak bahasa pemrograman, perbedaannya terletak pada jumlah bit yang dialokasikan untuk setiap bit pada tipe data primitif tergantung pada bahasa pemrograman,compiler dan sistem operasinya.

2. Tipe Data Abstrak
Tipe data abstrak atau yang biasa disebut Abstrak Data Tipe(ADT) merupakan tipe data yang dibentuk oleh programer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data. Fitur Class adalah fitur Object Oriented Program(OPP) pada bahasa C++ yang mirip dengan fitur data structures Struct pada bahasa C. Keduanya berfungsi untuk membungkus tipe data di dalamnya sebagai anggota. menurut learn.microsoft.com perbedaan antara Struct dan Class adalah pada akses defaultnya dimana Struct bersifat public dan Class bersifat private.

3. Tipe Data Koleksi
Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
//Main Program
int main()
{
    char op;
    float num1, num2;
    //it allows user to enter operator i,e,+,-,*,/
    cin >> op;
    //it allows user to enter the operand
    cin >> num1 >> num2;
    //swicth statement begins
    switch (op)
    {
    //if user center +
    case '+':
        cout << num1+num2;
        break;
    //if user center -
    case '-':
        cout << num1-num2;
        break;
    //if user center *
    case '*':
        cout << num1*num2;
        break;
    //if user center 
    case '/':
        cout << num1/num2;
        break;
    // if the operator is other than =,-,*, or /
    //error massage will be display
    default:
        cout << "error! operator is not correct";
    } //switch statement ends
    return 0;
}
```

#### Output :
<img width="648" alt="Screenshot 2024-03-13 092552" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/9b91681e-75c9-4430-a810-0547bd0c82f2">


Program di atas merupakan sebuah kalkulator sederhana yang meminta pengguna untuk memasukkan operator matematika (+, -, *, /) dan dua bilangan. Setelah menerima input tersebut, program menggunakan sebuah switch statement untuk mengecek operator yang dimasukkan oleh pengguna. Jika operator sesuai dengan salah satu kasus yang ditentukan (+, -, *, /), maka program akan menjalankan operasi aritmatika yang sesuai dan menampilkan hasilnya. Jika operator yang dimasukkan tidak sesuai dengan operator yang diharapkan, program akan menampilkan pesan kesalahan.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>
//struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    //mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;
    //mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```

#### Output :
<img width="636" alt="Screenshot 2024-03-13 093145" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/68858d46-649a-41ff-a839-651beee49935">


Program di atas adalah contoh penggunaan struct dalam bahasa pemrograman C. Struct digunakan untuk menggabungkan beberapa tipe data menjadi satu tipe data yang lebih kompleks. Pada program ini, terdapat sebuah struct yang memiliki tiga anggota.
Di dalam fungsi main(), dua variabel dari tipe struct Mahasiswa yaitu mhs1 dan mhs2 dideklarasikan. Nilai-nilai untuk anggota-anggota dari struct tersebut kemudian diisi secara langsung. Setelah itu, isi dari struct mhs1 dan mhs2 dicetak ke layar menggunakan fungsi printf(), sehingga menampilkan informasi masing-masing mahasiswa, yaitu nama, alamat, dan umur.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
//deklarasi dan inisialisasi array
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;
//mencetak array
cout << "Isi array pertama :" << nilai[0] << endl;
cout << "Isi array kedua :" << nilai[1] << endl;
cout << "Isi array ketiga :" << nilai[2] << endl;
cout << "Isi array keempat :" << nilai[3] << endl;
cout << "Isi array kelima :" << nilai[4] << endl;
return 0;
}
```

#### Output :
<img width="638" alt="Screenshot 2024-03-13 094244" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/27c49dbd-d98a-4653-9dbe-8e5493bf17ef">


Program di atas merupakan contoh penggunaan array dalam bahasa pemrograman C++. Pada program tersebut, sebuah array bernama nilai dengan panjang 5 elemen (indeks 0-4) dideklarasikan dan diinisialisasi dengan beberapa nilai. Setelah itu, nilai dari setiap elemen array dicetak ke layar menggunakan objek cout dari library iostream. Setiap elemen dicetak dengan pesan yang menyatakan indeksnya dan nilai yang disimpan di dalamnya. Program kemudian mengembalikan nilai 0, menandakan bahwa program telah berakhir dengan sukses.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
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

```

#### Output:
<img width="639" alt="Screenshot 2024-03-13 094845" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/382cce58-fe4b-43b4-9485-33621a1c03dd">


Program di atas adalah sebuah program C++ sederhana yang menghitung luas dan keliling persegi berdasarkan panjang sisi yang dimasukkan oleh pengguna. Pertama-tama, program meminta pengguna untuk memasukkan panjang sisi persegi. Kemudian, program memanggil dua fungsi terpisah: hitungLuasPersegi dan hitungKelilingPersegi, dengan parameter sisi yang telah dimasukkan oleh pengguna. Fungsi hitungLuasPersegi digunakan untuk menghitung luas persegi dengan rumus sisi * sisi, sementara fungsi hitungKelilingPersegi digunakan untuk menghitung keliling persegi dengan rumus 4 * sisi. Setelah nilai luas dan keliling diperoleh, program mencetak hasilnya ke layar menggunakan objek cout dari library iostream. Terakhir, program mengembalikan nilai 0, menandakan bahwa program telah berakhir dengan sukses.

Kesimpulan Tipe Data Primitif:<br/>
Tipe data primitif digunakan untuk menyimpan data yang sederhana dan tidak kompleks seperti bilangan bulat, bilangan pecahan, karakter, dan nilai boolean. Dalam pemrograman, pemilihan tipe data yang tepat sangat penting untuk memastikan program berjalan dengan baik dan efisien.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

```C++
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
```
#### Output:
<img width="637" alt="Screenshot 2024-03-13 100554" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/d65d01c7-8f08-42da-bacc-a2c5ad0ba30b">


Program di atas merupakan contoh penggunaan class dan struct dalam bahasa pemrograman C++. Dalam program tersebut, terdapat dua struktur data yang berbeda: class Mahasiswa dan struct Poin.

1. Class Mahasiswa:
   - Class ini memiliki dua atribut: nama dan umur.
   - Terdapat constructor yang digunakan untuk menginisialisasi objek Mahasiswa dengan nilai nama dan umur.
   - Method displayInfo() digunakan untuk menampilkan informasi tentang mahasiswa, yaitu nama dan umur.

2. Struct Poin:
   - Struct ini memiliki dua atribut: x dan y, yang mewakili koordinat titik dalam sebuah bidang.

Di dalam fungsi main(), contoh penggunaan class dan struct ditunjukkan:
- Objek mhs1 dari class Mahasiswa dibuat dengan menggunakan constructor dan kemudian metode displayInfo() dipanggil untuk menampilkan informasi mahasiswa tersebut.
- Objek p dari struct Poin dibuat dan kemudian koordinatnya dicetak ke layar.

Keseluruhan program menunjukkan perbedaan antara penggunaan class dan struct dalam C++, di mana class digunakan untuk menggabungkan data dan fungsi-fungsi yang beroperasi pada data tersebut dalam sebuah unit tunggal, sementara struct biasanya digunakan untuk mengelompokkan beberapa variabel yang terkait dalam satu kesatuan.

A. Fungsi dari Class<br/>
Class adalah konstruk yang digunakan untuk mendefinisikan tipe data yang kompleks, yang dapat memiliki data members (variabel) dan method (fungsi). Class juga dapat menggunakan inheritance (warisan) untuk mendefinisikan relasi antar class. Class memiliki default access modifier yang adalah private, yang berarti bahwa data members dan method hanya dapat diakses oleh fungsi yang ada dalam class tersebut. Class juga dapat memiliki constructor (konstruktor) yang digunakan untuk membuat objek class.

B. Fungsi dari Struct<br/>
Struct adalah konstruk yang digunakan untuk mendefinisikan tipe data yang sederhana, yang dapat memiliki data members (variabel) tetapi tidak dapat memiliki method. Struct juga dapat menggunakan inheritance (warisan) untuk mendefinisikan relasi antar struct. Struct memiliki default access modifier yang adalah public, yang berarti bahwa data members dan method dapat diakses oleh fungsi luar. Struct juga tidak dapat memiliki constructor.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
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

    // Menggunakan transform untuk mengalikan setiap elemen dalam vektor dengan faktor
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
```

#### Output:
<img width="632" alt="Screenshot 2024-03-13 103408" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/0151a000-2217-4bbe-b0e8-07c82ae727df">


Program di atas adalah contoh penggunaan vektor dan fungsi transform dalam bahasa pemrograman C++. Pada program tersebut, terdapat sebuah vektor bernama numbers yang berisi sekumpulan bilangan bulat. Program juga mendefinisikan sebuah fungsi multiply_by_factor yang digunakan untuk mengalikan sebuah bilangan dengan suatu faktor. Selanjutnya, program mendeklarasikan sebuah variabel factor yang merupakan faktor untuk perkalian. Kemudian, program membuat sebuah vektor baru bernama result yang memiliki ukuran yang sama dengan vektor numbers. Pada bagian utama program, fungsi transform digunakan untuk mengalikan setiap elemen dalam vektor numbers dengan faktor yang ditentukan, dan hasilnya disimpan dalam vektor result. Hasil perkalian kemudian dicetak ke layar, bersama dengan vektor awal numbers.

## Perbedaan Array dengan Map
1. Array
Array adalah tipe data terstruktur yang berguna untuk menyimpan sejumlah data yang bertipe sama. Array biasanya ditulis dalam bentuk sebuah variabel yang didefinisikan dengan indeks awal dan akhirnya. Setiap elemen dalam array dapat diakses menggunakan indeks. Array tidak memiliki fitur untuk membuat hubungan antara data yang sederhana.
   
3. Map
Map adalah tipe data yang menyimpan data dalam bentuk key-value pairs, dimana setiap elemen dalam map terdiri dari kunci dan nilai yang dipetakan. Map memiliki fitur untuk membuat hubungan antara kunci dan nilai yang kompleks. Map dapat digunakan untuk menyimpan data yang bersifat asosiatif, dimana kunci dapat berupa tipe data yang tidak harus berupa bilangan bulat.

Perbedaan antara array dan map terkait performance adalah bahwa array lebih efisien untuk menyimpan data yang berurutan dan dapat diakses menggunakan indeks, sedangkan map lebih efisien untuk menyimpan data yang bersifat asosiatif dan dapat diakses menggunakan kunci. Kebutuhan memory dan performance saat mengakses data juga berbeda antara array dan map.


## Kesimpulan
Tipe data adalah salah satu bagian penting dalam pemrograman, yang digunakan untuk menentukan jenis dan tipe data yang akan digunakan dalam program. Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem, sedangkan tipe data abstrak atau Abstrak Data Tipe (ADT) adalah tipe data yang dibentuk oleh programer itu sendiri. Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan, memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. Pilihan tipe data yang tepat sangat penting untuk memastikan program berjalan dengan baik dan efisien.

## Referensi
[1] Asisten Praktikum, "Modul 1 Tipe Data", Learning Management System, 2024.

[2] Sigit N. "Pengenalan Tentang Tipe Data Primitif dan Bukan Primitif di Bahasa Pemrograman C++", 2017.

