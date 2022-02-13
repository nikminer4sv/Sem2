#include <iostream>

using namespace std;

class ArrayList {
private:
    char* array;
    int rawSize;

public:
    int size;
    int shiftSize = 5;

private:
    void Shift() {

        char* array = new char[size + shiftSize];

        for (int i = 0; i < size; i++)
            array[i] = this->array[i];

        this->array = array;

        rawSize += shiftSize;

    }

public:

    void Test() {
        cout << rawSize << endl;
    }

    ArrayList(int n) {
        array = new char[n];
        size = 0;
        rawSize = n;
    }

    void Add(char symbol) {

        if (size == rawSize) 
            Shift();

        array[size++] = symbol;

    }

    char Get(int index) {

        if (index > size - 1 || index < 0)
            throw invalid_argument("Invalid index");

        return array[index];

    }

    void Remove(int index) {

        if (index > size - 1 || index < 0)
            throw invalid_argument("Invalid index");

        char* array = new char[rawSize - 1];
        
        for (int i = 0; i < index; i++)
            array[i] = this->array[i];

        for (int i = index + 1; i < size; i++)
            array[i - 1] = this->array[i];

        this->array = array;

        size -= 1;

    }

    ~ArrayList() {

        delete[] array;

    }


};

void PrintList(ArrayList& list) {

    for (int i = 0; i < list.size; i++)
        cout << list.Get(i) << " ";

    cout << endl;

}

void Task(ArrayList& list1, ArrayList& list2) {
    if (list2.size == 0 || list1.size - list2.size < 0) 
        return;

    int forSize = list1.size - list2.size;

    for (int i = 0; i < forSize + 1; i++) {

        bool exist = true;

        for (int j = 0; j < list2.size; j++) {

            if (list1.Get(i + j) != list2.Get(j)) {

                exist = false;
                break;

            }

        }

        if (exist) {

            for (int j = 0; j < list2.size; j++) {
                list1.Remove(i);
            }

            forSize = list1.size - list2.size;

        }

    }
}

int main() {

    ArrayList list1(5);
    list1.Add('h');
    list1.Add('e');
    list1.Add('l');
    list1.Add('l');
    list1.Add('o');

    ArrayList list2(3);
    list2.Add('0');


    Task(list1, list2);

    PrintList(list1);


}