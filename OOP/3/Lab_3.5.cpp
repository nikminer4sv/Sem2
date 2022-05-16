#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

struct Element {
    int counter{};
    vector<int> lines{};

    Element() = default;
};

void Search(const string& line, int lineNumber, map<string, Element>& literals) {
    smatch match;
    if (regex_match(line, match, regex(".*?\"(\\w*)\".*?|.*?(\\d+(\\.\\d+)?).*?"))) {
        size_t index = 1;
        if (match[index] == "")
            index = 2;

        literals[match[index]].counter++;
        literals[match[index]].lines.push_back(lineNumber);
    }
}

int main() {

    const string FILE_NAME = "3.5_testfile.txt";

    map<string, Element> literals;
    ifstream ifs(FILE_NAME);
    
    int line_number = 1;
    while (!ifs.eof()) {
        string line;
        getline(ifs, line);
        Search(line, line_number++, literals);
    }

    for (const auto& item : literals) {
        cout << item.first << " | " << item.second.counter << " | ";
        for (const auto& element : item.second.lines)
            cout << element << " ";
        cout << endl;
    }

}
