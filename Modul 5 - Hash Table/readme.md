# <h1 align="center">Laporan Praktikum Modul 5 - Hash Table</h1>
<p align="center">Ben Waiz Pintus W - 2311102169</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori
Hash table merupakan struktur data yang secara asosiatif menyimpan data. Dalam hal ini, data disimpan dalam format array, di mana setiap nilai data memiliki nilai indeks uniknya sendiri. Akses data akan menjadi sangat cepat jika Anda mengetahui indeks dari data yang diinginkan.

Fungsi utamanya pada data adalah mempercepat proses akses data. Hal ini berkaitan dengan peningkatan data dalam jumlah besar yang diproses oleh jaringan data global dan lokal. Hash table adalah solusi untuk membuat proses akses data lebih cepat dan memastikan bahwa data dapat dipertukarkan dengan aman.[1]

Cara Kerja Struktur Data Hash Table :
1. Inisialisasi
   
   Hash Table awalnya dibuat dengan ukuran tertentu, yang biasanya merupakan bilangan prima. Ukuran ini dapat disesuaikan sesuai kebutuhan.

2. Fungsi Hash
   
   Hash Table menggunakan fungsi hash untuk memetakan nilai yang diberikan dengan kunci tertentu ke indeks dalam array. Fungsi hash ini harus menghasilkan nilai yang unik untuk setiap kunci yang berbeda, sehingga elemen-elemen dapat disimpan dengan benar.

3. Pemetaan Nilai

   Ketika sebuah elemen baru ditambahkan ke Hash Table, fungsi hash digunakan untuk menentukan indeks tempat elemen tersebut akan disimpan dalam array. Ini memungkinkan akses cepat ke elemen berdasarkan kunci.

4. Penanganan Bentrokan

   Beberapa metode yang umum digunakan adalah chaining (menggunakan linked list untuk menyimpan elemen dengan nilai hash yang sama) dan linear probing (mencari slot kosong berikutnya dalam array jika terjadi bentrokan).

5. Operasi Utama

   Operasi utama yang digunakan dalam Hash Table adalah pencarian (untuk mencari elemen berdasarkan kunci), penambahan (untuk menambahkan elemen baru), dan penghapusan (untuk menghapus elemen). Fungsi hash digunakan dalam operasi ini untuk menentukan indeks elemen yang akan diakses atau dimodifikasi.

6. Efisiensi

   Efisiensi Hash Table tergantung pada efisiensi fungsi hash yang digunakan. Fungsi hash yang baik harus menghasilkan distribusi nilai hash yang merata untuk menghindari bentrokan yang berlebihan.

Operasi dalam Struktur Data Hash Table :

1. Pencarian (Search): Digunakan untuk mencari elemen/data dalam Hash Table berdasarkan kunci atau indeksnya. Pencarian dilakukan dengan menggunakan fungsi hash untuk menghasilkan indeks elemen yang dicari.
   
2. Penyisipan (Insertion): Operasi ini digunakan untuk menyisipkan elemen/data baru ke dalam Hash Table. Elemen baru akan ditempatkan pada indeks yang dihasilkan oleh fungsi hash.

3. Penghapusan (Deletion): Digunakan untuk menghapus elemen/data dari Hash Table berdasarkan kunci atau indeksnya. Elemen yang dihapus akan dihapus dari indeks yang dihasilkan oleh fungsi hash.

4. Update: Operasi ini digunakan untuk mengubah nilai elemen/data yang sudah ada dalam Hash Table. Nilai elemen dapat diubah berdasarkan kunci atau indeksnya.

5. Collision Handling: Collision terjadi ketika dua atau lebih elemen memiliki indeks yang sama setelah melalui fungsi hash. Operasi ini digunakan untuk menangani collision dan memastikan bahwa elemen-elemen dengan indeks yang sama dapat disimpan dan diakses dengan benar.

