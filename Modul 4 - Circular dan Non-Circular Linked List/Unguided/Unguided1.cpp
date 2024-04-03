//Ben Waiz Pintus W
//2311102169

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string name;
    string id;
    Mahasiswa* next;
};

class LinkedListCircular {
private:
    Mahasiswa* head;

public:
    LinkedListCircular() {
        head = nullptr;
    }

    // Menambahkan mahasiswa di depan
    void tambahDepan(string name, string id) {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->name = name;
        newMahasiswa->id = id;

        if (head == nullptr) {
            head = newMahasiswa;
            newMahasiswa->next = head;
        } else {
            Mahasiswa* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newMahasiswa->next = head;
            last->next = newMahasiswa;
            head = newMahasiswa;
        }
        cout << "Mahasiswa berhasil ditambahkan di depan!" << endl;
    }

    // Menambahkan mahasiswa di belakang
    void tambahBelakang(string name, string id) {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->name = name;
        newMahasiswa->id = id;

        if (head == nullptr) {
            head = newMahasiswa;
            newMahasiswa->next = head;
        } else {
            Mahasiswa* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newMahasiswa;
            newMahasiswa->next = head;
        }
        cout << "Mahasiswa berhasil ditambahkan di belakang!" << endl;
    }

    // Menambahkan mahasiswa di tengah
    void tambahTengah(string name, string id, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0!" << endl;
            return;
        }
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->name = name;
        newMahasiswa->id = id;

        if (head == nullptr) {
            head = newMahasiswa;
            newMahasiswa->next = head;
            cout << "Mahasiswa berhasil ditambahkan di tengah!" << endl;
            return;
        }

        Mahasiswa* temp = head;
        int count = 1;
        while (count < posisi - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count < posisi - 1) {
            cout << "Posisi terlalu besar!" << endl;
            return;
        }

        newMahasiswa->next = temp->next;
        temp->next = newMahasiswa;
        cout << "Mahasiswa berhasil ditambahkan di tengah!" << endl;
    }

    // Ubah data mahasiswa di depan
    void ubahDepan(string name, string id) {
        if (head == nullptr) {
            cout << "Linked List Kosong!" << endl;
            return;
        }
        head->name = name;
        head->id = id;
        cout << "Data mahasiswa di depan berhasil diubah!" << endl;
    }

    // Ubah data mahasiswa di belakang
    void ubahBelakang(string name, string id) {
        if (head == nullptr) {
            cout << "Linked List Kosong!" << endl;
            return;
        }
        Mahasiswa* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->name = name;
        temp->id = id;
        cout << "Data mahasiswa di belakang berhasil diubah!" << endl;
    }

    // Ubah data mahasiswa di tengah
    void ubahTengah(string name, string id, int posisi) {
        if (head == nullptr) {
            cout << "Linked List Kosong!" << endl;
            return;
        }
        Mahasiswa* temp = head;
        int count = 1;
        while (count < posisi && temp->next != head) {
            temp = temp->next;
            count++;
        }
        if (count != posisi) {
            cout << "Posisi terlalu besar!" << endl;
            return;
        }
        temp->name = name;
        temp->id = id;
        cout << "Data mahasiswa di posisi " << posisi << " berhasil diubah!" << endl;
    }

    // Hapus data mahasiswa di depan
    void hapusDepan() {
        if (head == nullptr) {
            cout << "Linked List Kosong!" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Mahasiswa* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Mahasiswa* del = head;
            head = head->next;
            temp->next = head;
            delete del;
        }
        cout << "Data mahasiswa di depan berhasil dihapus!" << endl;
    }

    // Hapus data mahasiswa di belakang
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "Linked List Kosong!" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Mahasiswa* temp = head;
            Mahasiswa* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
        cout << "Data mahasiswa di belakang berhasil dihapus!" << endl;
    }

    // Hapus data mahasiswa di tengah
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "Linked List Kosong!" << endl;
            return;
        }
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0!" << endl;
            return;
        }
        Mahasiswa* temp = head;
        Mahasiswa* prev = nullptr;
        int count = 1;
        while (count < posisi && temp->next != head) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count != posisi) {
            cout << "Posisi terlalu besar!" << endl;
            return;
        }
        if (temp == head) {
            hapusDepan();
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Data mahasiswa di posisi " << posisi << " berhasil dihapus!" << endl;
    }

    // Hapus semua data mahasiswa
    void hapusList() {
        if (head == nullptr) {
            cout << "Linked List Kosong!" << endl;
            return;
        }
        Mahasiswa* current = head;
        Mahasiswa* next = nullptr;
        while (current->next != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete current;
        head = nullptr;
        cout << "Semua data mahasiswa berhasil dihapus!" << endl;
    }

    // Menampilkan daftar mahasiswa
    void tampilkan() {
        if (head == nullptr) {
            cout << "Linked List Kosong!" << endl;
            return;
        }
        Mahasiswa* temp = head;
        do {
            cout << "Nama : " << temp->name << ", NIM : " << temp->id << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    LinkedListCircular list;
    int choice;
    string name, id;
    int posisi;

    do {
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
        cout << "\nLIST DATA DAN NIM MAHASISWA\n";
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
        cout << "Menu :\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. Tampilkan Data\n";
        cout << "0. Keluar\n";
        cout << "Pilih Operasi : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama : ";
                cin >> name;
                cout << "Masukkan NIM : ";
                cin >> id;
                list.tambahDepan(name, id);
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin >> name;
                cout << "Masukkan NIM : ";
                cin >> id;
                list.tambahBelakang(name, id);
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin >> name;
                cout << "Masukkan NIM : ";
                cin >> id;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                list.tambahTengah(name, id, posisi);
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin >> name;
                cout << "Masukkan NIM : ";
                cin >> id;
                list.ubahDepan(name, id);
                break;
            case 5:
                cout << "Masukkan Nama : ";
                cin >> name;
                cout << "Masukkan NIM : ";
                cin >> id;
                list.ubahBelakang(name, id);
                break;
            case 6:
                cout << "Masukkan Nama : ";
                cin >> name;
                cout << "Masukkan NIM : ";
                cin >> id;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                list.ubahTengah(name, id, posisi);
                break;
            case 7:
                list.hapusDepan();
                break;
            case 8:
                list.hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                list.hapusTengah(posisi);
                break;
            case 10:
                list.hapusList();
                break;
            case 11:
                list.tampilkan();
                break;
            case 0:
                cout << "Matur Suwun !!!" << endl;
                break;
            default:
                cout << "Maaf, pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
