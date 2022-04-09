#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main(){

    std:list<char> a;
    a.push_back('c');
    a.push_back('b');
    a.push_back('a');
    a.push_back('b');
    a.push_back('c');
    


    std::list<char> b;

    for(const auto& el: a){
        if(count(a.begin(), a.end(), el) == 2 && 
           find(b.begin(), b.end(), el) == b.end()){
            b.push_back(el);
        }
    }

    for(const auto& el: b){
        cout << el << " ";
    }

    return 0;
}
