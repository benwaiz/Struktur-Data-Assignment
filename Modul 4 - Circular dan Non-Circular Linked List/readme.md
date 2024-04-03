# <h1 align="center">Laporan Praktikum Modul 4 - Circular dan Non-Circular Linked List</h1>
<p align="center">Ben Waiz Pintus W - 2311102169</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Linked List Circular

Circular Linked List adalah tipe Linked List yang membentuk lingkaran, dengan simpul terakhir terhubung kembali ke simpul pertama. Tidak ada simpul yang menunjuk ke null seperti pada Single Linked List dan Double Linked List.[1]

### Linked List Non Circular

Simpul pertama dari linked list disebut sebagai head atau simpul kepala. Apabila linked list berisi elemen kosong, maka nilai pointer dari head menunjuk ke NULL. Begitu juga untuk pointer berikutnya dari simpul terakhir atau simpul ekor akan menunjuk ke NULL.[2]

## Guided 

### 1. Linked List Non Circular

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR

// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
    int nomor = 1;
    while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
        while (bantu->next != tail)
        {
            bantu = bantu->next;
        }
        tail = bantu;
        tail->next = NULL;
        delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
    {
    if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan ditengah!" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
        while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == 0)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan(3);
    tampil();
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
    insertTengah(7, 2);
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
![Screenshot 2024-04-03 151539](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/4f9e0b12-b276-4a20-90c2-1a2a758820db)

Program ini memiliki fungsi-fungsi dasar seperti menambahkan node di depan, di belakang, dan di tengah linked list, menghapus node dari depan, belakang, dan tengah, mengubah nilai node di depan, belakang, dan tengah, serta menghitung jumlah node dan membersihkan seluruh isi linked list. 
Setiap node memiliki satu data integer dan pointer menuju node berikutnya.

### 2. Linked List Circular

```C++
#include <iostream>

using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
    return 1; // true
    else
    return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {

            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
init();
insertDepan("Ayam");
tampil();
insertDepan("Bebek");
tampil();
insertBelakang("Cicak");
tampil();
insertBelakang("Domba");
tampil();
hapusBelakang();
tampil();
hapusDepan();
tampil();
insertTengah("Sapi", 2);
tampil();
hapusTengah(2);
tampil();

return 0;
}
```

#### Output :
![Screenshot 2024-04-03 152107](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/8ab54fbd-1702-4fb8-a58c-0fe0313bde47)

Program ini memiliki fungsi-fungsi dasar seperti menambahkan node di depan, di belakang, dan di tengah linked list, menghapus node dari depan, belakang, dan tengah, menghitung jumlah node, membersihkan seluruh isi linked list, dan menampilkan isi dari linked list. 
Setiap node memiliki satu data string dan pointer menuju node berikutnya, dengan pointer terakhir menunjuk kembali ke head untuk membentuk lingkaran.

## Unguided 

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:

```C++
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
```

#### Output:

#### Tampilan Awal
![Screenshot 2024-04-03 152745](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/9f835794-69c5-47a9-872e-5b89f7ced924)

#### Tampilan Operasi Tambah
![Screenshot 2024-04-03 160418](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/4a0f7467-6bf9-4506-b19a-5b8656f2c03d)
![Screenshot 2024-04-03 160508](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/e51b7418-f069-4554-b180-a93f992118bb)

#### Tampilan Operasi Hapus
![Screenshot 2024-04-03 160655](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/2b0c0334-abe3-42bb-a49e-c440e9c10740)
![Screenshot 2024-04-03 162208](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/af540686-0590-4bcb-85a2-8bac8e6baae3)

#### Tampilan Operasi Ubah
![Screenshot 2024-04-03 162418](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/94d44fc5-f7ff-4580-b079-fb39e8d413e2)
![Screenshot 2024-04-03 162524](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/03daf0ad-feda-4e8b-abfa-f9f4cc4338a1)

#### Tampilan Operasi Tampil Data
![Screenshot 2024-04-03 162615](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/c4734973-8424-4a93-816b-c230804e5fbb)

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![Screenshot 2024-04-03 163459](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/b17d6f27-03da-4eb9-9683-24e1c2281816)

### 3. Lakukan perintah berikut:

#### a) Tambah data Wati 2330004 diantara Farrel dan Denis
![Screenshot 2024-04-03 163659](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/3da9f15e-847c-4622-9d7f-2315894da10d)

#### b) Hapus data Denis
![Screenshot 2024-04-03 163806](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/3217945f-316a-4985-b064-ee7a5e803aae)

#### c) Tambahkan data berikut di awal: Owi 2330000
![Screenshot 2024-04-03 163909](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/434a4d60-573f-4c99-9e79-e8c4ad6f361e)

#### d) Tambahkan data berikut di akhir: David 2330010
![Screenshot 2024-04-03 164037](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/facd001c-6c77-43b3-931b-3d839d0dd31b)

#### e) Ubah data Udin menjadi data berikut: Idin 23300045
![Screenshot 2024-04-03 164207](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/1953491b-3f73-4094-936f-5169226d99bc)

#### f) Ubah data terkahir menjadi berikut: Lucy 23300101
![Screenshot 2024-04-03 164323](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/5826e707-60f4-4f36-a9a5-2d5b460094cd)

#### g) Hapus data awal
![Screenshot 2024-04-03 164409](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/bc4f896e-1bd3-404c-a49b-877e70b377e4)

#### h) Ubah data awal menjadi berikut: Bagas 2330002
![Screenshot 2024-04-03 164528](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/27fb8e01-985c-4191-9785-0eb368164b4e)

#### i) Hapus data akhir
![Screenshot 2024-04-03 164615](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/5d1c71ce-6c95-4655-a712-d87714d84658)

#### j) Tampilkan seluruh data
![Screenshot 2024-04-03 164724](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/a8cec40c-592d-4a15-882b-cab3f40926e2)

Linked list sirkular adalah struktur data linear di mana setiap elemen terhubung dengan elemen berikutnya dan elemen terakhir terhubung kembali ke elemen pertama. Program ini memungkinkan pengguna untuk menambah, mengubah, dan menghapus data mahasiswa dari linked list, baik dari depan, belakang, maupun posisi tengahnya. Pengguna dapat memilih operasi yang ingin dilakukan melalui menu interaktif yang ditampilkan pada layar. Program ini juga dapat menampilkan seluruh data mahasiswa yang tersimpan dalam linked list.

## Kesimpulan
Dalam struktur data linked list, terdapat dua jenis utama: linked list linear dan linked list sirkular. Linked list linear adalah struktur data di mana setiap elemen terhubung dengan elemen berikutnya dalam satu arah, dengan elemen terakhir menunjuk ke null. Sementara itu, linked list sirkular adalah varian di mana elemen terakhir terhubung kembali ke elemen pertama, membentuk lingkaran. Keuntungan linked list sirkular adalah tidak ada elemen yang "membuntuti" akhir, sehingga operasi navigasi lebih mudah. Namun, perlu hati-hati dalam penanganan kasus khusus, seperti linked list kosong. Kedua jenis linked list ini memiliki kegunaan dan kompleksitas waktu operasi yang berbeda, sehingga penting untuk memilih jenis yang sesuai dengan kebutuhan aplikasi dan melakukan penanganan khusus sesuai kebutuhan.

## Referensi
[1] "Pengertian Linked List: Struktur Data dalam Pemrograman.
https://fikti.umsu.ac.id/pengertian-linked-list-struktur-data-dalam-pemrograman/

[2] "Struktur Data Linked List: Pengertian, Karakteristik, dan Jenis-jenisnya" Trivusi. 2022
https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html?m=1
