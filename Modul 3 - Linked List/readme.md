# <h1 align="center">Laporan Praktikum Modul 3 - Linked List</h1>
<p align="center">Ben Waiz Pintus W - 2311102169</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

Linked List adalah salah satu struktur data penting dalam pemrograman yang digunakan untuk menyimpan dan mengelola data secara dinamis. 
Struktur data ini memungkinkan kita untuk dengan mudah membuat tempat baru untuk menyimpan data kapan saja dibutuhkan.
Dalam Linked List, data disimpan dalam bentuk simpul atau node yang saling terhubung satu sama lain dengan menggunakan referensi atau alamat dari simpul selanjutnya dalam urutan.
Setiap simpul berisi dua hal penting: data yang ingin kita simpan dan alamat referensi ke simpul berikutnya dalam urutan.
Dengan begitu, setiap simpul dapat menyimpan data dan mengetahui alamat simpul selanjutnya.

Jenis-Jenis Liked List :

1. Single Linked List, setiap simpul memiliki dua bagian: data yang ingin disimpan dan referensi ke simpul berikutnya. Simpul terakhir menunjuk ke null sebagai penanda akhir Linked List.
   Keuntungan Single Linked List adalah struktur datanya yang ringan karena hanya memerlukan satu referensi untuk setiap simpul. Namun, untuk mencari elemen tertentu, kita harus melintasi seluruh Linked List dari awal hingga elemen yang diinginkan.

2. Double Linked List lebih kompleks daripada Single Linked List. Setiap simpul memiliki tiga bagian: data, referensi ke simpul berikutnya, dan referensi ke simpul sebelumnya.
   Keuntungan Double Linked List adalah kemampuan untuk melintasi Linked List maju (dari depan ke belakang) dan mundur (dari belakang ke depan) dengan mudah. Namun, kelemahannya adalah memerlukan lebih banyak ruang memori karena setiap simpul harus menyimpan dua referensi.

Istilah Dalam Linked List :
1. Node : Node sendiri memiliki nama lain yaitu simpul, penggunaan istilah node ditujukan untuk mewakili satuan data di dalam linked list.
2. Pointer : Variabel pointer adalah sebuah variabel yang bisa menyimpan data berupa alamat.
3. Head : Head adalah sebuah istilah yang diberikan kepada simpul atau node yang berada di paling depan.
4. Tail : tail adalah sebuah istilah yang diberikan kepada simpul atau node yang berada di paling belakang.
   
## Guided 

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
    bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    baru->next = head;
    head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
    cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
    // tranversing
        bantu = head;
        int nomor = 1;
    while( nomor < posisi - 1 ){
        bantu = bantu->next;
        nomor++;
    }
    baru->next = bantu->next;
    bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
    delete hapus;
    }
        else{
        head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){

        if( nomor == posisi-1 ){
            bantu2 = bantu;
        }
        if( nomor == posisi ){
            hapus = bantu;
        }
        bantu = bantu->next;
        nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;

            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
        bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){

        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
init();
insertDepan(3);tampil();
insertBelakang(5);
tampil();
insertDepan(2);
tampil();
insertDepan(1);
tampil();
hapusDepan();
tampil();
hapusBelakang();
tampil();
insertTengah(7,2);
tampil();
hapusTengah(2);
tampil();
ubahDepan(1);
tampil();
ubahBelakang(8);
tampil();
ubahTengah(11, 2);
tampil();
return 0;
}
```

#### Output :
<img width="631" alt="Screenshot 2024-03-26 171052" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/e0427b7c-264d-4609-91b7-c23bb23a91e2">

Program ini menyediakan sejumlah fungsi dasar untuk mengelola linked list, termasuk penambahan elemen di depan, di belakang, atau di tengah, penghapusan elemen di depan, di belakang, atau di tengah, serta pengubahan nilai elemen di depan, di belakang, atau di tengah. 
Selain itu, program juga memiliki fungsi untuk menghitung jumlah elemen dalam linked list dan untuk menampilkan isi linked list ke layar.

### 2. Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }
void pop() {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
}
bool update(int oldData, int newData) {
    Node* current = head;while (current != nullptr) {
        if (current->data == oldData) {
            current->data = newData;
            return true;
        }
        current = current->next;
    }
    return false;
}
void deleteAll() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main() {
    DoublyLinkedList list;
    while (true) {
    cout << "1. Add data" << endl;
    cout << "2. Delete data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Clear data" << endl;
    cout << "5. Display data" << endl;
    cout << "6. Exit" << endl;int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2: {
            list.pop();
            break;
        }
        case 3: {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData, newData);
            if (!updated) {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4: {
            list.deleteAll();
            break;
        }
        case 5: {
            list.display();
            break;
        }
        case 6: {
            return 0;
        }
        default: {
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
return 0;
}
```

