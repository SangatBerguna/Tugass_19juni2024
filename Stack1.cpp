#include <iostream>
using namespace std;

// Stack Linked List menggunakan struct
struct DaftarTugas {
    string namaTugas;
    int nomorTugas;
    string batasWaktuTugas;

    DaftarTugas* prev;
    DaftarTugas* next;
};

DaftarTugas* head = nullptr;
DaftarTugas* tail = nullptr;
DaftarTugas* cur = nullptr;
DaftarTugas* newNode = nullptr;
DaftarTugas* del = nullptr;

int maksimalTugas = 5;

// Fungsi untuk menghitung jumlah tugas dalam stack
int countTugas() {
    if (head == nullptr) {
        return 0;
    } else {
        int banyak = 0;
        cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

// Cek apakah stack penuh
bool isFullTugas() {
    return countTugas() == maksimalTugas;
}

// Cek apakah stack kosong
bool isEmptyTugas() {
    return countTugas() == 0;
}

// Menambahkan tugas ke dalam stack
void pushTugas(string namaTugas, int nomorTugas, string batasWaktuTugas) {
    if (isFullTugas()) {
        cout << "Stack penuh!" << endl;
    } else {
        if (isEmptyTugas()) {
            head = new DaftarTugas();
            head->namaTugas = namaTugas;
            head->nomorTugas = nomorTugas;
            head->batasWaktuTugas = batasWaktuTugas;
            head->prev = nullptr;
            head->next = nullptr;
            tail = head;
        } else {
            newNode = new DaftarTugas();
            newNode->namaTugas = namaTugas;
            newNode->nomorTugas = nomorTugas;
            newNode->batasWaktuTugas = batasWaktuTugas;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }
    }
}

// Menghapus tugas dari stack
void popTugas() {
    if (isEmptyTugas()) {
        cout << "Stack kosong!" << endl;
    } else {
        del = tail;
        if (tail->prev != nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = nullptr;
            tail = nullptr;
        }
        delete del;
    }
}

// Menampilkan tugas dalam stack
void displayTugas() {
    if (isEmptyTugas()) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "\nData tugas dalam stack:" << endl;
        cur = tail;
        while (cur != nullptr) {
            cout << "Nama Tugas: " << cur->namaTugas << ", Nomor Tugas: " << cur->nomorTugas << ", Batas Waktu Tugas: " << cur->batasWaktuTugas << endl;
            cur = cur->prev;
        }
    }
}

// Mengintip tugas pada posisi tertentu
void peekTugas(int posisi) {
    if (isEmptyTugas()) {
        cout << "Stack kosong!" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi && cur != nullptr) {
            cur = cur->prev;
            nomor++;
        }
        if (cur != nullptr) {
            cout << "Tugas pada posisi ke-" << posisi << ": " << cur->namaTugas << ", Nomor Tugas: " << cur->nomorTugas << ", Batas Waktu Tugas: " << cur->batasWaktuTugas << endl;
        } else {
            cout << "Posisi tugas tidak valid!" << endl;
        }
    }
}

// Mengubah tugas pada posisi tertentu
void changeTugas(string namaTugas, int nomorTugas, string batasWaktuTugas, int posisi) {
    if (isEmptyTugas()) {
        cout << "Stack kosong!" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi && cur != nullptr) {
            cur = cur->prev;
            nomor++;
        }
        if (cur != nullptr) {
            cur->namaTugas = namaTugas;
            cur->nomorTugas = nomorTugas;
            cur->batasWaktuTugas = batasWaktuTugas;
        } else {
            cout << "Posisi tugas tidak valid!" << endl;
        }
    }
}

// Menghapus semua tugas dalam stack
void destroyTugas() {
    cur = head;
    while (cur != nullptr) {
        del = cur;
        cur = cur->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
}

int main() {
    // Contoh penggunaan fungsi-fungsi stack tugas
    pushTugas("Tugas1", 1, "2024-06-01");
    displayTugas();
    pushTugas("Tugas2", 2, "2024-06-02");
    pushTugas("Tugas3", 3, "2024-06-03");
    pushTugas("Tugas4", 4, "2024-06-04");
    pushTugas("Tugas5", 5, "2024-06-05");
    displayTugas();

    pushTugas("Tugas6", 6, "2024-06-06");
    displayTugas();

    popTugas();
    displayTugas();

    cout << "Apakah stack tugas penuh? " << (isFullTugas() ? "Ya" : "Tidak") << endl;
    cout << "Apakah stack tugas kosong? " << (isEmptyTugas() ? "Ya" : "Tidak") << endl;

    peekTugas(3);

    cout << "Jumlah tugas dalam stack: " << countTugas() << endl;

    changeTugas("TugasUbah", 2, "2024-06-10", 2);
    displayTugas();

    destroyTugas();
    cout << "Apakah stack tugas penuh? " << (isFullTugas() ? "Ya" : "Tidak") << endl;
    cout << "Apakah stack tugas kosong? " << (isEmptyTugas() ? "Ya" : "Tidak") << endl;
    cout << "Jumlah tugas dalam stack: " << countTugas() << endl;

    displayTugas(); // Tampilkan tugas setelah destroy untuk memastikan semua terhapus

    return 0;
}