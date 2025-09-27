#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm mã hóa Caesar
string encryptCaesar(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isupper(c)) {
            result += char((c - 'A' + key) % 26 + 'A');
        } else if (islower(c)) {
            result += char((c - 'a' + key) % 26 + 'a');
        } else {
            result += c; 
        }
    }
    return result;
}

// Hàm gi?i mã Caesar
string decryptCaesar(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isupper(c)) {
            result += char((c - 'A' - key + 26) % 26 + 'A');
        } else if (islower(c)) {
            result += char((c - 'a' - key + 26) % 26 + 'a');
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string plaintext, ciphertext;
    int key;

    // --- Nh?p b?n rõ và khóa d? mã hóa ---
    cout << "Nhap ban ro: ";
    getline(cin, plaintext);

    cout << "Nhap khoa k (so buoc dich chuyen): ";
    cin >> key;
    cin.ignore();

    ciphertext = encryptCaesar(plaintext, key);
    cout << "Ban ma: " << ciphertext << endl;

    // --- Nh?p b?n mã và khóa d? gi?i mã ---
    cout << "\nNhap ban ma de giai ma: ";
    getline(cin, ciphertext);

    cout << "Nhap khoa k de giai ma: ";
    cin >> key;

    string decrypted = decryptCaesar(ciphertext, key);
    cout << "Ban ro sau giai ma: " << decrypted << endl;

    return 0;
}

