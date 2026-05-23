#include "Parkir.h"
#include <iostream>
using namespace std;

Parkir::Parkir() {
    frontMasuk = rearMasuk = -1;
    frontKeluar = rearKeluar = -1;
    top = -1;
}

void Parkir::tambahKendaraan(){
    cout<<"==========================="<<endl;
    cout<<"| Parkir Mobil 4000 / Jam |"<<endl;
    cout<<"| Parkir Motor 2000 / Jam |"<<endl;
    cout<<"==========================="<<endl;
    if(rearMasuk == MAX-1){
        cout<<"Antrian masuk penuh\n";
        return;
    }
    Kendaraan k;
    cout<<"Plat nomor : ";
    cin>>k.plat;
    cout<<"Jenis (motor/mobil) : ";
    cin>>k.jenis;
    if (k.jenis == "mobil" || k.jenis == "motor") {
        cout<<"Jam masuk : ";
        cin>>k.jamMasuk;
        rearMasuk++;
        antrianMasuk[rearMasuk] = k;
        if(frontMasuk == -1)
            frontMasuk = 0;
        cout<<"Kendaraan masuk ke antrian parkir" << endl;
    } else {
        cout << "jenis kendaraan tidak diketahui"<< endl;
    }
}

void Parkir::kendaraanMasuk(){
    if(frontMasuk == -1){
        cout<<"Tidak ada kendaraan di antrian masuk" << endl;
        return;
    }
    if(rearKeluar == MAX-1){
        cout<<"Antrian parkir penuh" << endl;
        return;
    }
    Kendaraan k = antrianMasuk[frontMasuk];
    frontMasuk++;
    if(frontMasuk > rearMasuk)
        frontMasuk = rearMasuk = -1;
    rearKeluar++;
    antrianKeluar[rearKeluar] = k;
    if(frontKeluar == -1)
        frontKeluar = 0;
    cout<<"Kendaraan berhasil parkir" << endl;
}

void Parkir::kendaraanKeluar(){
    if(frontKeluar == -1){
        cout<<"Tidak ada kendaraan di parkiran" << endl;
        return;
    }
    Kendaraan k = antrianKeluar[frontKeluar];
    cout<<"Jam keluar : ";
    cin>>k.jamKeluar;
    int lama = k.jamKeluar - k.jamMasuk;
    int tarif;
    if(k.jenis == "motor") {
        tarif = lama * 2000;
    } else if (k.jenis == "mobil") {
        tarif = lama * 4000;
    }
    cout<<"Total bayar : "<<tarif<<endl;
    frontKeluar++;
    if(frontKeluar > rearKeluar)
        frontKeluar = rearKeluar = -1;
    simpanRiwayat(k);
}

void Parkir::lihatAntrian() {
    cout<<"\nAntrian Masuk:" << endl;
    if(frontMasuk == -1)
        cout<<"Kosong\n";
    else{
        for(int i=frontMasuk;i<=rearMasuk;i++)
            cout<<antrianMasuk[i].plat<<" "<<antrianMasuk[i].jenis<<endl;
    }
    cout<<"\nKendaraan di Parkiran:\n";
    if(frontKeluar == -1)
        cout<<"Kosong\n";
    else{
        for(int i=frontKeluar;i<=rearKeluar;i++)
            cout<<antrianKeluar[i].plat<<" "<<antrianKeluar[i].jenis<<endl;
    }
}

void Parkir::simpanRiwayat(Kendaraan k){
    if(top == MAX_KENDARAAN-1){
        cout<<"Riwayat penuh\n";
        return;
    }
    top++;
    riwayat[top] = k;
}

void Parkir::lihatRiwayatTerakhir(){
    if(top == -1){
        cout<<"Belum ada riwayat\n";
        return;
    }
    cout<<"Riwayat terakhir\n";
    cout<<"Plat : "<<riwayat[top].plat<<endl;
    cout<<"Jenis : "<<riwayat[top].jenis<<endl;
}

void Parkir::cariPlat(string plat){
    for(int i=frontKeluar;i<=rearKeluar;i++){
        if(antrianKeluar[i].plat == plat){
            cout<<"Kendaraan ditemukan di parkiran\n";
            return;
        }
    }
    cout<<"Kendaraan tidak ditemukan\n";
}