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