6. Resize: Operasi ini digunakan untuk mengubah ukuran Hash Table jika jumlah elemen/data yang disimpan melebihi kapasitas yang ditentukan. Resize dilakukan untuk menjaga efisiensi dan kinerja Hash Table.

7. Iterasi: Operasi yang digunakan untuk mengakses dan memproses semua elemen/data yang ada dalam Hash Table secara berurutan. [2]
   
## Guided 

### 1. Guided I

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value),
next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
            cout << current->key << ": " << current->value << endl;
            current = current->next;
            }
        }
    }
};  

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();
    
    return 0;
}
```

#### Output :
![Screenshot 2024-04-17 001416](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/aeb80510-bbbe-455e-9081-d254cd7b49cc)

Program di atas merupakan implementasi dari struktur data hash table menggunakan teknik hashing sederhana dengan metode pembagian. Hash table tersebut memungkinkan operasi-operasi dasar seperti penyisipan (insertion), pencarian (searching), penghapusan (deletion), dan penelusuran (traversal). 
Setiap elemen dalam hash table direpresentasikan sebagai simpul (Node) yang terdiri dari kunci (key) dan nilai (value).

### 2. Guided II

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
    return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name) {
    int hash_val = hashFunc(name);
    for (auto node : table[hash_val]) {
        if (node->name == name) {
            return node->phone_number;
        }
    }
    return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
                for (auto pair : table[i]) {
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
HashMap employee_map;

employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");

cout << "Nomer Hp Mistah : "
<<employee_map.searchByName("Mistah") << endl;
cout << "Phone Hp Pastah : "
<<employee_map.searchByName("Pastah") << endl;

employee_map.remove("Mistah");

cout << "Nomer Hp Mistah setelah dihapus : "
<<employee_map.searchByName("Mistah") << endl << endl;

cout << "Hash Table : " << endl;

employee_map.print();

return 0;
}
```

#### Output :
![Screenshot 2024-04-17 001806](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/7a611b95-2390-4a44-ac2b-14ddc844fc39)

Program di atas merupakan implementasi dari struktur data hash map menggunakan chaining untuk menangani tabrakan (collision). Hash map tersebut digunakan untuk menyimpan informasi nama dan nomor telepon karyawan. Setiap karyawan direpresentasikan oleh sebuah simpul (node) yang terdiri dari nama dan nomor telepon. 
Program menyediakan operasi-operasi dasar seperti penyisipan (insertion), pencarian (searching), dan penghapusan (removal) berdasarkan nama karyawan.

## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
### a. Setiap mahasiswa memiliki NIM dan nilai.
### b. Program memiliki tampilan pilihan menu berisi poin C.
### c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
//Ben Waiz Pintus W
//2311102169

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    string nim;
    string nama; // Menambahkan variabel nama
    int nilai;
};

