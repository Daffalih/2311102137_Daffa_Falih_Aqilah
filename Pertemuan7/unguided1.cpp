// Daffa Falih Aqilah
// 2311102137
// S1IF-11-D

#include<iostream>

using namespace std;

struct node{ 
    string nama_137;
    node *next;
};
    node *front;  
    node *back; 

void Inisialisasi_137(){ 
    front = NULL;
    back = NULL;
}

bool isEmpty_137(){
    if (front == 0){
        return true; 
    } else {
        return false; 
    }
}

void TambahData_137(string name_137){
    node *baru = new node; 
    baru->nama_137 = name_137; 
    baru->next = NULL; 
    if(isEmpty_137() == true){ 
        front = back = baru; 
        back->next = NULL; 
    } else if(isEmpty_137() == false){ 
        back->next = baru; 
        back = baru; 
    }
}

void KurangiAntrian_137(){
    node *hapus; 
    if(isEmpty_137() == true){ 
        cout << "Antrian masih kosong!" << endl;
    } else if(isEmpty_137() == false){ 
        if(front->next != NULL){ 
            hapus = front; 
            front = front->next;
            delete hapus; 
        } else { 
            front = back = NULL; 
        }
    }
}

int HitungAntrian_137(){
    node *hitung; 
    hitung = front; 
    int jumlah_137 = 0; 
    while(hitung != NULL){ 
        hitung = hitung->next; 
        jumlah_137++; 
    }
    return jumlah_137; 
}

void HapusAntrian_137(){
    node *hapus, *bantu; 
    bantu = front; 
    while(bantu != NULL){ 
        hapus = bantu; 
        bantu = bantu->next; 
        delete hapus; 
    }
    front = back = NULL; 
}

void LihatAntrian_137(){
    node *bantu; 
    bantu = front; 
    if(isEmpty_137() == true){  
        cout << "Antrian kosong!" << endl; 
    } else if(isEmpty_137() == false){ 
        cout << "--- Antrian saat ini ---" << endl;  
        int NomorAntrian_137 = 1; 
        while(bantu != NULL){ 
            cout << NomorAntrian_137 << ". " << bantu->nama_137 << endl; 
            bantu = bantu->next; 
            NomorAntrian_137++; 
        }
    }
    cout << endl;
}

int main(){
    //Menambah 3 data nama kedalam antrian
    TambahData_137("Budi");
    TambahData_137("Andi");
    TambahData_137("Ancika");

    //Menampilkan data yang sudah ditambahkan
    LihatAntrian_137();

    //Mengurangi data
    KurangiAntrian_137();

    //menampilkan data setelah dikurangi
    LihatAntrian_137();

    //Menghapus seluruh antrian
    HapusAntrian_137();

    //menampilkan data setelah dihapus
    LihatAntrian_137();
    
    return 0;
}
