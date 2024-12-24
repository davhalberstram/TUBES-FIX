#include "MLL.h"
#include <iostream>

// Inisialisasi list Guru
void createListGuru(ListGuru &G) {
    G.First = Nil;
}

// Inisialisasi list Murid
void createListMurid(ListMurid &M) {
    M.First = Nil;
}

// Membuat node Guru baru
adrPr createGuru(string namaGuru) {
    adrPr P = new elmPr;
    P->namaGuru = namaGuru;
    P->FirstCh = Nil; // Belum ada murid yang dihubungkan
    P->nextPr = Nil;  // Node berikutnya kosong
    return P;
}

// Membuat node Murid baru
adrCh createMurid(string namaMurid) {
    adrCh P = new elmCh;
    P->namaMurid = namaMurid;
    P->nextCh = Nil; // Node berikutnya kosong
    return P;
}

// Menambahkan Guru ke dalam list Guru
void insertGuru(ListGuru &G, adrPr P) {
    P->nextPr = G.First; // Hubungkan node baru ke awal list
    G.First = P;         // Perbarui pointer head
}

// Menambahkan Murid ke dalam list Murid
void insertMurid(ListMurid &M, adrCh P) {
    P->nextCh = M.First; // Hubungkan node baru ke awal list
    M.First = P;         // Perbarui pointer head
}

// Mencari Guru berdasarkan nama
adrPr cariGuru(const ListGuru &G, string namaGuru) {
    adrPr P = G.First;
    while (P != Nil && P->namaGuru != namaGuru) {
        P = P->nextPr;
    }
    return P; // Kembalikan node Guru atau Nil jika tidak ditemukan
}

// Mencari Murid berdasarkan nama
adrCh cariMurid(const ListMurid &M, string namaMurid) {
    adrCh P = M.First;
    while (P != Nil && P->namaMurid != namaMurid) {
        P = P->nextCh;
    }
    return P; // Kembalikan node Murid atau Nil jika tidak ditemukan
}

// Menampilkan semua Guru dalam list
void showGuru(const ListGuru &G) {
    adrPr P = G.First;
    while (P != Nil) {
        cout << "Guru: " << P->namaGuru << endl;

        // Menampilkan murid-murid yang terhubung
        adrCh murid = P->FirstCh;
        if (murid != Nil) {
            cout << "  Murid: ";
            while (murid != Nil) {
                cout << murid->namaMurid << (murid->nextCh != Nil ? ", " : "");
                murid = murid->nextCh;
            }
            cout << endl;
        } else {
            cout << "  Tidak ada murid yang terhubung." << endl;
        }

        P = P->nextPr;
    }
}

// Menghubungkan Guru dengan Murid
void menghubungkanGuruMurid(ListGuru &G, ListMurid &M, string namaGuru, string namaMurid) {
    adrPr guru = cariGuru(G, namaGuru); // Cari Guru
    adrCh murid = cariMurid(M, namaMurid); // Cari Murid

    if (guru != Nil && murid != Nil) {
        // Buat salinan murid untuk dimasukkan ke dalam list Guru
        adrCh relasi = new elmCh;
        relasi->namaMurid = murid->namaMurid;
        relasi->nextCh = guru->FirstCh; // Hubungkan ke murid pertama dari Guru
        guru->FirstCh = relasi;         // Perbarui murid pertama dari Guru
        cout << "Berhasil menghubungkan Guru " << namaGuru << " dengan Murid " << namaMurid << "." << endl;
    } else {
        cout << "Gagal menghubungkan. Pastikan nama Guru dan Murid benar." << endl;
    }
}

// Menghapus Guru beserta relasinya
void hapusGuru(ListGuru &G, string namaGuru) {
    adrPr prev = Nil, P = G.First;
    while (P != Nil && P->namaGuru != namaGuru) {
        prev = P;
        P = P->nextPr;
    }
    if (P != Nil) {
        if (prev == Nil) {
            G.First = P->nextPr; // Guru pertama dihapus
        } else {
            prev->nextPr = P->nextPr;
        }
        adrCh relasi = P->FirstCh;
        while (relasi != Nil) {
            adrCh temp = relasi;
            relasi = relasi->nextCh;
            delete temp; // Hapus semua relasi murid
        }
        delete P; // Hapus node Guru
        cout << "Guru " << namaGuru << " berhasil dihapus beserta relasinya." << endl;
    } else {
        cout << "Guru " << namaGuru << " tidak ditemukan." << endl;
    }
}

// Menampilkan Murid yang diajari oleh Guru tertentu
void tampilkanMuridDariGuru(const ListGuru &G, string namaGuru) {
    adrPr guru = cariGuru(G, namaGuru);
    if (guru != Nil) {
        cout << "Guru: " << namaGuru << endl;
        adrCh murid = guru->FirstCh;
        if (murid != Nil) {
            cout << "  Murid: ";
            while (murid != Nil) {
                cout << murid->namaMurid << (murid->nextCh != Nil ? ", " : "");
                murid = murid->nextCh;
            }
            cout << endl;
        } else {
            cout << "  Tidak ada murid yang diajari." << endl;
        }
    } else {
        cout << "Guru " << namaGuru << " tidak ditemukan." << endl;
    }
}

// Menghapus Murid pada Guru tertentu beserta relasinya
void hapusMuridPadaGuru(ListGuru &G, string namaGuru, string namaMurid) {
    adrPr guru = cariGuru(G, namaGuru);
    if (guru != Nil) {
        adrCh prev = Nil, murid = guru->FirstCh;
        while (murid != Nil && murid->namaMurid != namaMurid) {
            prev = murid;
            murid = murid->nextCh;
        }
        if (murid != Nil) {
            if (prev == Nil) {
                guru->FirstCh = murid->nextCh;
            } else {
                prev->nextCh = murid->nextCh;
            }
            delete murid; // Hapus murid
            cout << "Murid " << namaMurid << " pada Guru " << namaGuru << " berhasil dihapus." << endl;
        } else {
            cout << "Murid " << namaMurid << " tidak ditemukan pada Guru " << namaGuru << "." << endl;
        }
    } else {
        cout << "Guru " << namaGuru << " tidak ditemukan." << endl;
    }
}

// Menampilkan Guru dengan jumlah Murid paling sedikit
void guruPalingSedikitMurid(const ListGuru &G) {
    adrPr P = G.First;
    adrPr minGuru = Nil;
    int minCount = INT_MAX;
    while (P != Nil) {
        int count = 0;
        adrCh murid = P->FirstCh;
        while (murid != Nil) {
            count++;
            murid = murid->nextCh;
        }
        if (count < minCount) {
            minCount = count;
            minGuru = P;
        }
        P = P->nextPr;
    }
    if (minGuru != Nil) {
        cout << "Guru dengan murid paling sedikit adalah " << minGuru->namaGuru;
        cout << " dengan " << minCount << " murid." << endl;
    } else {
        cout << "Tidak ada Guru dalam daftar." << endl;
    }
}
