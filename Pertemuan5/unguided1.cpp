// Daffa Falih Aqilah - 2311102137 - S1IF-11-D

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Mahasiswa{
    string nama_137;
    string nim_137;
    int nilai_137;
};

struct HashNode{
    Mahasiswa data;
    HashNode* next;
    HashNode(const Mahasiswa& data) : data(data), next(nullptr){}
};

class HashTable{
    private:
    static const int TABLE_SIZE = 10;
    vector<HashNode*>table[TABLE_SIZE];

    int hashFunc_137(const string& nim_137){
        int hashVal = 0;
        for(char c : nim_137){
            hashVal += c;
        }
        return hashVal % TABLE_SIZE;
    }

    public:
    void insert_137(const Mahasiswa& mahasiswa){
        int index = hashFunc_137(mahasiswa.nim_137);
        HashNode* newNode = new HashNode(mahasiswa);
        newNode->next = table[index].size() > 0 ? table[index][0] : nullptr;
        table[index].insert(table[index].begin(),newNode);
    }
    void hapus_137(const string& nim){
        int index = hashFunc_137(nim);
        for(size_t i=0; i<table[index].size(); i++){
            if(table[index][i]->data.nim_137 == nim){
                delete table[index][i];
                table[index].erase(table[index].begin()+i);
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak dapat ditemukan " <<endl;
    }

    Mahasiswa* searchByNIM(const string& nim){
        int index = hashFunc_137(nim);
        for(size_t i = 0; i <table[index].size(); i++){
            if(table[index][i]->data.nim_137 == nim){
                return &(table[index][i]->data);
            }
        }
        return nullptr;
    }

    vector<Mahasiswa*> searchBYRange(int minNilai, int maxNilai){
        vector<Mahasiswa*> result;
        for(int i = 0; i < TABLE_SIZE; i++){
            for(size_t j = 0; j < table[i].size(); j++){
                if(table[i][j]->data.nilai_137 >= minNilai && table[i][j]->data.nilai_137 <= maxNilai){
                    result.push_back(&(table[i][j]->data));
                }
            }
        }
        return result;
    }

    void tampilkan_137(){
        cout << "Data Mahasiswa yang ada dalam Hash Table : "<<endl;
        for(int i = 0; i < TABLE_SIZE; i++){
            for (size_t j = 0; j < table[i].size(); j++){
                Mahasiswa* mhs = &(table[i][j]->data);
                cout << "Nama Mahasiswa: " << mhs->nama_137 << "\tNIM: " << mhs->nim_137 << "\tNilai: " << mhs->nilai_137 << endl;
            }
        }
    }

};

int main(){
    HashTable hashTable_137;
    int pilih_;

    menu:
    cout << "================================" <<endl;
    cout << "- Program Hash Table Mahasiswa -" <<endl;
    cout << "================================" <<endl;
    cout << "1. Tambah data Mahasiswa"<<endl;
    cout << "2. Hapus data Mahasiswa"<<endl;
    cout << "3. Cari data Mahasiswa berdasarkan NIM"<<endl;
    cout << "4. Cari data Mahasiswa berdsarkan rentang nilai"<<endl;
    cout << "5. Tampilkan semua data"<<endl;
    cout << "6. Keluar"<<endl;
    cout << "Pilih menu diatas : "; cin >> pilih_137;
    cout << endl;

    switch(pilih_137){
        case 1 :{
            Mahasiswa mhs;
            cout << "=========================" <<endl;
            cout << "- TAMBAH DATA MAHASISWA -" <<endl;
            cout << "=========================" <<endl;
            cout << "Masukkan Nama Mahasiswa : ";
            cin >> mhs.nama_137;
            cout << "Masukkan NIM Mahasiswa : ";
            cin >> mhs.nim_137;
            cout << "Masukkan Nilai Mahasiswa : ";
            cin >> mhs.nilai_137;
            hashTable_137.insert_137(mhs);
            goto menu;
            break;
        }
        case 2 :{
            string nim;
            cout << "========================" <<endl;
            cout << "- HAPUS DATA MAHASISWA -" <<endl;
            cout << "========================" <<endl;
            cout << "Masukkan NIM untuk menghapus data Mahasiswa : ";
            cin >> nim;
            hashTable_137.hapus_137(nim);
            cout << "Data Mahasiswa dengan NIM " << nim << " telah dihapus"<<endl;
            goto menu;
            break;
        }
        case 3 :{
            string nim;
            cout << "=======================================" <<endl;
            cout << "- CARI DATA MAHASISWA BERDASARKAN NIM -" <<endl;
            cout << "=======================================" <<endl;
            cout << "Masukkan NIM untuk mencari data Mahasiswa: ";
            cin >> nim;
            Mahasiswa* result = hashTable_137.searchByNIM(nim);
            if(result != nullptr){
                cout << "Data ditemukan!!"<<endl;
                cout << "Nama: " << result->nama_137 << "\nNIM: " << result->nim_137 << "\nNilai: " << result->nilai_137 <<endl;
            }else{
                cout << "Data mahasiswa dengan NIM " << nim << "Tidak dapat ditemukan"<<endl;
            }
            goto menu;
            break;
        }
        case 4 :{
            int minNilai , maxNilai ;
            cout << "============================================" <<endl;
            cout << "- Tentukan Rentang Nilai Yang Ingin Dicari -" <<endl;
            cout << "============================================" <<endl;
            cout << "Nilai minimal : "; cin >> minNilai;
            cout << "Nilai maksimal : "; cin >> maxNilai;
            cout << "Rentang nilai yang dicari " << minNilai << " sampai " << maxNilai << endl;
            vector<Mahasiswa*> result = hashTable_137.searchBYRange(minNilai, maxNilai);
            if(result.size() > 0){
                cout << "Data mahasiswa dalam rentang nilai " << minNilai << " hingga " << maxNilai << ":\n";
                for(Mahasiswa* mhs : result){
                    cout << "Nama Mahasiswa: " << mhs->nama_137 << "\tNIM: " << mhs->nim_137 << "\tNilai: "<< mhs->nilai_137 <<endl;
                }
            }else{
                cout << "Tidak ada Mahasiswa dalam rentang nilai tersebut "<<endl;
            }
            goto menu;
            break;
        }
        case 5 :{
            hashTable_137.tampilkan_137();
            goto menu;
            break;
        }
        case 6 :
            cout << "Anda keluar dari program!"<<endl;
            break;
        default :
            cout << "Pilihan anda tidak ada didalam menu "<<endl;
            goto menu;
    }
    return 0;
}