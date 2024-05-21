// Daffa Falih Aqilah
// 2311102137
// S1IF-11-D

#include <iostream> // Memasukkan pustaka untuk input dan output

using namespace std; // Menggunakan namespace std agar tidak perlu menuliskan std:: secara berulang

// Fungsi bubbleSort_137 untuk mengurutkan array karakter
void bubbleSort_137(char arr[], int n) {
for (int i = 0; i < n - 1; i++) { 
for (int j = 0; j < n - i - 1; j++) { 
if (arr[j] > arr[j + 1]) { 
char temp_137 = arr[j]; // Tukar elemen sekarang dengan elemen selanjutnya
arr[j] = arr[j + 1];
arr[j + 1] = temp_137;
}
}
}
}

// Fungsi binarySearch untuk mencari huruf dalam array karakter yang sudah diurutkan
int binarySearch_137(const char arr[], int kiri_137, int kanan_137, char cariHuruf_137) {
while (kiri_137 <= kanan_137) { 
int tengah_137 = kiri_137 + (kanan_137 - kiri_137) / 2; 

if (arr[tengah_137] == cariHuruf_137) 
return tengah_137; 

if (arr[tengah_137] < cariHuruf_137) 
kiri_137 = tengah_137 + 1; 
else
kanan_137 = tengah_137 - 1; 
}

return -1; // Jika huruf tidak ditemukan, kembalikan -1
}

int main() {
  char masukan_137[100]; 
  char cariHuruf_137; 

  cout << "Masukkan kalimat: "; 
  cin.getline(masukan_137, 100); 

  cout << "Masukkan Huruf yang dicari dalam kalimat: "; // Minta pengguna memasukkan huruf yang dicari
  cin >> cariHuruf_137; 

  int length_137 = 0; // Variabel untuk panjang kalimat
  while (masukan_137[length_137] != '\0') { 
    length_137++;
  }

  bubbleSort_137(masukan_137, length_137); // Urutkan kalimat menggunakan bubble sort

  cout << "Kalimat diurutkan (a-z): " << masukan_137 << endl; 

  int result_137 = binarySearch_137(masukan_137, 0, length_137 - 1, cariHuruf_137); 
  if (result_137 != -1) { 
    cout << "Huruf : " << cariHuruf_137 << " ditemukan pada indeks ke- " << result_137 << " Pada kalimat yang telah diurutkan" << endl;
  } else { 
    cout << "Huruf " << cariHuruf_137 << " Tidak ditemukan dalam kalimat " << endl;
  }
  return 0; 
}