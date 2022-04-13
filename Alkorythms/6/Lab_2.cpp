#include <iostream>
#include <string>

using namespace std;

struct Data {
    string definition;
    size_t vowel;

    Data() = default;

    Data(string definition, size_t vowel) {
        definition = definition;
        vowel = vowel;
    }
};

struct Element {
    string key;
    Data data;
    Element* next;
};

class HashMap {
private:
    Element* _head = nullptr;

public:

    HashMap() = default;

    void Append(string key, const Data& data) {
        Element* element = new Element;
        element->data = data;
        element->key = key;

        Element* temp = _head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = element;
    }

    Data& operator[](string key) {
        
        Element* temp = _head;
        while (temp->next != nullptr)
            if (temp->key == key)
                return temp->data;

        return _head->data;

    }

};

int main() {

    Data data("Definition", 3);
    HashMap map;
    map.Append("ggwp", data);

    cout << map["ggwp"].definition;

}