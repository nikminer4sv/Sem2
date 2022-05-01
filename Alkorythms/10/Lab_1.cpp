#include <iostream>
#include <vector>
#include <string>

using namespace std;
class SmartShedule;

class Person
{
private:
    bool _days[31]{};
    size_t _sizeDays = 31;
    size_t _weekendDays = 9;
    string _firstName = "";
    string _lastName = "";
    string _patronymic = "";

public:
    friend SmartShedule;

    Person()
    {
        cin.clear();
        cout << "Enter the first name: ";
        getline(cin, _firstName);

        cout << "Enter the last name: ";
        getline(cin, _lastName);

        cout << "Enter the patronymic: ";
        getline(cin, _patronymic);

        size_t quantityDaysOfWork = _sizeDays - _weekendDays;
        cout << "You should be work " << quantityDaysOfWork << " days" << endl;

        cout << "Enter the prefer days for work in this month: ";
        for (int i = 0; i < quantityDaysOfWork; i++)
        {
            size_t idxDay;
            cin >> idxDay;
            if (idxDay > _sizeDays)
            {
                cout << "Invalid! Maximum number of days of month = " << _sizeDays << "! Please try again!" << endl;
                i--;
                continue;
            }
            if (_days[idxDay - 1])
            {
                cout << "Invalid! Enter the other day!" << endl;
                i--;
                continue;
            }

            _days[idxDay - 1] = 1;
        }
        cin.get();
    }

public:
    void printAll()
    {
        cout << "==============I=N=F=O=R=M=A=T=I=O=N==============" << endl;
        
        cout << "First name -> " << _firstName << endl;
        cout << "Last name -> " << _lastName << endl;
        cout << "Patronymic -> " << _patronymic << endl;

        cout << "Days for work: " << endl;
        for (size_t i = 0; i < _sizeDays; i++)
            if (_days[i])
                cout << i + 1 << " ";
        cout << endl;

        for (size_t i = 0; i < _sizeDays; i++)
            cout << _days[i] << " ";
        cout << endl;

        cout << "==============E=N=D==============" << endl;
    }
};

class SmartShedule
{
private:
    size_t _quantityZero = 0;
    size_t _quantityNoZero = 0;
    vector<Person> _persons;
    vector<int> _idxDayWithoutZero;
    vector<int> _idxDayWithZero;

public:
    SmartShedule() = default;

public:
    void addPerson(Person &person)
    {
        _persons.push_back(person);
    }

    void printPersons()
    {
        for (size_t i = 0; i < _persons.size(); i++)
            _persons[i].printAll();
    }

    void sortShedule()
    {
        findEmptyDays();

        if (_quantityNoZero != 0)
        {
            size_t freeNumberNoZero = _quantityNoZero * (_persons.size() - 1);

            if (_quantityNoZero <= _quantityZero && freeNumberNoZero >= _quantityZero)
            {
                for (size_t i = 0, j = 0; i < _quantityZero; i++, j++)
                {
                    _persons[i]._days[_idxDayWithZero[i]] = _persons[i]._days[_idxDayWithoutZero[j]];
                    _persons[i]._days[_idxDayWithoutZero[j]] = 0;
                    if (j == _idxDayWithoutZero.size() - 1)
                        j = -1;
                }
            }
            else if (_quantityNoZero <= _quantityZero && freeNumberNoZero < _quantityZero)
            {
                for (size_t i = 0; i < _quantityNoZero; i++)
                {
                    _persons[i]._days[_idxDayWithZero[i]] = _persons[i]._days[_idxDayWithoutZero[i]];
                    _persons[i]._days[_idxDayWithoutZero[i]] = 0;
                }
            }
            else
            {
                for (size_t i = 0, j = 0; j < _quantityZero; i++, j++)
                {
                    _persons[i]._days[_idxDayWithZero[j]] = _persons[i]._days[_idxDayWithoutZero[j]];
                    _persons[i]._days[_idxDayWithoutZero[j]] = 0;
                    if (i == _persons.size() - 1)
                        i = -1;
                }
            }
        }
    }

private:
    void findEmptyDays()
    {
        if (_persons.size() <= 1)
            return;

        for (size_t j = 0; j < _persons[0]._sizeDays; j++)
        {
            size_t tempQuantityZero = 0, tempQuantityNoZero = 0;
            for (size_t i = 0; i < _persons.size() - 1; i++)
            {
                if (!_persons[i]._days[j] && !_persons[i + 1]._days[j])
                {
                    if (i == 0)
                        tempQuantityZero++;
                }
                else if (_persons[i]._days[j] && _persons[i + 1]._days[j])
                {
                    if (i == 0)
                        tempQuantityNoZero++;
                }
                else
                {
                    if (i > 0 && tempQuantityZero > 0)
                        tempQuantityZero--;

                    if (i > 0 && tempQuantityNoZero > 0)
                        tempQuantityNoZero--;
                }
            }

            if (tempQuantityNoZero == 1)
            {
                _quantityNoZero++;
                _idxDayWithoutZero.push_back(j);
            }

            if (tempQuantityZero == 1)
            {
                _quantityZero++;
                _idxDayWithZero.push_back(j);
            }
        }

        cout << "Quantity zero = " << _quantityZero << endl;
        cout << "Quantity no zero = " << _quantityNoZero << endl;
    }
};

int main()
{
    Person person;
    Person person2;
    Person person3;

    person.printAll();
    person2.printAll();
    person3.printAll();
    cout << "=================================" << endl;

    SmartShedule shedule;
    shedule.addPerson(person);
    shedule.addPerson(person2);
    shedule.addPerson(person3);

    shedule.sortShedule();
    cout << "=================================" << endl;
    shedule.printPersons();

    return 0;
}