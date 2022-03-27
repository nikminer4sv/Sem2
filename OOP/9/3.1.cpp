#include <iostream>
#include <string>
#include <vector>

using namespace std;

string inttohex(int a)
{
    string tmp("");
    do
    {
        int r(a%16);
        if (r>9) {r+=(int)'A'-10;}
        else  {r+=(int)'0';};
        tmp=(char)r+tmp;
        a/=16;
    } while (a);
    return tmp;
}

bool IsPalindrom(string input) {

    string temp = input;
    reverse(input.begin(), input.end());

    if (input == temp)
        return true;
    else
        return false;

}

void t4_1() {

    string input;
    getline(cin, input);

    int pos = 0;

    while (true) {

        int a = input.find("(", pos);
        int b = input.find(")", pos);

        if (a != -1 && b == -1) {
            input.replace(a, input.size() - a, "");
            break;
        } else if (a != -1 && b != -1) {
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

        if (IsPalindrom(to_string(i)) && IsPalindrom(inttohex(i))) 
            cout << i << " " << inttohex(i) << endl;

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

    for (string word : words) {
        
        bool flag = true;
        for (size_t i = 0; i < word.size() - 1; i++) {
            if (word[i] > word[i + 1]) {
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
    
    //t4_2();
    t4_3();

    /*string input;
    cin >> input;
    cout << IsPalindrom(input);*/
    /*
    string str;
    getline(cin, str);
    regex e("\\([^)]*\\)");
    str = regex_replace(str, e, "");
    cout << str << "\n";

     string input;
    getline(cin, input);
    regex e("(\\(.*\\))|(\\(.*)");
    string a = regex_replace(input, e, "");

    cout << a;

    */

}