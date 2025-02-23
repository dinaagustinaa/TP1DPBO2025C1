#include <iostream>
#include <string>

using namespace std;

class Petshop {

    //Inisialisasi atribut yang dibutuhkan
    private:
    string id;
    string name;
    string category;
    double price;

    public:
    Petshop() {
        //Constructor
        this->id = "";
        this->name = "";
        this->category = "";
        this->price = price;
    }   

    //Inisialisasi method yang dibutuhkan
    Petshop(string id, string name, string category, double price) {
        this->id = id;
        this->name = name;
        this->category = category;
        this->price = price;
    }

    //Setter dan Getter ID
    void setIdProduct(string id) {
        this->id = id;
    }

    string getIdProduct() {
        return this->id;
    }

    //Setter dan Getter Name
    void setNameProduct(string name) {
        this->name = name;
    }
    
    string getNameProduct() {
        return this->name; 
    }

    //Setter dan Getter Category
    void setCategoryProduct(string category) {
        this->category = category;
    }

    string getCategoryProduct() {
        return this->category;
    }

    //Setter dan Getter Price
    void setPriceProduct(double price) {
        this->price = price;
    }
    
    double getPriceProduct() {
        return this->price;
    }

    //Destructor
    ~Petshop() {
    }

};