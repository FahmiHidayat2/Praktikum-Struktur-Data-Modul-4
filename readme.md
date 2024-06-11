# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Fahmi Hidayat</p>

## Dasar Teori

Algoritma searching adalah adalah suatu prosedur atau langkah-langkah yang digunakan untuk menemukan lokasi atau keberadaan suatu elemen tertentu dalam sebuah kumpulan data. Ini bisa berupa array, list, atau struktur data lainnya [1]. Algoritma pencarian merupakan bagian penting dalam ilmu komputer dan digunakan dalam berbagai aplikasi, mulai dari pencarian data dalam basis data hingga operasi pencarian dalam algoritma pemrosesan teks.

### 1. Linear Search
Linear search adalah metode pencarian yang paling sederhana. Pada linear search, pencarian dilakukan dengan memeriksa setiap elemen dalam struktur data satu per satu sampai elemen yang dicari ditemukan atau seluruh elemen telah diperiksa. Metode ini tidak memerlukan data terurut dan dapat diterapkan pada struktur data apa pun.

Kelebihan Linear Search:

Sederhana dan mudah diimplementasikan.
Tidak memerlukan data terurut.
Kekurangan Linear Search:

Tidak efisien untuk struktur data yang besar karena memerlukan waktu pencarian yang linier (O(n)).
Performa menurun seiring dengan bertambahnya jumlah elemen.
### 2. Binary Search
Binary search adalah metode pencarian yang lebih efisien dibandingkan linear search. Namun, binary search hanya dapat diterapkan pada data yang sudah terurut. Metode ini bekerja dengan membagi struktur data menjadi dua bagian yang sama besar dan membandingkan elemen tengah dengan elemen yang dicari. Jika elemen tengah bukan elemen yang dicari, maka pencarian dilanjutkan pada salah satu bagian (kiri atau kanan) yang masih relevan. Proses ini berulang sampai elemen yang dicari ditemukan atau sub-bagian yang relevan menjadi kosong.

Kelebihan Binary Search:

Sangat efisien untuk data yang besar karena memerlukan waktu pencarian logaritmik (O(log n)).
Performa yang baik untuk data yang sudah terurut.
Kekurangan Binary Search:

Hanya dapat diterapkan pada data yang sudah terurut.
Implementasi lebih kompleks dibandingkan linear search.
## Guided 
### 1. Sequential Search
```c++
// Guided 1
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu) {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
```

### 2. Binary Search
```c++
// Guided 2

#include <iostream>
#include <iomanip>

using namespace std;

int bil_data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(bil_data[j] < bil_data[min]) {
                min = j;
            }
        }
        temp = bil_data[i];
        bil_data[i] = bil_data[min];
        bil_data[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(bil_data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(bil_data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main() {
    cout << "\t BINARY SEARCH\n";
    cout << "\n Data : ";
    // tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    binary_search();
    return 0;
}
```

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk melakukan binary search pada array karakter
int binarySearch(char arr[], int left, int right, char x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Memeriksa apakah x adalah elemen tengah
        if (arr[mid] == x)
            return mid;

        // Jika x lebih besar, maka x hanya bisa berada di subarray kanan
        if (arr[mid] < x)
            left = mid + 1;

        // Jika x lebih kecil, maka x hanya bisa berada di subarray kiri
        else
            right = mid - 1;
    }

    // Jika elemen tidak ditemukan
    return -1;
}

