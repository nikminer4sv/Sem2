#include <iostream>
#include <tuple>

using namespace std;

bool WordInText(const char* text, const char* word) {
    return strstr(text, word) != nullptr;
}

bool IsSeparator(char symbol) {
    static const char array[] = ".,:;!?-() ";
    return strchr(array, symbol) != nullptr;
}

char* EditText(char* text) {
    char* result = new char[256];
    int resultIndex = 0;

    int index = -1;
    bool isWord = false;

    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (IsSeparator(text[i])) {
            if (isWord == true) {
                isWord = false;
                
                char* word = new char[i - index]{};
                for (int j = 0; j < i - index; j++) {
                    word[j] = text[j + index];
                }

                if (!WordInText(result, word)) {
                    for (int j = 0; j < i - index; j++) {
                        result[resultIndex++] = word[j];
                    }
                } 

                delete[] word;        
            }

            result[resultIndex++] = text[i];

        } else {
            if (isWord == false) {
                index = i;
                isWord = true;
            }
        }
    }

    return result;
}

int main() {
    char* text = new char[256]{};
    gets(text);

    auto result = EditText(text);
    cout << result;

    delete[] result;
}