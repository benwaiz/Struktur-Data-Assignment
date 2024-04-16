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
