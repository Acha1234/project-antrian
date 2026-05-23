#include <iostream>
#include <string>
using namespace std;
#define MAX 5
#define MAX_KENDARAAN 100
struct Kendaraan{
    string plat;
    string jenis;
    int jamMasuk;
    int jamKeluar;
    int cari;
};
class Parkir{
public:
    Kendaraan antrianMasuk[MAX];
    Kendaraan antrianKeluar[MAX];
    Kendaraan riwayat[MAX_KENDARAAN];
    int frontMasuk, rearMasuk;
    int frontKeluar, rearKeluar;
    int top;
public:
    Parkir();
    void tambahKendaraan();
    void kendaraanMasuk();
    void kendaraanKeluar();
    void lihatAntrian();
    void simpanRiwayat(Kendaraan k);
    void lihatRiwayatTerakhir();
    void cariPlat(string plat);
};