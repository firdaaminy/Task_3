#include <iostream>

using namespace std;

#ifndef LIST_H
#define LIST_H

struct matakuliah {
    int id_matkul, sks_matkul;
    string nama_matkul, kelas_matkul, dosen_matkul;
};

class Node {
    matakuliah data;
    Node* next;

  public:
    Node() {};
    void SetData(matakuliah dt) {
        data = dt;
    }
    void SetNext(Node* nx) {
        next = nx;
    }
    matakuliah Data() {
        return data;
    }
    Node* Next() {
        return next;
    }
};

void insertFirst();
void insertLast();
void insertAfter(Node* prv);
void deleteFirst();
void deleteLast();
void deleteAfter(Node* prv);
void viewList();
void searchElement();

#endif // LIST_H
