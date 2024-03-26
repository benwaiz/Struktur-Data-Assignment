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