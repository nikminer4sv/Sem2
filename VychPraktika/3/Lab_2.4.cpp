#include <iostream>
#include <string>
using namespace std;


struct Node {

    Node* next;
    char symbolData;

    Node(const char symbol) {
        symbolData = symbol;
        this->next = nullptr;
    }
    void Print(){
        cout << symbolData << endl;
    }
};

class list {
private:
    Node* first = nullptr;
    Node* last = nullptr;
    int size = 0;

    bool Separator(const char& a, const char& b) {
        return a >= b;
    }

    bool Compare(const char& a, const char& b) {
        return a == b;
    }

public:
    bool is_empty() const {
        return first == nullptr;
    }

    void print() {

        Node* p = first;
        while (p) {
            p->Print();
            p = p->next;
        }
        cout << endl;
    }

    void remove(const char& symbol) {
        if (is_empty()) return;

        if (Compare(first->symbolData, symbol)) {

            Node* p = first;
            first = p->next;
            delete p;
            return;
        }

        if (Compare(last->symbolData, symbol)) {

            if (first == last) {
                Node* p = first;
                first = p->next;
                delete p;
            }

            Node* p = first;
            while (p->next != last)
                p = p->next;

            p->next = nullptr;

            delete last;
            last = p;
            return;
        }

        Node* itPrev = first;       
        Node* itCurrent = first->next; 

        while (itCurrent && !Compare(itCurrent->symbolData, symbol))
        {
            itCurrent = itCurrent->next;
            itPrev = itPrev->next;
        }

        if (!itCurrent) {
            cout << "This element does not exist" << endl;
            return;
        }

        itPrev->next = itCurrent->next;
        delete itCurrent;
    }

    list() : first(nullptr), last(nullptr) {}

    void push_back(char& stud) {

        Node* p = new Node(stud);

        if (is_empty()) {
            first = p;
            last = p;
            size++;
            return;
        }

        Node* temp = first;
        size++;

        if (size == 2 && Separator(temp->symbolData, p->symbolData))
        {
            p->next = last;
            first = p;
            return;
        }

        while (temp->next != nullptr)
        {
            if (Separator(p->symbolData, temp->symbolData) && Separator(temp->next->symbolData, p->symbolData))
            {
                p->next = temp->next;
                temp->next = p;
                return;
            }
            else if (Separator(temp->symbolData, p->symbolData))
            {
                p->next = first;
                first = p;
                return;
            }
            else temp = temp->next;
        }

        last->next = p; 
        last = p;
    }

    void Task(list& l2){


    }

};

void Menu(list& l1, char& symbol, list& l2)
{
    while (true)
    {
        cout << "Enter the choose:  " << endl;

        cout << "1. Add new symbol." << endl;
        cout << "2. Search a students by \"symbols\" and create a new list of them." << endl;
        cout << "3. Delete a symbol." << endl;
        cout << "4. Print the list's of symbols." << endl;
        cout << "5. Exit." << endl;

        int choose;
        cin >> choose;

        if (choose == 5) break;

        switch (choose)
        {
        case 1:
        {
            cout << "Symbol = ";
            cin >> symbol;

            l1.push_back(symbol);

            break;
        }
        case 2:
        {
            // cout << "Enter the first symbols of surname, name, patronymic (\"K\" \"D\" \"A\"): ";

            // cin >> stud.Surname[0];
            // cin >> stud.Name[0];
            // cin >> stud.Patronymic[0];

            // l1.createl2(l2, stud);

            break;
        }
        case 3:
        {
            cout << "Enter the symbol (\"x\")" << endl;

            cout << "Symbol = ";
            cin >> symbol;

            l1.remove(symbol);

            break;
        }
        case 4:
        {
            cout << "\n========================LIST=OF=STUDENTS===========================" << endl;
            l1.print();
            cout << "====================SECOND=LIST=OF=STUDENTS========================" << endl;
            l2.print();

            break;
        }

        default:
            break;
        }

        cout << endl;
    }
}

int main() {

    list l1, l2;
    char symbol;

    Menu(l1, symbol, l2);

    return 0;
}