#include <iostream>
#include <fstream>
#include <cstring>

class String
{
private:
	char *Symbols;
	int size;

public:
	String()
	{
		size = 1;
		Symbols = new char[size];
		Symbols[0] = ' ';
	}

	String(int _size)
	{
		if (_size < 1)
			size = 1;
		else
			size = _size;
		Symbols = new char[size];
		for (int i = 0; i < size; i++)
		{
			Symbols[i] = ' ';
		}
	}

	String(const String &CopySymbols) : size(CopySymbols.size)
	{
		Symbols = new char[size];
		for (int i = 0; i < size; i++)
		{
			Symbols[i] = CopySymbols.Symbols[i];
		}
	}

	~String()
	{
		delete[] Symbols;
		size = 0;
	}

	void Print()
	{
		for (auto c = 0; c < size; c++)
			std::cout << Symbols[c] << ' ';

		std::cout << std::endl;
	}

	int GetSize()
	{
		return size;
	}

	friend std::ostream &operator<<(std::ostream &str, const String &s)
	{
		return str << s.Symbols;
	}

	friend std::istream &operator>>(std::istream &str, String &s)
	{
		if (!s.Symbols)
			s.Symbols = new char[128]{};

		s.Symbols[0] = '\0';
		std::cin.getline(s.Symbols, 128);

		s.size = strlen(s.Symbols);

		return str;
	}

	String &operator=(const String &v)
	{
		if (&v != this)
		{
			delete[] Symbols;
			size = v.size;
			Symbols = new char[v.size];
			for (int i = 0; i < size; i++)
			{
				Symbols[i] = v.Symbols[i];
			}
		}
		return *this;
	}

	friend bool operator==(const String &left, const String &right)
	{
		auto result = strcmp(left.Symbols, right.Symbols);

		return result == 0;
	}

	friend bool operator>(const String &left, const String &right)
	{
		auto result = strcmp(left.Symbols, right.Symbols);

		if (result == 1)
			return true;
		else
			return false;
	}

	friend bool operator<(const String &left, const String &right)
	{
		auto result = strcmp(left.Symbols, right.Symbols);

		if (result == -1)
			return true;
		else
			return false;
	}

	void Erase(const int index)
	{
		memmove(this->Symbols + index, this->Symbols + index + 1, this->size - index);
	}

	void Task(const String &s)
	{
		for (int i = 0; i < strlen(s.Symbols); i++)
		{
			int j = 0;
			while (j < strlen(this->Symbols))
			{
				if (this->Symbols[j] == s.Symbols[i])
					this->Erase(j);
				else
					++j;
			}
		}
	}
};