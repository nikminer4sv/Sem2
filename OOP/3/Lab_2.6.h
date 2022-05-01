#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class bit256BinaryNumber
{
private:
    const int capacity = 256;
    short size = 0;
    string result = "0";
    string maxBit = "";

private:
    void plusOnDigital(string& result, const int digital)
    {
        int temp2 = 0;
        string temp = "0";

        temp = to_string((result[result.size() - 1] - '0') + digital);
        if (temp.size() == 1)
            result[result.size() - 1] = (((result[result.size() - 1] - '0') + digital) + '0');
        else
        {
            for (int j = result.size() - 1; j >= 0; j--)
            {
                if (temp2)
                {
                    temp = to_string(((result[j] - '0') + temp2) + '0');
                    if (temp.size() == 1)
                    {
                        result[j] = (((result[j] - '0') + temp2) + '0');
                        break;
                    }
                }
                result[j] = temp[1];
                temp2 = temp[0] - '0';
            }

            if (temp2 && temp.size() > 1)
                result.insert(temp2, 0);
        }
    }

    void IndexValidation(size_t index) const
    {
        if (index >= capacity)
            throw std::invalid_argument("Invalid index!");
    }

    void clear()
    {
        maxBit = "";
        result = "0";
        size = 0;
    }

    void print()
    {
        cout << maxBit << endl;
    }

public:
    bit256BinaryNumber() = default;

    bit256BinaryNumber(string& str)
    {
        IndexValidation(str.size());
        size = str.size();
        maxBit = str;
    }

    bit256BinaryNumber(const bit256BinaryNumber& object)
    {
        clear();

        result = object.result;
        size = object.maxBit.size();

        maxBit = object.maxBit;
    }

    bit256BinaryNumber& operator=(const bit256BinaryNumber& object)
    {
        this->clear();

        this->result = object.result;
        this->size = object.maxBit.size();

        this->maxBit = object.maxBit;

        return *this;
    }

    char& operator[](const size_t idx)
    {
        IndexValidation(idx);
        return maxBit[idx];
    }

    const char operator[](const size_t idx) const
    {
        IndexValidation(idx);
        return maxBit[idx];
    }

    friend ostream& operator<<(ostream& os, const bit256BinaryNumber& object)
    {
        os << "Bits -> " << object.maxBit << endl;
        os << "Capacity -> " << object.capacity << "; size -> " << object.size << endl;
        os << "Decitimal number (or task) -> " << object.result << endl;

        return os;
    }

    friend istream& operator>>(istream& os, bit256BinaryNumber& object)
    {
        cout << "Enter the binary digital: ";
        string str;
        getline(os, str);
        object.clear();
        object.size = str.size();
        object.result = "0";
        object.maxBit = str;

        return os;
    }

    const bit256BinaryNumber& operator-(const bit256BinaryNumber& object) const
    {
        bit256BinaryNumber tempStr2 = object;
        bit256BinaryNumber tempStr1 = *this;
        bit256BinaryNumber tempAnswer;

        tempAnswer.maxBit.resize(tempStr1.maxBit.size());
        for (size_t i = 0; i < tempAnswer.maxBit.size(); i++)
            tempAnswer.maxBit[i] = '0';
        // cout << tempStr2.maxBit << endl;

        if (tempStr1.maxBit.size() > tempStr2.maxBit.size())
        {
            while (tempStr2.maxBit.size() != tempStr1.maxBit.size())
            {
                tempStr2.maxBit.insert(0, "0");
            }
        }

        bool isMinus = false;
        int idxBeforeMinus = 0;
        for (int i = tempStr1.maxBit.size() - 1; i >= 0; i--)
        {
            if (isMinus && tempStr1.maxBit.at(i) == '1')
            {
                tempStr1.maxBit[i] = '0';

                int tempDigital = stoi(to_string(tempStr1.maxBit[i])) - stoi(to_string(tempStr2.maxBit[i]));

                if (tempDigital == 1)
                    tempAnswer.maxBit[i] = '1';
                else if (tempDigital == 0)
                    tempAnswer.maxBit[i] = '0';

                for (; idxBeforeMinus > i; idxBeforeMinus--)
                {
                    tempStr1.maxBit[idxBeforeMinus] = '1';

                    tempDigital = stoi(to_string(tempStr1.maxBit[idxBeforeMinus])) - stoi(to_string(tempStr2.maxBit[idxBeforeMinus]));

                    if (tempDigital == 1)
                        tempAnswer.maxBit[idxBeforeMinus] = '1';
                    else if (tempDigital == 0)
                        tempAnswer.maxBit[idxBeforeMinus] = '0';
                    else if (tempDigital == -1)
                    {
                        tempAnswer.maxBit = "0";
                        return tempAnswer;
                    }
                    

                    cout << tempAnswer.maxBit << endl;
                }
                idxBeforeMinus = 0;
                isMinus = false;
            }

            if (isMinus)
                continue;

            int digital = stoi(to_string(tempStr1.maxBit[i])) - stoi(to_string(tempStr2.maxBit[i]));

            if (digital == 1)
                tempAnswer.maxBit[i] = '1';
            else if (digital == 0)
                tempAnswer.maxBit[i] = '0';
            else if (digital == -1)
            {
                idxBeforeMinus = i - 1;
                tempAnswer.maxBit[i] = '1';
                isMinus = true;
            }
        }

        bit256BinaryNumber* newStr = new bit256BinaryNumber(tempAnswer);
        return *newStr;
    }

    const bit256BinaryNumber& operator<<(const int& digital) const
    {
        bit256BinaryNumber tempStr;
        tempStr = *this;

        tempStr.maxBit.insert(maxBit.size(), digital, '0');
        tempStr.maxBit.erase(0, digital);

        bit256BinaryNumber* newStr = new bit256BinaryNumber(tempStr);
        return *newStr;
    }

    const bit256BinaryNumber& operator>>(const int& digital) const
    {
        bit256BinaryNumber tempStr;
        tempStr = *this;

        tempStr.maxBit.insert(0, digital, '0');
        tempStr.maxBit.erase(tempStr.maxBit.size() - digital);
        tempStr.convertToDecimalNumber();

        bit256BinaryNumber* newStr = new bit256BinaryNumber(tempStr);
        return *newStr;
    }

    ~bit256BinaryNumber() { clear(); }

public:
    string convertToDecimalNumber()
    {
        result = "0";
        for (size_t i = 0; i < size; i++)
        {
            int temp2 = 0;
            string temp = "0";

            if (result.size() == 1)
                result = to_string(stoi(result) * 2 + (maxBit[i] - '0'));
            else if (result.size() >= 2)
            {
                for (int j = result.size() - 1; j >= 0; j--)
                {
                    temp = to_string((result[j] - '0') * 2);
                    if (temp.size() == 1)
                    {
                        result[j] = temp[0];

                        if (temp2)
                        {
                            result[j] = (((result[j] - '0') + temp2) + '0');
                            temp2 = 0;
                        }
                    }
                    else
                    {
                        result[j] = temp[1];
                        if (temp2)
                            result[j] = ((result[j] - '0') + temp2) + '0';

                        temp2 = temp[0] - '0';
                    }
                }

                if (temp2 && temp.size() > 1)
                    result.insert(0, to_string(temp2));

                if (maxBit[i] != '0')
                {
                    int digital = 1;
                    plusOnDigital(result, digital);
                }
            }
        }

        return result;
    }

    void task()
    {
        maxBit = '1';
        size = 201;
        for (int i = 1; i < size; i++)
            maxBit += '0';

        convertToDecimalNumber();
    }
};