#### Output :
<img width="639" alt="Screenshot 2024-03-26 172111" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/a34582cb-ab96-426d-82aa-3977b578935c">

 Di dalam fungsi main(), program menyediakan menu interaktif yang memungkinkan pengguna untuk memilih operasi yang ingin dilakukan pada Doubly Linked List, seperti menambahkan, menghapus, mengubah, menghapus semua elemen, dan menampilkan isi linked list.

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
####    a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
####    b. Hapus data Akechi
####    c. Tambahkan data berikut diantara John dan Jane : Futaba 18
####    d. Tambahkan data berikut diawal : Igor 20
####    e. Ubah data Michael menjadi : Reyn 18
####    f. Tampilkan seluruh data

```C++
//BEN WAIZ PINTUS W
//2311102169

#include <iostream>
#include <string>
using namespace std;

// Struktur Node
struct Node {
    string name;
    int usia;
    Node* next;
};

// Kelas Linked List
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Fungsi untuk menyisipkan data di akhir daftar
    void sisipkan(string name, int usia) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Fungsi untuk menampilkan semua data dalam daftar
    void tampilkan() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " " << temp->usia << endl;
            temp = temp->next;
        }
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void hapusNode(string name) {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Jika node head sendiri menyimpan nama yang akan dihapus
        if (temp != nullptr && temp->name == name) {
            head = temp->next;
            delete temp;
            return;
        }

        // Mencari node yang akan dihapus
        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        // Jika nama tidak ada dalam daftar
        if (temp == nullptr) {
            return;
        }

        // Memutuskan hubungan node dari linked list
        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk menyisipkan node setelah node tertentu
    void sisipkanSetelah(string nameBefore, string name, int usia) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->usia = usia;

        Node* temp = head;
        while (temp != nullptr && temp->name != nameBefore) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << nameBefore << " tidak ditemukan dalam daftar." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Fungsi untuk menyisipkan node di awal daftar
    void sisipkanDiAwal(string name, int usia) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->usia = usia;

        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk mengubah data berdasarkan nama
    void ubah(string name, string newName, int usiaBaru) {
        Node* temp = head;
        while (temp != nullptr && temp->name != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << name << " tidak ditemukan dalam daftar." << endl;
            return;
        }

        temp->name = newName;
        temp->usia = usiaBaru;
    }
};

int main() {
    LinkedList daftar;

    // Memasukkan data
    daftar.sisipkan("Andika", 17);
    daftar.sisipkan("John", 19);
    daftar.sisipkan("Jane", 20);
    daftar.sisipkan("Michael", 18);
    daftar.sisipkan("Yusuke", 19);
    daftar.sisipkan("Akechi", 20);
    daftar.sisipkan("Hoshino", 18);
    daftar.sisipkan("Karin", 18);

    char pilihan;
    string name, newName;
    int usia, usiaBaru;

    do {
        cout << "Menu:" << endl;
        cout << "a. Tampilkan semua data" << endl;
        cout << "b. Hapus data Akechi" << endl;
        cout << "c. Tambahkan data di antara John dan Jane" << endl;
        cout << "d. Tambahkan data di awal" << endl;
        cout << "e. Ubah data Michael" << endl;
        cout << "f. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 'a':
                break;
            case 'b':
                daftar.hapusNode("Akechi");
                cout << "Data Akechi telah dihapus." << endl;
                break;
            case 'c':
                cout << "Masukkan nama dan usia yang ingin ditambahkan: ";
                cin >> name >> usia;
                daftar.sisipkanSetelah("John", name, usia);
                break;
            case 'd':
                cout << "Masukkan nama dan usia yang ingin ditambahkan di awal: ";
                cin >> name >> usia;
                daftar.sisipkanDiAwal(name, usia);
                break;
            case 'e':
                cout << "Masukkan nama dan usia baru untuk Michael: ";
                cin >> newName >> usiaBaru;
                daftar.ubah("Michael", newName, usiaBaru);
                break;
            case 'f':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        // Menampilkan data setelah setiap operasi
        cout << "Data mahasiswa:" << endl;
        daftar.tampilkan();
        cout << endl;

    } while (pilihan != 'f');

    return 0;
}
```

