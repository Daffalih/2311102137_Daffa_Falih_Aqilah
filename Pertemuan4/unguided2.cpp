// Daffa Falih Aqilah - 2311102137 - S1IF-11-D

#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct node {
    string nama_137;
    string nim_137;
    node *next;
};

// Deklarasi variabel head dan tail
node *head;
node *tail;

// Inisialisasi linked list
void init_137() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool isempty() {
    return head == NULL;
}
// Menghitung jumlah node dalam linked list
int hitunglist_137() {
    int jumlah = 0;
    node *bantu = head;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Menambah data mahasiswa di depan linked list
void insertdepan_137(string nama_137, string nim_137) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_137 = nama_137;
    baru->nim_137 = nim_137;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Menambah data mahasiswa di belakang linked list
void insertbelakang_137(string nama_137, string nim_137) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_137 = nama_137;
    baru->nim_137 = nim_137;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Menambah data mahasiswa di tengah linked list
void inserttengah_137(string nama_137, string nim_137, int posisi_137) {
    if (posisi_137 < 1 || posisi_137 > hitunglist_137() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi_137 == 1) {
            insertdepan_137(nama_137, nim_137);
        } else if (posisi_137 == hitunglist_137() + 1) {
            insertbelakang_137(nama_137, nim_137);
        } else {
            node *baru = new node;
            baru->nama_137 = nama_137;
            baru->nim_137 = nim_137;

            node *bantu = head;
            for (int i = 1; i < posisi_137 - 1; ++i) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

// Mengubah data mahasiswa di depan linked list
void ubahdepan_137(string nama_137, string nim_137) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = head->nama_137;
        string nim_sebelum = head->nim_137;

        // Mengubah data
        head->nama_137 = nama_137;
        head->nim_137 = nim_137;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_137 << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di belakang linked list
void ubahbelakang_137(string nama_137, string nim_137) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = tail->nama_137;
        string nim_sebelum = tail->nim_137;

        // Mengubah data
        tail->nama_137 = nama_137;
        tail->nim_137 = nim_137;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_137 << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di tengah linked list
void ubahtengah_137(string nama_137, string nim_137, int posisi_137) {
    if (posisi_137 < 1 || posisi_137 > hitunglist_137()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        node *bantu = head;
        for (int i = 1; i < posisi_137; ++i) {
            bantu = bantu->next;
        }

        // Menyimpan data sebelum diubah
        string nama_sebelum = bantu->nama_137;
        string nim_sebelum = bantu->nim_137;

        // Mengubah data
        bantu->nama_137 = nama_137;
        bantu->nim_137 = nim_137;

        // Menampilkan informasi
        cout << "Data pada posisi " << posisi_137 << " telah diubah dari " << nama_sebelum << " menjadi " << nama_137 << endl;
    }
}
// Menghapus data mahasiswa di depan linked list
void hapusdepan_137() {
    if (!isempty()) {
        node *hapus = head;
        cout << "Data " << head->nama_137 << " berhasil dihapus dari depan" << endl;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di belakang linked list
void hapusbelakang_137() {
    if (!isempty()) {
        cout << "Data " << tail->nama_137 << " berhasil dihapus dari belakang" << endl;
        node *hapus = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di tengah linked list
void hapustengah_137(int posisi_137) {
    if (!isempty()) {
        if (posisi_137 < 1 || posisi_137 > hitunglist_137()) {
            cout << "Posisi diluar jangkauan" << endl;
        } else {
            if (posisi_137 == 1) {
                hapusdepan_137();
            } else if (posisi_137 == hitunglist_137()) {
                hapusbelakang_137();
            } else {
                node *hapus = head;
                for (int i = 1; i < posisi_137 - 1; ++i) {
                    hapus = hapus->next;
                }
                node *hapus_node = hapus->next;
                hapus->next = hapus_node->next;
                cout << "Data " << hapus_node->nama_137 << " berhasil dihapus dari posisi " << posisi_137 << endl;
                delete hapus_node;
            }
        }
    } else {
        cout << "Linked list kosong!" << endl;
    }
}
// Menghapus data di dalam linked list
void hapuslist_137() {
    while (!isempty()) {
        hapusdepan_137();
    }
    cout << "Linked list berhasil dihapus semua!" << endl;
}

// Menampilkan data dalam linked list
void tampilkan_137() {
    if (!isempty()) {
        node *bantu = head;
        int nomor_137 = 1; // Variabel untuk nomor indeks atau nomor urut
        cout << setw(5) << left << "No" << setw(15) << left << "NAMA" << "NIM" << endl;
        while (bantu != NULL) {
            cout << setw(5) << left << nomor_137 << setw(15) << left << bantu->nama_137 << bantu->nim_137 << endl;
            bantu = bantu->next;
            nomor_137++; // Menginkremen nomor indeks atau nomor urut
        }
    } else {
        cout << "Linked list kosong!" << endl;
    }
}
int main() {
    init_137();
    int pilihan_137;
    string nama_137;
    string nim_137;
    int posisi_137;

    do {
        // Menampilkan menu 
        cout << "------------------------------------------------------------------------------"<<endl;
        cout << "                      Program Linked List Non-Circular                        "<<endl;
        cout << "------------------------------------------------------------------------------"<<endl;
        cout <<endl;
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Keluar" << endl;
        cout << "------------------------------------------------------------------------------"<<endl;
        cout << "Opsi Pilihan :";cin >> pilihan_137;
        cout <<endl;

        switch (pilihan_137) {
            // Menu 1 berfungsi untuk menginputkan nama dan nim ke depan data linked list
            case 1:
                cout << "=-----------Tambah Depan-----------="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_137;
                cout << "Masukkan NIM :";
                cin >> nim_137;
                cout<<endl;
                cout << "Data "<<nama_137<<" telah ditambahkan"<<endl;
                cout << endl;
                insertdepan_137(nama_137, nim_137);
                break;
                // Menu 2 yang berfungsi untuk menginputkan nama dan nim ke bagian belakang dari data linked list
            case 2:
                cout << "=-----------Tambah Belakang-----------="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_137;
                cout << "Masukkan NIM :";
                cin >> nim_137;
                cout<<endl;
                cout << "Data "<<nama_137<<" telah ditambahkan"<<endl;
                cout << endl;
                insertbelakang_137(nama_137, nim_137);
                break;
                // Menu 3 yang berfungsi untuk menginputkan nama dan nim ke bagian tengah ataupun posisi manapun yang diinginkan oleh user dari data linked list
            case 3:
                cout << "=-----------Tambah Tengah-----------="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_137;
                cout << "Masukkan NIM :";
                cin >> nim_137;
                cout << "Masukkan Posisi :";
                cin >> posisi_137;
                cout<<endl;
                cout << "Data "<<nama_137<<" telah ditambahkan"<<endl;
                cout << endl;
                inserttengah_137(nama_137, nim_137, posisi_137);
                break;
                // Menu 4 yang berfungsi untuk mengubah data di posisi belakang pada linked list 
            case 4:
                cout << "=------------Ubah Depan------------="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_137;
                cout << "Masukkan NIM :";
                cin >> nim_137;
                cout << endl;
                ubahdepan_137(nama_137, nim_137);
                break;
                // Menu 5 yang berfungsi untuk mengubah data di posisi belakang pada linked list 
            case 5:
                cout << "=------------Ubah Belakang------------="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_137;
                cout << "Masukkan NIM :";
                cin >> nim_137;
                cout << endl;
                ubahbelakang_137(nama_137, nim_137);
                break;
                // Menu 6 yang berfungsi untuk mengubah data di posisi tengah atau posisi manapun yang diinginkan oleh user pada linked list 
            case 6:
                cout << "=------------Ubah Tengah------------="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_137;
                cout << "Masukkan NIM :";
                cin >> nim_137;
                cout << "Masukkan Posisi :";
                cin >> posisi_137;
                cout << endl;
                ubahtengah_137(nama_137, nim_137, posisi_137);
                break;
                // Menu 5 yang berfungsi untuk menghapus data di posisi depan pada linked list 
            case 7:
                cout << "=------------Hapus Depan------------="<<endl;
                cout <<endl;
                hapusdepan_137();
                break;
                // Menu 5 berfungsi untuk menghapus data di posisi belakang pada linked list 
            case 8:
                cout << "=-----------Hapus Belakang-----------="<<endl;
                cout <<endl;
                hapusbelakang_137();
                break;
                // Menu 5 berfungsi untuk menghapus data di posisi tengah atau posisi manapun yang diinginkan user pada linked list 
            case 9:
                cout << "=------------Hapus Tengah------------="<<endl;
                cout <<"Posisi :";
                cin >>posisi_137;
                cout <<endl;
                hapustengah_137(posisi_137);
                break;
                // Menu 10 memiliki fungsi untuk menghapus seluruh data yang berada didalam list yang telah diinputkan oleh user
            case 10:
                cout << "=------------Hapus List------------="<<endl;
                hapuslist_137();
                break;
                // Menu 11 memiliki fungsi untuk menampilkan seluruh data yang telah di tambahkan oleh user
            case 11:
                cout << "------------------------------------------------------------------------------"<<endl;
                cout << "                        Menampilkan Semua data mahasiswa                      "<<endl;
                cout << "------------------------------------------------------------------------------"<<endl;
                cout << "--------------------------------------"<<endl;
                cout << "            Data Mahasiswa            "<<endl;
                cout << "--------------------------------------"<<endl;
                tampilkan_137();
                break;
                // Menu 0 berfungsi untuk menutup atau menghentikan program
            case 0:
                cout << "------------------------------------------"<<endl;
                cout << "            Keluar Dari Program           "<<endl;
                cout << "------------------------------------------"<<endl;
                break;
                // Fungsi apabila user menginputkan angka selain yang ada di menu
            default:
                cout << "----------------------------------------------"<<endl;
                cout << "             Pilihan Tidak Valid              "<<endl;
                cout << "----------------------------------------------"<<endl;
        }
    } while (pilihan_137 != 0);

    return 0;
}