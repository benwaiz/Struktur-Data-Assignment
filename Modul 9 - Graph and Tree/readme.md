# <h1 align="center">Laporan Praktikum Modul 9 - Graph dan Tree</h1>
<p align="center">Ben Waiz Pintus W - 2311102169</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Pengertian
Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan. 
Simpul pada graph disebut dengan verteks (V), sedangkan sisi yang menghubungkan antar verteks disebut edge (E). Pasangan (x,y) disebut sebagai edge, yang menyatakan bahwa simpul x terhubung ke simpul y. [1]

Tree merupakan salah satu bentuk struktur data tidak linear yang menggambarkan hubungan yang bersifat hirarkis (hubungan one to many) antara elemen-elemen. Tree bisa didefinisikan sebagai kumpulan simpul/node dengan satu elemen khusus yang disebut root dan node lainnya. 
Tree juga adalah suatu graph yang acyclic, simple, connected yang tidak mengandung loop. [2]
 
 ### Jenis-jenis Graph
 Graph dapat dibedakan berdasarkan arah jelajahnya dan ada tidaknya label bobot pada relasinya. Berdasarkan arah jelajahnya graph dibagi menjadi Undirected graph dan Directed graph. 
 Pada undirected graph, simpul-simpulnya terhubung dengan edge yang sifatnya dua arah. Kebalikan dari undirected graph, pada directed graph simpul-simpulnya terhubung oleh edge yang hanya bisa melakukan jelajah satu arah pada simpul yang ditunjuk. 
 
 Selain arah jelajahnya, graph dapat dibagi menjadi 2 berdasarkan ada tidaknya label bobot pada koneksinya, yaitu weighted graph dan unweighted graph. Weighted graph adalah jenis graph yang cabangnya diberi label bobot berupa bilangan numerik. 
 Berbeda dengan jenis sebelumnya, unweighted graph tidak memiliki properti bobot pada koneksinya. [1]
 
 ### Binary Tree
Binary tree adalah suatu tree dengan syarat bahwa tiap node (simpul) hanya boleh memiliki maksimal dua subtree dan kedua subtree tersebut harus terpisah. Tiap node dalam binary tree boleh memiliki paling banyak dua child (anak simpul), secara khusus anaknya  dinamakan kiri dan kanan. [3]

### Istilah dalam Binary Tree
1. Full Binary Tree, semua simpul (kecuali daun) memiliki dua anak dan tiap cabang memiliki panjang ruas yang sama.
2. Complete Binary Tree, Hampir sama dengan Full Binary Tree, semua simpul (kecuali daun) memiliki dua anak tetapi memiliki panjang ruas berbeda.
3. Similar Binary Tree, dua pohon yang memiliki struktur yang sama tetapi informasinya berbeda.
4. Equivalent binary tree, dua pohon yang memiliki struktur informasi yang sama.
5. Kewed tree, dua pohon yang semua simpulnya mempunyai satu anak atau turunan kecuali daun. [3]

## Guided 

### 1. Guided I

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph(){
    for (int baris = 0; baris <7; baris ++){
        cout <<" " << setiosflags (ios::left)<<setw (15)<< simpul [baris] << " : ";
    for (int kolom = 0; kolom<7; kolom++){
        if (busur[baris][kolom]!=0){
            cout << " " << simpul[kolom]<< "(" << busur[baris][kolom]<< ")";
        }
    }
    cout << endl;
    }
}

int main(){
    tampilGraph();
    return 0;
}
```

#### Output :
![Screenshot 2024-05-29 154412](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/ace35e80-c44d-42bf-a259-4985915e32d2)

Program di atas adalah implementasi dalam bahasa C++ yang menampilkan representasi graf berarah dan berbobot, di mana simpul (node) dan busur (edge) antara simpul-simpul tersebut ditentukan dalam dua array: simpul untuk menyimpan nama-nama kota dan busur untuk menyimpan bobot perjalanan antar kota. 
Fungsi tampilGraph mencetak setiap simpul bersama dengan simpul-simpul lain yang terhubung dengannya, serta bobot busur yang menghubungkan mereka, menggunakan perulangan for untuk iterasi melalui simpul dan busur.

### 2. Guided II

```C++
#include <iostream>

