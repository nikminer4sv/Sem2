#include <iostream>
#include <string>
using namespace std;

void deleteOneSymbol(string& obj)
{
    const string constObj = obj;
    for (int i = 0; i < constObj.size(); i++)
    {
        int quantity = 0;
        string rabbit = obj;

        while (rabbit.find_first_of(constObj[i]) != -1)
        {
            rabbit.erase(rabbit.find_first_of(constObj[i]), 1);
            quantity++;
        }

        if (quantity == 1)
        {
            obj.erase(obj.find_first_of(constObj[i]), 1);
        }
    }
}

int main()
{
    string text;
    getline(cin, text);
    deleteOneSymbol(text);
    cout << text << endl;

	return 0;
}