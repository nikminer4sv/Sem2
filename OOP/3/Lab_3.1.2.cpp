#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

static const string k_base_symbols = "01";

bool IsLegalNumber(const string str, size_t base, const string base_symbols = k_base_symbols)
{
    size_t pos = 0;
    while (str[pos])
    {
        int i = 0;
        while (str[pos] != base_symbols[i])
        {
            i++;
        }

        if (i > base)
            return false;

        ++pos;
    }

    return true;
}

size_t AnyToDec(const string str, size_t base, const string base_symbols = k_base_symbols)
{
    size_t result = 0;
    size_t string_length = str.length();
    assert(base <= base_symbols.length());
    assert(IsLegalNumber(str, base));

    for (int i = string_length - 1, counter = 0; i >= 0; --i, ++counter)
    {
        int digit = 0;
        while (base_symbols[digit] != str[i])
            digit++;
        result += digit * pow(base, counter);
    }

    return result;
}

int main()
{
    string number;
    int base = 2;
    cout << "Enter a number and first base" << endl;
    cin >> number;
    cout << number << " in base 2 = " << AnyToDec(number, base);
}