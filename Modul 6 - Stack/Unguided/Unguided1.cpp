#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(string kalimat) {
  // Konversi kalimat menjadi huruf kecil
  for (int i = 0; i < kalimat.length(); i++) {
    kalimat[i] = tolower(kalimat[i]);
  }

  // Hapus spasi dan karakter non-huruf
  string temp = "";
  for (int i = 0; i < kalimat.length(); i++) {
    if (isalpha(kalimat[i])) {
      temp += kalimat[i];
    }
  }

  // Buat stack untuk menyimpan karakter kalimat
  stack<char> s;
  for (int i = 0; i < temp.length(); i++) {
    s.push(temp[i]);
  }

  // Bandingkan karakter dari depan dan belakang
  for (int i = 0; i < temp.length() / 2; i++) {
    if (s.top() != temp[i]) {
      return false;
    }
    s.pop();
  }

  return true;
}

int main() {
  string kalimat;

  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  if (isPalindrome(kalimat)) {
    cout << "Kalimat " << kalimat << " adalah palindrom" << endl;
  } else {
    cout << "Kalimat " << kalimat << " bukan palindrom" << endl;
  }

  return 0;
}