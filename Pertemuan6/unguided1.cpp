// Daffa Falih Aqilah
// 2311102137
// S1IF-11-D

#include <iostream>
#include <stack>

using namespace std;

// Fungsinya untuk menentukan apakah kalimat tersebut Palindrom atau tidak
string cleanstack_137(string str) {
    string cleaned;
    for (char c : str) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

// Fungsi mengecek palindrome
bool Palindrome_137(string str) {
    stack<char> charStack;
    str = cleanstack_137(str);

    // Memeriksa apakah kalimat kosong
    if (str.empty()) {
        return false;
    }

    for (char c : str) {
        charStack.push(c);
    }

    for (char c : str) {
        if (c != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    int choice;
    string kalimat;

    do {
        cout << "--------------- Menu --------------" << endl;
        cout << "1. Cek kalimat palindrome" << endl;
        cout << "2. Keluar" << endl;
        cout <<"-----------------------------------"<<endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Masukkan kalimat: ";
                getline(cin, kalimat);

                if (Palindrome_137(kalimat)) {
                    cout << "Kalimat tersebut adalah palindrom." << endl;
                } else {
                    cout << "Kalimat tersebut bukan palindrom." << endl;
                }
                break;
            case 2:
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (choice != 2);

    return 0;
}