#### Output:
a. <img width="636" alt="Screenshot 2024-03-26 174224" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/600c963f-c7c4-45e3-8f17-3001b8bb776d">

b. <img width="334" alt="Screenshot 2024-03-26 174503" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/e4fd9a4c-f180-40e2-86d3-f53b5da4b908">

c. <img width="347" alt="Screenshot 2024-03-26 174641" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/8da52886-6d4f-4c9f-9018-700329a06f1b">

d. <img width="376" alt="Screenshot 2024-03-26 174840" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/08b54f1b-d2c4-48c4-ab2f-b4bb529d71cc">

e. <img width="294" alt="Screenshot 2024-03-26 174950" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/fc6c234f-7538-470e-8a18-89a2ef5d371d">

f. <img width="246" alt="Screenshot 2024-03-26 175055" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/99230542-3b5e-4156-97f7-526133841654">


Program ini memanfaatkan kelas LinkedList untuk mengimplementasikan operasi-operasi dasar seperti menyisipkan data, menghapus data, menyisipkan data di awal atau setelah node tertentu, serta mengubah data berdasarkan nama.

### 2. Soal mengenai Double Linked List Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
### Nama Produk Harga
### Originote 60.000
### Somethinc 150.000
### Skintific 100.000
### Wardah 50.000
### Hanasui 30.000

### Case:
### 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
### 2. Hapus produk wardah
### 3. Update produk Hanasui menjadi Cleora dengan harga 55.000
### 4. Tampilkan menu seperti dibawah ini

### Toko Skincare Purwokerto
### 1. Tambah Data
### 2. Hapus Data
### 3. Update Data
### 4. Tambah Data Urutan Tertentu
### 5. Hapus Data Urutan Tertentu
### 6. Hapus Seluruh Data
### 7. Tampilkan Data
### 8. Exit
### Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

### Nama Produk Harga
### Originote 60.000
### Somethinc 150.000
### Azarine 65.000
### Skintific 100.000
### Cleora 55.000

