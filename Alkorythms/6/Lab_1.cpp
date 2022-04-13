#include <iostream>

using namespace std;

int partition(int* array, int left, int right) {
 
    int pivot = array[left];
    int count = 0;

    for (int i = left + 1; i <= right; i++)
        if (array[i] <= pivot)
            count++;
 
    int pivotIndex = left + count;
    swap(array[pivotIndex], array[left]);
 
    int i = left, j = right;
    while (i < pivotIndex && j > pivotIndex) {
 
        while (array[i] <= pivot)
            i++;
        
 
        while (array[j] > pivot)
            j--;
        
 
        if (i < pivotIndex && j > pivotIndex)
            swap(array[i++], array[j--]);
        
    }
 
    return pivotIndex;
}
 
void QuickSort(int* array, int left, int right) {
 
    if (left >= right)
        return;

    int p = partition(array, left, right);
 
    QuickSort(array, left, p - 1);
 
    QuickSort(array, p + 1, right);
}

int main() {

    cout << "1. Manual\n"
         << "2. Random\n";

    int choice;
    cin >> choice;

    int sellers, buyers;
    int* s_costs;
    int* b_costs;

    if (choice == 1) {

        cin >> sellers >> buyers;

        s_costs = new int[sellers];
        b_costs = new int[buyers];

        for (int i = 0; i < sellers; i++)
            cin >> s_costs[i]; 

        for (int i = 0; i < buyers; i++)
            cin >> b_costs[i]; 

    } else if (choice == 2) {

        sellers = rand() % 5 + 1;
        buyers = rand() % 5 + 1;

        s_costs = new int[sellers];
        b_costs = new int[buyers];

        for (int i = 0; i < sellers; i++)
            s_costs[i] = rand() % 110;

        for (int i = 0; i < buyers; i++)
            b_costs[i] = rand() % 110;

        cout << "Sellers: " << sellers << endl;
        cout << "Buyers: " << buyers << endl;    

        cout << "Sellers prices:" << endl;
        for (int i = 0; i < sellers; i++)
            cout << s_costs[i] << " ";
        cout << endl;
        
        cout << "Buyers prices:" << endl;
        for (int i = 0; i < buyers; i++)
            cout << b_costs[i] << " ";
        cout << endl;

    } else {
        cout << "error";
    }

    int compares = 0;
    QuickSort(s_costs, 0, sellers - 1);
    QuickSort(b_costs, 0, buyers - 1);

    int sum = 0;
    int index = 0;
    while (b_costs[buyers - 1 - index] - s_costs[index] > 0 && index < sellers && index < buyers) {
        compares += 3;
        sum += b_costs[buyers - 1 - index] - s_costs[index];
        index += 1;
    }

    cout << sum << endl;
    cout << "Compares: " << compares;

}