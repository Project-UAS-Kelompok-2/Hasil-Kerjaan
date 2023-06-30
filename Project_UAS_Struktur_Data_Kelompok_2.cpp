/*
    Project Ujian Akhir Semester Struktur data kelompok 2
*/

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *head = NULL, *tail = NULL, *bantu, *hapus, *insert, *cari;
int x;

//pengerjaan "Tampil" -> Bagus Ari Sudamto 
void tampil(){
    if (head == NULL){
        cout<<"Linked list kosong"<<endl;
        return;
    }
    node *current = head;
    cout<<"Isi linked list: ";
    do{
        cout<<current->data<<" ";
        current = current->next;
    }
    while (current != head);
    cout<<endl;
}

//pengerjaan "Enqueque" -> Mediana Nurlaili
void enqueue(){
    node *baru;
    baru = new node;
    cout<<"masukan data: ";
    cin>>baru->data;
    baru->next = NULL;
    if (head == NULL){
        head = baru;
        head->next = head;
        tail = head;
    }
    else{
        tail->next = baru;
        baru->next = head;
        tail = baru;
    }
    tampil();
}

//pengerjaan "Dequeue" -> Sulthon Febriawan
void dequeue(){
    if (head == NULL){
        cout<<"Linked List Kosong"<<endl;
        return;
    }
    else if (head == tail){
        cout<<"data yang di-dequeque"<<head->data<<endl;
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        node *temp = head;
        cout<<"Data yang di-dequeue"<<head->data<<endl;
        head = head->next;
        tail->next = head;
        delete temp;
    }
}

//pengerjaan "Full" -> Ryanveno Pasha
void full(){
    int count = 0;
    if (head != NULL){
        node *current = head;
        do{
            count++;
            current = current->next;
        }
        while (count >= 10);
    }
    if (count >= 10){
        cout<<"Linked list telah penuh."<<endl;
    }
    else{
        cout<<"Linked list belum penuh."<<endl;
    }
}

//pengerjaan "Empty" -> Dimas Agus Prasetyo
void empty(){
    if (head == NULL){
        cout<<"Linked list kosong"<<endl;
    }
    else{
        cout<<"Linked list belum kosong"<<endl;
    }
}

//pengerjaan "Clear" -> Angga Pradipa
void clear(){
    if (head ==  NULL){
        cout<<"Linked List Sudah Kosong."<<endl;
    }
    else{
        node *current = head;
        while (current != tail){
            node *temp = current;
            current = current->next;
            delete temp;
        }
        delete tail;
        head = NULL;
        tail = NULL;
        cout<<"Linked list berhasil dikososngkan"<<endl;
    }
}

//Membuat program menu "Queue Single Linked Circular List" -> Dimas Agus Prasetyo
int main(){
    char huruf;
    short pil;

    do{
        cout<<"===================================================="<<endl;
        cout<<"   Menu Program Queue single linked circular list   "<<endl;
        cout<<"===================================================="<<endl;
        cout<<"1. Enqueque"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Tampil"<<endl;
        cout<<"4. Full"<<endl;
        cout<<"5. Empty"<<endl;
        cout<<"6. Clear"<<endl;

        cout<<"Masukan pilihan anda: ";
        cin>>pil;

        switch (pil){
        case 1:
            enqueue();
            break;
        
        case 2:
            dequeue();
            break;
        
        case 3:
            tampil();
            break;
        
        case 4:
            full();
            break;

        case 5:
            empty();
            break;

        case 6:
            clear();
            break;
        
        default:
            break;
        }
    }
    while (pil !=7);
    return 0;
}
