#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

bool IsFunction(string line, auto pos, auto pos1)
{
    while (*pos == ' ')
    {
        ++pos;
    }
    if (!isalpha(*pos))
    {
        return false;
    }
    while (*pos != '(') 
    {
        if (*pos == ' ')
        {
            ++pos;
            continue;
        }
        if (!(isalnum(*pos) || *pos == '_' || *pos == '*' || *pos == '&')) 
        {
            return false;
        }
    }
    return true;
}

void Search(string line)
{
    auto pos = line.begin();
    auto pos1 = std::search(pos, line.end(), ";");
    while (pos1 != line.end())
    {
        bool flag = IsFunction(line, pos, pos1);
        if (flag)
        {
            while (pos != pos1)
            {
                cout << *pos;
                ++pos;
            }
        }
        auto pos = std::search(line.begin(), line.end(), ";");
        auto pos1 = std::search(pos, line.end(), ";");
    }
    
}

int main()
{
    string full = "";
    ifstream ifs("3.5.cpp");
    while (!ifs.eof())
    {
        string line;
        getline(ifs, line);
        full += line + " ";
    }
    cout << full << endl;
}

void*sos();