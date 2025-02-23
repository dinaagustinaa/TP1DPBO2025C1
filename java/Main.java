// Main.java
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Inisialisasi variabel
        int i, n = 0;
        String id, name, category;
        double price;
        Scanner scan = new Scanner(System.in);

        // Inisialisasi list untuk menyimpan data
        LinkedList<Petshop> daftar = new LinkedList<>();

        // Input jumlah data
        System.out.print("Input jumlah data: ");
        n = scan.nextInt();
        scan.nextLine(); // Clear buffer

        // Looping untuk input data
        for (i = 0; i < n; i++) {
            System.out.println("\nData ke-" + (i+1));
            System.out.print("ID: ");
            id = scan.nextLine();
            System.out.print("Nama: ");
            name = scan.nextLine();
            System.out.print("Kategori: ");
            category = scan.nextLine();
            System.out.print("Harga: ");
            price = scan.nextDouble();
            scan.nextLine(); // Clear buffer

            Petshop temp = new Petshop(id, name, category, price);
            daftar.add(temp);
        }

        // Tampilkan data awal
        System.out.println("\nData yang telah diinput:");
        i = 0;
        for (Petshop p : daftar) {
            System.out.println("Data ke-" + (i+1));
            System.out.println("ID: " + p.getIdProduct());
            System.out.println("Name: " + p.getNameProduct());
            System.out.println("Category: " + p.getCategoryProduct());
            System.out.println("Price: " + p.getPriceProduct());
            System.out.println();
            i++;
        }

        // Menu fitur
        char fitur;
        do {
            System.out.println("\nFitur yang tersedia:");
            System.out.println("- V -> Menampilkan semua data");
            System.out.println("- C -> Menambahkan data");
            System.out.println("- U -> Mengedit data");
            System.out.println("- D -> Menghapus data");
            System.out.println("- S -> Mencari data sesuai nama produk");
            System.out.println("- E -> Keluar (Exit)");

            System.out.print("Pilih fitur: ");
            fitur = scan.next().charAt(0);
            scan.nextLine(); // Clear buffer

            String target;

            switch (fitur) {
                case 'V':
                    System.out.println("\nData yang tersedia:");
                    i = 0;
                    for (Petshop p : daftar) {
                        System.out.println("Data ke-" + (i+1));
                        System.out.println("ID: " + p.getIdProduct());
                        System.out.println("Name: " + p.getNameProduct());
                        System.out.println("Category: " + p.getCategoryProduct());
                        System.out.println("Price: " + p.getPriceProduct());
                        System.out.println();
                        i++;
                    }
                    break;

                case 'C':
                    System.out.println("\nMasukkan Data Baru:");
                    System.out.print("ID: ");
                    id = scan.nextLine();
                    System.out.print("Nama: ");
                    name = scan.nextLine();
                    System.out.print("Kategori: ");
                    category = scan.nextLine();
                    System.out.print("Harga: ");
                    price = scan.nextDouble();
                    scan.nextLine(); // Clear buffer

                    daftar.add(new Petshop(id, name, category, price));
                    System.out.println("Data berhasil ditambahkan");
                    break;

                case 'U':
                    System.out.print("Masukan ID yang akan diupdate: ");
                    target = scan.nextLine();
                    boolean foundUpdate = false;

                    for (Petshop p : daftar) {
                        if (p.getIdProduct().equals(target)) {
                            System.out.println("\nMasukkan data baru:");
                            System.out.print("ID: ");
                            id = scan.nextLine();
                            System.out.print("Nama: ");
                            name = scan.nextLine();
                            System.out.print("Kategori: ");
                            category = scan.nextLine();
                            System.out.print("Harga: ");
                            price = scan.nextDouble();
                            scan.nextLine(); // Clear buffer

                            p.setIdProduct(id);
                            p.setNameProduct(name);
                            p.setCategoryProduct(category);
                            p.setPriceProduct(price);

                            System.out.println("Data berhasil diupdate");
                            foundUpdate = true;
                            break;
                        }
                    }
                    if (!foundUpdate) {
                        System.out.println("ID tidak ditemukan");
                    }
                    break;

                case 'D':
                    System.out.print("Masukan ID Produk yang akan dihapus: ");
                    target = scan.nextLine();
                    boolean foundDelete = false;

                    for (i = 0; i < daftar.size(); i++) {
                        if (daftar.get(i).getIdProduct().equals(target)) {
                            daftar.remove(i);
                            System.out.println("Data berhasil dihapus");
                            foundDelete = true;
                            break;
                        }
                    }
                    if (!foundDelete) {
                        System.out.println("ID tidak ditemukan");
                    }
                    break;

                case 'S':
                    System.out.print("Masukan Nama Produk yang akan dicari: ");
                    target = scan.nextLine();
                    boolean foundSearch = false;

                    for (Petshop p : daftar) {
                        if (p.getNameProduct().equals(target)) {
                            System.out.println("\nData ditemukan:");
                            System.out.println("ID: " + p.getIdProduct());
                            System.out.println("Name: " + p.getNameProduct());
                            System.out.println("Category: " + p.getCategoryProduct());
                            System.out.println("Price: " + p.getPriceProduct());
                            foundSearch = true;
                            break;
                        }
                    }
                    if (!foundSearch) {
                        System.out.println("Produk tidak ditemukan");
                    }
                    break;
            }
        } while (fitur != 'E');

        System.out.println("\nProgram selesai");
        scan.close();
    }
}
