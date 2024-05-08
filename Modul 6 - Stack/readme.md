# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Ben Waiz Pintus W - 2311102169</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori
 Stack atau dalam Bahasa Indonesia diartikan tumpukan, adalah struktur data linier yang mengikuti prinsip Last In First Out (LIFO). 
 Artinya elemen yang terakhir disisipkan akan menjadi elemen pertama yang keluar. Cara struktur data stack dalam menyimpan sebuah nilai dapat kita bayangkan seperti piring yang disusun rapi secara bertumpuk ke atas. 
 Apabila kita ingin mengambil piring bagian bawah, kita harus terlebih dahulu menyisihkan semua piring yang ada di atas.[1]

 ### Jenis-jenis operasi stack
 1. Pop

    operasi Pop pada stack adalah operasi yang berfokus pada penghapusan elemen.

2. Push

   Kebalikan dari pop, operasi Push justru lebih berfokus pada memasukkan elemen ke dalam stack atau tumpukan.

3. isFull

   Operasi stack yang satu ini adalah untuk mengetahui apakah tumpukan sudah penuh atau belum.

4. isEmpty

   isEmpty merupakan operasi yang digunakan untuk memeriksa apakah tumpukan kosong atau tidak.

5. Peek

   operasi Peek atau mengintip adalah operasi yang dilakukan untuk mengetahui data teratas dari tumpukan tanpa harus menghapusnya.[2]
   
## Guided 

### 1. Guided I

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);        
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index --;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index --;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main () {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;\

    cetakArrayBuku();
    
    return 0;
}
```

#### Output :
![Screenshot 2024-05-08 120216](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/8e54f2e8-db0b-4be7-8a67-2fc5ede0bdc3)


Program di atas adalah implementasi stack menggunakan array dalam bahasa C++. Program ini memiliki fungsi-fungsi dasar stack seperti push, pop, peek, isEmpty, isFull, countStack, changeArrayBuku, dan destroyArrayBuku. 
Program ini juga dapat mencetak isi dari stack, memeriksa apakah stack penuh atau kosong, melihat elemen pada posisi tertentu, menghitung jumlah elemen dalam stack, mengubah data pada posisi tertentu, serta menghapus seluruh data dalam stack. 
Pada program ini, data yang disimpan adalah daftar buku yang ditambahkan ke dalam stack dan kemudian dicetak.


## Unguided 

### 1. Unguided I

Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. 
Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
//Ben Waiz Pintus W
//2311102169

#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(string kalimat) {
  // Konversi kalimat menjadi huruf kecil
  for (int i = 0; i < kalimat.length(); i++) {
    kalimat[i] = tolower(kalimat[i]);
  }

  // Hapus spasi dan karakter non-huruf
  string temp = "";
  for (int i = 0; i < kalimat.length(); i++) {
    if (isalpha(kalimat[i])) {
      temp += kalimat[i];
    }
  }

  // Buat stack untuk menyimpan karakter kalimat
  stack<char> s;
  for (int i = 0; i < temp.length(); i++) {
    s.push(temp[i]);
  }

  // Bandingkan karakter dari depan dan belakang
  for (int i = 0; i < temp.length() / 2; i++) {
    if (s.top() != temp[i]) {
      return false;
    }
    s.pop();
  }

  return true;
}

int main() {
  string kalimat;

  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  if (isPalindrome(kalimat)) {
    cout << "Kalimat " << kalimat << " adalah palindrom" << endl;
  } else {
    cout << "Kalimat " << kalimat << " bukan palindrom" << endl;
  }

  return 0;
}
```

#### Output:
![Screenshot 2024-05-08 121031](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/fe8ddfb2-7ad8-4726-b124-f46999009270)
![Screenshot 2024-05-08 121103](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/0d6b0a78-b1e0-44d4-a209-86725c6cb2c1)


Program meminta pengguna memasukkan sebuah kalimat. Kemudian, string tersebut dibersihkan dari karakter non-alphanumeric dan semua huruf diubah menjadi huruf kecil agar perbandingannya menjadi case-insensitive.
String yang telah dibersihkan akan diperiksa apakah merupakan palindrom atau tidak. Program menggunakan struktur data stack untuk memeriksa apakah string tersebut merupakan palindrom.
Program memasukkan setengah karakter pertama dari string ke dalam stack. Kemudian, program memeriksa setengah karakter kedua dengan karakter yang di-pop dari stack.
Jika semua karakter cocok (membaca dari kedua ujung ke tengah) dan tidak ada perbedaan, maka string dianggap sebagai palindrom. Jika ada perbedaan, maka string tidak merupakan palindrom.


### 1. Unguided II

Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
//Ben Waiz Pintus W
//2311102169

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan huruf-huruf dalam sebuah kalimat menggunakan stack
string reverseLetters(const string& sentence) {
    stack<char> charStack;

    // Memasukkan setiap huruf ke dalam stack
    for (char c : sentence) {
        charStack.push(c);
    }

    // Membangun kalimat terbalik dari stack
    string reversedSentence;
    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }

    return reversedSentence;
}

int main() {
    string sentence;
    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, sentence);

    string reversed = reverseLetters(sentence); // Balikkan huruf-huruf dalam kalimat dari paling akhir ke awal menggunakan stack

    cout << "Hasil pembalikan kalimat: " << reversed << endl;

    return 0;
}

```

#### Output:
![Screenshot 2024-05-08 125015](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/5a1a9921-2de8-4d7f-b868-d4ef22a1b115)

Program meminta pengguna memasukkan sebuah kalimat yang terdiri dari minimal tiga kata. Lalu, Kalimat tersebut akan dibaca oleh program. Selanjutnya, Program akan memasukkan setiap huruf dari kalimat ke dalam stack. 
Setelah semua huruf dimasukkan ke dalam stack, program akan membalikkan urutan huruf dengan mengeluarkan huruf dari stack satu per satu dan memasukkannya ke dalam string hasil pembalikan huruf.
Program akan mencetak hasil pembalikan huruf dari paling akhir ke awal ke layar.

## Kesimpulan
Keuntungan dari menggunakan stack adalah management data yang efisien, management fungsi yang efisien, kontrol atas memori, manajemen memori cerdas, 
tidak mudah rusak, dan tidak mengizinkan pengubahan variabel. Namun dibalik keuntungan nya, stack juga memiliki kekurangan. Diantaranya yaitu 
ukuran memori yang terbatas, kemungkinan stack overflow, akses acak tidak dimungkinkan, dapat menyebabkan fungsi tidak terdefinisi, 
dan penghentian yang tidak diinginkan.
## Referensi
[1] Trivusi, "Struktur Data Stack: Pengertian, Karakteristik, dan Kegunaannya", 2022. https://www.trivusi.web.id/2022/07/struktur-data-stack.html

[2] Maulana Adieb, "Memahami Stack, Struktur Data yang Mudahkan Programmer Jalankan Tugasnya", 2021. https://glints.com/id/lowongan/stack-adalah/
