#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Tim nghich dao modulo cua a theo mod m
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1; // Neu khong tim thay nghich dao, dung tam 1 de van chay
}

// Ham ma hoa Affine
string affineEncrypt(string text, int a, int b) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char(((a * (c - base) + b) % 26) + base);
        } else {
            result += c;
        }
    }
    return result;
}

// Ham giai ma Affine (khong kiem tra khoa)
string affineDecrypt(string text, int a, int b) {
    string result = "";
    int a_inv = modInverse(a, 26); // luon tinh nghich dao, khong kiem tra
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char((a_inv * ((c - base - b + 26)) % 26) + base);
        } else {
            result += c;
        }
    }
    return result;
}

int ucln(int a, int b) {
    return b == 0 ? a : ucln(b, a % b);
}

int main() {
    string ban_ro, ban_ma, ban_ma_nhap;
    int a_mahoa, b_mahoa;
    int a_giaima, b_giaima;

    cout << "=== THUAT TOAN AFFINE ===\n";

    // Ma hoa
    cout << "\n--- MA HOA ---\n";
    cout << "Nhap ban ro: ";
    getline(cin, ban_ro);
    cout << "Nhap khoa a (nguyen to cung 26): ";
    cin >> a_mahoa;
    cout << "Nhap khoa b: ";
    cin >> b_mahoa;
    cin.ignore();

    if (ucln(a_mahoa, 26) != 1) {
        cout << "Khoa a khong hop le. Phai nguyen to cung 26.\n";
        return 0;
    }

    ban_ma = affineEncrypt(ban_ro, a_mahoa, b_mahoa);
    cout << "Ban ma: " << ban_ma << "\n";

    // Giai ma
    cout << "\n--- GIAI MA ---\n";
    cout << "Nhap ban ma: ";
    getline(cin, ban_ma_nhap);
    cout << "Nhap khoa a: ";
    cin >> a_giaima;
    cout << "Nhap khoa b: ";
    cin >> b_giaima;

    string ban_ro_giaima = affineDecrypt(ban_ma_nhap, a_giaima, b_giaima);
    cout << "Ban ro sau giai ma: " << ban_ro_giaima << "\n";

    return 0;
}

