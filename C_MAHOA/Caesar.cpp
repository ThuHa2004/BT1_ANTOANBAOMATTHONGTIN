#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// H�m m� h�a Caesar
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

// H�m gi?i m� Caesar
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

    // --- Nh?p b?n r� v� kh�a d? m� h�a ---
    cout << "Nhap ban ro: ";
    getline(cin, plaintext);

    cout << "Nhap khoa k (so buoc dich chuyen): ";
    cin >> key;
    cin.ignore();

    ciphertext = encryptCaesar(plaintext, key);
    cout << "Ban ma: " << ciphertext << endl;

    // --- Nh?p b?n m� v� kh�a d? gi?i m� ---
    cout << "\nNhap ban ma de giai ma: ";
    getline(cin, ciphertext);

    cout << "Nhap khoa k de giai ma: ";
    cin >> key;

    string decrypted = decryptCaesar(ciphertext, key);
    cout << "Ban ro sau giai ma: " << decrypted << endl;

    return 0;
}

