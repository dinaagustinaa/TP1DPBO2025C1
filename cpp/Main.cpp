#include <iostream>
#include <string.h>
#include <list>
#include <vector>
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

    //Looping untuk menginput data
    for(i = 0; i < n; i++){

        //Inisialisasi objek Petshop pada setiap proses looping
        Petshop temp;

        cin >> id >> name >> category >> price;
        temp.setIdProduct(id);
        temp.setNameProduct(name);
        temp.setCategoryProduct(category);
        temp.setPriceProduct(price);

        daftar.push_back(temp);
       
    }

    //Menampilkan data awal
    cout << "Data yang telah diinput: " << '\n';
    i = 0;
    for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++){
        cout << "Data ke-" << i+1 << '\n';
        cout << "ID: " << j->getIdProduct() << '\n';
        cout << "Name: " << j->getNameProduct() << '\n';
        cout << "Category: " << j->getCategoryProduct() << '\n';
        cout << "Price: " << j->getPriceProduct() << '\n';
        cout << '\n';
        i++;
    }
    
    //Query yang diingankan
    char fitur;

    do {
        cout << "Fitur yang tersedia: " << '\n';
        cout << "- V -> Menampilkan semua data" << '\n';
        cout << "- C -> Menambahkan data" << '\n';
        cout << "- U -> Mengedit data" << '\n';
        cout << "- D -> Menghapus data" << '\n';
        cout << "- S -> Mencari data sesuai nama produk" << '\n';
        cout << "- E -> Keluar (Exit)" << '\n';

        //Masukan fitur yang diinginkan
        cout << "Pilih fitur: ";
        cin >> fitur;

        string target;

        if(fitur == 'V'){
            cout << "Data yang tersedia: " << '\n';
            i = 0;

            for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++){
                cout << "Data ke-" << i+1 << '\n';
                cout << "ID: " << j->getIdProduct() << '\n';
                cout << "Name: " << j->getNameProduct() << '\n';
                cout << "Category: " << j->getCategoryProduct() << '\n';
                cout << "Price: " << j->getPriceProduct() << '\n';
                cout << '\n';
                i++;
            }

        }else if(fitur == 'C') {

            cout << "Masukkan Data Baru: ";

            Petshop temp;
            cin >> id >> name >> category >> price;

            temp.setIdProduct(id);
            temp.setNameProduct(name);
            temp.setCategoryProduct(category);
            temp.setPriceProduct(price);

            daftar.push_back(temp);

            cout << "Data berhasil ditambahkan" << '\n';
            
        }else if(fitur == 'U'){
            
            cout << "Masukan ID yang akan diupdate: " << '\n';
            cin >> target;
            for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++){
                
                if((*j).getIdProduct().compare(target) == 0){

                    cout << "Masukkan data baru: ";
                    cin >> id >> name >> category >> price;

                    (*j).setIdProduct(id);
                    (*j).setNameProduct(name);
                    (*j).setCategoryProduct(category);
                    (*j).setPriceProduct(price);
                    
                    cout << "Data berhasil diupdate" << '\n';
                }
            }
            
        }else if(fitur == 'D'){
            
            cout << "Masukan ID Produk yang akan diupdate: " << '\n';
            cin >> target;
            
            for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++){
                
                if((*j).getIdProduct().compare(target) == 0){
                    j = daftar.erase(j);
                    cout << "Data berhasil dihapus" << '\n';
                }
            }
            
        }else if(fitur == 'S'){
            
            cout << "Masukan Nama Produk yang akan dicari: " << '\n';
            cin >> target;

            for(list<Petshop>::iterator j = daftar.begin(); j != daftar.end(); j++){
                if((*j).getNameProduct().compare(target) == 0){
                    Petshop temp = *j;
                    j = daftar.end();
                    cout << "Data ditemukan: " << '\n';
                    cout << "ID: " << j->getIdProduct() << '\n';
                    cout << "Name: " << j->getNameProduct() << '\n';
                    cout << "Category: " << j->getCategoryProduct() << '\n';
                    cout << "Price: " << j->getPriceProduct() << '\n';
                    cout << '\n';
                }
            }
        }
        
    } while (fitur != 'E');

    cout << "Program selesai" << '\n';

    return 0;
    
}