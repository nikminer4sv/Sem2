#include <iostream>

using namespace std;

template<typename T>
void Fill(T* Array, int ArraySize);
void Fill(double* Array, int ArraySize);
void Fill(char* Array, int ArraySize);
void Fill(char** Array, int ArraySize);

template<typename T, typename C>
void MergeSort(T* Array, int ArraySize, C comparator);


template<typename T>
void MergeSort(T* Array, int ArraySize);

template<typename T>
void Print(T* Array, int ArraySize);


bool CharComporator(const char* a, const char* b){
    return strcmp(a, b) <= 0;
}

int main() {
    int n, k;
    cin >> n;
    cout << "Choose type of elemets:\n1. Integer\n2. Double\n3. Char\n4. C-string\n";
    cin >> k;

    switch (k) {
        case 1: {    
            int* Int = new int[n];
            Fill(Int, n);
            MergeSort(Int, n);
            Print(Int, n);
            break;
        }
            
        case 2: {    
            double* Double = new double[n];
            Fill(Double, n);
            MergeSort(Double, n);
            Print(Double, n);
            break;
        }
        
        case 3: {
            char* Char = new char[n];
            Fill(Char, n);
            MergeSort(Char, n);
            Print(Char, n);
            break;
        }
            
        case 4: {
            char** PChar = new char*[n];
            for (int i = 0; i < n; i++)
                PChar[i] = new char[255];
            
            Fill(PChar, n);
            MergeSort(PChar, n, [](const char* a, const char* b){return strcmp(a,b)<0;});
            Print(PChar, n);
            break;
        }
        
        default:
            cout << "stupid...";
            break;
    }

}

template<typename T>
void Fill(T* Array, int ArraySize) {
    for (int i = 0; i < ArraySize; i++)
        Array[i] = rand() % 100 + 1;
    
}
void Fill(double* Array, int ArraySize) {
    for (int i = 0; i < ArraySize; i++)
        Array[i] = (rand() % 1000 + 1) / 10.0;
    
}

void Fill(char* Array, int ArraySize) {
    char Symbols[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < ArraySize; i++)
        Array[i] = Symbols[rand() % int(sizeof(Symbols) - 2) + 1];
    
}

template<typename T> 
T getRandomNumber(T min, T max) {
    return rand() %(max-min+1) + min;
}


void Fill(char** Array, int ArraySize) {
    for (int i = 0; i < ArraySize; i++) {
        int j = 0;
        for (; j < rand() % 10 + 1; j++) 
            Array[i][j] = getRandomNumber('a', 'z');
        
        Array[i][j] = '\0';
    }
}

template<typename T, typename C>
void MergeSort(T* Array, int ArraySize, C comparator) {
    if (ArraySize < 2)
        return;

    MergeSort(Array, ArraySize / 2, comparator);
    MergeSort(&Array[ArraySize / 2], ArraySize - (ArraySize / 2), comparator);

    T* buf = new T[ArraySize];
    int idbuf = 0, idl = 0, idr = ArraySize / 2 ;

    while ((idl < ArraySize / 2) && (idr < ArraySize))
        if (comparator(Array[idl],Array[idr]))
            buf[idbuf++] = Array[idl++];
        else
            buf[idbuf++] = Array[idr++];

    while (idl < ArraySize / 2) 
        buf[idbuf++] = Array[idl++];

    while (idr < ArraySize) 
        buf[idbuf++] = Array[idr++];

    for (idl = 0; idl < ArraySize; idl++)
        Array[idl] = buf[idl];
        
    delete[]buf;

}

template<typename T>
void MergeSort(T* Array, int ArraySize) {
    MergeSort(Array, ArraySize, [](const T& a, const T&b){return a<b;});
}


template<typename T>
void Print(const T* Array, const int ArraySize) {
    for (int i = 1; i <= ArraySize; i++) {
        cout << Array[i - 1] << "\t";
        if ((i % 20) == 0)
            cout << endl;
        
    }
}