#include <iostream>
#include <list>

using namespace std;

void t2_4() {

    list<char> list1{'a', 'b', 'c', 'd', 'e', 'f'};
    list<char> list2{'d', 'e'};

    for (size_t i = 0; i < list1.size() - list2.size(); i++) {
        
        bool flag = true;
        for (size_t j = 0; j < list2.size(); j++) {
            list<char>::iterator it1 = list1.begin();
            advance(it1, i + j);
            list<char>::iterator it2 = list2.begin();
            advance(it2, j);
            if (*it1 != *it2) {
                flag = false;
                break;
            }
        }

        if (flag) {
            list<char>::iterator it = list1.begin();
            advance(it, i);
            for (size_t j = 0; j < list2.size(); j++) {

                list1.erase(it);
            }
        }

    }

    list<char>::iterator it = list1.begin();
    for (int i = 0; i < list1.size(); i++) {
        cout << *it;
        advance(it, 1);
    }

}

int main() {

    t2_4();

}