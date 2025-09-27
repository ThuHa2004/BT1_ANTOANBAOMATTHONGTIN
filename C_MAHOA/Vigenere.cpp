#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char shift_letter_encrypt(char p, char k) {
    if (isupper(p)) {
        int P = p - 'A';
        int K = toupper(k) - 'A';
        int C = (P + K) % 26;
        return char(C + 'A');
    } else if (islower(p)) {
        int P = p - 'a';
        int K = tolower(k) - 'a';
        int C = (P + K) % 26;
        return char(C + 'a');
    }
    return p;
}

char shift_letter_decrypt(char c, char k) {
    if (isupper(c)) {
        int C = c - 'A';
        int K = toupper(k) - 'A';
        int P = (C - K + 26) % 26;
        return char(P + 'A');
    } else if (islower(c)) {
        int C = c - 'a';
        int K = tolower(k) - 'a';
        int P = (C - K + 26) % 26;
        return char(P + 'a');
    }
    return c;
}

string extend_key(const string& key, const string& text) {
    string ext;
    int keylen = key.length();
    if (keylen == 0) return ext;
    int j = 0;
    for (size_t i = 0; i < text.length(); ++i) {
        if (isalpha(text[i])) {
            ext += key[j % keylen];
            ++j;
        } else {
            ext += text[i]; 
        }
    }
    return ext;
}

string encrypt(const string& plaintext, const string& key) {
    string ext = extend_key(key, plaintext);
    string out = plaintext;
    for (size_t i = 0; i < plaintext.length(); ++i) {
        if (isalpha(plaintext[i])) {
            out[i] = shift_letter_encrypt(plaintext[i], ext[i]);
        } else {
            out[i] = plaintext[i];
        }
    }
    return out;
}

string decrypt(const string& ciphertext, const string& key) {
    string ext = extend_key(key, ciphertext);
    string out = ciphertext;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        if (isalpha(ciphertext[i])) {
            out[i] = shift_letter_decrypt(ciphertext[i], ext[i]);
        } else {
            out[i] = ciphertext[i];
        }
    }
    return out;
}

int main() {
    int choice;
    do {
        cout << "\n===== MA HOA VIGENERE =====\n";
        cout << "1. Ma hoa (Encrypt)\n";
        cout << "2. Giai ma (Decrypt)\n";
        cout << "3. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;
        cin.ignore(); // bo dau newline

        if (choice == 1) {
            string plain, key;
            cout << "Nhap ban ro: ";
            getline(cin, plain);
            cout << "Nhap khoa: ";
            getline(cin, key);
            string cipher = encrypt(plain, key);
            cout << "Ban ma: " << cipher << "\n";
        } else if (choice == 2) {
            string cipher, key;
            cout << "Nhap ban ma: ";
            getline(cin, cipher);
            cout << "Nhap khoa: ";
            getline(cin, key);
            string plain = decrypt(cipher, key);
            cout << "Ban ro: " << plain << "\n";
        } else if (choice == 3) {
            cout << "Thoat chuong trinh.\n";
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 3);

    return 0;
}

