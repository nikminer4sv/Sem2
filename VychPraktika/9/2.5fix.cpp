#include <iostream>

using namespace std;

class ArrayList {
private:
    char* components = new char[256];
    int* indices = new int[256];
    int startIndex = 0;
    int endIndex = 0;

public:

private:
    struct InvalidIndex : public exception{

        const char * what () const throw () {
            return "Index must be right:)";
        }

    };

public:

    char Get(int index) {

        if (index < 0 || index > GetSize() - 1) 
            throw InvalidIndex();

        int tempIndex = startIndex;

        for (int i = 0; i < index; i++ )
            tempIndex = indices[tempIndex];

        return components[tempIndex];

    }

    int GetSize() {

        if (endIndex == startIndex)
            return 0;

        int index = startIndex;
        int counter = 0;

        while (indices[index] != 0) {

            counter += 1;
            index = indices[index];

        }

        return counter + 1;

    }

    void PrintRawData() {

        for (int i = 0; i < endIndex; i++)
            cout << components[i] << " ";

        cout << endl;

        for (int i = 0; i < endIndex; i++)
            cout << indices[i] << " ";

        cout << endl;

    }

    void Delete(int index) {

        if (index < 0 || index > GetSize() - 1) 
            throw InvalidIndex();
        

        if (index == 0) {
            startIndex = indices[startIndex];
            return;
        }

        int tempValue = startIndex;
        for (int i = 0; i < index - 1; i++) 
            tempValue = indices[tempValue];

        indices[tempValue] = indices[indices[tempValue]];

        // H e l g o i
        // 5 2 3 4 0 1

        // H i e l g o

    }

    void Append(char value) {

        if (endIndex == 0) {
            components[endIndex++] = value;
            return;
        }

        components[endIndex] = value;
        indices[endIndex - 1] = endIndex;
        endIndex += 1;


    }

    void Insert(char value, int index) {

        if (index < 0 || index > GetSize() - 1) 
            throw InvalidIndex();

        components[endIndex] = value;
        indices[index - 1] = endIndex;
        indices[endIndex] = index;
        endIndex += 1;

    }

    void Print() {

        int index = startIndex;

        while (indices[index] != 0) {

            cout << components[index] << " ";
            index = indices[index];

        }

        cout << components[index];

        cout << endl;

    }
};

void Task(ArrayList& list1, ArrayList& list2) {

    if (list2.GetSize() == 0 || list1.GetSize() - list2.GetSize() < 0) 
        return;

    int forSize = list1.GetSize() - list2.GetSize();

    for (int i = 0; i < forSize; i++) {

        bool exist = true;

        for (int j = 0; j < list2.GetSize(); j++) {

            if (list1.Get(i + j) != list2.Get(j)) {

                exist = false;
                break;

            }

        }

        if (exist) {
            
            for (int j = 0; j < list2.GetSize(); j++) {
                list1.Delete(i);
                cout << i << endl;
            }

        }

    }
}


int main() {

    ArrayList list1;
    list1.Append('H');
    list1.Append('e');
    list1.Append('l');
    list1.Append('l');
    list1.Append('o');
    list1.Print();

    ArrayList list2;
    list2.Append('e');
    list2.Append('l');

    Task(list1, list2);
    /*list1.Delete(1);
    list1.Delete(1);
    list1.Delete(1);
    list1.Delete(1);
    list1.Print();*/

    // 1 3 6 9
    // 1 3 3 0

    /*for (int i = 0; i < SIZE; i++) 
        cout << components[i] << " ";
    cout << endl;
    for (int i = 0; i < SIZE; i++) 
        cout << indices[i] << " ";
    cout << endl;*/

    //Print();

    // H e l l o i 
    // 5 2 3 4 0 1

    //list1.PrintRawData();
    list1.Print();

}