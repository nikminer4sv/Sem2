#include <iostream>
#include <list>

using namespace std;

void add(list<char>& , const char&);

void print(list<char>& l)
{
    list<char>::iterator it = l.begin();
    for (int i = 0 ; i < l.size(); i++)
        cout << *it++ << endl;
}

template<typename T>
void quickSort(T *array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

bool Compare(const char& a, const char& b) {
        return a == b;
}

void Task(list<char>& l1, list<char>& l2)
{
    list<char>::iterator it1 = l1.begin(), it2 = l1.begin();
    int i = 0;
    it2++;
    cout << *it1 << ' ' << *it2 << endl;

    while (i < l1.size())
    {
        int quantity = 1;
        while (i < l1.size() && Compare(*it1, *it2))
        {
            quantity++;
            i++;
            it1++;
            it2++;
        }
        
        if (quantity == 2)
            add(l2, *it1);
            
        if (i < l1.size() - 1)
        {
            it1++;
            it2++;
            i++;
        }
        else
            break;
    }   
}

void add(list<char>& l1, const int& amount)
{  
    char symbol;
    for (int i = 0; i < amount; i++)
    {    
        cin >> symbol;
        l1.push_back(symbol);
    }

    int size = l1.size();
    char* garbage = new char[size];
    list<char>::iterator it = l1.begin();
    for (int i = 0; i < size; i++)
        garbage[i] = *it++;

    l1.erase(l1.begin(), l1.end());
    quickSort(garbage, 0, size - 1);

    for (int i = 0; i < size; i++)
        l1.push_back(garbage[i]);
    
    delete[] garbage;
}

void add(list<char>& l, const char& symbol)
{  
    if (l.empty())
    {
        l.push_back(symbol);
        return;
    }
        
    int size = l.size();
    char* garbage = new char[size + 1];

    list<char>::iterator it = l.begin();
    for (int i = 0; i < size; i++)
        garbage[i] = *it++;
    garbage[size] = symbol;

    l.erase(l.begin(), l.end());
    quickSort(garbage, 0, size);

    for (int i = 0; i < size + 1; i++)
        l.push_back(garbage[i]);
    
    delete[] garbage;
}

void Menu(list<char>& l1, char& symbol, list<char>& l2)
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
            add(l1, amount);
            
            break;
        }
        case 2:
        {
            cout << "Creating a new list...";

            Task(l1, l2);
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
            print(l1);
            cout << "====================SECOND=LIST=OF=STUDENTS========================" << endl;
            print(l2);

            break;
        }

        default:
            break;
        }

        cout << endl;
    }
}

int main() {

    list<char> l1, l2;
    char symbol;

    Menu(l1, symbol, l2);

    return 0;
}