#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)

using namespace std;
struct matakuliah {
        int id_matkul, sks_matkul;
        string nama_matkul, kelas_matkul, dosen_matkul;
};

typedef matakuliah infotype;

typedef struct elmlist *address;
struct elmlist {
        infotype info;
        address next;
};

struct list {
        address first;
};

void insertFirst(list *L, address P);
void insertLast(list *L, address P);
void insertAfter(list *L, address P, address Prec);
void insertSort(list *L, address P);
void deleteFirst(list *L, address P);
void deleteLast(list *L, address P);
void deleteAfter(list *L, address P, address Prec);
void viewList(list *L);
void searchElement(list *L, int x);
void sequentialSearch(list *L, int cari);
void ShowMenu(int pilihan);
void InputData(infotype *x);
address alokasi(infotype x);

void sortBySKS(list *L);
int countNodes(list *L);
void clearList(list *L);

#endif // MATAKULIAH1_H_INCLUDED
