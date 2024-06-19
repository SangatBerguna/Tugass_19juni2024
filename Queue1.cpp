#include <iostream>
using namespace std;

struct DaftarTugas {
    string namaTugas;
    int nomorTugas;
    string deadlineTugas;
};

// array Antrian
int maksimalAntrianArray = 3, front = 0, back = 0;
// ruang antrian array
DaftarTugas antrianTugas[3];

// isFull / cek data antrian penuh atau tidak
bool isFull() {
    return back == maksimalAntrianArray;
}

// isEmpty
bool isEmpty() {
    return back == 0;
}

// tambahtugas / penambahan data antrian
void tambahtugas(DaftarTugas data) {
    if (isFull()) {
        cout << "Antrian penuh!!" << endl;
    } else {
        antrianTugas[back] = data;
        back++;
    }
}

// hapustugasawal / penghapusan data depan
void hapustugasawal() {
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            antrianTugas[i] = antrianTugas[i + 1];
        }
        back--;
    }
}

// menghitung / menghitung banyak data yg ngantri
int menghitung() {
    return back;
}

// hapustugas / clear
void hapustugas() {
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        back = 0;
        front = 0;
    }
}

// cetaktugas / View
void cetaktugas() {
    cout << "Jumlah tugas yang ngantri : " << menghitung() << " tugas." << endl;
    cout << "Data Antrian Tugas : " << endl;
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        for (int i = 0; i < maksimalAntrianArray; i++) {
            // cek apakah ruang kosong atau tidak
            if (i < back) {
                cout << i + 1 << ". " << antrianTugas[i].namaTugas << " - " << antrianTugas[i].nomorTugas << " - " << antrianTugas[i].deadlineTugas << endl;
            } else {
                cout << i + 1 << ". (kosong)" << endl;
            }
        }
    }
    cout << "\n" << endl;
}

int main() {
    DaftarTugas tugas1 = {"Tugas1", 1, "2024-06-01"};
    DaftarTugas tugas2 = {"Tugas2", 2, "2024-06-02"};
    DaftarTugas tugas3 = {"Tugas3", 3, "2024-06-03"};
    DaftarTugas tugas4 = {"Tugas4", 4, "2024-06-04"};
    DaftarTugas tugas5 = {"Tugas5", 5, "2024-06-05"};

    tambahtugas(tugas1);
    cetaktugas();

    tambahtugas(tugas2);
    tambahtugas(tugas3);
    tambahtugas(tugas4);
    tambahtugas(tugas5);
    cetaktugas();

    DaftarTugas tugas6 = {"Tugas6", 6, "2024-06-06"};
    tambahtugas(tugas6);
    cetaktugas();

    hapustugasawal();
    cetaktugas();

    hapustugas();
    cetaktugas();

    cout << "Jumlah tugas dalam antrian: " << menghitung() << endl;

    return 0;
}