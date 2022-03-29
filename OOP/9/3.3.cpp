#include <iostream>
#include <list>

using namespace std;

void t2_4() {

    list<char> list1{'a', 'b', 'c', 'd', 'e', 'f'};
    list<char> list2{'d', 'e'};

    int forSize = list1.size() - list2.size();
    for (int i = 0; i < forSize + 1; i++) {

        bool exist = true;

        for (int j = 0; j < list2.size(); j++) {
            
            auto it1 = next(list1.begin(), i + j);
            auto it2 = next(list2.begin(), j);    
            if (*it1 != *it2) {
                exist = false;
                break;
            }

        }

        if (exist) {
            auto it1 = next(list1.begin(), i);
            auto it2 = next(list1.begin(), i + list2.size());
            list1.erase(it1, it2);

            forSize = list1.size() - list2.size();

        }
    }

    for (auto it1 = list1.begin(); it1 != list1.end(); ++it1)
        cout << *it1;

    cout << endl;

}

void t2_6() {

    list<int> l{2,4,1,3,5,6,2,3,4,10};
    int min = INT_MAX;
    
    auto left = l.begin();
    auto right = l.rbegin();

    for (int i = 0; i < l.size() / 2; i++) {
        int sum = *left + *right;
        cout << *left << " " << *right << endl;

        if (sum < min)
            min = sum;

        ++left;
        ++right;

    }

    cout << min;

}

int main() {

    t2_6();

}