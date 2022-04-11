#include <iostream>
#include <cstring>
#include <list>
#include <algorithm>

using namespace std;

bool Search(list<char>& listmain, list<char>& list1, auto pos)
{
    bool Flag = true;
    size_t size = list1.size();
    auto temp = list1.begin();

    while (temp != list1.end())
    {
        if (*temp != *pos)
        {
            Flag = false;
            break;
        }
        temp++;
        pos++;
    }

    return Flag;
}

void Task(list<char>& listmain, list<char>& list1, list<char>& list2)
{
    if (list1.size() == 0 || listmain.size() < list1.size())
        return;

    bool Flag = true;
    auto temp = list1.begin();
    auto pos = std::find(listmain.begin(), listmain.end(), *temp);

    while (pos != listmain.end())
    {
        Flag = Search(listmain, list1, pos);
        if (Flag)
        {
            for (int j = 0; j < list1.size(); j++)
            {
                pos = listmain.erase(pos);
            }

            auto temp = list2.begin();
            for (int j = 0; j < list2.size(); j++)
            {
                listmain.insert(pos, *temp++);
            }
        }
        pos = std::find(pos, listmain.end(), *temp);
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
