#include <iostream>
#include <cstring>

using namespace std;

#define ASize (255)

class ArrayList
{
private:
    char Data[ASize]{};
    int Index[ASize]{};

    int _idx_head = 0;
    int _idx_tail = 0;
    int Size = 0;
public:

private:
    struct InvalidIndex : public exception
    {
        [[nodiscard]] const char* what() const noexcept override
        {
            return "Index must be right:)";
        }
    };

public:

    char Get(int index) const
    {
        if (index < 0 || index > GetSize() - 1)
            throw InvalidIndex();

        int it = _idx_head;
        for (size_t i = 0; i < index; i++)
            it = Index[it];

        return Data[it];
    }

    char* getData()
    {
        char data[256]{};
        for (int i = 0; i < Size; i++)
        {
            data[i] = Data[i];
        }

        return data;
    }

    [[nodiscard]] size_t GetSize() const
    {
        return Size;
    }

    void PrintRawData() const
    {
        cout << "DATA: ";
        for (int i = 0; i < _idx_tail; i++)
            cout << Data[i] << " ";
        cout << endl;

        cout << "INDX: ";
        for (int i = 0; i < _idx_tail; i++)
            cout << Index[i] << " ";
        cout << endl;
    }

    void Delete(int index)
    {
        if (index < 0 || index > GetSize() - 1)
            throw InvalidIndex();

        if (index == 0)
        {
            _idx_head = Index[_idx_head];
            return;
        }

        int tempValue = _idx_head;
        for (int i = 0; i < index - 1; i++)
            tempValue = Index[tempValue];

        Index[tempValue] = Index[Index[tempValue]];
    }

    void Delete(size_t idx, size_t length)
    {
        if (idx < 0 || idx + length > GetSize() - 1)
            throw InvalidIndex();

        for (int it = idx; it < idx + length; it++)
        {
            Delete(it);
        }
    }

    bool Append(char value)
    {
        if (Size == ASize)
        {
            return false;
        }

        Size++;
        if (_idx_tail == 0)
        {
            Data[_idx_tail++] = value;
            return true;
        }

        Data[_idx_tail] = value;
        Index[_idx_tail - 1] = _idx_tail;
        _idx_tail++;

        return true;
    }

    bool Insert(char* value, int index)
    {
        if (Size == ASize)
        {
            return false;
        }

        if (index < 0 || index > GetSize() - 1)
            throw InvalidIndex();

        Index[index - 1] = _idx_tail;
        for (int i = 0; i < strlen(value); i++)
        {
            Data[_idx_tail] = value[i];
            Index[_idx_tail++] = _idx_tail + 1;
        }
        Index[_idx_tail - 1] = index + 1;

        Size++;
        return true;
    }

    int Contains(char value)
    {
        if (!Size)
        {
            return -1;
        }

        size_t it = _idx_head;
        while (Index[it])
        {
            if (Data[it] == value)
            {
                return it;
            }
            it = Index[it];
        }

        return Data[it] == value ? it : -1;
    }

    int Contains(const ArrayList& other)
    {
        int pos_first = -1;
        for (int idx = 0; idx < other.GetSize(); idx++)
        {
            int pos_current = Contains(other.Get(idx));
            if (pos_current == -1)
            {
                return -1;
            }
            if (pos_first == -1)
            {
                pos_first = pos_current;
            }
        }

        return pos_first;
    }

    void Print() const
    {
        if (!Size)
        {
            return;
        }

        size_t it = _idx_head;
        while (Index[it])
        {
            cout << Data[it] << " ";
            it = Index[it];
        }

        cout << Data[it] << endl;
    }
};

void Task(ArrayList& listmain, ArrayList& list1, ArrayList& list2)
{
    if (list1.GetSize() == 0 || listmain.GetSize() - list1.GetSize() < 0)
        return;

    auto pos = listmain.Contains(list1);
    if (pos >= 0)
    {
        listmain.Delete(pos, list1.GetSize());
        listmain.Insert(list2.getData(), pos);
    }
}


int main()
{
    ArrayList listmain, list1, list2;
    char text[ASize]{};
    cout << "Main text" << endl;
    cin.getline(text, ASize);
    for (int i = 0; i < strlen(text); i++)
    {
        listmain.Append(text[i]);
    }

    cout << "Text to delete" << endl;
    cin.getline(text, ASize);
    for (int i = 0; i < strlen(text); i++)
    {
        list1.Append(text[i]);
    }

    cout << "Text to insert" << endl;
    cin.getline(text, ASize);
    for (int i = 0; i < strlen(text); i++)
    {
        list2.Append(text[i]);
    }

    Task(listmain, list1, list2);
    listmain.Print();
}
