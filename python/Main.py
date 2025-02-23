# main.py
from petshop import Petshop

def main():
    # Inisialisasi list untuk menyimpan data
    daftar = []

    # Input jumlah data
    n = int(input("Input jumlah data: "))

    # Looping untuk input data
    for i in range(n):
        print(f"\nData ke-{i+1}")
        id = input("ID: ")
        name = input("Nama: ")
        category = input("Kategori: ")
        price = float(input("Harga: "))

        temp = Petshop(id, name, category, price)
        daftar.append(temp)

    # Tampilkan data awal
    print("\nData yang telah diinput:")
    for i, p in enumerate(daftar):
        print(f"Data ke-{i+1}")
        print(f"ID: {p.get_id_product()}")
        print(f"Name: {p.get_name_product()}")
        print(f"Category: {p.get_category_product()}")
        print(f"Price: {p.get_price_product()}")
        print()

    # Menu fitur
    while True:
        print("\nFitur yang tersedia:")
        print("- V -> Menampilkan semua data")
        print("- C -> Menambahkan data")
        print("- U -> Mengedit data")
        print("- D -> Menghapus data")
        print("- S -> Mencari data sesuai nama produk")
        print("- E -> Keluar (Exit)")

        fitur = input("Pilih fitur: ").upper()

        if fitur == 'V':
            print("\nData yang tersedia:")
            for i, p in enumerate(daftar):
                print(f"Data ke-{i+1}")
                print(f"ID: {p.get_id_product()}")
                print(f"Name: {p.get_name_product()}")
                print(f"Category: {p.get_category_product()}")
                print(f"Price: {p.get_price_product()}")
                print()

        elif fitur == 'C':
            print("\nMasukkan Data Baru:")
            id = input("ID: ")
            name = input("Nama: ")
            category = input("Kategori: ")
            price = float(input("Harga: "))

            daftar.append(Petshop(id, name, category, price))
            print("Data berhasil ditambahkan")

        elif fitur == 'U':
            target = input("Masukan ID yang akan diupdate: ")
            found = False

            for p in daftar:
                if p.get_id_product() == target:
                    print("\nMasukkan data baru:")
                    id = input("ID: ")
                    name = input("Nama: ")
                    category = input("Kategori: ")
                    price = float(input("Harga: "))

                    p.set_id_product(id)
                    p.set_name_product(name)
                    p.set_category_product(category)
                    p.set_price_product(price)

                    print("Data berhasil diupdate")
                    found = True
                    break

            if not found:
                print("ID tidak ditemukan")

        elif fitur == 'D':
            target = input("Masukan ID Produk yang akan dihapus: ")
            found = False

            for i, p in enumerate(daftar):
                if p.get_id_product() == target:
                    daftar.pop(i)
                    print("Data berhasil dihapus")
                    found = True
                    break

            if not found:
                print("ID tidak ditemukan")

        elif fitur == 'S':
            target = input("Masukan Nama Produk yang akan dicari: ")
            found = False

            for p in daftar:
                if p.get_name_product() == target:
                    print("\nData ditemukan:")
                    print(f"ID: {p.get_id_product()}")
                    print(f"Name: {p.get_name_product()}")
                    print(f"Category: {p.get_category_product()}")
                    print(f"Price: {p.get_price_product()}")
                    found = True
                    break

            if not found:
                print("Produk tidak ditemukan")

        elif fitur == 'E':
            break

    print("\nProgram selesai")

if __name__ == "__main__":
    main()
