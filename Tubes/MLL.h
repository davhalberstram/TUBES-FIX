#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

// Definisi tipe data untuk Guru dan Murid
typedef string infotypePr; // Informasi Guru
typedef string infotypeCh; // Informasi Murid
typedef struct elmPr *adrPr; // Pointer untuk Guru
typedef struct elmCh *adrCh; // Pointer untuk Murid

// Struktur node Guru
struct elmPr {
    infotypePr namaGuru; // Nama Guru
    adrCh FirstCh;       // Pointer ke list murid
    adrPr nextPr;        // Pointer ke Guru berikutnya
};

// Struktur node Murid
struct elmCh {
    infotypeCh namaMurid; // Nama Murid
    adrCh nextCh;         // Pointer ke Murid berikutnya
};

// Struktur list Guru
struct ListGuru {
    adrPr First; // Pointer ke Guru pertama
};

// Struktur list Murid
struct ListMurid {
    adrCh First; // Pointer ke Murid pertama
};

// Deklarasi fungsi dan prosedur
void createListGuru(ListGuru &G);
void createListMurid(ListMurid &M);
adrPr createGuru(string namaGuru);
adrCh createMurid(string namaMurid);
void insertGuru(ListGuru &G, adrPr P);
void insertMurid(ListMurid &M, adrCh P);
adrPr cariGuru(const ListGuru &G, string namaGuru);
adrCh cariMurid(const ListMurid &M, string namaMurid);
void showGuru(const ListGuru &G);
void menghubungkanGuruMurid(ListGuru &G, ListMurid &M, string namaGuru, string namaMurid);
void hapusGuru(ListGuru &G, string namaGuru);
void tampilkanMuridDariGuru(const ListGuru &G, string namaGuru);
void hapusMuridPadaGuru(ListGuru &G, string namaGuru, string namaMurid);
void guruPalingSedikitMurid(const ListGuru &G);

#endif
