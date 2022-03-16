#include <array>
#include <iostream>

using namespace std;

template <size_t Capacity>
class ArrayList
{
private:
	std::array<char, Capacity> _data{};
	std::array<size_t, Capacity> _index{};

	int _idx_head = 0;
	int _idx_tail = 0;

	size_t _size = 0U;

public:
private:
	struct InvalidIndex : public exception
	{
		[[nodiscard]] const char *what() const noexcept override
		{
			return "Index must be right:)";
		}
	};

public:
	[[nodiscard]] char Get(int index) const
	{
		if (index < 0 || index > GetSize())
			throw InvalidIndex();

		int it = _idx_head;
		for (size_t i = 0; i < index; i++)
			it = _index[it];

		return _data[it];
	}

	[[nodiscard]] size_t GetSize() const
	{
		return _size;
	}

	void PrintRawData() const
	{
		cout << "DATA: ";
		for (int i = 0; i < _idx_tail; i++)
			cout << _data[i] << " ";
		cout << endl;

		cout << "INDX: ";
		for (int i = 0; i < _idx_tail; i++)
			cout << _index[i] << " ";
		cout << endl;
	}

	void Delete(int index)
	{
		if (index < 0 || index > GetSize())
			throw InvalidIndex();

		if (index == 0)
		{
			_idx_head = _index[_idx_head];
			return;
		}

		int tempValue = _idx_head;
		for (int i = 0; i < index - 1; i++)
			tempValue = _index[tempValue];

		_index[tempValue] = _index[_index[tempValue]];
	}

	void Delete(size_t idx, size_t length)
	{
		if (idx < 0 || idx + length > GetSize())
			throw InvalidIndex();

		for (int it = idx; it < idx + length; it++)
		{
			Delete(it);
		}
	}

	bool Append(char value)
	{
		if (_size == Capacity)
		{
			return false;
		}

		if (_idx_tail == 0)
		{
			_data[_idx_tail++] = value;
			return true;
		}

		_data[_idx_tail] = value;
		_index[_idx_tail - 1] = _idx_tail;
		_idx_tail += 1;

		_size++;
		return true;
	}

	bool Insert(char value, int index)
	{
		if (_size == Capacity)
		{
			return false;
		}

		if (index < 0 || index > GetSize())
			throw InvalidIndex();

		_data[_idx_tail] = value;
		_index[index - 1] = _idx_tail;
		_index[_idx_tail] = index;
		_idx_tail += 1;

		_size++;
		return true;
	}

	int Contains(char value)
	{
		if (!_size)
		{
			return -1;
		}

		size_t it = _idx_head;
		while (_index[it])
		{
			if (_data[it] == value)
			{
				return it;
			}
			it = _index[it];
		}

		return _data[it] == value ? it : -1;
	}

	int Contains(const ArrayList<Capacity> &other)
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
		size_t it = _idx_head;
		while (_index[it])
		{
			cout << _data[it] << " ";
			it = _index[it];
		}

		cout << _data[it] << endl;
	}
};

template <size_t Capacity>
void Task(ArrayList<Capacity> &list1, ArrayList<Capacity> &list2)
{
    const int n = int('z') - int('a') + 1;
    int g[n];
    for (int i = 0; i < n; i++)
    {
        g[i] = 0;
    }
    for (int i = 0; i < list1.GetSize(); i++)
    {
        g[int(list1.Get(i)) - int('a')]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (g[i] > 1)
        {
            char temp = (char(('a' + i)));
            list2.Append(temp);
        }
    }
}

int main() {
    ArrayList<64> list1;
    cout << "Enter the amount of chars: " << endl;
    int size;
    cin >> size;
    if (size < 16)
    {
        for (int k = 0; k < size; k++)
        {
            char temp;
            cin >> temp;
            list1.Append(temp);
        }
        list1.Print();

        ArrayList<64> list2;

        Task(list1, list2);
        list2.Print();
    }
    else
    {
        cout << "Wrong enter!";
    }
    return 0;
}