#include "MLL.h"
#include <iostream>
using namespace std;

int main() {
    ListGuru G;
    ListMurid M;

    createListGuru(G);
    createListMurid(M);

    int pilihan;
    string namaGuru, namaMurid;

    do {
        cout << "\n=== Menu ===" << endl;
        cout << "1. Tambah Guru" << endl;
        cout << "2. Tampilkan Guru" << endl;
        cout << "3. Tambah Murid" << endl;
        cout << "4. Hubungkan Guru dan Murid" << endl;
        cout << "5. Hapus Guru" << endl;
        cout << "6. Cari Guru" << endl;
        cout << "7. Tampilkan Murid dari Guru" << endl;
        cout << "8. Hapus Murid pada Guru" << endl;
        cout << "9. Guru dengan murid paling sedikit" << endl;
        cout << "10. Cari Murid" << endl;
        cout << "11. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama Guru: ";
                cin >> namaGuru;
                insertGuru(G, createGuru(namaGuru));
                break;

            case 2:
                showGuru(G);
                break;

            case 3:
                cout << "Masukkan nama Murid: ";
                cin >> namaMurid;
                insertMurid(M, createMurid(namaMurid));
                break;

            case 4:
                cout << "Masukkan nama Guru: ";
                cin >> namaGuru;
                cout << "Masukkan nama Murid: ";
                cin >> namaMurid;
                menghubungkanGuruMurid(G, M, namaGuru, namaMurid);
                break;

            case 5:
                cout << "Masukkan nama Guru yang ingin dihapus: ";
                cin >> namaGuru;
                hapusGuru(G, namaGuru);
                break;

            case 6:
                cout << "Masukkan nama Guru yang ingin dicari: ";
                cin >> namaGuru;
                if (cariGuru(G, namaGuru))
                    cout << "Guru " << namaGuru << " ditemukan." << endl;
                else
                    cout << "Guru " << namaGuru << " tidak ditemukan." << endl;
                break;

            case 7:
                cout << "Masukkan nama Guru: ";
                cin >> namaGuru;
                tampilkanMuridDariGuru(G, namaGuru);
                break;

            case 8:
                cout << "Masukkan nama Guru: ";
                cin >> namaGuru;
                cout << "Masukkan nama Murid yang ingin dihapus: ";
                cin >> namaMurid;
                hapusMuridPadaGuru(G, namaGuru, namaMurid);
                break;

            case 9:
                guruPalingSedikitMurid(G);
                break;

            case 10:
                cout << "Masukkan nama Murid yang dicari: ";
                cin >> namaMurid;
                if (cariMurid(M, namaMurid))
                    cout << "Murid " << namaMurid << " ditemukan." << endl;
                else
                    cout << "Murid " << namaMurid << " tidak ditemukan." << endl;
                break;

            case 11:
                cout << "Keluar program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 11);

    return 0;
}
