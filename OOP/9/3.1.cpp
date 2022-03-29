#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string IntToHex(int a) {
    stringstream s;
    s << hex << a;
    return s.str();
}

bool IsPalindrom(const string& input) {
    auto it_1 = input.begin();
    auto it_2 = input.rbegin();

    while(it_1 != input.end() && it_2 != input.rend()){
        if(*it_1 != *it_2){
            return false;
        }

        ++it_1;
        ++it_2;
    }

    return true;
}

void t4_1() {

    string input;
    getline(cin, input);

    int pos = 0;
    while (true) {

        int a = input.find("(", pos);
        int b = input.find(")", pos);

        if (a >= 0 && b < 0) {
            input.replace(a, input.size() - a, "");
            break;
        } else if (a >= 0 && b >= 0) {
            input.replace(a, b - a + 1, "");
            pos = a + 1;
        } else {
            break;
        }
        
    }

    cout << input << endl;

}

void t4_2() {

    for(size_t i = 0;i < 1000000; i++) {
        if (IsPalindrom(to_string(i)) && IsPalindrom(IntToHex(i))) 
            cout << i << " " << IntToHex(i) << endl;

    }

}

vector<string> Split(const string& input) {

    vector<string> words;

    int pos = 0;
    while (true) {

        int index = input.find(" ", pos);

        if (index == -1) {
            break;
        } else {
            words.push_back(input.substr(pos, index - pos));
            pos = index + 1;
        }

    }

    words.push_back(input.substr(pos, input.size() - pos));

    return words;

}

void t4_3() {

    string input;
    getline(cin, input);

    vector<string> words = Split(input);
    vector<string> result;

    for (const auto& word : words) {
        
        bool flag = true;
        for (size_t i = 0; i < word.size() - 1; i++) {
            if (std::tolower(word[i]) > std::tolower(word[i + 1])) {
                flag = false;
                break;
            }
        }

        if (flag)
            result.push_back(word);

    }

    for (string word : result) 
        cout << word << endl;

}

int main() {
    
    t4_3();

}