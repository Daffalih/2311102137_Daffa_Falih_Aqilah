//Daffa Falih Aqilah
//2311102137

#include <iostream>
#include <iomanip>

using namespace std;

void TampilGraph_137(int JumlahSimpul_137, string* NamaSimpul_137, int** BobotSimpul_137) {
    cout << setw(10) << " ";
    for (int i = 0; i < JumlahSimpul_137; i++) {
        cout << setw(10) << NamaSimpul_137[i];
    }
    cout << endl;

    for (int baris_137 = 0; baris_137 < JumlahSimpul_137; baris_137++) {
        cout << setw(10) << NamaSimpul_137[baris_137];
        for (int kolom_137 = 0; kolom_137 < JumlahSimpul_137; kolom_137++) {
            cout << setw(10) << BobotSimpul_137[baris_137][kolom_137];
        }
        cout << endl;
    }
}

int main() {
    int JumlahSimpul_137;
    int Nomor_137 = 1;
    int Bobot_137;

    cout << "--- PROGRAM GRAPH ---" << endl;

    cout << "Masukkan jumlah simpul = ";
    cin >> JumlahSimpul_137;

    string* NamaSimpul_137 = new string[JumlahSimpul_137];

    cout << "--- Masukkan nama simpul ---" << endl; 
    for (int i = 0; i < JumlahSimpul_137; i++) {
        cout << "Masukkan nama simpul " << Nomor_137++ << " = ";
        cin >> NamaSimpul_137[i];
    }
    cout << endl;

    int** BobotSimpul_137 = new int*[JumlahSimpul_137];
    for (int i = 0; i < JumlahSimpul_137; i++) {
        BobotSimpul_137[i] = new int[JumlahSimpul_137]();
    }

    cout << "--- Masukkan Bobot Antar Simpul ---" << endl;
    for (int i = 0; i < JumlahSimpul_137; i++) {
        for (int j = 0; j < JumlahSimpul_137; j++) {
            if (i != j) {
                cout << "Bobot " << NamaSimpul_137[i] << " --> " << NamaSimpul_137[j] << " = ";
                cin >> Bobot_137;
                BobotSimpul_137[i][j] = Bobot_137;
            }
        }
    }
    cout << endl;

    TampilGraph_137(JumlahSimpul_137, NamaSimpul_137, BobotSimpul_137);

    return 0;
}
