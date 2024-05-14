// Daffa Falih Aqilah
// 2311102137
// S1IF-11-D

#include<iostream>

using namespace std;

// deklarasi struct node
struct node{ // node berisi variabel NamaMahasiswa_137, NIM_137, dan pointer next
    string NamaMahasiswa_137;
    string NIM_137;
    node *next;
};
    node *front; // deklarasi node front
    node *back; // deklarasi node back

// prosedur inisialisasi node front dan back sebagai NULL
void Inisialisasi_137(){ 
    front = NULL;
    back = NULL;
}

// fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty_137(){
    if (front == 0){
        return true; 
    } else {
        return false; 
    }
}

// Prosedur untuk menambahkan data pada antrian
void TambahData_137(string Name_137, string NIM_137){
    node *baru = new node; //tambah node baru
    baru->NamaMahasiswa_137 = Name_137; //node baru berisi nama mahasiswa dan NIM 
    baru->NIM_137 = NIM_137; 
    baru->next = NULL; 
    if(isEmpty_137() == true){ 
        front = back = baru; 
        back->next = NULL; 
    } else if(isEmpty_137() == false){ 
        back->next = baru; //node baru sebagai node selanjutnya dari antrian yang sudah ada
        back = baru; //node baru sebagai back
    }
}

//Prosedur untuk mengurangi antrian 
void KurangiAntrian_137(){
    node *hapus; //inisialisasi node hapus
    if(isEmpty_137() == false){ //jika antrian tidak kosong, maka lanjutkan
        if(front->next != NULL){ //jika node selanjutnya setelah antrian pertama bukan NULL, maka lanjutkan
            hapus = front; //node hapus sebagai front
            front = front->next; //pindahkan front ke node selanjutnya setelah node pertama
            delete hapus; //hapus node pertama
        } else { //jika tidak ada node selanjutnya setelah antrian pertama, maka lanjutkan
            front = back = NULL; //front dan back adalah NULL
        }
    }
}

//Fungsi untuk menghitung jumlah antrian
int HitungAntrian_137(){
    node *hitung; //inisialisasi node hitung
    hitung = front; //node hitung sebagai front
    int jumlah_137 = 0; 
    while(hitung != NULL){ //jika node hitung bukan NULL, maka ulangi
        hitung = hitung->next; //node hitung berlanjut ke node selanjutnya
        jumlah_137++; 
    }
    return jumlah_137; 
}

//Prosedur untuk menghapus seluruh antrian
void HapusAntrian_137(){
    node *hapus, *bantu; //inisialisasi node hapus dan node bantu
    bantu = front; //node bantu sebagai front
    while(bantu != NULL){ 
        hapus = bantu; //node hapus sama dengan node bantu
        bantu = bantu->next; 
        delete hapus; 
    }
    front = back = NULL;
}

void LihatAntrian_137(){
    node *bantu; //node bantu
    bantu = front; 
    if(isEmpty_137() == true){ //jika antrian kosong, maka tampilkan "Antrian kosong!" 
        cout << "Antrian kosong!" << endl; 
    } else if(isEmpty_137() == false){ //jika antrian tidak kosong, maka lanjutkan
        cout << "====Antrian Saat Ini====" << endl; 
        int NomorAntrian_137 = 1; 
        while(bantu != NULL){ //jika node bantu bukan NULL, maka ulangi
            cout << NomorAntrian_137 << ". " << bantu->NamaMahasiswa_137 << " - " << bantu->NIM_137 << endl; 
            bantu = bantu->next; 
            NomorAntrian_137++; //nomor antrian bertambah
        }
    }
    cout << endl;
}

int main(){
    string NamaMahasiswa_137, NIM_137; 
    int Pilih_137; 
    char Yakin_137;
    MenuUtama:
    cout << "=======MENU ANTRIAN MAHASISWA=======" << endl; //Tampilan menu antrian mahasiswa
    cout << "1. Tambah antrian" << endl;
    cout << "2. Kurangi antrian" << endl;
    cout << "3. Hitung jumlah antrian" << endl;
    cout << "4. Hapus antrian" << endl;
    cout << "5. Lihat antrian" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilihan Anda [1-6] = ";
    cin >> Pilih_137;
    cout << endl;
    switch(Pilih_137){ //switch case berdasarkan pilihan user
        case 1: //jika user memilih 1, maka tampilkan menu tambah antrian
            cout << "=====Tambah Antrian=====" << endl;
            cout << "Masukkan nama mahasiswa = ";
            cin >> NamaMahasiswa_137;
            cout << "Masukkan NIM mahasiswa = ";
            cin >> NIM_137;
            TambahData_137(NamaMahasiswa_137, NIM_137); //pemanggilan prosedur TambahData_137 dengan parameter nama mahasiswa dan NIM
            cout << "Data mahasiswa telah tersimpan!" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2: //jika user memilih 2, maka tampilkan menu kurangi antrian
            cout << "====Kurangi Antrian====" << endl;
            if(isEmpty_137() == true){ //Jika antrian kosong, maka tampilkan "Antrian masih kosong!"
                cout << "Antrian masih kosong!" << endl;
            } else { //jika antrian tidak kosong, maka lanjutkan
                cout << "Apakah anda ingin mengurangi antrian (menghapus antrian pertama)? [y/n] = "; //validasi keyakinan user untuk mengurangi antrian
                cin >> Yakin_137;
                if(Yakin_137 == 'y' || Yakin_137 == 'Y'){ //jika user menginputkan y atau Y, maka lanjutkan
                    KurangiAntrian_137(); //pemanggilan prosedur KurangiAntrian_137()
                    cout << "Antrian telah dikurangi" << endl;
                } else if(Yakin_137 == 'n' || Yakin_137 == 'Y'){ //jika user menginputkan n atau N, maka tampilkan "Aksi dibatalkan"
                    cout << "Aksi dibatalkan" << endl;
                }
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 3: //jika user memilih 3, maka tampilkan menu Hitung Jumlah Antrian
            cout << "====Hitung Jumlah Antrian====" << endl;
            cout << "Antrian yang tersimpan saat ini sebanyak " << HitungAntrian_137() << endl; //Pemanggilan fungsi HitungAntrian_137()
            cout << endl;
            goto MenuUtama;
            break;
        case 4: //jika user memilih 4, maka tampilkan menu hapus antrian
            cout << "====Hapus Antrian====" << endl;
            cout << "Apakah Anda yakin untuk menghapus seluruh antrian? [y/n] = "; //validasi keyakinan user untuk menghapus seluruh antrian
            cin >> Yakin_137;
            if(Yakin_137 == 'y' || Yakin_137 == 'Y'){ //jika user menginputkan y atau Y, maka lanjutkan
                HapusAntrian_137(); //pemanggilan prosedur HapusAntrian_137()
                cout << "Antrian telah dihapus" << endl;
            } else if(Yakin_137 == 'n' || Yakin_137 == 'N'){ //jika user menginputkan n atau N, maka tampilkan "Aksi dibatalkan"
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 5: //jika user memilih 5, maka tampilkan antrian
            LihatAntrian_137(); //pemanggilan prosedur LihatAntrian_137()
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "Anda keluar dari program" << endl;
            cout << endl;
            return 0;
            break;
        default: //jika user memilih selain 1-5, maka tampilkan "Pilihan yang anda masukkan salah!"
            cout << "Pilihan yang anda masukkan salah!" << endl;
            cout << endl;
            goto MenuUtama;
        break;
        }
}
