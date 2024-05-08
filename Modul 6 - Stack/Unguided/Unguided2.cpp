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
