// Daffa Falih Aqilah - 2311102137 - S1IF-11-D

#include <iostream>
using namespace std;

struct Node {
    string nama_138;
    int usia_138;
    Node* next_138;
};

Node* head_138 = nullptr;

void tampilkanList_138() {
    cout << "[ Nama ]" << "\t" << "[ Usia ]" << endl;
    Node* saatIni_138 = head_138;
    while (saatIni_138 != nullptr) {
        cout << saatIni_138->nama_138 << "\t\t" << saatIni_138->usia_138 << endl;
        saatIni_138 = saatIni_138->next_138;
    }
}

void insertDepan_138(string nama_138, int usia_138) {
    Node* baru_138 = new Node;
    baru_138->nama_138 = nama_138;
    baru_138->usia_138 = usia_138;
    baru_138->next_138 = head_138;
    head_138 = baru_138;
}

void insertBelakang_138(string nama_138, int usia_138) {
    Node* baru_138 = new Node;
    baru_138->nama_138 = nama_138;
    baru_138->usia_138 = usia_138;
    baru_138->next_138 = nullptr;
    if (head_138 == nullptr) {
        head_138 = baru_138;
    }
    else {
        Node* temp_138 = head_138;
        while (temp_138->next_138 != nullptr) {
            temp_138 = temp_138->next_138;
        }
        temp_138->next_138 = baru_138;
    }
}

void insertTengah_138(string nama_138, int usia_138, int posisi_138) {
    Node* baru_138 = new Node;
    baru_138->nama_138 = nama_138;
    baru_138->usia_138 = usia_138;
    Node* bantu_138 = head_138;
    for (int i_138 = 1; i_138 < posisi_138 - 1; i_138++) {
        if (bantu_138 != nullptr) {
            bantu_138 = bantu_138->next_138;
        }
    }
    if (bantu_138 != nullptr) {
        baru_138->next_138 = bantu_138->next_138;
        bantu_138->next_138 = baru_138;
    }
}

void hapusData_138(string nama_138) {
    Node* hapus_138 = head_138;
    Node* prev_138 = nullptr;
    while (hapus_138 != nullptr && hapus_138->nama_138 != nama_138) {
        prev_138 = hapus_138;
        hapus_138 = hapus_138->next_138;
    }
    if (hapus_138 == nullptr) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    if (prev_138 == nullptr) {
        head_138 = hapus_138->next_138;
    }
    else {
        prev_138->next_138 = hapus_138->next_138;
    }
    delete hapus_138;
}

void ubahData_138(string nama_138, string newnama_138, int newusia_138) {
    Node* temp_138 = head_138;
    while (temp_138 != nullptr && temp_138->nama_138 != nama_138) {
        temp_138 = temp_138->next_138;
    }
    if (temp_138 != nullptr) {
        temp_138->nama_138 = newnama_138;
        temp_138->usia_138 = newusia_138;
    }
}

void tampilkanData() {
    Node* temp_138 = head_138;
    while (temp_138 != nullptr) {
        cout << temp_138->nama_138 << " " << temp_138->usia_138 << endl;
        temp_138 = temp_138->next_138;
    }
}

int main() {
    insertBelakang_138("Daffa", 19);
    insertBelakang_138("John", 19);
    insertBelakang_138("Jane", 20);
    insertBelakang_138("Michael", 18);
    insertBelakang_138("Yusuke", 19);
    insertBelakang_138("Akechi", 20);
    insertBelakang_138("Hoshino", 18);
    insertBelakang_138("Karin", 18);

    char pilihan_138;
    do {
        cout << "\nMenu:\n";
        cout << "a. Tampilkan data sesuai urutan tersedia (Data pertama adalah nama dan usia pengguna)\n";
        cout << "b. Hapus data Akechi\n";
        cout << "c. Tambahkan data berikut diantara John dan Jane : Futaba 18\n";
        cout << "d. Tambahkan data berikut diawal : igor 20\n";
        cout << "e. Ubah data Michael menjadi : Reyn 18\n";
        cout << "f. Tampilkan seluruh data\n";
        cout << "g. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan_138;

        switch (pilihan_138) {
            case 'a':
                cout << "\nData yang tersedia:\n";
                tampilkanList_138();
                break;
            case 'b':
                hapusData_138("Akechi");
                cout << "Data Akechi berhasil dihapus.\n";
                cout << "\nData yang tersedia setelah penghapusan:\n";
                tampilkanList_138();
                break;
            case 'c':
                insertTengah_138("Futaba", 18, 3); 
                cout << "Data Futaba berhasil ditambahkan.\n";
                cout << "\nData yang tersedia setelah penambahan:\n";
                tampilkanList_138();
                break;
            case 'd':
                insertDepan_138("Igor", 20);
                cout << "Data Igor berhasil ditambahkan di awal.\n";
                cout << "\nData yang tersedia setelah penambahan:\n";
                tampilkanList_138();
                break;
            case 'e':
                ubahData_138("Michael", "Reyn", 18);
                cout << "Data Michael berhasil diubah menjadi Reyn 18.\n";
                cout << "\nData yang tersedia setelah perubahan:\n";
                tampilkanList_138();
                break;
            case 'f':
                cout << "\nTampilan seluruh data sekarang:\n";
                tampilkanList_138();
                break;
            case 'g':
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                break;
        }
    } while (pilihan_138 != 'g');

    return 0;
}
