#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Ham chuan hoa de do dai chia het cho m
string chuanHoaChuoi(string s, int m) {
    while ((int)s.size() % m != 0) {
        s += 'X';
    }
    return s;
}

// Ham ma hoa hoan vi
string maHoa(string banRo, const vector<int>& khoa) {
    int m = (int)khoa.size();
    string s = chuanHoaChuoi(banRo, m);
    string banMa = "";

    for (int i = 0; i < (int)s.size(); i += m) {
        for (int j = 0; j < m; j++) {
            banMa += s[i + khoa[j] - 1];
        }
    }
    return banMa;
}

// Ham giai ma
string giaiMa(string banMa, const vector<int>& khoa) {
    int m = (int)khoa.size();
    string banRo = "";

    for (int i = 0; i < (int)banMa.size(); i += m) {
        string block(m, ' ');
        for (int j = 0; j < m; j++) {
            block[khoa[j] - 1] = banMa[i + j];
        }
        banRo += block;
    }
    // Bo padding x o cuoi
    // Loai bo cac ky tu 'X' o cuoi (padding), nhung giu khoang trang
	while (!banRo.empty() && banRo[banRo.size() - 1] == 'X') {
	    if (banRo.size() >= 2 && banRo[banRo.size() - 2] == ' ')
	        break; // neu truoc 'X' la dau cach thi giu lai
	    banRo.erase(banRo.size() - 1, 1);
	}

    return banRo;
}

int main() {
    int choice;
    do {
        cout << "\n===== CHUONG TRINH MA HOA HOAN VI =====\n";
        cout << "1. Ma hoa\n";
        cout << "2. Giai ma\n";
        cout << "3. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            string banRo;
            int m;
            vector<int> khoa;

            cout << "Nhap ban ro: ";
            getline(cin, banRo);

            cout << "Nhap do dai khoa: ";
            cin >> m;
            khoa.resize(m);

            cout << "Nhap khoa (vi tri tu 1 den " << m << "): ";
            for (int i = 0; i < m; i++) cin >> khoa[i];

            string banMa = maHoa(banRo, khoa);
            cout << "Ban ma: " << banMa << endl;
            cin.ignore(); 
        }
        else if (choice == 2) {
            string banMaNhap;
            int m2;
            vector<int> khoa2;

            cout << "Nhap ban ma: ";
            getline(cin, banMaNhap);

            cout << "Nhap do dai khoa: ";
            cin >> m2;
            khoa2.resize(m2);

            cout << "Nhap khoa (vi tri tu 1 den " << m2 << "): ";
            for (int i = 0; i < m2; i++) cin >> khoa2[i];

            string giai = giaiMa(banMaNhap, khoa2);
            cout << "Ban giai ma: " << giai << endl;
            cin.ignore(); 
        }
        else if (choice == 3) {
            cout << "Thoat chuong trinh.\n";
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 3);

    return 0;
}

