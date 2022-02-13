#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<char> s;

    char* text = new char[256];
    gets(text);

    int temp = -1;

    for (int i = 0; i < strlen(text); i++) {

        if (text[i] == ' ') {

            for (int j = i - 1; j > temp; j--) {

                //cout << text[j];
                s.push(text[j]);

            }

            temp = i;
            s.push(' ');

        }

    }

    for (int j = strlen(text); j > temp; j--) {

        s.push(text[j]);

    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

}