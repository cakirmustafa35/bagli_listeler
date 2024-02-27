//node sınıfı nasıl oluşur onu öğreniyoruz arkadaşlar

#include <iostream>
using namespace std;

class Node {

public:
    int deger;
    Node* next;

    Node(int deger) {
        this->deger = deger;
        next = NULL;

    }


};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int count;

public:
    LinkedList(int deger) {
        Node* node = new Node(deger);
        head = node;
        tail = node;
        count = 1;//eleman sayısını belirtir 
    }

    ~LinkedList() {
        cout << "Destructor is called " << endl;
        Node* tmp = head;
        while (head) {
            head = head->next;
            delete tmp;
            tmp = head;
        }

    }


    void printHead() {
        if (head != NULL)//programı crahslamasın diye yazıldı
            cout <<"Head :"<< head->deger << endl;

    }
    void printTail() {
        if (head != NULL)
            cout << "Tail :" << tail->deger << endl;
    }
    
    void getCount() {
        cout << "List Count : " << this->count << endl;
    }

};

int main()
{
    LinkedList* linkedList1 = new LinkedList(12);
    linkedList1->getCount();
    linkedList1->printHead();
    linkedList1->printTail();
    delete linkedList1;


}

