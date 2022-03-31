#include <iostream>
#include <vector>
#include <string>
#include "Common/nikminer4sv.h"

using namespace std;
using namespace nikminer4sv;

void Task(Matrix<int>& matrix) {
    
    Matrix<int> sq = matrix;
    sq.Pow(2);
    Matrix<int> f = sq;
    f.Pow(2);
    Matrix<int> e = f;
    e.Pow(2);

    matrix = matrix + sq + f + e;

}

int main() {
    
    Matrix<int> m(2,2);
    m.AscendingFill();
    Task(m);
    cout << m;
}
