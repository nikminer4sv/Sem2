#include<iostream>
using namespace std;

class SpiralArray {
public:
	SpiralArray(const int size) {
		this->size = size;

		arr = new int* [size];
		for (int i = 0; i < size; i++) {
			arr[i] = new int [size] {};
		}
	}

	~SpiralArray() {
		for (int i = 0; i < size; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "Size = " << size;
	}

	void fill() {
		if (!size) {
			return;
		}

		int MaxRoads = size + (size - 1);
		int Roads = 0;

		int digital = 1;

		int variable = 0;
		int fill_length = size;

		int idx_min = 0;

		while (true) {
			int i = size - fill_length;
			int j = idx_min;

			//down
			for (; i < fill_length;i++) {
				arr[i][j] = digital++;
			}

			Roads++;
			if (Roads == MaxRoads)
				break;


			//rigth
			i--;
			j++;
			for (; j < fill_length;j++) {
				arr[i][j] = digital++;
			}

			Roads++;
			if (Roads == MaxRoads)
				break;

			//up
			i--;
			j--;
			for(; i >= idx_min; i--) {
				arr[i][j] = digital++;
			}

			Roads++;
			if (Roads == MaxRoads)
				break;

			//left
			i++;
			j--;
			idx_min++;
			for (; j >= idx_min; j--) {
				arr[i][j] = digital++;
			}

			Roads++;
			if (Roads == MaxRoads)
				break;

			fill_length--;
		}

	}

private: 
	int size;
	int** arr;
};


int main() {
	int size;
	cout << "Enter the rang of matrix: ";
	cin >> size;

	SpiralArray ob(size);
	ob.fill();
	ob.print();
	
	system("pause");
	return 0;
}
