#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  const int MAX_OPERASI = 4;
  char operasi[MAX_OPERASI] = {'+', '-', '*', '/'};
  string namaOperasi[MAX_OPERASI] = {"Penjumlahan", "Pengurangan", "Perkalian", "Pembagian"};
  int hasil[MAX_OPERASI];

  // Lakukan perhitungan untuk semua operasi
  for (int i = 0; i < MAX_OPERASI; i++) {
    int angka1, angka2;

    // Input angka
    cout << "Masukkan angka pertama untuk " << namaOperasi[i] << ": ";
    cin >> angka1;

    cout << "Masukkan angka kedua untuk " << namaOperasi[i] << ": ";
    cin >> angka2;

    // Hitung hasil
    switch (operasi[i]) {
      case '+':
        hasil[i] = angka1 + angka2;
        break;
      case '-':
        hasil[i] = angka1 - angka2;
        break;
      case '*':
        hasil[i] = angka1 * angka2;
        break;
      case '/':
        if (angka2 == 0) {
          cout << "Pembagian dengan 0 tidak diizinkan!" << endl;
          continue;
        }
        hasil[i] = angka1 / angka2;
        break;
    }
  }

  // Tampilkan hasil
  cout << "=====================================" << endl;
  cout << "Hasil Perhitungan" << endl;
  cout << "=====================================" << endl;

  for (int i = 0; i < MAX_OPERASI; i++) {
    cout << namaOperasi[i] << ": " << hasil[i] << endl;
  }

  return 0;
}
