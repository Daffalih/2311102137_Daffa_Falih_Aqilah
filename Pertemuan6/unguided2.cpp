// Daffa Falih Aqilah
// 2311102137
// S1IF-11-D

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// fungsinya adalah untuk membalikkan kata seperti daffa jadi affad
string membalikankata_137(string sentence) {
    stack<char> charStack;
    string reversedSentence;

    for (char c : sentence) {
        charStack.push(c);
    }

    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }

    return reversedSentence;
}

int main() {
    int choice;
    string kalimat;
    do {
        cout <<"--------------- Menu --------------"<<endl;
        cout << "1. Balikkan Kalimat"<<endl;
        cout << "2. Keluar"<<endl;
        cout <<"-----------------------------------"<<endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
            // inputkan kata yang ingin dibalikkan
                cout << "Masukkan kalimat: ";
                getline(cin, kalimat);
                cout << "Kalimat Awal: " << kalimat << endl;
                cout << "Kalimat Terbalik: " << membalikankata_137(kalimat) << endl;
                break;
            case 2:
                cout << "Terima kasih sudah menggunakan program ini:) " << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (choice != 2);

    return 0;
}