int main() {
    string kalimat;
    char huruf;

    // Input kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Input huruf yang akan dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Mengubah kalimat menjadi array karakter
    int n = kalimat.length();
    char arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = kalimat[i];
    }

    // Mengurutkan array karakter
    sort(arr, arr + n);

    // Menampilkan array yang telah diurutkan
    cout << "Kalimat yang telah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;

    // Melakukan binary search untuk mencari huruf
    int result = binarySearch(arr, 0, n - 1, huruf);

    // Menampilkan hasil pencarian
    if (result != -1)
        cout << "Huruf '" << huruf << "' ditemukan pada indeks " << result << " dalam array yang diurutkan." << endl;
    else
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;

    return 0;
}
```
Program ini bertujuan untuk mencari sebuah huruf dalam kalimat yang diinput oleh pengguna menggunakan algoritma Binary Search. Pertama, pengguna diminta untuk memasukkan sebuah kalimat dan huruf yang ingin dicari. Kalimat ini kemudian diubah menjadi sebuah array karakter. Agar Binary Search dapat diterapkan, array karakter ini harus diurutkan terlebih dahulu menggunakan fungsi `sort` dari pustaka algoritma C++. Setelah array diurutkan, program menggunakan fungsi `binarySearch` untuk mencari indeks huruf yang dicari. Fungsi ini bekerja dengan cara membagi array menjadi dua bagian dan membandingkan elemen tengah dengan huruf yang dicari. Jika elemen tengah adalah huruf yang dicari, indeks elemen tersebut dikembalikan. Jika huruf yang dicari lebih besar dari elemen tengah, pencarian dilanjutkan pada subarray kanan; jika lebih kecil, pencarian dilanjutkan pada subarray kiri. Proses ini diulang sampai huruf ditemukan atau subarray menjadi kosong. Hasil pencarian kemudian ditampilkan: jika huruf ditemukan, indeksnya dalam array yang diurutkan akan ditampilkan, sedangkan jika tidak ditemukan, pesan yang sesuai akan ditampilkan. Program ini menekankan pentingnya pengurutan data sebelum melakukan pencarian biner untuk memastikan hasil pencarian yang akurat.
#### Output:
<img width="439" alt="image" src="https://github.com/FahmiHidayat2/Praktikum-Struktur-Data-Modul-4/assets/161399477/6968cc73-24d8-4fc4-8f24-725fe26008f9">

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!
```c++
#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk menghitung jumlah dan frekuensi huruf vokal dalam sebuah kalimat
int hitungVokal_030(string kalimat_030, int frekuensiVokal_030[]) {
    int jumlahVokal_030 = 0;

    // Inisialisasi frekuensi setiap huruf vokal dengan 0
    for (int i_030 = 0; i_030 < 5; ++i_030) {
        frekuensiVokal_030[i_030] = 0;
    }

    // Melakukan iterasi untuk setiap karakter dalam kalimat
    for (size_t i_030 = 0; i_030 < kalimat_030.length(); ++i_030) {
        char karakter_030 = kalimat_030[i_030];
        // Mengecek apakah karakter adalah huruf vokal
        if (karakter_030 == 'a' || karakter_030 == 'A') {
            frekuensiVokal_030[0]++;
            jumlahVokal_030++;
        } else if (karakter_030 == 'i' || karakter_030 == 'I') {
            frekuensiVokal_030[1]++;
            jumlahVokal_030++;
        } else if (karakter_030 == 'u' || karakter_030 == 'U') {
            frekuensiVokal_030[2]++;
            jumlahVokal_030++;
        } else if (karakter_030 == 'e' || karakter_030 == 'E') {
            frekuensiVokal_030[3]++;
            jumlahVokal_030++;
        } else if (karakter_030 == 'o' || karakter_030 == 'O') {
            frekuensiVokal_030[4]++;
            jumlahVokal_030++;
        }
    }

    return jumlahVokal_030;
}

