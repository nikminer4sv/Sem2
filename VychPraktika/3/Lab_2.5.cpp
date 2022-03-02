#include <iostream>
#include <cstring>
#define Asize 255
using namespace std;

class TaskE
{
private:
    char data[Asize]{};
    int index[Asize]{};
    int idx = 0;

    int empty = -1;
    int tail = 0;

    bool firstZero = true;

public:

    void printData()
    {   
        int k = 0;
        while (index[k])
        {
            cout << data[k] << '\t';
            k = index[k];
            if (k == -1)
                k = index[k];
        }
        
        cout << data[k] << endl;   

        for (int i = 0; i < idx; i++)
            cout << index[i] << '\t';
        cout << endl;
    }

    void addText(const char text[])
    {   
        
        if (firstZero)
        {
            for (int i = 0; i < strlen(text); i++)
            {
                data[i] = text[i];
                index[idx] = ++idx;
            }

            index[idx - 1] = 0;
            firstZero = false;

            return;
        }  

        for (int i = 0; i < strlen(text); i++)
        {
            data[idx] = text[i];
            index[idx - 1] = idx++;
        }
        index[idx - 1] = 0;
    }

    void addSymbol(const char text)
    {   
        if (empty != -1)
        {
            data[empty] = text;
            index[tail] = empty;
            index[empty] = 0;
            empty = -1;

            return;  
        } 

        if (firstZero)
        {   
            data[idx] = text;
            index[idx] = ++idx;

            index[idx] = 0;
            firstZero = false;

            return;
        }  
        
        int temp = 0;
        int idLocation;


        cout << "Enter the index" << endl;
        cin >> idLocation;
        idLocation--;

        data[idx] = text;
        index[idx] = idx++;
        
        for (int i = 0; i < idx; i++)
        {
            cout << index[i] << '\t';
        }
        cout << endl;
        
        if (idLocation == 0)
            idLocation++;
        
        temp = index[idLocation - 1];

        index[idLocation - 1] = index[idx - 1];
        index[idx - 1] = temp;
        
    }

    void printText()
    {

        for (int i = 0; i < idx; i++)
            cout << data[i] << '\t';

        cout << endl;

    }

    void Task(TaskE& list2)
    {
        char Temp[Asize];
        int k = 0;
        for (int i = 0; i < idx; i++)
        {
            int quantity = 1;
            for (int j = 0; j < idx; j++)
            {
                if (data[i] == data[j] && i != j)
                    quantity++;
                  
            }
            if (quantity == 2)
                Temp[k++] = data[i];
        }
        Temp[k] = '\0';
        list2.addText(Temp);
    }

    void DeleteSymbol(const int x)
    {
        
        int k = 0;
        int it = 0;

        while (index[k])
        {
            int prevK = k;
            k = index[k];
            it++;
            if (it == x) 
            {   
                index[prevK] = index[k];
                data[k] = '*';
                index[k] = -1;

                cout << it << endl;
                cout << data[it] << endl;
                cout << k << endl;
                break;
            }
               
        }

        it = 0;
        tail = index[0];

        while (tail != 0)
            tail = index[++it];

        tail = index[--it];


        cout << tail << endl;

        empty = -1;
        for (int i = 0; i < idx; i++)
        {
            if (index[i] == -1)
                empty = i;
        }
        
        if (empty == -1)
            return;

    }
};


void menu(TaskE& list1, TaskE& list2)
{   
    bool menu = true;
    char text[Asize]{};
    while (menu)
    {
        cout << "Enter the choose: " << endl;
        int choose;
        cout << "1. Add text\n" 
            << "2. Add symbol\n" 
            << "3. Task\n" 
            << "4. Delete element\n"
            << "5. Print\n"
            << "6. Exit\n";
        cin >> choose;
        switch (choose)
        {
        case 1:
            {   
                cin.get();
                cout << "Enter the text: " << endl;
                cin.getline(text, Asize);
                list1.addText(text);

                break;
            }
        case 2:
            {
                char ch;
                cout << "Enter the symbol: ";
                cin >> ch;
                list1.addSymbol(ch);
                break;
            }
        case 3:
            {
                list1.Task(list2);
                break;
            }
        case 4:
            {
                int x;
                cout << "Enter the index" << endl;
                cin >> x;
                list1.DeleteSymbol(x - 1);
                break;
            }
        case 5:
            {
                cout << "LIST-1" << endl;
                list1.printData();
                list1.printText();
                cout << "LIST-2" << endl;
                list2.printData();
                //list2.printText();
                break;
            }
        case 6:
            {
                menu = false;
                break;
            }

        default:
            break;
        }

    }
    
}

int main()
{

    TaskE list1, list2;

    menu(list1,list2);
    
    return 0;
}