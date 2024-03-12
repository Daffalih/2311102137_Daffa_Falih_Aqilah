#include <iostream>
#include <map>

using namespace std;

int main() {
  // Membuat map kosong
  map<string, int> m;

  // Menambahkan elemen ke map
  m["Daffa"] = 20;
  m["Falih"] = 21;
  m["Aqilah"] = 22;

  // Menampilkan isi map
  for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " : " << it->second << endl;
  }

  // Mencari elemen dalam map
  auto it = m.find("Aqilah");
  if (it != m.end()) {
    cout << "Nilai Aqilah: " << it->second << endl;
  } else {
    cout << "Aqilah tidak ditemukan" << endl;
  }

  return 0;
}