int main() {
    string kalimat_030;
    int frekuensiVokal_030[5] = {0}; // Array untuk menyimpan frekuensi kemunculan masing-masing huruf vokal

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat_030);

    // Memanggil fungsi untuk menghitung jumlah dan frekuensi huruf vokal dalam kalimat
    int jumlahVokal_030 = hitungVokal_030(kalimat_030, frekuensiVokal_030);

    cout << "Frekuensi kemunculan masing-masing huruf vokal:" << endl;
    cout << "'a': " << frekuensiVokal_030[0] << endl;
    cout << "'i': " << frekuensiVokal_030[1] << endl;
    cout << "'u': " << frekuensiVokal_030[2] << endl;
    cout << "'e': " << frekuensiVokal_030[3] << endl;
    cout << "'o': " << frekuensiVokal_030[4] << endl;
    cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahVokal_030 << endl;
    
    cout << "" << endl;
    cout << "" << endl;

    return 0;
}
```
kode diatas adalah contoh program yang menghitung jumlah dan frekuensi kemunculan huruf vokal dalam sebuah kalimat.
Program dimulai dengan mendeklarasikan sebuah string kalimat_030 yang akan digunakan untuk menyimpan input kalimat dari pengguna. Selanjutnya, sebuah array frekuensiVokal_030 dengan panjang 5 digunakan untuk menyimpan frekuensi kemunculan masing-masing huruf vokal (a, i, u, e, o). Fungsi hitungVokal_030() dibuat untuk menghitung jumlah dan frekuensi huruf vokal dalam kalimat yang diberikan. Di dalam fungsi hitungVokal_030(), dilakukan iterasi untuk setiap karakter dalam kalimat. Setiap karakter diuji untuk menentukan apakah itu adalah huruf vokal. Jika iya, maka frekuensi kemunculan huruf vokal tersebut diinkremen dan jumlah huruf vokal juga ditambah. Setelah iterasi selesai, fungsi mengembalikan jumlah total huruf vokal dalam kalimat. Di dalam fungsi main(), program meminta pengguna untuk memasukkan sebuah kalimat. Kemudian, program memanggil fungsi hitungVokal_030() untuk menghitung jumlah dan frekuensi huruf vokal dalam kalimat tersebut. Setelah perhitungan selesai, program menampilkan frekuensi kemunculan masing-masing huruf vokal, serta jumlah total huruf vokal dalam kalimat.

#### output :
<img width="386" alt="image" src="https://github.com/FahmiHidayat2/Praktikum-Struktur-Data-Modul-4/assets/161399477/c4917159-86c8-4d48-8c98-445368727437">

### 3. . Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!
```c++
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
```
Penjelasan:

Fungsi hitungAngkaEmpat mengiterasi melalui setiap elemen dalam array data dan menghitung berapa kali angka 4 muncul. Pada setiap iterasi, jika elemen saat ini adalah angka 4, kita tambahkan 1 ke jumlahEmpat. Fungsi main digunakan untuk memanggil fungsi hitungAngkaEmpat dengan data yang diberikan dan menampilkan hasilnya.
Hasil dari program ini akan menampilkan jumlah kemunculan angka 4 dalam data yang diberikan.
#### output :
<img width="443" alt="image" src="https://github.com/FahmiHidayat2/Praktikum-Struktur-Data-Modul-4/assets/161399477/054bd87f-d695-4b67-be4f-c0aca9623083">



## Kesimpulan
Dalam praktikum ini, kami menjelaskan dua algoritma pencarian: Linear Search dan Binary Search. Linear Search adalah metode sederhana yang memeriksa setiap elemen dalam urutan tertentu hingga elemen yang dicari ditemukan atau semua elemen telah diperiksa. Di sisi lain, Binary Search merupakan metode pencarian yang lebih efisien untuk data yang sudah terurut. Ini bekerja dengan membagi data menjadi dua bagian dan memeriksa elemen tengah untuk menentukan di mana elemen yang dicari berada, mengurangi jumlah langkah yang dibutuhkan untuk menemukannya. Dalam praktikum ini, kami juga menyajikan contoh program dalam bahasa C++ untuk menerapkan kedua algoritma pencarian ini.

## Referensi
[1] Robert Sedgewick and Kevin Wayne, "Algorithms 4th Edition", Addison Wesley, 2011.
