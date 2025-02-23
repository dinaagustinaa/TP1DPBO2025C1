#include <iostream>
#include <string>
#include <list>
#include "Petshop.cpp"

using namespace std;

int main() {
    //Inisialisasi variabel yang dibutuhkan
    int i, n = 0;
    string id, name, category;
    double price;

    //Inisialisasi list/daftar untuk menyimpan data
    list<Petshop> daftar;

    //Masukan jumlah data yang akan diinput
    cout << "Input jumlah data: ";
    cin >> n;
    cin.ignore(); // Membersihkan buffer

    //Looping untuk menginput data
    for(i = 0; i < n; i++) {
        cout << "\nData ke-" << i+1 << endl;
        //Inisialisasi objek Petshop pada setiap proses looping
        cout << "ID: ";
        getline(cin, id);
        cout << "Nama: ";
        getline(cin, name);
        cout << "Kategori: ";
        getline(cin, category);
        cout << "Harga: ";
        cin >> price;
        cin.ignore(); // Membersihkan buffer

        Petshop temp(id, name, category, price); // Menggunakan constructor langsung
        daftar.push_back(temp);
    }

    //Menampilkan data awal
    cout << "\nData yang telah diinput: " << endl;
    i = 0;
    for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++){
        cout << "Data ke-" << i+1 << endl;
        cout << "ID: " << j->getIdProduct() << endl;
        cout << "Name: " << j->getNameProduct() << endl;
        cout << "Category: " << j->getCategoryProduct() << endl;
        cout << "Price: " << j->getPriceProduct() << endl;
        cout << endl;
        i++;
    }
    
    //Fitur yang diinginkan
    char fitur;

    do {
        cout << "\nFitur yang tersedia: " << endl;
        cout << "- V -> Menampilkan semua data" << endl;
        cout << "- C -> Menambahkan data" << endl;
        cout << "- U -> Mengedit data" << endl;
        cout << "- D -> Menghapus data" << endl;
        cout << "- S -> Mencari data sesuai nama produk" << endl;
        cout << "- E -> Keluar (Exit)" << endl;

        //Masukan fitur yang diinginkan
        cout << "Pilih fitur: ";
        cin >> fitur;
        cin.ignore(); // Membersihkan buffer
        
        string target;
        
        //Looping untuk setiap fitur
        if(fitur == 'V') {
            cout << "\nData yang tersedia: " << endl;
            i = 0;
            for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++){
                cout << "Data ke-" << i+1 << endl;
                cout << "ID: " << j->getIdProduct() << endl;
                cout << "Name: " << j->getNameProduct() << endl;
                cout << "Category: " << j->getCategoryProduct() << endl;
                cout << "Price: " << j->getPriceProduct() << endl;
                cout << endl;
                i++;
            }

        } else if(fitur == 'C') {
            cout << "\nMasukkan Data Baru:" << endl;
            cout << "ID: ";
            getline(cin, id);
            cout << "Nama: ";
            getline(cin, name);
            cout << "Kategori: ";
            getline(cin, category);
            cout << "Harga: ";
            cin >> price;
            cin.ignore();

            Petshop temp(id, name, category, price);
            daftar.push_back(temp);

            cout << "Data berhasil ditambahkan" << endl;
            
        } else if(fitur == 'U') {
            cout << "Masukan ID yang akan diupdate: ";
            getline(cin, target);
            bool found = false;
            
            for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++) {
                if(j->getIdProduct() == target) {
                    cout << "\nMasukkan data baru:" << endl;
                    cout << "ID: ";
                    getline(cin, id);
                    cout << "Nama: ";
                    getline(cin, name);
                    cout << "Kategori: ";
                    getline(cin, category);
                    cout << "Harga: ";
                    cin >> price;
                    cin.ignore();

                    j->setIdProduct(id);
                    j->setNameProduct(name);
                    j->setCategoryProduct(category);
                    j->setPriceProduct(price);
                    
                    cout << "Data berhasil diupdate" << endl;
                    found = true;
                    
                }
            }
            if (!found) {
                cout << "ID tidak ditemukan" << endl;
            }
            
        } else if(fitur == 'D') {
            cout << "Masukan ID Produk yang akan dihapus: ";
            getline(cin, target);
            bool found = false;
            
            for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++) {
                if(j->getIdProduct() == target) {
                    daftar.erase(j);
                    cout << "Data berhasil dihapus" << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "ID tidak ditemukan" << endl;
            }
            
        } else if(fitur == 'S') {
            cout << "Masukan Nama Produk yang akan dicari: ";
            getline(cin, target);
            bool found = false;

            for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++) {
                if(j->getNameProduct() == target) {
                    cout << "\nData ditemukan:" << endl;
                    cout << "ID: " << j->getIdProduct() << endl;
                    cout << "Name: " << j->getNameProduct() << endl;
                    cout << "Category: " << j->getCategoryProduct() << endl;
                    cout << "Price: " << j->getPriceProduct() << endl;
                    found = true;
                    
                }
            }
            if (!found) {
                cout << "Produk tidak ditemukan" << endl;
            }
        }else if(fitur == 'E') {
            cout << "\nProgram selesai" << endl;
            
        } else {
            cout << "Input tidak valid" << endl;
        }
        
    } while (fitur != 'E');

    return 0;
}
