#include <iostream>

using namespace std;

// Fungsi untuk menghitung berapa kali angka 4 muncul dalam data menggunakan Sequential Search
int hitungAngkaEmpat(int data[], int panjangData) {
    int jumlahEmpat = 0;

    // Melintasi setiap elemen dalam data
    for (int i = 0; i < panjangData; ++i) {
        // Jika elemen saat ini adalah angka 4, tambahkan ke jumlahEmpat
        if (data[i] == 4) {
            jumlahEmpat++;
        }
    }

    return jumlahEmpat;
}

int main() {
    // Data yang diberikan
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int panjangData = sizeof(data) / sizeof(data[0]);

    // Memanggil fungsi untuk menghitung berapa kali angka 4 muncul dalam data
    int jumlahEmpat = hitungAngkaEmpat(data, panjangData);

    // Menampilkan hasil
    cout << "Banyaknya angka 4 dalam data adalah: " << jumlahEmpat << endl;

    return 0;
}

