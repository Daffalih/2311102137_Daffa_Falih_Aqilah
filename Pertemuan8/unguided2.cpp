// Daffa Falih Aqilah
// 2311102137
// S1IF-11-D

#include <iostream>
#include <cstring>

using namespace std;

// Fungsi untuk menghitung banyaknya huruf vokal dalam sebuah kalimat
int hitungVokal_137(const char *kalimat) {
    int jumlahVokal_137 = 0;
    int panjangKalimat = strlen(kalimat);

    // Loop untuk setiap karakter dalam kalimat
    for (int i = 0; i < panjangKalimat; ++i) {
        // Memeriksa apakah karakter merupakan huruf vokal
        if (kalimat[i] == 'a' || kalimat[i] == 'A' ||
            kalimat[i] == 'e' || kalimat[i] == 'E' ||
            kalimat[i] == 'i' || kalimat[i] == 'I' ||
            kalimat[i] == 'o' || kalimat[i] == 'O' ||
            kalimat[i] == 'u' || kalimat[i] == 'U') {
            jumlahVokal_137++;
        }
    }

    return jumlahVokal_137;
}

int main() {
    char kalimat[137];

    cout << "Masukkan sebuah kalimat: ";
    cin.getline(kalimat, 137);

    int jumlahVokal = hitungVokal_137(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlahVokal << endl;

    return 0;
}
