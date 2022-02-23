#include <array>
#include <iostream>

using namespace std;

template<size_t Capacity>
class ArrayList {
private:
    static constexpr size_t _capacity = 256U;

    std::array<char, Capacity> _data{};
    std::array<size_t, Capacity> _index{};

    int _idx_head = 0;
    int _idx_tail = 0;

    size_t _size = 0U;
public:

private:
    struct InvalidIndex : public exception{
        [[nodiscard]] const char * what () const noexcept override {
            return "Index must be right:)";
        }
    };

public:

    char Get(int index) const {
        if (index < 0 || index > GetSize() - 1)
            throw InvalidIndex();

        int it = _idx_head;
        for (size_t i = 0; i < index; i++ )
            it = _index[it];

        return _data[it];
    }

    [[nodiscard]] size_t GetSize() const{
        return _size;
    }

    void PrintRawData() const {
        cout << "DATA: ";
        for (int i = 0; i < _idx_tail; i++)
            cout << _data[i] << " ";
        cout << endl;

        cout << "INDX: ";
        for (int i = 0; i < _idx_tail; i++)
            cout << _index[i] << " ";
        cout << endl;
    }

    void Delete(int index) {
        if (index < 0 || index > GetSize() - 1)
            throw InvalidIndex();

        if (index == 0) {
            _idx_head = _index[_idx_head];
            return;
        }

        int tempValue = _idx_head;
        for (int i = 0; i < index - 1; i++)
            tempValue = _index[tempValue];

        _index[tempValue] = _index[_index[tempValue]];

        // H e l g o i
        // 5 2 3 4 0 1

        // H i e l g o

    }

    void Delete(size_t idx, size_t length){
        if (idx < 0 || idx+length > GetSize() - 1)
            throw InvalidIndex();

        for(int it = idx; it<idx+length;it++){
            Delete(it);
        }
    }

    bool Append(char value) {
        if (_size == _capacity) {
            return false;
        }

        if (_idx_tail == 0) {
            _data[_idx_tail++] = value;
            return true;
        }

        _data[_idx_tail] = value;
        _index[_idx_tail - 1] = _idx_tail;
        _idx_tail += 1;

        _size++;
        return true;
    }

    bool Insert(char value, int index) {
        if (_size == _capacity) {
            return false;
        }

        if (index < 0 || index > GetSize() - 1)
            throw InvalidIndex();

        _data[_idx_tail] = value;
        _index[index - 1] = _idx_tail;
        _index[_idx_tail] = index;
        _idx_tail += 1;

        _size++;
        return true;
    }

    int Contains(char value) {
        if (!_size) {
            return -1;
        }

        size_t it = _idx_head;
        while (_index[it]) {
            if (_data[it] == value) {
                return it;
            }
            it = _index[it];
        }

        return _data[it] == value ? it : -1;
    }

    int Contains(const ArrayList<Capacity>& other) {
        int pos_first = -1;
        for(int idx = 0; idx < other.GetSize(); idx++){
            int pos_current = Contains(other.Get(idx));
            if(pos_current == -1){
                return -1;
            }
            if(pos_first == -1){
                pos_first = pos_current;
            }
        }

        return pos_first;
    }

    void Print() const {
        if(!_size){
            return;
        }

        size_t it = _idx_head;
        while (_index[it]) {
            cout << _data[it] << " ";
            it = _index[it];
        }

        cout << _data[it] << endl;
    }
};

template<size_t Capacity>
void Task(ArrayList<Capacity>& list1, ArrayList<Capacity>& list2) {

    if (list2.GetSize() == 0 || list1.GetSize() - list2.GetSize() < 0)
        return;

    auto pos = list1.Contains(list2);
    if(pos >= 0){
        list1.Delete(pos, list2.GetSize());
    }
}


int main() {

    ArrayList<16> list1;
    list1.Append('H');
    list1.Append('e');
    list1.Append('l');
    list1.Append('l');
    list1.Append('o');
    list1.Print();

    ArrayList<16> list2;
    list2.Append('e');
    list2.Append('l');
    list2.Print();

    Task(list1, list2);
    list1.Print();
}
