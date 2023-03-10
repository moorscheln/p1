#include "CircularDynamicArray.cpp"
#include <string>
#include <random>
#include <iostream>
#include <ctime>
#include <iostream>
#include <unistd.h>
using namespace std;

std::string gen_random(const int len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        tmp_s += alphanum[arc4random() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

char ABCrandom()
{
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char tmp_s;

    tmp_s = alphanum[arc4random() % (sizeof(alphanum) - 1)];

    return tmp_s;
}

int randomInt(int low, int high)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(low, high);
    // distribution in range [low, high] (I got frustrated with C++ rng so I looked up a better way. I understand none of this)
    return dist6(rng);
}

std::string randomString(int maxLength)
{
    int length = randomInt(1, maxLength);
    return gen_random(length);
}

template <typename ArrayType>
void print(CircularDynamicArray<ArrayType> arr)
{
    for (int i = 0; i < arr.length(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void QSUnittest(int blank = 100)
{
    CircularDynamicArray<int> CDA;
    for (int i = 0; i < 10; i++)
    {
        CDA.addEnd(i);
    }
    // for (int i = 0; i < size / 4; i++)
    // {
    for (int i = 1; i <= CDA.length(); i++)
    {

        std::cout << "Expected " << i - 1 << " Got " << CDA.QuickSelect(i) << std::endl;
    }
}

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
    std::cout << "Head[" << C.head() << "] ??? "
              << " Head Element: " << C[C.head()] << std::endl;
    std::cout << "Tail[" << C.tail() << "] ??? "
              << " Tail Element: " << C[C.tail()] << std::endl;

    std::cout << std::endl;
    std::cout << "AddEnd(0)" << std::endl;
    C.addEnd(0);
    for (int i = 0; i < C.length(); i++)
    {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Head[" << C.head() << "] ??? "
              << " Head Element: " << C[C.head()] << std::endl;
    std::cout << "Tail[" << C.tail() << "] ??? "
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
    std::cout << "Head[" << C.head() << "] ??? "
              << " Head Element: " << C[C.head()] << std::endl;
    std::cout << "Tail[" << C.tail() << "] ??? "
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

void QSUnsorted(int blank = 100)
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
    cout << "CircularDynamicArray<float> C(10);" << std::endl;
    // for (int i = 0; i < C.length(); i++)
    //     C[i] = i;
    for (int i = 0; i < C.length(); i++)
        std::cout << C[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < C.length(); i++)
    {
        int n = randomInt(1, 10);
        std::cout << "Expected " << n << " Got " << C.QuickSelect(n) << std::endl;
    }
}

void Mytest()
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
    std::cout << "Original" << std::endl;
    // for (int i = 0; i < C.length(); i++)
    //     C[i] = i;
    for (int i = 0; i < C.length(); i++)
        std::cout << C[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Add End -> 0" << std::endl;
    std::cout << "Expected: "
              << "10 5 4 8 9 2 1 3 6 7 0" << std::endl;

    for (int i = 1; i <= C.length(); i++)
    {

        std::cout << "Expected " << i << " Got " << C.QuickSelect(i) << std::endl;
        std::cout << " UserIndex = " << i << " Our Index = " << C.operatorIndex(i) << std::endl;
    }
}

void AddRemoveReverseSearchChar()
{
    CircularDynamicArray<char> arr(26);
    for (int i = 0; i < 26; i++)
    {
        arr[i] = (char)(65 + i);
    }
    for (int i = 0; i < 13; i++)
    {
        print(arr);
        int dice = randomInt(1, 7);
        switch (dice)
        {
        case 1:
        {
            std::cout << "Added End" << std::endl;
            arr.addEnd(ABCrandom());
            break;
        }
        case 2:
        {
            std::cout << "Added Front" << std::endl;
            arr.addFront(ABCrandom());
            break;
        }
        case 3:
        {
            std::cout << "Deleted End" << std::endl;
            arr.delEnd();
            break;
        }
        case 4:
        {
            std::cout << "Deleted Front" << std::endl;
            arr.delFront();
            break;
        }
        case 5:
        {
            std::cout << "Reversed" << std::endl;
            arr.reverse();
            break;
        }
        case 6:
        {
            std::cout << "Sorting.." << std::endl;
            arr.stableSort();
            char targetLetter = ABCrandom();
            std::cout << "In search for " << targetLetter << ", LinearSearch got: " << arr.linearSearch(targetLetter) << ", Binsearch got: " << arr.binSearch(targetLetter) << std::endl;
            break;
        }
        case 7:
        {
            std::cout << "Clearing.." << std::endl;
            arr.clear();
            std::cout << "Out of clear, now trying to print.." << std::endl;
            print(arr);
            std::cout << "^Above should be empty line, size is: " << arr.length() << " (should be 0), capacity is: " << arr.capacity() << " (should be 2)" << std::endl;
            for (int i = 0; i < 13; i++)
                arr.addFront(ABCrandom());
            std::cout << "Threw in some values" << std::endl;
        }
        }
    }
    print(arr);
}

void MassiveArrayDefaultSizeString(int number, CircularDynamicArray<string> &arr)
{
    std::string randstring;
    for (int i = 0; i < number; i++)
    {
        randstring = randomString(5);
        (i % 2 == 0) ? arr.addFront(randstring) : arr.addEnd(randstring);
    }
}

void MassiveArrayStarterSizeString(int size, CircularDynamicArray<string> &arr)
{
    int length;
    std::string randstring;
    for (int i = 0; i < size; i++)
    {
        length = randomInt(1, 5);
        randstring = gen_random(length);
        arr[i] = randstring;
    }
}

template <typename element>
void Big3Tester(CircularDynamicArray<element> &ar1, CircularDynamicArray<element> &ar2)
{
    std::cout << "Original array:" << std::endl;
    print(ar1);
    std::cout << "Copy='d array:" << std::endl;
    ar2 = ar1;
    print(ar2);
    std::cout << "Copycon'd array:" << std::endl;
    CircularDynamicArray<element> ar3 = ar1;
    print(ar3);
    std::cout << "Removing half from original. Only original should show changes" << std::endl;
    for (int i = 0; i <= ar1.length() / 2; i++)
    {
        ar1.delEnd();
    }
    std::cout << "Original: ";
    print(ar1);
    std::cout << "Copy=: ";
    print(ar2);
    std::cout << "Copycon: ";
    print(ar3);
    std::cout << "Finally, deleting copycon'd array (Should do nothing noticeable but cause no errors)" << std::endl;
    // ar3 goes out of scope
}

int main()
{
    int n = 20;
    std::cout << "\n\n-----------------------GENERATING STRINGS------------------------\n"
              << std::endl;
    CircularDynamicArray<string> CDA2(n);
    MassiveArrayStarterSizeString(n, CDA2);
    print(CDA2);
    std::cout << "\n\n-----------------------STABLE SORTING------------------------\n"
              << std::endl;
    CDA2.stableSort();
    print(CDA2);
    std::cout << "\n\n-----------------------GENERATING STRINGS------------------------\n"
              << std::endl;
    CircularDynamicArray<string> CDA;
    MassiveArrayDefaultSizeString(n, CDA);
    print(CDA);
    std::cout << "\n\n----------------------- STABLE SORTING------------------------\n"
              << std::endl;
    CDA.stableSort();
    print(CDA);
    std::cout << "\n\n-----------------------TESTING QUICKSELECT [disclaimer, this only tests the sorted case, please do your own testing]------------------------\n"
              << std::endl;
    QSUnittest(n);
    // std::cout << "\n\n-----------------------TESTING QUICKSELECT [UNSORTED CASE]]------------------------\n"
    //           << std::endl;
    // QSUnsorted(n);
    std::cout << "\n\n-----------------------TESTING ADD REMOVE REVERSE SEARCHES CLEAR------------------------\n"
              << std::endl;
    AddRemoveReverseSearchChar();
    std::cout << "\n\n-----------------------TESTING BIG 3------------------------\n"
              << std::endl;
    Big3Tester(CDA, CDA2);
    std::cout << "\n\n-----------------------TESTING MYTEST------------------------\n"
              << std::endl;
    Mytest();
    std::cout << "\n\n-----------------------TESTING QS SORTED------------------------\n"
              << std::endl;
    QSSorted();
}