using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon

struct Pohon {
    char data;
    Pohon *left, *right, *parent; //pointer
};

//pointer global
Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
            cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!"<< endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!"<< endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
                cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
                return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
            cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    return 0;
    } else {
        if (!node) {
        return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
        return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan) {
            return heightKiri + 1;
            } else {
            return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main() {
    init();
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    characteristic();
}  
```

#### Output :
![Screenshot 2024-05-29 155052](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/a781a23d-d5bf-41ff-aa50-d1a6e97b6a03)
![Screenshot 2024-05-29 155125](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/e539eb4b-6dc3-4e3c-9818-36fce46c34d7)

Program ini memungkinkan pengguna untuk membuat pohon biner, menambahkan node kiri dan kanan, memperbarui data dalam node, mengambil data node, dan menemukan informasi lengkap tentang suatu node termasuk parent, sibling, dan child-nya. 
Selain itu, program menyediakan metode traversal seperti preOrder, inOrder, dan postOrder untuk menjelajahi pohon. Program juga dilengkapi dengan fungsi untuk menghitung ukuran dan tinggi pohon, menghapus subtree, dan menghapus seluruh pohon.

## Unguided 

### 1. Unguided I

Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
//Ben Waiz Pintus W
//2311102169

#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

// Struktur untuk merepresentasikan simpul dalam graph
struct Vertex {
    string nama_169;
    int jarak_169;
};

// Fungsi untuk membuat graph yang direpresentasikan sebagai adjacency matrix
vector<vector<int>> createGraph(vector<string>& vertices) {
    // Mendapatkan jumlah simpul dari user
    int numVertices2311102169;
    cout << "Masukkan jumlah simpul: ";
    cin >> numVertices2311102169;

    // Memasukkan nama simpul
    vertices.resize(numVertices2311102169);
    for (int i = 0; i < numVertices2311102169; i++) {
        cout << "Masukkan nama simpul " << i + 1 << ": ";
        cin >> vertices[i];
    }

    // Membangun adjacency matrix
    vector<vector<int>> adjacencyMatrix(numVertices2311102169, vector<int>(numVertices2311102169));
    for (int i = 0; i < numVertices2311102169; i++) {
        for (int j = 0; j < numVertices2311102169; j++) {
            if (i == j) {
                // Bobot untuk simpul yang sama selalu 0
                adjacencyMatrix[i][j] = 0;
            } else {
                cout << "Masukkan bobot " << vertices[i] << "-->" << vertices[j] << ": ";
                cin >> adjacencyMatrix[i][j];
            }
        }
    }

    return adjacencyMatrix;
}

// Fungsi untuk mencari jarak antara dua kota (simpul) dalam graph
int findDistance(const vector<vector<int>>& adjacencyMatrix, const vector<string>& vertices,
                 const string& startCity, const string& endCity) {
    // Mencari indeks kota awal dan kota tujuan dalam daftar simpul
    auto startIt = find(vertices.begin(), vertices.end(), startCity);
    auto endIt = find(vertices.begin(), vertices.end(), endCity);

    if (startIt == vertices.end() || endIt == vertices.end()) {
        return -1; // Kota tidak ditemukan
    }

    int startIndex = distance(vertices.begin(), startIt);
    int endIndex = distance(vertices.begin(), endIt);

    // Menghitung jarak menggunakan algoritma Dijkstra
    vector<int> distances(vertices.size(), INT_MAX);
    distances[startIndex] = 0;

    // Menginisialisasi set simpul yang belum dikunjungi
    set<int> unvisitedVertices;
    for (int i = 0; i < vertices.size(); i++) {
        unvisitedVertices.insert(i);
    }

    // Menjalankan algoritma Dijkstra
    while (!unvisitedVertices.empty()) {
        // Menemukan simpul dengan jarak terpendek dari simpul awal yang belum dikunjungi
        int currentVertex = *min_element(unvisitedVertices.begin(), unvisitedVertices.end(),
                                         [&](int i, int j) { return distances[i] < distances[j]; });

        // Menghapus simpul dari set simpul yang belum dikunjungi
        unvisitedVertices.erase(currentVertex);

        // Memperbarui jarak simpul yang terhubung dengan simpul saat ini
        for (int neighbor = 0; neighbor < vertices.size(); neighbor++) {
            if (adjacencyMatrix[currentVertex][neighbor] > 0 &&
                distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor] < distances[neighbor]) {
                distances[neighbor] = distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor];
            }
        }
    }

    // Mengembalikan jarak ke kota tujuan
    return distances[endIndex];
}

int main() {
    // Membangun graph
    vector<string> vertices;
    vector<vector<int>> adjacencyMatrix = createGraph(vertices);

    // Mencari jarak antara dua kota
    string kotaAwal_169, kotaAkhir_169;
    cout << "Masukkan nama kota awal: ";
    cin >> kotaAwal_169;
    cout << "Masukkan nama kota tujuan: ";
    cin >> kotaAkhir_169;

    int distance = findDistance(adjacencyMatrix, vertices, kotaAwal_169, kotaAkhir_169);

    // Menampilkan hasil
    if (distance == -1) {
        cout << "Tidak ada jalur dari " << kotaAwal_169 << " ke " << kotaAkhir_169 << "." << endl;
    } else {
        cout << "Jarak dari " << kotaAwal_169 << " ke " << kotaAkhir_169 << " adalah " << distance << " kilometer." << endl;
    }

    return 0;
}
```

#### Output:
![Screenshot 2024-05-29 160453](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/88d88d1a-2f30-4fcb-a988-6126fb2df227)

Program meminta pengguna untuk memasukkan jumlah simpul (kota) dan nama-nama kota tersebut, kemudian mengisi bobot (jarak) antara setiap pasangan kota. 
Setelah graf terbentuk, pengguna dapat memasukkan nama kota awal dan kota tujuan, dan program akan menghitung serta menampilkan jarak terpendek antara kedua kota. Jika salah satu kota tidak ditemukan dalam graf, program akan menampilkan pesan bahwa tidak ada jalur antara kedua kota tersebut.

### 2. Unguided II

Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
//Ben Waiz Pintus W
//2311102169

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data_169;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data_169) {
    Pohon *node = new Pohon();
    node->data_169 = data_169;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data_169) {
    if (isEmpty()) {
        root = newPohon(data_169);
        cout << "\nNode " << data_169 << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data_169, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data_169 << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data_169);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data_169 << " berhasil ditambahkan ke child kiri " << node->data_169 << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data_169, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data_169 << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data_169);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data_169 << " berhasil ditambahkan ke child kanan " << node->data_169 << endl;
            return baru;
        }
    }
}

