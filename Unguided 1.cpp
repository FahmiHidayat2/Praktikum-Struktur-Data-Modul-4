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

