#include <iostream>
#include "MATA KULIAH.h"

address alokasi(infotype x) {
    address P=new elmlist;
    info(P)=x;
    return P;
}

void InputData(infotype *x) {
    infotype l;
    cout<<"Masukkan nama mata kuliah: ";
    cin>>l.nama_matkul;
    cout<<"Masukkan ID mata kuliah: ";
    cin>>l.id_matkul;
    cout<<"Masukkan jumlah sks mata kuliah: ";
    cin>>l.sks_matkul;
    cout<<"Masukkan kelas mata kuliah ";
    cin>>l.kelas_matkul;
    cout<<"Masukkan nama dosen mata kuliah: ";
    cin>>l.dosen_matkul;
    *x=l;
}

void insertFirst(list *L, address P) {
    infotype x;
    InputData(&x);
    P=alokasi(x);
    if ((*L).first!=nil) {
        next(P)=nil;
        (*L).first=P;
    } else {
        next(P)=nil;
        next(P)=(*L).first;
        (*L).first=P;
    }
}

void ShowMenu(int pilihan) {
    list L;
    address P;
    cout<<"1. Insert First";
    cin>>pilihan;
    switch (pilihan) {
        case 1:
            insertFirst(&L, P);
            break;
    }
}
