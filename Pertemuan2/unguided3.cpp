/*
Daffa Daffa Falih Aqilah - 2311102137
*/

#include <iostream>

using namespace std;

int main() {
  int pilihan;
  int data[10];
  float rata_rata;
  int max = INT_MIN;
  int min = INT_MAX;

  // Input data
  cout << "Masukkan 10 nomor: ";
  for (int i = 0; i < 10; i++) {
    cin >> data[i];
  }

  // Tampilkan menu
  do {
    cout << endl;
    cout << "Menu:" << endl;
    cout << "1. Mencari nilai maksimum" << endl;
    cout << "2. Mencari nilai minimum" << endl;
    cout << "3. Mencari nilai rata-rata" << endl;
    cout << "4. Keluar" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        // Mencari nilai maksimum
        for (int i = 0; i < 10; i++) {
          if (data[i] > max) {
            max = data[i];
          }
        }
        cout << "Nilai maksimum: " << max << endl;
        break;
      case 2:
        // Mencari nilai minimum
        for (int i = 0; i < 10; i++) {
          if (data[i] < min) {
            min = data[i];
          }
        }
        cout << "Nilai minimum: " << min << endl;
        break;
      case 3:
        // Mencari nilai rata-rata
        rata_rata = 0;
        for (int i = 0; i < 10; i++) {
          rata_rata += data[i];
        }
        rata_rata /= 10;
        cout << "Nilai rata-rata: " << rata_rata << endl;
        break;
      case 4:
        // Keluar
        cout << "Terima kasih telah menggunakan program ini!" << endl;
        break;
      default:
        // Pilihan tidak valid
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (pilihan != 4);

  return 0;
}