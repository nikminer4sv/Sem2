#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>

using namespace std;

void Amount(vector<string> program, vector<string>& functions)
{
    for (size_t i = 0; i < functions.size(); i++)
    {
        int count = 0;
        for (size_t j = 0; j < program.size(); j++)
        {
            auto pos = program[j].find(functions[i]);
            if (pos != string::npos)
                count++;
        }
        functions[i] += " -- " + to_string(count);
    }
}

void Search(string line, vector<string>& functions)
{
    char text[200];
    strcpy_s(text, line.c_str());
    regex str_expr("([\\w*&]*?)\\s?(\\w*?)\\((.*?)\\)");
    cmatch cm;
    regex_match(text, cm, str_expr);
    if (cm.size() > 0)
    { 
        functions.push_back(cm[2]);
    }  
}

int main()
{
    vector<string> program;
    vector<string> functions;
    ifstream ifs("FindFunction.cpp");
    while (!ifs.eof())
    {
        string line;
        getline(ifs, line);
        program.push_back(line);
        Search(line, functions);
    }
    Amount(program, functions);
    for (string temp : functions)
    {
        cout << temp << endl;
    }
}