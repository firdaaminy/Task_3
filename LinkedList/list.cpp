#include <iostream>
#include "list.h"

int id_total = 1;

address alokasi(infotype x) {
    address P=new elmlist;
    info(P)=x;
    return P;
}

void InputData(infotype *x) {
    infotype l;
    cout<<"ID mata kuliah: " << id_total << endl;
    l.id_matkul = id_total;
    id_total++;
    cout<<"Masukkan nama mata kuliah: ";
    getline(cin, l.nama_matkul);
    cout<<"Masukkan jumlah sks mata kuliah: ";
    cin>>l.sks_matkul;
    cin.ignore();
    cout<<"Masukkan kelas mata kuliah: ";
    getline(cin, l.kelas_matkul);
    cout<<"Masukkan nama dosen mata kuliah: ";
    getline(cin, l.dosen_matkul);
    *x=l;
}

void insertFirst(list *L, address P) {
    if ((*L).first==nil) {
        (*L).first=P;
        next((*L).first)=nil;
    } else {
        next(P)=nil;
        next(P)=(*L).first;
        (*L).first=P;
    }
}

void insertLast(list *L, address P) {
    address Q;
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

void deleteFirst (list *L, address P){
    P = first(*L);
    if(P == nil) return;

    if(next(P) == nil) {
        (*L).first = nil;
        delete P;
    }
    else {
        (*L).first = next(P);
        delete P;
    }
}

void deleteLast (list *L, address P)
{
    address Q;
    Q=(*L).first;
    while (next(next(Q))!=nil) {
        Q=next(Q);
    }
    P=next(Q);
    next(Q)=nil;
    delete P;
}

void deleteAfter(list *L, address P, address Prec) {
    Prec = (*L).first;
    while(info(Prec).id_matkul != info(P).id_matkul) {
        Prec = next(Prec);
    }
    P = next(Prec);
    next(Prec) = next(P);
    delete P;
}

void searchElement(list *L, int x) {
    bool found = false;
    address Q;
    Q = first(*L);
    while (Q != nil && found == false)
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
    if(!found) {
        cout << "DATA TIDAK DITEMUKAN." << endl;
        return;
    }
    cout<<"Nama mata kuliah dari ID tersebut adalah: "<<info(Q).nama_matkul<<endl;
    cout<<"Jumlah sks dari mata kuliah tersebut adalah: "<<info(Q).sks_matkul<<endl;
    cout<<"Ruang kelas dari mata kuliah tersebut adalah: "<<info(Q).kelas_matkul<<endl;
    cout<<"Nama dosen pengajar dari mata kuliah tersebut adalah: "<<info(Q).dosen_matkul<<endl;
    cout << endl;
}

void sequentialSearch(list *L, int cari) {
    address cur = (*L).first;
    infotype temp;
    temp.id_matkul = cari;
    insertLast(L, alokasi(temp));
    while(info(cur).id_matkul != cari) {
        cur = next(cur);
    }
    if(info(cur).nama_matkul.empty()) {
        cout << "DATA TIDAK DITEMUKAN." << endl;
    }
    else {
        cout << "Nama mata kuliah dari ID tersebut adalah: " << info(cur).nama_matkul << endl;
        cout << "Jumlah sks dari mata kuliah tersebut adalah: " << info(cur).sks_matkul << endl;
        cout << "Ruang kelas dari mata kuliah tersebut adalah: " << info(cur).kelas_matkul << endl;
        cout << "Nama dosen pengajar dari mata kuliah tersebut adalah: " << info(cur).dosen_matkul << endl;
        cout << endl;
    }
    address P;
    deleteLast(L, P);
}

void insertSort(list *L, address P) {
    insertLast(L, P);
    sortBySKS(L);
}

int countNodes(list *L) {
    address cur = first(*L);

    int nodes = 0;

    if(cur == NULL) return 0;
    else {
        while(cur != NULL) {
            nodes++;
            cur = next(cur);
        }
        return nodes;
    }
}

void clearList(list *L) {
    address cur = first(*L);

    while(cur != NULL) {
        address tmp = next(cur);
        delete cur;
        cur = tmp;
    }
    first(*L) = NULL;
}

void sortBySKS(list *L) {
    address sechead = NULL;

    address cur = first(*L);

    bool done = false;
    int nodes = countNodes(L);
    int new_nodes = 0;

    int cursks = 0;

    if(cur == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        int wtf = 0;
        while(nodes != new_nodes) {
            while(cur != NULL) {
                if(info(cur).sks_matkul == cursks) {
                    address newNode;
                    newNode = alokasi(info(cur));
                    next(newNode) = NULL;

                    if (sechead == NULL) {
                        sechead = newNode;
                    }
                    else {
                        address seccur = sechead;
                        while(next(seccur) != NULL) {
                            seccur = next(seccur);
                        }
                        next(seccur) = newNode;
                    }
                    new_nodes++;
                }
                cur = next(cur);
            }
            cur = first(*L);
            cursks++;
        }
        clearList(L);
        first(*L) = sechead;
    }
}

void ShowMenu(int pilihan) {
    list L;
    char lanjut;
    infotype data;
    L.first = nil;
    address P;
    do{
        cout << "============ MENU =================" << endl;
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Insert After"<<endl;
        cout<<"4. Delete First"<<endl;
        cout<<"5. Delete Last"<<endl;
        cout<<"6. Delete After"<<endl;
        cout<<"7. View List"<<endl;
        cout<<"8. Search Data"<<endl;
        cout<<"9. Search Sequential with Sentinel"<<endl;
        cout<<"10. Insertion Sort"<<endl;
        cout << "11. Sort (BY SKS)" << endl;
        cout << "12. Total Elements" << endl;
        cout<<"Masukkan nomor menu yang anda pilih: ";
        cin>>pilihan;
        cin.ignore();
        cout<<endl;
        switch (pilihan) {
            case 1: {
                InputData(&data);
                P = alokasi(data);
                insertFirst(&L, P);
                break;
            }
            case 2: {
                InputData(&data);
                P = alokasi(data);
                insertLast(&L, P);
                break;
            }
            case 3: {
                int idbaru;
                address Z;
                cout<<"Masukkan ID mata kuliah yang telah Anda masukkan sebelumnya: ";
                cin>>idbaru;
                cin.ignore();
                address R;
                R=(L).first;
                while (info(R).id_matkul!=idbaru) {
                    R=next(R);
                }
                InputData(&data);
                Z=alokasi(data);
                insertAfter(&L,Z,R);
                break;
            }
            case 4:
                deleteFirst(&L, P); break;
            case 5:
                deleteLast(&L, P); break;
            case 6: {
                address Prec;
                int idhapus;
                cout<<"Masukkan ID mata kuliah yang ingin Anda hapus: ";
                cin>>idhapus;
                cin.ignore();
                address S;
                S=(L).first;
                while (info(S).id_matkul!=idhapus) {
                    S=next(S);
                }
                deleteAfter(&L, S, Prec);
                break;
            }
            case 7:
                viewList(&L);
                break;
            case 8: {
                int idcari;
                cout<<"Masukkan ID mata kuliah yang Anda ingin cari: ";
                cin>>idcari;
                cin.ignore();
                searchElement(&L, idcari);
                break;
            }
            case 9: {
                int cari;
                cout << "Masukkan ID mata kuliah yang ingin dicari: ";
                cin >> cari;
                cin.ignore();
                sequentialSearch(&L, cari);
                break;
            }
            case 10: {
                InputData(&data);
                P = alokasi(data);
                insertSort(&L, P);
                break;
            }
            case 11:
                sortBySKS(&L);
                break;
            case 12:
                cout << "Total Element dalam List: " << countNodes(&L) << endl;
                break;
            default:
                cout<<"MAAF, NOMOR PILIHAN TERSEBUT TIDAK ADA"<<endl;
                break;
        }
        do {
            cout << "Lanjut? (Y/N) ";
            cin >> lanjut;
        } while(lanjut != 'Y' && lanjut != 'N' && lanjut != 'y' && lanjut != 'n');
    } while(lanjut == 'Y' || lanjut == 'y');
}
void viewList(list *L) {
    address P;
    P=(*L).first;
    while ((P)!=nil){
        cout<<"Nama mata kuliah: "<<info(P).nama_matkul<<endl;
        cout<<"ID mata kuliah: "<<info(P).id_matkul<<endl;
        cout<<"Jumlah SKS mata kuliah: "<<info(P).sks_matkul<<endl;
        cout<<"Ruang kelas mata kuliah: "<<info(P).kelas_matkul<<endl;
        cout<<"Nama dosen pengajar mata kuliah: "<<info(P).dosen_matkul<<endl;
        cout<<endl;
        if(next(P) != nil)
            P=next(P);
        else break;
    }
}
