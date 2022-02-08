#include<iostream>
using namespace std;

class SpiralArray {
public:
	SpiralArray(const int size) {
		this->size = size;
		arr = new int* [size] {};
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

	void get() {

		if (size != 0){
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << "\t";
				}
				cout << endl;
			}
		}
		else cout << "Size = " << size;

	}

	void set() {
		if (size != 0) {
			int MaxRoads = size + (size - 1);
			int Roads = 0;

			int digital = 1;

			int variable = 0;
			int copy_size = size;

			int indexEachFourthRoad = 0;

			while (true) {
				int i = size - copy_size, j = indexEachFourthRoad;

				while (i < copy_size) {
					arr[i][j] = digital++;
					i++;
				}
				Roads++;
				if (Roads == MaxRoads)
					break;

				i--;
				j++;
				while (j < copy_size) {
					arr[i][j] = digital++;
					j++;
				}
				Roads++;
				if (Roads == MaxRoads)
					break;

				i--;
				j--;
				while (i >= indexEachFourthRoad) {
					arr[i][j] = digital++;
					i--;
				}
				Roads++;
				if (Roads == MaxRoads)
					break;

				i++;
				j--;
				indexEachFourthRoad++;
				while (j >= indexEachFourthRoad) {
					arr[i][j] = digital++;
					j--;
				}
				Roads++;
				if (Roads == MaxRoads)
					break;
				copy_size--;
			}
		}
		else cout << "Size = " << size;
	}

	void setManually() {
		if (size != 0) {
			int MaxRoads = size + (size - 1);
			int Roads = 0;

			int digital;

			int variable = 0;
			int copy_size = size;

			int indexEachFourthRoad = 0;

			while (true) {
				int i = size - copy_size, j = indexEachFourthRoad;

				while (i < copy_size) {
					cin >> digital;
					arr[i][j] = digital;
					i++;
				}
				Roads++;
				if (Roads == MaxRoads)
					break;

				i--;
				j++;
				while (j < copy_size) {
					cin >> digital;
					arr[i][j] = digital;
					j++;
				}
				Roads++;
				if (Roads == MaxRoads)
					break;

				i--;
				j--;
				while (i >= indexEachFourthRoad) {
					cin >> digital;
					arr[i][j] = digital;
					i--;
				}
				Roads++;
				if (Roads == MaxRoads)
					break;

				i++;
				j--;
				indexEachFourthRoad++;
				while (j >= indexEachFourthRoad) {
					cin >> digital;
					arr[i][j] = digital;
					j--;
				}
				Roads++;
				if (Roads == MaxRoads)
					break;
				copy_size--;
			}
		}
		else cout << "Size = " << size;
	}
private: 
	int size;
	int** arr;
};


int main() {
	int size;
	cin >> size;

	SpiralArray ob(size);
	ob.set();
	ob.get();
	
	system("pause");
	return 0;
}
