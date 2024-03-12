#include <iostream>

using namespace std;

// **Class Person**
class Person {
  private:
    string nama;
    int usia;

  public:
    Person() {} // Constructor default
    Person(string nama, int usia) { // Constructor dengan parameter
      this->nama = nama;
      this->usia = usia;
    }

    string getNama() { return nama; } // nama
    void setNama(string nama) { this->nama = nama; } // Setter untuk nama

    int getUsia() { return usia; } // Getter untuk usia
    void setUsia(int usia) { this->usia = usia; } // Setter untuk usia

    void printInfo() { // Fungsi untuk mencetak informasi
      cout << "Nama: " << nama << endl;
      cout << "Usia: " << usia << endl;
    }
};

// **Struct Point**
struct Point {
  int x;
  int y;

  void printPoint() { // Fungsi untuk mencetak koordinat
    cout << "Titik (" << x << ", " << y << ")" << endl;
  }
};

int main() {
  // **Contoh penggunaan Class Person**
  Person p1("Daffa", 20); // Membuat objek Person dengan nama Budi dan usia 20
  p1.printInfo(); // Mencetak informasi Person p1

  Person p2; // Membuat objek Person default
  p2.setNama("Falih"); // Mengatur nama Person p2 menjadi Ani
  p2.setUsia(22); // Mengatur usia Person p2 menjadi 22
  p2.printInfo(); // Mencetak informasi Person p2

  // **Contoh penggunaan Struct Point**
  Point p3 = {10, 20}; // Membuat objek Point dengan koordinat (10, 20)
  p3.printPoint(); // Mencetak koordinat Point p3

  Point p4; // Membuat objek Point default
  p4.x = 30; // Mengatur koordinat x Point p4 menjadi 30
  p4.y = 40; // Mengatur koordinat y Point p4 menjadi 40
  p4.printPoint(); // Mencetak koordinat Point p4

  return 0;
}
