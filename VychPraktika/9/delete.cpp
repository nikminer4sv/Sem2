#include <iostream>
#include <tuple>

using namespace std;

bool isSeparator(char symbol) {

    char array[] = ".,:;!?-() ";

    for (char separator : array) {

        if (separator == symbol)
            return true;

    }

    return false;

}

char** SplitToWords(char* text, int& count) {

    char** result = new char*[256];
    int resultIndex = 0;

    bool isWord = false;
    int index = 0;

    for (int i = 0; i < strlen(text); i++) {

        if (!isSeparator(text[i])) {

            if (isWord == false) {

                index = i;
                isWord = true;

            }

        } else {

            if (isWord == true) {

                /*for (int j = index; j < i; j++)
                    cout << text[j];

                cout << endl;*/

                result[resultIndex] = new char[i - index];

                for (int j = 0; j < i - index; j++)
                    result[resultIndex][j] = text[j + index];

                resultIndex += 1;


                isWord = false;

            }

        }

    }

    if (isWord == true) {

        result[resultIndex] = new char[strlen(text) - index];

        for (int j = 0; j < strlen(text) - index; j++)
            result[resultIndex][j] = text[j + index];

        resultIndex += 1;

    }

    count = resultIndex;

    return result;

}

int main() {

    char* text = new char[256];
    gets(text);

    int count;
    char** result = SplitToWords(text, count);

    for (int i = 0; i < count; i++) {

        for (int j = 0; j < strlen(result[i]); j++) {

            cout << result[i][j];

        }

        cout << endl;

    }

}