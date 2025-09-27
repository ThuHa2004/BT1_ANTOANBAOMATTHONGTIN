#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string chuanHoaChuoi(const string &str) {
    string res = "";
    for (size_t i = 0; i < str.size(); i++) {
        char c = toupper(str[i]);
        if (c >= 'A' && c <= 'Z') {
            if (c == 'J') c = 'I';
            res += c;
        }
    }
    return res;
}

vector< vector<char> > taoBangKhoa(const string &key) {
    string bang = "";
    string k = chuanHoaChuoi(key);

    for (size_t i = 0; i < k.size(); i++) {
        if (bang.find(k[i]) == string::npos) bang += k[i];
    }
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // không có J
    for (size_t i = 0; i < alphabet.size(); i++) {
        if (bang.find(alphabet[i]) == string::npos) bang += alphabet[i];
    }

    vector< vector<char> > matrix(5, vector<char>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = bang[i * 5 + j];
        }
    }
    return matrix;
}

pair<int,int> timViTri(const vector< vector<char> > &matrix, char c) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == c) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

string chuanBiCap(const string &s) {
    string str = chuanHoaChuoi(s);
    string res = "";
    for (size_t i = 0; i < str.size(); i++) {
        char a = str[i];
        char b = (i + 1 < str.size()) ? str[i + 1] : 'X';
        if (a == b) {
            res += a;
            res += 'X';
        } else {
            res += a;
            res += b;
            i++;
        }
    }
    if (res.size() % 2 != 0) res += 'X';
    return res;
}

// Mã hóa
string playfairEncrypt(const string &text, const string &key) {
    vector< vector<char> > matrix = taoBangKhoa(key);
    string pairs = chuanBiCap(text);
    string result = "";

    for (size_t i = 0; i < pairs.size(); i += 2) {
        char a = pairs[i], b = pairs[i+1];
        pair<int,int> pa = timViTri(matrix, a);
        pair<int,int> pb = timViTri(matrix, b);

        if (pa.first == pb.first) {
            result += matrix[pa.first][(pa.second + 1) % 5];
            result += matrix[pb.first][(pb.second + 1) % 5];
        } else if (pa.second == pb.second) {
            result += matrix[(pa.first + 1) % 5][pa.second];
            result += matrix[(pb.first + 1) % 5][pb.second];
        } else {
            result += matrix[pa.first][pb.second];
            result += matrix[pb.first][pa.second];
        }
    }
    return result;
}

// Giai ma
string playfairDecrypt(const string &text, const string &key) {
    vector< vector<char> > matrix = taoBangKhoa(key);
    string str = chuanHoaChuoi(text);
    string result = "";

    for (size_t i = 0; i < str.size(); i += 2) {
        char a = str[i], b = str[i+1];
        pair<int,int> pa = timViTri(matrix, a);
        pair<int,int> pb = timViTri(matrix, b);

        if (pa.first == pb.first) {
            result += matrix[pa.first][(pa.second + 4) % 5];
            result += matrix[pb.first][(pb.second + 4) % 5];
        } else if (pa.second == pb.second) {
            result += matrix[(pa.first + 4) % 5][pa.second];
            result += matrix[(pb.first + 4) % 5][pb.second];
        } else {
            result += matrix[pa.first][pb.second];
            result += matrix[pb.first][pa.second];
        }
    }

   
    string clean = "";
    for (size_t i = 0; i < result.size(); i++) {
        if (i > 0 && i < result.size()-1 && result[i] == 'X' && result[i-1] == result[i+1]) {
            continue; 
        }
        clean += result[i];
    }
    if (!clean.empty() && clean[clean.size()-1] == 'X') {
        clean.erase(clean.size()-1, 1); 
    }
    return clean;
}

int main() {
    while (true) {
        cout << "\n--- MA HOA PLAYFAIR ---\n";
        cout << "1. Ma hoa\n";
        cout << "2. Giai ma\n";
        cout << "3. Thoat\n";
        cout << "Chon che do: ";
        int choice;
        cin >> choice;
        cin.ignore(); 

        if (choice == 3) {
            cout << "Thoat chuong trinh.\n";
            break;
        }

        string text, key;
        cout << "Nhap van ban: ";
        getline(cin, text);
        cout << "Nhap khoa: ";
        getline(cin, key);

        if (choice == 2) {
            string enc = playfairEncrypt(text, key);
            cout << "Ban ma: " << enc << endl;
        } else if (choice == 1) {
            string dec = playfairDecrypt(text, key);
            cout << "Ban giai ma: " << dec << endl;
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
    return 0;
}

