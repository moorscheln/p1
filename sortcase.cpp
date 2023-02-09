#include <iostream>
using namespace std;
#include "CircularDynamicArray.cpp"

void foo(CircularDynamicArray<int> x)
{
    for (int i = 0; i < x.length() / 2; i++)
        x[i] = x[x.length() / 2 + i];
    // X => "6 7 8 9 10 15 19 6 7 8 9 10 15 19 11"
    for (int i = 0; i < x.length(); i++)
        cout << x[i] << " ";
    cout << endl;
}

int main()
{
    CircularDynamicArray<float> C(10);
    C[0] = 100;
    C[1] = 5;
    C[2] = 35;
    C[3] = 5;
    C[4] = 10;
    C[5] = 90;
    C[6] = 75;
    C[7] = 50;
    C[8] = 1;
    C[9] = 99;
    cout << "CircularDynamicArray<float> C(10);" << endl;
    // for (int i = 0; i < C.length(); i++)
    //     C[i] = i;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    // C => "100 5 2 3 4 5 6 7 8 9"

    cout << "StableSort Executing" << endl;
    C.stableSort();
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
}