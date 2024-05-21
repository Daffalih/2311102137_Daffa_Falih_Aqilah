// Daffa Falih Aqilah
// 2311102137
// S1IF-11-D

#include <iostream> 
using namespace std; 

// Fungsi untuk melakukan pencarian secara berurutan
int sequentialSearch_137(int data[], int n, int target) {
    int hitung = 0; 
    for (int i = 0; i < n; i++) { 
        if (data[i] == target) { 
            hitung++; 
        }
    }
    return hitung; 
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; 
    int a = sizeof(data) / sizeof(data[0]); 
    int target = 4; 

    // Memanggil fungsi sequentialSearch untuk menghitung kemunculan target
    int hitung = sequentialSearch_137(data, a, target);

    // Menampilkan hasil pencarian
    cout << "Pada data: 9, 4, 1, 4, 7, 10, 5, 4, 12, 4" << endl;
    cout << "Banyak angka 4 di dalam data adalah: " << hitung << endl;

    return 0; 
}
