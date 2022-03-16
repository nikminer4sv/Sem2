#include <iostream>
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
        cout << "Size = " << size << endl;
        cout << endl;
    }

    void remove(const char& symbol) {
        if (is_empty()) return;

        if (Compare(first->symbolData, symbol)) {

            Node* p = first;
            first = p->next;

            size--;
            delete p;
            return;
        }

        if (Compare(last->symbolData, symbol)) {

            Node* p = first;
            while (p->next != last)
                p = p->next;

            p->next = nullptr;

            size--;
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
        size--;
        delete itCurrent;
    }

    list() : first(nullptr), last(nullptr) {}

    void push_back(char& symbol) {

        Node* p = new Node(symbol);

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
                p->next = temp;
                first = p;
                return;
            }
            else temp = temp->next;
        }

        last->next = p; 
        last = p;
    }

    void Task(list& l2){

        Node* itPrev = first;       

        while (itPrev->next)
        {
            int quantity = 1;
            while (itPrev->next && Compare(itPrev->symbolData, itPrev->next->symbolData))
            {
                quantity++;
                itPrev = itPrev->next;
            }
            
            if (quantity == 2)
                l2.push_back(itPrev->symbolData);
                

            if (itPrev->next)
                itPrev = itPrev->next;
            
        }
    }

};

void Menu(list& l1, char& symbol, list& l2)
{
    while (true)
    {
        cout << "Enter the choose:  " << endl;

        cout << "1. Add new symbol." << endl;
        cout << "2. Search for identical symbols, that are repeated twice and create a new list of them." << endl;
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
            cout << "How many symbols do you want to enter? " << endl;
            int amount;
            cin >> amount;
            for (int i = 0; i < amount; i++)
            {
                cout << "Symbol = ";
                cin >> symbol;

                l1.push_back(symbol);
            }
            
            break;
        }
        case 2:
        {
            cout << "Creating a new list...";

            l1.Task(l2);
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