```C++
//BEN WAIZ PINTUS W
//2311102169

#include <iostream>
using namespace std;

struct Node {
    string namaProduk;
    double price;
    Node* prev;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void tambahData(string name, double price) {
        Node* newNode = new Node;
        newNode->namaProduk = name;
        newNode->price = price;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void hapusData(string name) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == name) {
                if (current == head && current == tail) {
                    head = tail = NULL;
                } else if (current == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void updateData(string name, string newName, double newPrice) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == name) {
                current->namaProduk = newName;
                current->price = newPrice;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void tambahDataUrutanTertentu(string name, double price, string setelah) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == setelah) {
                Node* newNode = new Node;
                newNode->namaProduk = name;
                newNode->price = price;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Produk setelahnya tidak ditemukan!" << endl;
    }

    void hapusDataUrutanTertentu(string name) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == name) {
                if (current == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void hapusSeluruhData() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = NULL;
    }

    void tampilkanData() {
        Node* current = head;
        cout << "----------------------" << endl;
        cout << "Nama Produk  ||\t Harga " << endl;
        cout << "----------------------" << endl;
        while (current != NULL) {
            cout << current->namaProduk << "\t" << current->price << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList daftarProduk;
    daftarProduk.tambahData("Originote", 60000);
    daftarProduk.tambahData("Somethinc", 150000);
    daftarProduk.tambahData("Skintific", 100000);
    daftarProduk.tambahData("Wardah", 50000);
    daftarProduk.tambahData("Hanasui", 30000);

    int pilihan;
    string name, newName, setelah;
    double price, newPrice;

    do {
        cout << "--------------------------------" << endl;
        cout << " || Toko Skincare Purwokerto || " << endl;
        cout << "--------------------------------" << endl;

        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama Produk: ";
                cin >> name;
                cout << "Harga: ";
                cin >> price;
                daftarProduk.tambahData(name, price);
                daftarProduk.tampilkanData();
                break;
            case 2:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> name;
                daftarProduk.hapusData(name);
                daftarProduk.tampilkanData();
                break;
            case 3:
                cout << "Nama Produk yang akan diupdate: ";
                cin >> name;
                cout << "Nama Baru: ";
                cin >> newName;
                cout << "Harga Baru: ";
                cin >> newPrice;
                daftarProduk.updateData(name, newName, newPrice);
                daftarProduk.tampilkanData();
                break;
            case 4:
                cout << "Nama Produk: ";
                cin >> name;
                cout << "Harga: ";
                cin >> price;
                cout << "Setelah Produk: ";
                cin >> setelah;
                daftarProduk.tambahDataUrutanTertentu(name, price, setelah);
                daftarProduk.tampilkanData();
                break;
            case 5:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> name;
                daftarProduk.hapusDataUrutanTertentu(name);
                daftarProduk.tampilkanData();
                break;
            case 6:
                daftarProduk.hapusSeluruhData();
                cout << "Seluruh data telah dihapus." << endl;
                break;
            case 7:
                daftarProduk.tampilkanData();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);

    return 0;
}
```
#### Output:

##### Tampilan Awal:
<img width="635" alt="Screenshot 2024-03-26 185853" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/5b2846a3-48c3-4639-a39c-0a0613d92c35">

##### 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific:
<img width="225" alt="Screenshot 2024-03-26 190231" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/0d459ef1-9e41-4b94-a59f-59dba6fbe2e6">

##### 2. Hapus produk wardah:
<img width="248" alt="Screenshot 2024-03-26 190400" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/786bfb0b-07c2-467f-a3fd-8b550aa5b5ab">

##### 3, Update produk Hanasui menjadi Cleora dengan harga 55.000
<img width="255" alt="Screenshot 2024-03-26 190637" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/57a8a388-b1f4-48c8-8464-75b84ce80c18">

##### 4. Tampilan Akhir Menu
<img width="216" alt="Screenshot 2024-03-26 190741" src="https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/18131b0a-b51e-46fb-b134-14d382db2c02">


Program di atas adalah sebuah aplikasi manajemen produk skincare yang menggunakan struktur data linked list untuk menyimpan data produk. Program ini memungkinkan pengguna untuk menambah, menghapus, mengubah, dan menampilkan data produk, serta menyisipkan atau menghapus data pada posisi tertentu dalam daftar. 
Setiap data produk disimpan dalam bentuk node yang terdiri dari nama produk dan harganya


## Kesimpulan
Jadi Linked list atau senarai berantai adalah struktur data yang menerapkan dynamic allocation. Program hanya akan meminta ruang dari memori jika ada data yang memang membutuhkan ruang tersebut.
Di saat sebuah data sudah memiliki tempat, selanjutnya menghubungkan data sebelumnya dengan data yang baru datang. Cara menghubungkannya sederhana, cukup mengaitkan alamat dari data yang baru datang dengan data di sebelahnya.

## Referensi
[1] Annisa medina Sari. "Pengertian Linked List: Struktur Data dalam Pemrograman" fikti.umsu, 2023. 

[2] hans. "Tentang Linked List" antekteknologi, 2023.
