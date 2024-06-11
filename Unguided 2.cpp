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

