#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class ReversePolishEntry
{
private:
    stack<string> STACK_OPERATORS;

    string OPERATORS = "><=!&|";
    string RESULT_STR = "";

    bool IsOperator(const string &s)
    {
        if (s.length() > 2)
            return false;

        if (OPERATORS.find_first_of(s, 0) != string::npos)
            return true;

        return false;
    }

    bool ComputeValue(int a, int b, const string &expOperator)
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

    vector<string> Split(const string &str)
    {
        vector<string> result;
        istringstream iss(str);
        for (string s; iss >> s;)
            result.push_back(s);
        return result;
    }

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

    string convertToRPE2(string &inputLine)
    {
        string TEMP_STR = "";

        size_t startPosition = 0;
        size_t endPosition = 0;

        bool flag = true;

        while (flag)
        {
            endPosition = inputLine.find_first_of(OPERATORS, startPosition);
            for (size_t i = startPosition; i < endPosition; i++)
            {
                if (inputLine[i] == '(')
                {
                    STACK_OPERATORS.push("(");
                    continue;
                }
                else if (inputLine[i] == ')')
                {
                    while (STACK_OPERATORS.top() != "(")
                    {
                        RESULT_STR += STACK_OPERATORS.top();
                        RESULT_STR += " ";
                        STACK_OPERATORS.pop();
                    }
                    STACK_OPERATORS.pop();
                    continue;
                }

                RESULT_STR += inputLine[i];
            }
            RESULT_STR += " ";
            startPosition = endPosition;

            endPosition = inputLine.find_first_not_of(OPERATORS, startPosition);
            for (size_t i = startPosition; i < endPosition; i++)
                TEMP_STR += inputLine[i];
            startPosition = endPosition;

            if (STACK_OPERATORS.empty())
            {
                STACK_OPERATORS.push(TEMP_STR);
            }
            else if (Priority(STACK_OPERATORS.top()) < Priority(TEMP_STR))
            {
                STACK_OPERATORS.push(TEMP_STR);
            }
            else
            {
                while (Priority(STACK_OPERATORS.top()) >= Priority(TEMP_STR))
                {
                    RESULT_STR += STACK_OPERATORS.top();
                    RESULT_STR += " ";
                    STACK_OPERATORS.pop();

                    if (STACK_OPERATORS.empty())
                    {
                        STACK_OPERATORS.push(TEMP_STR);
                        TEMP_STR = "";
                        break;
                    }
                }
                STACK_OPERATORS.push(TEMP_STR);
            }

           /* cout << "Check result = " << RESULT_STR << "; STACK = " << STACK_OPERATORS.top()
                 << "; TEMP STR = " << TEMP_STR << "; START_POS = " << startPosition
                 << "; END_POS = " << endPosition << endl
                 << endl;*/

            TEMP_STR = "";

            if (inputLine.find_first_not_of(OPERATORS, startPosition) == startPosition && inputLine.find_first_of(OPERATORS, startPosition) == string::npos)
            {
                
                endPosition = inputLine.size();

                for (size_t i = startPosition; i < endPosition; i++)
                {
                    if (inputLine[i] == '(')
                    {
                        STACK_OPERATORS.push("(");
                        continue;
                    }
                    else if (inputLine[i] == ')')
                    {
                        while (STACK_OPERATORS.top() != "(")
                        {
                            RESULT_STR += " ";
                            RESULT_STR += STACK_OPERATORS.top();
                            STACK_OPERATORS.pop();
                        }
                        RESULT_STR += " ";
                        STACK_OPERATORS.pop();
                        continue;
                    }
                    RESULT_STR += inputLine[i];
                }
                while (!STACK_OPERATORS.empty())
                {
                    RESULT_STR += " ";
                    RESULT_STR += STACK_OPERATORS.top();
                    STACK_OPERATORS.pop();
                }

               // cout << "THE END = " << RESULT_STR << endl;
                flag = false;
            }
        }
        return RESULT_STR;        
    }
};
int main()
{
    string inputLine;
    cout << "Enter the mathemathical example: ";
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