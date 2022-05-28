#include<iostream>
#include<cstring>
using namespace std;

class Test
{
public:
    Test(const char* text)
    {
        for (int i = 0; text[i] != '\0'; i++)
            size++;
        this->text = new char[++size];
        memcpy(this->text, text, size);
    }
    char* getText() const
    {
        char* copyText = new char[size];
        memcpy(copyText, text, size);

        return copyText;
    }
    
private:
    char* text = nullptr;
    int size = 0;
};

int main()
{
    Test obj("gei");
    char* fg = new char[20];
    fg = obj.getText();
    cout << fg << endl;
    cout << fg[0] << endl;
    fg[0] = 'h';
    cout << "test = " << fg << endl;
    fg = obj.getText();
    cout << fg << endl;


    return 0;
}