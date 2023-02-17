#include "CircularDynamicArray.cpp"
#include <string>
#include <random>
#include <iostream>
#include <ctime>
#include <iostream>
#include <unistd.h>
using namespace std;
void QSSorted(int blank = 100)
{
    CircularDynamicArray<float> C(10);
    C[0] = 10;
    C[1] = 5;
    C[2] = 4;
    C[3] = 8;
    C[4] = 9;
    C[5] = 2;
    C[6] = 1;
    C[7] = 3;
    C[8] = 6;
    C[9] = 7;
    for (int i = 0; i < C.length(); i++)
    {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Head[" << C.head() << "] — "
              << " Head Element: " << C[C.head()] << std::endl;
    std::cout << "Tail[" << C.tail() << "] — "
              << " Tail Element: " << C[C.tail()] << std::endl;

    std::cout << std::endl;
    std::cout << "AddEnd(0)" << std::endl;
    C.addEnd(0);
    for (int i = 0; i < C.length(); i++)
    {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Head[" << C.head() << "] — "
              << " Head Element: " << C[C.head()] << std::endl;
    std::cout << "Tail[" << C.tail() << "] — "
              << " Tail Element: " << C[C.tail()] << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Cap: " << C.capacity() << std::endl;
    std::cout << "Size: " << C.length() << std::endl;
    std::cout << "C[0] = " << C[0] << std::endl;
    std::cout << "C.front = " << C.head() << std::endl;
    std::cout << "C.back = " << C.tail() << std::endl;
    std::cout << "addFront(-1)" << std::endl;
    C.addFront(-1);
    std::cout << "Cap: " << C.capacity() << std::endl;
    std::cout << "Size: " << C.length() << std::endl;
    std::cout << "C[0] = " << C[0] << std::endl;
    std::cout << "C.head = " << C.head() << std::endl;
    std::cout << "C.back = " << C.tail() << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < C.capacity(); i++)
    {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Head[" << C.head() << "] — "
              << " Head Element: " << C[C.head()] << std::endl;
    std::cout << "Tail[" << C.tail() << "] — "
              << " Tail Element: " << C[C.tail()] << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < C.length(); i++)
    {
        std::cout << "C[" << i << "]: " << C[i] << std::endl;
    }
    std::cout << std::endl;
    C.QuickSelect(1);
    for (int i = 1; i <= C.length(); i++)
    {
        std::cout << "k=" << i << " Expected " << i - 2 << " Got: " << C.QuickSelect(i) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Executing StableSort" << std::endl;
    C.stableSort();
    std::cout << std::endl;
    for (int i = 1; i <= C.length(); i++)
    {
        std::cout << "k=" << i << " Expected " << i - 2 << " Got: " << C.QuickSelect(i) << std::endl;
    }
    std::cout << std::endl;
}
int main()
{
    int n = 20;
   
    std::cout << "\n\n-----------------------TESTING QS SORTED------------------------\n"
              << std::endl;
    QSSorted();
}