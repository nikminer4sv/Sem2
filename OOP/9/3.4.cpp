#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

string GetReversePolishNotation(string inputString) {
    
    string outputString = "";
	stack<char> operators;
	bool flag = false;

    for (int i = 0; i < inputString.length(); i++) {
		if (inputString[i] == '(')
			operators.push('(');
		else if (inputString[i] == ')') {
			while (operators.top() != '(') {
				outputString += operators.top();
				outputString += " ";
				operators.pop();
			}
			operators.pop();
		}
		else if (inputString[i] != '+' && inputString[i] != '-' && inputString[i] != '*' && 
			 inputString[i] != '/' && inputString[i] != '^') {

			string temp = "";

			while (inputString[i] != '+' && inputString[i] != '-' && inputString[i] != '*' && 
			       inputString[i] != '/' && inputString[i] != '^' && inputString[i] != ')' &&
			       inputString[i] != '(') {

				temp += inputString[i];
				if (i+1 != inputString.length())
					i++;
				else {
					flag = true;
					break;
				}
			}	
			
			i--;

			outputString += temp + " ";
			if (flag == true)
				break;
		} else {
			if ((!operators.empty()) && ((((inputString[i] == '+' || inputString[i] == '-') && 
			   (operators.top() != '('))) || ((operators.top() != '+' && operators.top() != '-') && operators.top() != '('))) {
				outputString += operators.top();
				outputString += " ";
				operators.pop();
				operators.push(inputString[i]);

			} else {
				operators.push(inputString[i]);
			}
        	}
	}
	while (!operators.empty()) {
		outputString += operators.top();
		outputString += " ";
		operators.pop();
	}

    return outputString;

}

vector<string> Split(const std::string& str) {
	vector<string> result;
	istringstream iss(str);
	for (string s; iss >> s; )
		result.push_back(s);
	return result;
}

bool IsOperator(string s) {

    if (s.length() > 1)
        return false;

    if (s == "+" || s == "-" || s == "/" || s == "*" || s == "^")
        return true;

    return false;

}

int ComputeValue(int a, int b, string expOperator) {

    if (expOperator == "+") 
        return (a + b);
    else if (expOperator == "-")
        return (a - b);
    else if (expOperator == "*")
        return (a * b);
    else if (expOperator == "/")
        return (a / b);
    else    
        return (pow(a, b));

}

int ComputeReversePolishNotation(string input) {

    stack<string> resulting;
    vector<string> elements = Split(input);
    for (string s : elements) {

        if (IsOperator(s)) {

            int b = stoi(resulting.top());
            resulting.pop();
            int a = stoi(resulting.top());
            resulting.pop();
            int value = ComputeValue(a, b, s);
            resulting.push(to_string(value));

        } else {
            resulting.push(s);
        }

    }

    return stoi(resulting.top());

}

int main() {
	
	string inputString;
	cin >> inputString;
    string reversedPolishNotation = GetReversePolishNotation(inputString);
    cout << ComputeReversePolishNotation(reversedPolishNotation) << endl;

}