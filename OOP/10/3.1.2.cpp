#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

static const string k_base_symbols = "0123456789ABCDEF";

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

string DecToAny(size_t number, size_t base, const string base_symbols = k_base_symbols)
{
    size_t a_number = number;
    string temp, temp1;
    int string_size = 0;

    do
    {
        temp.push_back(base_symbols[a_number % base]);
        a_number /= base;
        ++string_size;
    } while (a_number != 0);

    while (string_size != 0)
    {
        temp1.push_back(temp[--string_size]);
    }

    return temp1;
}

int main(int argc, char** argv)
{
    size_t base1, base2;
    string number;
    cout << "Enter a number and first base" << endl;
    cin >> number >> base1;
    cout << "Enter second base" << endl;
    cin >> base2;
    cout << number << " in base "
        << base1 << " to base "
        << base2 << " = "
        << DecToAny(AnyToDec(number, base1), base2);
}