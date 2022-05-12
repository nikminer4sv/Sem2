#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include <fstream>
#include <tuple>

using namespace std;

struct Element {
    int counter{};
    vector<int> lines{};

    Element() = default;
};

// \"(\w*)\"|(\d+(?:\.\d+)?)
// regex("\"(\\w*)\"|(\\d+(?:\\.\\d+)?)")))
void Search(string line, map<string, Element>& literals) {
    static int lineNumber = 1;
    smatch match;
    if (regex_match(line, match, regex(".*?\"(\\w*)\".*?|.*?(\\d+(?:\\.\\d+)?).*?"))) {
        size_t index = 1;
        if (match[index] == "")
            index = 2;
        if (literals.count(match[index]) == 0) {
            Element element;
            literals[match[index]] = element;
        }
        literals[match[index]].counter += 1;
        literals[match[index]].lines.push_back(lineNumber);
    }

    lineNumber += 1;
}

int main() {

    const string FILE_NAME = "3.5_testfile.cpp";

    map<string, Element> literals;

    vector<string> lines;
    ifstream ifs;
    ifs.open(FILE_NAME);
    while (!ifs.eof()) {
        string line;
        getline(ifs, line);
        lines.push_back(line);
        Search(line, literals);
    }

    for (auto& item : literals) {
        cout << item.first << " | " << item.second.counter << " | ";
        for (auto element : item.second.lines)
            cout << element << " ";
        cout << endl;
    }

}

/*

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
    strcpy(text, line.c_str());
    //regex str_expr("([\\w*&]*?)\\s?(\\w*?)\\((.*?)\\)");
    regex str_expr("\"(\\w*)\" | (\\d+(?:\\.\\d+)?)");
    cmatch cm;
    regex_match(text, cm, str_expr);
    if (cm.size() > 0) 
        functions.push_back(cm[2]);
     
}

int main() {

    const string FILE_NAME = "3.5_testfile.cpp";

    vector<string> program;
    vector<string> functions;
    ifstream ifs(FILE_NAME);
    while (!ifs.eof()) {
        string line;
        getline(ifs, line);
        program.push_back(line);
        Search(line, functions);
    }

    Amount(program, functions);
    for (string temp : functions)
        cout << temp << endl;
} */