#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool IsFibNumber (int* arr, int left, int right, int key)
{
	int midd = 0;
	while (1)
	{

		midd = (left + right) / 2;
		
		if (key < arr[midd])       // если искомое меньше значения в ячейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (key > arr[midd])  // если искомое больше значения в ячейке
			left = midd + 1;	   // смещаем левую границу поиска
		else                       // иначе (значения равны)
			return true;           // функция возвращает индекс ячейки

		if (left > right)          // если границы сомкнулись 
			return false;
	}
}

int main() {

    int n;
    cin >> n;

    int* fibnumbers = new int[n];

    fibnumbers[0] = 0;
    fibnumbers[1] = 1;

    int counter = 1;
    while (fibnumbers[counter] < n) {
        ++counter;
        fibnumbers[counter] = fibnumbers[counter - 1] + fibnumbers[counter - 2];
    }

    /*

    for (size_t i = 0; i < counter; i++) {
        cout << fibnumbers[i] << endl;
    }

    */

    int result = 0;
    for (size_t i = 4; i < n; i++) {

        bool flag = true;
        for (int j = 0; j < to_string(i).length(); j++) {

            if (IsFibNumber(fibnumbers, 0, counter, i)) {
                flag = false;
                break;
            }

            if (i > 9) {
                
                int left = 0;
                int right = to_string(i).length() - 1;

                int width = 1;
                int position = left;

                while (true) {

                    if (IsFibNumber(fibnumbers, 0, counter, stoi(to_string(i).substr(left, right + 1)))) {
                        flag = false;
                        break;
                    }

                    position += 1;

                    if (position + width > right + 1) {
                        width += 1;
                        position = left;
                    }

                    if (width > right - left + 1)
                        break;

                }

                //10

            }


        }

        if (flag) {
            cout << i << endl;
            result += 1;
        }

    }

    cout << result << endl;

    

}




/*

              * 
             **   
            ***
           ****
          *****
         ******
        *******
       ********             


        /*******
        *****                       /******        ****** 
        ***                         ****           ******* 
        *                           **             ********     




*/