void update(char data_169, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data_169;
            node->data_169 = data_169;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data_169 << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data_169 << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data_169 << endl;
            cout << "Root : " << root->data_169 << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data_169 << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data_169 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data_169 << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data_169 << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data_169 << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data_169 << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data_169 << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data_169 << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data_169 << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

// Menampilkan Child dari node
void showChild(Pohon *node) {
    if (node->left != NULL)
        cout << "Child Kiri : " << node->left->data_169 << endl;
    else
        cout << "Child Kiri : (tidak punya Child kiri)" << endl;

    if (node->right != NULL)
        cout << "Child Kanan : " << node->right->data_169 << endl;
    else
        cout << "Child Kanan : (tidak punya Child kanan)" << endl;
}

// Menampilkan Descendant dari node
void showDescendants(Pohon *node) {
    if (node == NULL)
        return;
    
    queue<Pohon*> q;
    q.push(node);
    vector<char> descendants;

    while (!q.empty()) {
        Pohon* current = q.front();
        q.pop();

        if (current != node) {
            descendants.push_back(current->data_169);
        }

        if (current->left != NULL) {
            q.push(current->left);
        }

        if (current->right != NULL) {
            q.push(current->right);
        }
    }

    if (descendants.empty()) {
        cout << "Node " << node->data_169 << " tidak punya descendants." << endl;
    } else {
        cout << "Descendants of node " << node->data_169 << " : ";
        for (char data : descendants) {
            cout << data << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menampilkan menu dan mengelola input pengguna
void menu() {
    char data_169;
    Pohon *node;
    int pilihan_169;
    
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Buat Node Root" << endl;
        cout << "2. Insert Left" << endl;
        cout << "3. Insert Right" << endl;
        cout << "4. Update Node" << endl;
        cout << "5. Retrieve Node" << endl;
        cout << "6. Find Node" << endl;
        cout << "7. PreOrder Traversal" << endl;
        cout << "8. InOrder Traversal" << endl;
        cout << "9. PostOrder Traversal" << endl;
        cout << "10. Tampilkan Child Node" << endl;
        cout << "11. Tampilkan Descendants Node" << endl;
        cout << "12. Hapus SubTree" << endl;
        cout << "13. Hapus Tree" << endl;
        cout << "14. Karakteristik Tree" << endl;
        cout << "15. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan_169;

        switch (pilihan_169) {
            case 1:
                cout << "Masukkan data untuk root: ";
                cin >> data_169;
                buatNode(data_169);
                break;
            case 2:
                cout << "Masukkan data untuk child kiri: ";
                cin >> data_169;
                cout << "Masukkan data parent: ";
                cin >> data_169;
                node = root;
                while (node && node->data_169 != data_169) {
                    if (node->left && node->left->data_169 == data_169) {
                        node = node->left;
                    } else if (node->right && node->right->data_169 == data_169) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data_169 == data_169) {
                    insertLeft(data_169, node);
                } else {
                    cout << "Node parent tidak ditemukan!" << endl;
                }
                break;
            case 3:
                cout << "Masukkan data untuk child kanan: ";
                cin >> data_169;
                cout << "Masukkan data parent: ";
                cin >> data_169;
                node = root;
                while (node && node->data_169 != data_169) {
                    if (node->left && node->left->data_169 == data_169) {
                        node = node->left;
                    } else if (node->right && node->right->data_169 == data_169) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data_169 == data_169) {
                    insertRight(data_169, node);
                } else {
                    cout << "Node parent tidak ditemukan!" << endl;
                }
                break;
            case 4:
                cout << "Masukkan data node yang akan diupdate: ";
                cin >> data_169;
                cout << "Masukkan data baru: ";
                char newData_169;
                cin >> newData_169;
                node = root;
                while (node && node->data_169 != data_169) {
                    if (node->left && node->left->data_169 == data_169) {
                        node = node->left;
                    } else if (node->right && node->right->data_169 == data_169) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data_169 == data_169) {
                    update(newData_169, node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 5:
                cout << "Masukkan data node yang akan diretrieve: ";
                cin >> data_169;
                node = root;
                while (node && node->data_169 != data_169) {
                    if (node->left && node->left->data_169 == data_169) {
                        node = node->left;
                    } else if (node->right && node->right->data_169 == data_169) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data_169 == data_169) {
                    retrieve(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 6:
                cout << "Masukkan data node yang akan dicari: ";
                cin >> data_169;
                node = root;
                while (node && node->data_169 != data_169) {
                    if (node->left && node->left->data_169 == data_169) {
                        node = node->left;
                    } else if (node->right && node->right->data_169 == data_169) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data_169 == data_169) {
                    find(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 7:
                cout << "\nPreOrder :" << endl;
                preOrder(root);
                cout << "\n" << endl;
                break;
            case 8:
                cout << "InOrder :" << endl;
                inOrder(root);
                cout << "\n" << endl;
                break;
            case 9:
                cout << "PostOrder :" << endl;
                postOrder(root);
                cout << "\n" << endl;
                break;
            case 10:
                cout << "Masukkan data node: ";
                cin >> data_169;
                node = root;
                while (node && node->data_169 != data_169) {
                    if (node->left && node->left->data_169 == data_169) {
                        node = node->left;
                    } else if (node->right && node->right->data_169 == data_169) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data_169 == data_169) {
                    showChild(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 11:
                cout << "Masukkan data node: ";
                cin >> data_169;
                node = root;
                while (node && node->data_169 != data_169) {
                    if (node->left && node->left->data_169 == data_169) {
                        node = node->left;
                    } else if (node->right && node->right->data_169 == data_169) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data_169 == data_169) {
                    showDescendants(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 12:
                cout << "Masukkan data node untuk menghapus subtree: ";
                cin >> data_169;
                node = root;
                while (node && node->data_169 != data_169) {
                    if (node->left && node->left->data_169 == data_169) {
                        node = node->left;
                    } else if (node->right && node->right->data_169 == data_169) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data_169 == data_169) {
                    deleteSub(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 13:
                clear();
                break;
            case 14:
                characteristic();
                break;
            case 15:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan_169 != 15);
}

int main() {
    init();
    menu();
    return 0;
}
```

#### Output:
![Screenshot 2024-05-29 162355](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/b828b701-9149-4bc9-ba80-e88897ee9860)
![Screenshot 2024-05-29 163133](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/55a4ec08-2607-4ac7-bfc1-9984c71e1eb0)
![Screenshot 2024-05-29 163202](https://github.com/benwaiz/Struktur-Data-Assignment/assets/161665572/185754bf-8a22-4f39-9843-3911f3119140)

Program memungkinkan pengguna untuk membuat pohon, menambahkan node sebagai child kiri atau kanan, memperbarui data node, mengambil data node, mencari node, menampilkan child dan descendant node, melakukan traversal (pre-order, in-order, post-order), menghapus subtree atau seluruh pohon, serta menampilkan karakteristik pohon seperti ukuran dan tinggi pohon. 
Semua fungsi ini diakses melalui menu interaktif yang memberikan pilihan kepada pengguna untuk melakukan berbagai operasi pada pohon biner.

## Kesimpulan
Graf dan tree adalah struktur data fundamental yang digunakan untuk merepresentasikan hubungan antara objek dalam berbagai konteks. Graf terdiri dari simpul dan sisi yang bisa berarah atau tak berarah serta berbobot, sehingga sangat berguna dalam aplikasi seperti jaringan komputer dan peta jalan. 
Tree adalah bentuk khusus dari graf tanpa siklus yang merepresentasikan hierarki, seperti dalam struktur organisasi atau sistem file. Pemahaman tentang graf dan tree memungkinkan implementasi algoritma yang efisien untuk pencarian, penyortiran, dan analisis data, yang esensial dalam banyak bidang ilmu komputer dan teknik.

## Referensi
[1] Trivusi, "Struktur Data Graph: Pengertian, Jenis, dan Kegunaannya", 2022. https://www.trivusi.web.id/2022/07/struktur-data-graph.html

[2] Mohammad Andi Triansyah, "Graph dan Tree", scribd.com, 2015. https://www.scribd.com/doc/282997630/Graph-Dan-Tree

[3] ahmadhadari77, "Graf (Graph) dan Pohon (Tree) - Algoritma Pemrograman 2", 2019. https://ahmadhadari77.blogspot.com/2019/05/graph-graf-dan-tree-pohon-algoritma.html
