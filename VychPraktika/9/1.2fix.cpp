#include <iostream>
#include <tuple>

using namespace std;

bool WordInText(char* text, char* word, int wordLength) {

    if (strlen(text) < wordLength)
        return false;

    for (int i = 0; i < strlen(text) - wordLength + 1;i++) {

        int counter = 0;

        for (int j = 0; j < wordLength; j++) {

            if (word[j] == text[i + j]) {
                counter += 1;
            }

        }

        if (counter == wordLength) {
            return true;
        }

    }

    return false;

}

bool IsSeparator(char symbol) {

    char array[] = ".,:;!?-() ";

    for (char separator : array) {

        if (separator == symbol)
            return true;

    }

    return false;

}

tuple<char*, int> EditText(char* text) {

    char* result = new char[256];
    int resultIndex = 0;

    int index = -1;
    bool isWord = false;

    for (int i = 0; i < strlen(text); i++) {

        if (IsSeparator(text[i])) {

            if (isWord == true) {

                isWord = false;
                
                char* word = new char[i - index];
                
                for (int j = 0; j < i - index; j++) {
                    word[j] = text[j + index];
                }

                if (!WordInText(result, word, i - index)) {
                    for (int j = 0; j < i - index; j++) {
                        result[resultIndex++] = word[j];
                    }

                }         

            }

            result[resultIndex++] = text[i];

        } else {

            if (isWord == false) {
                index = i;
                isWord = true;
            }

        }

    }

    return make_tuple(result, resultIndex);

}

int main() {

    char* text = new char[256];
    gets(text);
    
    char* result;
    int resultSize;

    tie(result, resultSize) = EditText(text);

    for (int i = 0; i < resultSize + 1; i++) {

        cout << result[i];
                
    }

}