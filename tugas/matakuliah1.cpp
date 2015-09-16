#include <iostream>
#include "matakuliah1.h"

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
    cout<<"Masukkan kelas mata kuliah: ";
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
        (*L).first=P;
        next((*L).first)=nil;
    } else {
        next(P)=nil;
        next(P)=(*L).first;
        (*L).first=P;
    }
}

void insertLast(list *L, address P ) {
    infotype x;
    InputData(&x);
    address Q;
    P=alokasi(x);
    Q=(*L).first;
    while (next(Q)!=nil) {
        Q=next(Q);
    }
    next(P)=nil;
    next(Q)=P;
}

void insertAfter(list *L, address P, address Prec) {
    address Q;
    Q=(*L).first;
    while (info(Q).id_matkul != info(Prec).id_matkul){
        Q=next(Q);
    }
    next(P)=nil;
    next(P)=next(Q);
    next(Q)=P;
}

void deleteFirst (list *L, address *P){
    *P = (*L).first ;
    (*L).first = next((*L).first);
    next(*P) = nil;
    delete P;
}

void deleteLast (list *L, address *P)
{
    address Q;
    Q=(*L).first;
    while (next(next(Q))!=nil) {
            Q=next(Q);
    }
    *P=next(Q);
    next(Q)=nil;
    delete P;
}

void deleteAfter(list *L, address *P, address Prec) {
    address Q;
    Q=(*L).first;
    while (info(Q).id_matkul=info(Prec).id_matkul) {
        Q=next(Q);
    }
    *P=next(Prec);
    next(Prec)=next(*P);
    next(*P)=nil;
}

void searchElement(list L, int x) {
    bool found = false;
    address Q;
    Q=first(L);
    while ((next(Q) != nil) or (found == false))
    {
        if(info(Q).id_matkul == x)
        {
            found = true;
        }
        else
        {
            Q = next(Q);
        }
    }
    cout<<"Nama mata kuliah dari ID tersebut adalah: "<<info(Q).nama_matkul<<endl;
    cout<<"Jumlah sks dari mata kuliah tersebut adalah: "<<info(Q).sks_matkul<<endl;
    cout<<"Ruang kelas dari mata kuliah tersebut adalah: "<<info(Q).kelas_matkul<<endl;
    cout<<"Nama dosen pengajar dari mata kuliah tersebut adalah: "<<info(Q).dosen_matkul<<endl;

}

void ShowMenu(int pilihan) {
    list L; infotype data;
    address P;
    do{
    cout<<"1. Insert First"<<endl;
    cout<<"2. Insert Last"<<endl;
    cout<<"3. Insert After"<<endl;
    cout<<"4. Delete First"<<endl;
    cout<<"5. Delete Last"<<endl;
    cout<<"6. Delete After"<<endl;
    cout<<"7. View List"<<endl;
    cout<<"8. Search Element"<<endl;
    cout<<"9. Search Sequential with Sentinel"<<endl;
    cout<<"10. Insertion Sort"<<endl;
    cout<<"Masukkan nomor menu yang anda pilih: ";
    cin>>pilihan;
    cout<<endl;
    switch (pilihan) {
        case 1:
            insertFirst(&L, P);
            break;
        case 2:
            insertLast(&L, P);
            break;
        case 3:
            int idbaru;
            address Z;
            cout<<"Masukkan ID mata kuliah yang telah Anda masukkan sebelumnya: ";
            cin>>idbaru;
            address R;
            R=(L).first;
            while (info(R).id_matkul!=idbaru) {
                R=next(R);
            }
            InputData(&data);
            Z=alokasi(data);
            insertAfter(&L,Z,R);
            break;
        case 4:
            deleteFirst(&L, &P);
        case 5:
            deleteLast(&L,&P);
        case 6:
            address Prec;
            int idhapus;
            cout<<"Masukkan ID mata kuliah yang ingin Anda hapus: ";
            cin>>idhapus;
            address S;
            S=(L).first;
            while (info(R).id_matkul!=idhapus) {
                S=next(S);
            }
            deleteAfter(&L, &S, Prec);
        case 7:
            viewList(L);
            break;
        case 8:
            int idcari;
            address K;
            cout<<"Masukkan ID mata kuliah yang Anda ingin cari: ";
            cin>>idcari;
            K=(L).first;
            while (info(K).id_matkul!=idbaru) {
                K=next(K);
            }
            searchElement(L, idcari);
        default:
            cout<<"MAAF, NOMOR PILIHAN TERSEBUT TIDAK ADA"<<endl;
            break;

    }
    }while(pilihan<11);
}
void viewList(list L) {
    address P;
    P=(L).first;
    while ((P)!=nil){
        cout<<"Nama mata kuliah: "<<info(P).nama_matkul<<endl;
        cout<<"ID mata kuliah: "<<info(P).id_matkul<<endl;
        cout<<"Jumlah SKS mata kuliah: "<<info(P).sks_matkul<<endl;
        cout<<"Ruang kelas mata kuliah: "<<info(P).kelas_matkul<<endl;
        cout<<"Nama dosen pengajar mata kuliah: "<<info(P).dosen_matkul<<endl;
        cout<<endl;
        P=next(P);
    }
}
