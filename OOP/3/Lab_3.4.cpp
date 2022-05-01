#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class ReversePolishEntry
{
private:
    stack<string> stackOperators;

    string operators = "><=!&|";
    string resultStr = "";

private:
    int Priority(const string &str)
    {
        if (str == "||" || str == "&&")
            return 2;
        else if (str == "==" || str == "!=")
            return 3;
        else if (str == ">=" || str == "<=" || str == ">" || str == "<")
            return 4;
        else if (str == "(")
            return 1;
    }

    bool ComputeValue(const int a, const int b, const string &expOperator)
    {
        if (expOperator == ">")
            return (a > b);
        else if (expOperator == "<")
            return (a < b);
        else if (expOperator == "==")
            return (a == b);
        else if (expOperator == "!=")
            return (a != b);
        else if (expOperator == ">=")
            return (a >= b);
        else if (expOperator == "<=")
            return (a <= b);
        else if (expOperator == "||")
            return a || b;
        else if (expOperator == "&&")
            return a && b;
    }

    bool IsOperator(const string &s)
    {
        if (s.length() > 2)
            return false;

        if (operators.find_first_of(s) == string::npos)
            return false;

        return true;
    }

    vector<string> Split(const string &str)
    {
        vector<string> result;
        istringstream iss(str);
        for (string s; iss >> s;)
            result.push_back(s);
        return result;
    }

public:
    bool ComputeReversePolishNotation(const string &input)
    {
        stack<string> resulting;
        vector<string> elements = Split(input);
        
        for (string s : elements)
        {
            if (IsOperator(s))
            {
                int b = stoi(resulting.top());
                resulting.pop();
                int a = stoi(resulting.top());
                resulting.pop();
                bool value = ComputeValue(a, b, s);
                resulting.push(to_string(value));
            }
            else
                resulting.push(s);
        }
        return stoi(resulting.top());
    }

    string convertToRPE2(const string &inputLine)
    {
        string tempStr = "";

        size_t startPosition = 0;
        size_t endPosition = 0;

        bool flag = true;

        while (flag)
        {
            endPosition = inputLine.find_first_of(operators, startPosition);
            for (size_t i = startPosition; i < endPosition; i++)
            {
                if (inputLine[i] == '(')
                {
                    stackOperators.push("(");
                    continue;
                }
                else if (inputLine[i] == ')')
                {
                    while (stackOperators.top() != "(")
                    {
                        resultStr += stackOperators.top();
                        resultStr += " ";
                        stackOperators.pop();
                    }
                    stackOperators.pop();
                    continue;
                }

                resultStr += inputLine[i];
            }
            resultStr += " ";
            startPosition = endPosition;

            endPosition = inputLine.find_first_not_of(operators, startPosition);
            for (size_t i = startPosition; i < endPosition; i++)
                tempStr += inputLine[i];
            startPosition = endPosition;

            if (stackOperators.empty())
            {
                stackOperators.push(tempStr);
            }
            else if (Priority(stackOperators.top()) < Priority(tempStr))
            {
                stackOperators.push(tempStr);
            }
            else
            {
                while (Priority(stackOperators.top()) >= Priority(tempStr))
                {
                    resultStr += stackOperators.top();
                    resultStr += " ";
                    stackOperators.pop();

                    if (stackOperators.empty())
                    {
                        stackOperators.push(tempStr);
                        tempStr = "";
                        break;
                    }
                }
                stackOperators.push(tempStr);
            }

           /* cout << "Check result = " << resultStr << "; STACK = " << stackOperators.top()
                 << "; TEMP STR = " << tempStr << "; START_POS = " << startPosition
                 << "; END_POS = " << endPosition << endl
                 << endl;*/

            tempStr = "";

            if (inputLine.find_first_not_of(operators, startPosition) == startPosition && inputLine.find_first_of(operators, startPosition) == string::npos)
            {
                endPosition = inputLine.size();

                for (size_t i = startPosition; i < endPosition; i++)
                {
                    if (inputLine[i] == '(')
                    {
                        stackOperators.push("(");
                        continue;
                    }
                    else if (inputLine[i] == ')')
                    {
                        while (stackOperators.top() != "(")
                        {
                            resultStr += " ";
                            resultStr += stackOperators.top();
                            stackOperators.pop();
                        }
                        resultStr += " ";
                        stackOperators.pop();
                        continue;
                    }
                    resultStr += inputLine[i];
                }
                while (!stackOperators.empty())
                {
                    resultStr += " ";
                    resultStr += stackOperators.top();
                    stackOperators.pop();
                }
               // cout << "THE END = " << resultStr << endl;
                flag = false;
            }
        }
        return resultStr;        
    }
};

int main()
{
    string inputLine;
    cout << "Enter the logical example: ";
    getline(cin, inputLine);
    ReversePolishEntry obj;
    string RPE = obj.convertToRPE2(inputLine);
    cout << "Reverse Polish Notation:\n" << RPE << endl;
    if (obj.ComputeReversePolishNotation(RPE))
        cout << "The answer = true " << obj.ComputeReversePolishNotation(RPE) << endl;
    else
        cout << "The answer = false " << obj.ComputeReversePolishNotation(RPE) << endl;
   
    return 0;
}