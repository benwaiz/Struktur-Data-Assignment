# <h1 align="center">Laporan Praktikum Modul 7 - Queue</h1>
<p align="center">Ben Waiz Pintus W - 2311102169</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Pengertian
 Queue atau dalam bahasa Indonesia yang berarti antrean adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. 
 Prinsip dasar dari struktur data ini adalah “First In, First Out” (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.[1]
 
 ### Prinsip FIFO pada Queue
 Caranya bekerja adalah seperti jejeran orang yang sedang menunggu antrean di supermarket di mana orang pertama yang datang adalah yang pertama dilayani (First In, First Out). 
 Pada struktur data ini, urutan pertama (data yang akan dikeluarkan) disebut Front atau Head. Sebaliknya, data pada urutan terakhir (data yang baru saja ditambahkan) disebut Back, Rear, atau Tail. 
 Proses untuk menambahkan data pada antrean disebut dengan Enqueue, sedangkan proses untuk menghapus data dari antrean disebut dengan Dequeue.[1]

 ### Jenis - Jenis Queue
 1. Simple Queue
 2. Circular Queue
 3. Priority Queue
 4. Double-Ended Queue (Dequeue). [2]

### Operasi - Operasi Dasar pada Queue
1. Enqueue: Menambahkan elemen ke akhir antrian
2. Dequeue: Menghapus elemen dari depan antrian
3. IsEmpty: Memeriksa apakah antrian kosong
4. IsFull: Memeriksa apakah antrian sudah penuh
5. Peek: Mendapatkan nilai bagian depan antrian tanpa menghapusnya
6. Initialize: Membuat antrian baru tanpa elemen data (kosong). [2]
   
## Guided 

### 1. Guided I

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
    return true; // =1
    } else {
    return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
    return true;
    } else {
    return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

#### Output :
![Screenshot 2024-05-16 102400](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/965c410a-096a-4a52-a399-0426a14bee73)


Program ini memungkinkan pengguna untuk menambahkan (enqueue) dan mengurangi (dequeue) elemen dari antrian, serta melihat jumlah total elemen dalam antrian dan mengosongkan antrian. 
Program menggunakan array sebagai wadah untuk menyimpan elemen-elemen antrian, dengan batasan maksimal antrian yang telah ditetapkan sebelumnya. Selain itu, program juga memiliki fungsi untuk memeriksa apakah antrian penuh atau kosong.


## Unguided 

### 1. Unguided I

Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
//2311102169
//Ben Waiz Pintus W
#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = nullptr; // Pointer depan
Node* back = nullptr; // Pointer belakang

void enqueueAntrian(string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (front == nullptr) { // Jika antrian kosong
        front = newNode;
        back = newNode;
    } else { // Jika antrian tidak kosong
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (front == nullptr) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    Node* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". " << current->data << endl;
        current = current->next;
        i++;
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

#### Output:
![Screenshot 2024-05-16 102912](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/d945c5fb-5c46-471f-b7d2-a28d9d6add16)

Dalam program ini, setiap elemen dalam antrian direpresentasikan sebagai node dalam linked list. 
Terdapat empat fungsi utama yaitu enqueueAntrian untuk menambahkan elemen ke dalam antrian, dequeueAntrian untuk menghapus elemen dari depan antrian, countQueue untuk menghitung jumlah total elemen dalam antrian, dan clearQueue untuk mengosongkan seluruh antrian. 
Program juga memiliki fungsi viewQueue untuk menampilkan isi dari antrian.

### 1. Unguided II

Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
//2311102169
//Ben Waiz Pintus W
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

Mahasiswa* front = nullptr; // Pointer depan
Mahasiswa* back = nullptr; // Pointer belakang

void enqueueAntrian(string nama, string nim) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;
    if (front == nullptr) { // Jika antrian kosong
        front = newNode;
        back = newNode;
    } else { // Jika antrian tidak kosong
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (front == nullptr) {
        cout << "Antrian kosong" << endl;
    } else {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Mahasiswa* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (front != nullptr) {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

void viewQueue() {
    cout << "Data antrian mahasiswa:" << endl;
    Mahasiswa* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
        i++;
    }
}

int main() {
    enqueueAntrian("Andi", "2311102169");
    enqueueAntrian("Maya", "123456789");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

#### Output:
![Screenshot 2024-05-16 104546](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/1001f5d4-17e6-41d5-89d0-75e84bf526af)

Setiap elemen dalam antrian direpresentasikan sebagai node yang memiliki dua atribut: nama dan NIM mahasiswa. 
Program ini menyediakan fungsi-fungsi seperti enqueueAntrian untuk menambahkan elemen ke dalam antrian, dequeueAntrian untuk menghapus elemen dari depan antrian, countQueue untuk menghitung jumlah total elemen dalam antrian, dan clearQueue untuk mengosongkan seluruh antrian. 
Selain itu, terdapat fungsi viewQueue untuk menampilkan isi dari antrian, yang dalam hal ini adalah nama dan NIM mahasiswa.

## Kesimpulan
Pemahaman tentang struktur data queue menjadi kunci untuk mengoptimalkan efisiensi dan kinerja aplikasi. adalah struktur data yang mengatur elemen-elemen data dengan prinsip “First In, First Out” (FIFO), serupa dengan antrean di kehidupan sehari-hari.
Queue mempunyai beberapa kelebihan, salah satunya yaitu Operasi seperti penyisipan dan penghapusan dapat dilakukan dengan mudah karena mengikuti aturan masuk pertama keluar pertama. 
Namun, Queue juga mempunyai kekurangan, salah satunya Operasi seperti penyisipan dan penghapusan elemen dari tengah cenderung banyak memakan waktu.

## Referensi
[1] Rizki Maulana, "Struktur Data Queue: Pengertian, Fungsi, dan Jenisnya", 2023. https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/

[2] Trivusi, "Struktur Data Queue: Pengertian, Jenis, dan Kegunaannya", 2023. https://www.trivusi.web.id/2022/07/struktur-data-queue.html
