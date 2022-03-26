#include <iostream>
#include <conio.h>

using namespace std;

#define Day (60 * 60 * 24)

class Time
{
    private:
    int Second = 0;
    int Minute = 0;
    int Hour = 0;

    public:
    Time() = default;
    
    Time(int second, int minute, int hour)
    {
        this->Second = second;
        this->Minute = minute;
        this->Hour = hour;
        InputCheck();
    }

    Time(const Time& obj)
    {
        Copy(obj);
        InputCheck();
    }

    ~Time()
    {
        int Second = 0;
        int Minute = 0;
        int Hour = 0;
    }

    int getSecond() const
    {
        return this->Second;
    }

    int getMinute() const
    {
        return this->Minute;
    }

    int getHour() const
    {
        return this->Hour;
    }

    Time &operator=(const Time &obj)
    {
        Copy(obj);
        InputCheck();
        return *this;
    }

    void operator+(int second)
    {
        this->Second += second;
        InputCheck();
    }
    
    Time operator+(const Time &obj)
    {
        this->Second += obj.Second;
        this->Minute += obj.Minute;
        this->Hour += obj.Hour;
        InputCheck();

        return *this;
    }

    void operator()(int second, int minute, int hour)
    {
        this->Second = second;
        this->Minute = minute;
        this->Hour = hour;
        InputCheck();
    }

    void Copy(const Time & obj)
    {
        this->Second = obj.Second;
        this->Minute = obj.Minute;
        this->Hour = obj.Hour;
        InputCheck();
    }

    int ToSeconds() const
    {
        return this->getSecond() + this->getMinute() * 60 + this->getHour() * 3600;
    }

    int Different(const Time& obj)
    {
        if (abs(this->ToSeconds() - obj.ToSeconds()) < Day)
        {
            return abs(this->ToSeconds() - obj.ToSeconds());
        }
    }

    void InputCheck()
    {
        bool Flag = false;
        if (this->Second >= 60)
        {
            int ToMinute = this->Second / 60;
            this->Second -= ToMinute * 60;
            this->Minute += ToMinute;
            Flag = true;
        }
        else if (this->Second < 0)
        {
            int ToMinute = this->Second / 60 - 1;
            this->Second -= ToMinute * 60;
            this->Minute += ToMinute;
            Flag = true;
        }
        if (this->Minute >= 60)
        {
            int ToHour = this->Minute / 60;
            this->Minute -= ToHour * 60;
            this->Hour += ToHour;
            Flag = true;
        }
        else if (this->Minute < 0)
        {
            int ToHour = this->Minute / 60 - 1;
            this->Minute -= ToHour * 60;
            this->Hour += ToHour;
            Flag = true;
        }
        if (this->Hour >= 24)
        {
            int ToRemove = this->Hour / 24;
            this->Hour -= ToRemove * 24;
            Flag = true;
        }
        else if (this->Hour < 0)
        {
            int ToRemove = this->Hour / 24 - 1;
            this->Hour -= ToRemove * 24;
            Flag = true;
        }
        if (Flag)
            InputCheck();
    }

    void Print()
    {
        cout << "SECOND -> " << this->Second 
             << "\tMINUTE -> " << this->Minute 
             << "\tHOUR -> " << this->Hour << endl;
    }
};

int main()
{
    bool IsWorking = true;
    int second, minute, hour;
    Time a, b;

    while (IsWorking)
    {
        system("cls");
        cout << "1. Add\n"
            << "2. Print\n"
            << "3. Sum\n"
            << "4. Different\n"
            << "5. Exit\n";

        int Choice = 0;
        cin >> Choice;

        switch (Choice)
        {
        case 1:
        {
            system("cls");
            cout << "Input seconds, minutes and hours\n";
            cin >> second >> minute >> hour;
            a(second, minute, hour);
            cout << "Input seconds, minutes and hours\n";
            cin >> second >> minute >> hour;
            b(second, minute, hour);
            break;
        }


        case 2:
        {
            a.Print();
            b.Print();
            _getch();
            break;
        }

        case 3:
        {
            Time c(a + b);
            c.Print();
            _getch();
            break;
        }

        case 4:
        {
            cout << "SECONDS -> " << a.Different(b) << endl;
            _getch();
            break;
        }

        case 5:
            IsWorking = false;
            break;

        default:
            cout << "TbI prosto kek\n";
            break;
        }
    }
}