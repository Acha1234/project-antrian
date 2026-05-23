#include "Parkir.h"
#include <iostream>
using namespace std;
int main(){
    Parkir p;
    int pilih;
    string plat;
    do {
        cout<<"   ========================="<< endl;
        cout<<"   | === SISTEM PARKIR === | " << endl;
        cout<<"1. |Tambah kendaraan       |" << endl;;
        cout<<"2. |Kendaraan masuk parkir |" << endl;;
        cout<<"3. |Kendaraan keluar parkir|" << endl;
        cout<<"4. |Lihat antrian kendaraan|" << endl;
        cout<<"5. |Lihat riwayat terakhir |" << endl;
        cout<<"6. |Cari kendaraan         |" << endl;
        cout<<"7. |Keluar                 |" << endl;
        cout<<"   ========================="<<endl;
        cout<<"Pilih Opsinya: ";
        cin>>pilih;
        switch(pilih){
        case 1:
            p.tambahKendaraan();
            break;
        case 2:
            p.kendaraanMasuk();
            break;
        case 3:
            p.kendaraanKeluar();
            break;
        case 4:
            p.lihatAntrian();
            break;
        case 5:
            p.lihatRiwayatTerakhir();
            break;
        case 6:
            cout<<"Masukkan plat : ";
            cin>>plat;
            p.cariPlat(plat);
            break;
        }
    }while(pilih != 7);
    
}