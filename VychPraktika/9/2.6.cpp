#include <iostream>

using namespace std;

struct InvalidListSize : public exception
{

	const char * what () const throw () {
    	return "List size must be more or equal to 2";
    }

};

struct Node {

    double Data;
    Node* Next;
    Node* Prev;

    Node() { Next = nullptr; }

};

class DoublyLinkedList {
private:
    Node* Head;

public:
    int Size;

public:
    DoublyLinkedList() { 

        Head = nullptr; 
        Size = 0;

    }

    double Get(int Index) {

        if (Index > Size - 1 || Index < 0)
            throw invalid_argument("Invalid index");

        Node* Temp = Head;

        if (Index >= Size / 2 + 1) {

            for (int j = Size - 1; j > Index - 1; j--)
                Temp = Temp->Prev;

        } else {

            for (int i = 0; i < Index; i++)
                Temp = Temp->Next;

        }

        

        return Temp->Data;
    }

    void Add(const double Value) {

        Node* NewNode = new Node;
        NewNode->Data = Value;

        if (Head == nullptr) {

            Head = NewNode;

        } else {

            if (Size == 1) {

                Head->Next = NewNode;
                Head->Prev = NewNode;
                NewNode->Prev = Head;
                NewNode->Next = Head;

            } else {

                Node* temp = Head->Prev;
                temp->Next = NewNode;
                NewNode->Prev = temp;
                NewNode->Next = Head;
                Head->Prev = NewNode;

            }

        }

        Size += 1;

    }

    bool Remove(int Index) {

        if (Index > Size - 1 || Index < 0)
            return false;

        if (Index == 0) {

            Head->Prev->Next = Head->Next;
            Head->Next->Prev = Head->Prev; 
            Head = Head->Next;

        } else {

            Node* Temp = Head;

            for (int i = 0; i < Index - 1; i++) 
                Temp = Temp->Next;

            Temp->Next->Next->Prev = Temp;
            Temp->Next = Temp->Next->Next;

            // 1 2 3 4 5
        }

        Size -= 1;

        return true;

    }

    void Test() {

        this->Remove(4);

    }

    /*void Print() {
        //ситуация когда лист пустой
        //поставить ассерт на размер листа

        //assert(Size > 0);
        
        Node* Temp = Head;

        cout << "Size is: " << Size << endl;

        for (int i = 0; i < Size; i++) {

            PrintStudentInfo(Temp->Data, i + 1);
            Temp = Temp->Next;

        }

    }*/

    /*~DoublyLinkedList() {

        Node* current = Head;

        while(current != nullptr) {
            Node* next = current->Next;
            delete current;
            current = next;
        }

        Head = nullptr;

    }*/

};

void PrintList(DoublyLinkedList& list) {

    for (int i = 0; i < list.Size; i++) 
        cout << list.Get(i) << " ";

    cout << endl;

}

double Task(DoublyLinkedList& list) {

    if (list.Size < 2)
        throw InvalidListSize();

    double min = list.Get(0) + list.Get(list.Size - 1);
    
    for (int i = 1; i < list.Size - 1; i++) {

        double temp = list.Get(i) + list.Get(list.Size - i - 1);

        if (temp < min)
            min = temp;

    }

    return min;

}

// hello
// el

/*void Task(CharList& list1, CharList& list2) {

    if (list2.Size == 0 || list1.Size - list2.Size < 0) 
        return;

    int forSize = list1.Size - list2.Size;

    for (int i = 0; i < forSize + 1; i++) {

        bool exist = true;

        for (int j = 0; j < list2.Size; j++) {

            if (list1.Get(i + j) != list2.Get(j)) {

                exist = false;
                break;

            }

        }

        if (exist) {

            for (int j = 0; j < list2.Size; j++) {
                list1.Remove(i);
            }

            forSize = list1.Size - list2.Size;

        }

    }

}*/

int main() {

    /*int n;
    cin >> n;

    DoublyLinkedList list;
    double* data = new double[2*n];

    for (int i = 0; i < 2 * n; i++) {

        double temp;
        cin >> temp;
        list.Add(temp);

    }

    Task(list);

    PrintList(list);*/

    DoublyLinkedList list;
    list.Add(1.3);
    list.Add(2.123);
    list.Add(3.5678);
    list.Add(4.123);
    list.Add(0.5678);
    list.Add(8.123);
    //list.Test();

    cout << Task(list) << endl;

    PrintList(list);

}