//listenin en başına node eklennesi

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
            cout << "Head :" << head->deger << endl;

    }
    void printTail() {
        if (head != NULL)
            cout << "Tail :" << tail->deger << endl;
    }

    void getCount() {
        cout << "List Count : " << this->count << endl;
    }

    void appendList(int deger) {
        Node* node = new Node(deger);// yeni nod oluşturuldu


        if (count == 0) {//eğer listemde hiç eleman yoksa yeni eleman head ve taili gösteicek

            head = node;
            tail = node;


        }
        else { //eğer bir veya fazlası varsa yeni gelen eleman tail olucak

            tail->next = node;
            tail = node;
        }
        count++;//yeni değer eklenilceğinden count arttırılmalıdır 
    }

    void printList() {
        Node* tmp = head;//headı gösteren pointer oluşturuldu

        while (tmp != NULL) {

            cout << tmp->deger << " , ";
            tmp = tmp->next;

        }
        cout << endl;


    }

    void deleteLastNode() {
        if (count == 0) {
            return;
        }

        Node* temp1 = head;
        Node* temp2 = head;

        while (temp1->next) {//baştan sona kadar tüm nodeları dolaşır

            temp2 = temp1;
            temp1 = temp1->next;
        }

        tail = temp2;
        tail->next = NULL;
        count--;
        if (count == 0) {
         
            head = NULL;
            tail = NULL;
        }

        delete temp1;




    }

    void addFirst(int deger) {
        Node* newNode = new Node(deger);
        if (count == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;

        }
        count++;
    }


};

int main()
{

    int x = 0;
    if (x)
        cout << "ok" << endl;


    LinkedList* linkedList1 = new LinkedList(12);
    linkedList1->appendList(5);
    linkedList1->appendList(24);
    linkedList1->appendList(8);
    linkedList1->appendList(7);

    linkedList1->getCount();
    linkedList1->printHead();
    linkedList1->printTail();
    linkedList1->printList();

    linkedList1->addFirst(15);
    linkedList1->printList();

    delete linkedList1;


}

