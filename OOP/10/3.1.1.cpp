#include <iostream>
#include <string>

using namespace std;

bool is_identifier(string& s)
{
    int i = 0;
    if (!s.size() || !isalpha(s[i++])) return false;
    while (i < s.size()) if (!isalnum(s[i++])) return false;
    return true;
}

bool is_number(string& s)
{
    int i = 0;
    if (!s.size() || !(isdigit(s[i]) || (s[i++] == '-'))) return false;
    while (i < s.size()) if (!isdigit(s[i++])) return false;
    return true;
}

int main() 
{
    string Array;
    getline(cin, Array);
    bool ind = is_identifier(Array);
    bool num = is_number(Array);
    if (!ind && !num)
    {
        cout << "Invalid";
    }
    else if (num)
    {
        cout << "Number";
    }
    else
    {
        cout << "Identifer";
    }
}