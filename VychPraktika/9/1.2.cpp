#include <iostream>

using namespace std;

bool isSeparator(char symbol) {

    char array[] = ".,:;!?-() ";

    for (char separator : array) {

        if (separator == symbol)
            return true;

    }

    return false;

}

bool WordInText(char* text, char* word) {

    if (strlen(text) == 0)
        return false;

    for (int i = 0; i < strlen(text) - strlen(word) + 1; i++) {

        int counter = 0;

        for (int j = 0; j < strlen(word); j++) {

            if (word[j] == text[i + j])
                counter += 1;

        }

        if (counter == strlen(word))
            return true;

    }

    return false;

}

// hello, my little friend friend b b c.

char* EditText(char* text) {

    char* result = new char[strlen(text)];
    int resultIndex = 0;

    bool isWord = false;
    int wordStartIndex = 0;

    for (int i = 0; i < strlen(text); i++) {

        if (!isSeparator(text[i])) {

            if (isWord == false) {
                wordStartIndex = i;
                isWord = true;
            }

        } else {

            if (isWord == true) {

                char* word = new char[i - wordStartIndex];
                int wordIndex = 0;

                for (int j = wordStartIndex; j < i; j++) {
                    word[wordIndex++] = text[j];
                }

                if (!WordInText(result, word)) {

                    for (int j = wordStartIndex; j < i; j++) {
                        result[resultIndex++] = text[j];
                    }

                }

                isWord = false;

            }

            result[resultIndex++] = text[i];

        }

    }

    if (isWord == true) {

        char* word = new char[strlen(text) - wordStartIndex];
        int wordIndex = 0;

        for (int j = wordStartIndex; j < strlen(text); j++) {
            word[wordIndex++] = text[j];
        }

        if (!WordInText(result, word)) {

            for (int j = wordStartIndex; j < strlen(text); j++) {
                result[resultIndex++] = text[j];
            }

        }

    }

    return result;

}

int main() {

    char* text = new char[256];
    char* result = new char[256];
    gets(text);

    result = EditText(text);

    for (int i = 0; i < strlen(result); i++) {
        cout << result[i];
    }

}