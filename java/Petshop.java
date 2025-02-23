// Petshop.java
public class Petshop {
    // Inisialisasi atribut
    private String id;
    private String name;
    private String category;
    private double price;

    // Constructor kosong
    public Petshop() {
        this.id = "";
        this.name = "";
        this.category = "";
        this.price = 0.0;
    }

    // Constructor dengan parameter
    public Petshop(String id, String name, String category, double price) {
        this.id = id;
        this.name = name;
        this.category = category;
        this.price = price;
    }

    // Setter dan Getter ID
    public void setIdProduct(String id) {
        this.id = id;
    }

    public String getIdProduct() {
        return this.id;
    }

    // Setter dan Getter Name
    public void setNameProduct(String name) {
        this.name = name;
    }

    public String getNameProduct() {
        return this.name;
    }

    // Setter dan Getter Category
    public void setCategoryProduct(String category) {
        this.category = category;
    }

    public String getCategoryProduct() {
        return this.category;
    }

    // Setter dan Getter Price
    public void setPriceProduct(double price) {
        this.price = price;
    }

    public double getPriceProduct() {
        return this.price;
    }
}
