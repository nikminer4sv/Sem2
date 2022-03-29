#include <iostream>
#include <cstring>
#include <iterator>
#include <list>

using namespace std;

char Get(list<char>& list1, int Index)
{
    if (Index > list1.size() - 1 || Index < 0)
    {
        throw std::invalid_argument("Invalid index");
    }

    list<char>::iterator it = list1.begin();
    advance(it, Index);

    return *it;
}

bool Search(list<char>& listmain, list<char>& list1, size_t index)
{
    bool Flag = true;
    size_t size = list1.size();

    for (int j = 0; j < size; j++)
    {
        if (Get(listmain, index + j) != Get(list1, j))
        {
            Flag = false;
            break;
        }
    }

    return Flag;
}

void Task(list<char>& listmain, list<char>& list1, list<char>& list2)
{
    if (list1.size() == 0 || listmain.size() < list1.size())
        return;

    int forSize = listmain.size() - list1.size();
    bool Flag = true;
    int i = 0;
    list<char>::iterator pos = listmain.begin(), pos1 = listmain.begin();

    for (; i < forSize; i++)
    {
        Flag = Search(listmain, list1, i);
        if (Flag)
        {
            advance(pos, i);
            for (int j = 0; j < list1.size(); j++)
            {
                pos = listmain.erase(pos);
            }

            int k = i;
            advance(pos1, k);

            for (int j = 0; j < list2.size(); j++)
            {
                listmain.insert(pos1, Get(list2, j));
            }

            forSize = listmain.size() + list2.size() - list1.size();
        }
    }
}

int main() {

    list<char> listmain, list1, list2;
    const char* textmain = "Modern problems require modern solutions";
    const char* text1 = "problems";
    const char* text2 = "people";

    while (*textmain)
    {
        listmain.push_back(*textmain++);
    }
    while (*text1)
    {
        list1.push_back(*text1++);
    }
    while (*text2)
    {
        list2.push_back(*text2++);
    }

    Task(listmain, list1, list2);

    for (char symb : listmain)
        cout << symb;
}