// Class HashTable untuk menyimpan data mahasiswa
class HashTable {
private:
    unordered_map<string, Mahasiswa> data;

public:
    // Fungsi untuk menambahkan data mahasiswa
    void tambahData(const Mahasiswa& mhs) {
        data[mhs.nim] = mhs;
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void hapusData(const string& nim) {
        data.erase(nim);
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    Mahasiswa* cariByNIM(const string& nim) {
        if (data.find(nim) != data.end()) {
            return &data[nim];
        }
        return nullptr;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
    vector<Mahasiswa> cariByNilai() {
        vector<Mahasiswa> result;
        for (auto& pair : data) {
            if (pair.second.nilai >= 80 && pair.second.nilai <= 90) {
                result.push_back(pair.second);
            }
        }
        return result;
    }
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "-=-=-=-=-=Menu-=-=-=-=-=-=-\n";
    cout << "1. Tambah data mahasiswa\n";
    cout << "2. Hapus data mahasiswa\n";
    cout << "3. Cari data mahasiswa berdasarkan NIM\n";
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80 - 90)\n";
    cout << "5. Keluar\n";
    cout << "Pilih : ";
}

int main() {
    HashTable hashTable;
    int pilihan;
    string nim;
    string nama; // Menambahkan variabel nama
    int nilai;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Mahasiswa mhs;
                cout << "Masukkan NIM : ";
                cin >> mhs.nim;
                cout << "Masukkan nama : ";
                cin.ignore(); // Membersihkan buffer sebelum membaca string
                getline(cin, mhs.nama); // Menggunakan getline untuk membaca nama dengan spasi
                cout << "Masukkan nilai : ";
                cin >> mhs.nilai;
                hashTable.tambahData(mhs);
                break;
            }
            case 2: {
                cout << "Masukkan NIM mahasiswa yang akan dihapus : ";
                cin >> nim;
                hashTable.hapusData(nim);
                break;
            }
            case 3: {
                cout << "Masukkan NIM mahasiswa yang akan dicari : ";
                cin >> nim;
                Mahasiswa* mhs = hashTable.cariByNIM(nim);
                if (mhs != nullptr) {
                    cout << "NIM : " << mhs->nim << ", Nama : " << mhs->nama << ", Nilai : " << mhs->nilai << endl;
                } else {
                    cout << "Mahasiswa dengan NIM tersebut tidak ditemukan!\n";
                }
                break;
            }
            case 4: {
                vector<Mahasiswa> result = hashTable.cariByNilai();
                if (result.empty()) {
                    cout << "Tidak ada mahasiswa dengan nilai di rentang (80 - 90)!\n";
                } else {
                    cout << "Mahasiswa dengan nilai di rentang (80 - 90) :\n";
                    for (const Mahasiswa& mhs : result) {
                        cout << "NIM : " << mhs.nim << ", Nama : " << mhs.nama << ", Nilai : " << mhs.nilai << endl;
                    }
                }
                break;
            }
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali!\n";
        }

    } while (pilihan != 5);

    return 0;
}
```

#### Output:
a. tampilan awal
![image](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/8ec7f67e-7076-4caa-ab66-b7cb732642e8)

b. menu tambah data
![Screenshot 2024-04-17 003646](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/2f39fbb3-b187-4eca-b7f6-3fb7df5ddffc)

c. menu cari data berdasarkan NIM
![Screenshot 2024-04-17 003851](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/f8cdf21e-95a3-42b3-8ec7-503ae1a58e9a)

d. menu cari data berdasarkan nilai
![Screenshot 2024-04-17 004039](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/f0386579-40f5-4b25-99a6-881e9fea1444)

e. menu hapus data
![Screenshot 2024-04-17 004245](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/d9645861-dfdd-40e5-96ef-fbfb6a8428ed)

Program ini memungkinkan pengguna untuk menambahkan, menghapus, mencari data mahasiswa berdasarkan NIM, serta mencari data mahasiswa yang memiliki nilai di rentang tertentu. Selain itu, program juga menyediakan menu interaktif untuk memudahkan pengguna dalam melakukan operasi-operasi tersebut. 
Setiap data mahasiswa disimpan dalam sebuah struktur data Mahasiswa yang terdiri dari NIM, nama, dan nilai. Pengguna dapat memilih operasi yang diinginkan dari menu yang disediakan hingga keluar dari program.

## Kesimpulan
Keuntungan utama dari hash table dibandingkan struktur data lainnya adalah efisiensi dan kecepatan. Waktu yang dibutuhkan untuk mengakses sebuah elemen cukup cepat sehingga bisa lebih diandalkan. Jadi, tidak perlu memakan waktu atau usaha besar untuk menyimpan dan mencari data yang diperlukan.

## Referensi
[1] Algoritma, "Pengertian Hash Table dan Cara Penggunaannya", 2022. https://algorit.ma/blog/hash-table-adalah-2022/

[2] Annisa, "Struktur Data Hash Table: Pengertian, Cara Kerja dan Operasi Hash Table",fikti.umsu, 2023. https://fikti.umsu.ac.id/struktur-data-hash-table-pengertian-cara-kerja-dan-operasi-hash-table/
