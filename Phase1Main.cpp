#include <iostream>
using namespace std;
#include "CircularDynamicArray.cpp"
template <typename ArrayType>
void print(CircularDynamicArray<ArrayType> arr)
{
    for (int i = 0; i < arr.length(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename element>
void Big3Tester(CircularDynamicArray<element> &ar1, CircularDynamicArray<element> &ar2)
{
    std::cout << "Original array:";
    print(ar1);
    std::cout << std::endl;
    std::cout << "ar1.length() " << ar1.length() << std::endl;
    std::cout << "ar1.capacity() " << ar1.capacity() << std::endl;
    std::cout << "Copy='d array:" << std::endl;
    ar2 = ar1;

    print(ar2);
    std::cout << "Copycon'd array:" << std::endl;
    CircularDynamicArray<element> ar3 = ar1;
    print(ar3);
    std::cout << "Removing half from original. Only original should show changes" << std::endl;
    std::cout << ar1.length() << std::endl;
    int originalLength = ar1.length() / 2;
    for (int i = 0; i < originalLength; i++)
    {
        ar1.delEnd();
        // cout << ar1.length() << endl;
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

void foo(CircularDynamicArray<int> x)
{
    for (int i = 0; i < x.length() / 2; i++)
        x[i] = x[(x.length() / 2) + i];
    // X => "6 7 8 9 10 15 19 6 7 8 9 10 15 19 11"
    for (int i = 0; i < x.length(); i++)
        cout << x[i] << " ";
    cout << endl;
}

int main()
{
    // CircularDynamicArray<float> Z(10);

    // Z.addEnd(10);

    // Z.addEnd(5);

    // Z.addEnd(4);

    // Z.addEnd(8);

    // Z.addEnd(9);

    // Z.addEnd(2);

    // Z.addEnd(1);

    // Z.addEnd(3);

    // Z.addEnd(6);

    // Z.addEnd(7);
    // CircularDynamicArray<float> Y(10);

    // Z.addEnd(2);

    // Z.addEnd(5);

    // Z.addEnd(1);

    // Z.addEnd(0);

    // Z.addEnd(7);

    // Z.addEnd(3);

    // Z.addEnd(8);

    // Z.addEnd(4);

    // Z.addEnd(9);

    // Z.addEnd(6);
    /*
    CircularDynamicArray<int> Z(10);
    Z[0] = 10;

    Z[1] = 5;

    Z[2] = 4;

    Z[3] = 8;

    Z[4] = 9;

    Z[5] = 2;

    Z[6] = 1;

    Z[7] = 3;

    Z[8] = 6;

    Z[9] = 7;

    CircularDynamicArray<int> Y(10);
    Y[0] = 2;

    Y[1] = 5;

    Y[2] = 1;

    Y[3] = 0;

    Y[4] = 7;

    Y[5] = 3;

    Y[6] = 8;

    Y[7] = 4;

    Y[8] = 9;

    Y[9] = 6;

    for (int i = 0; i < Z.length(); i++)
    {
        std::cout << Z[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Z[Z.head()]: " << Z[Z.head()] << std::endl;
    std::cout << "Z[Z.tail()]: " << Z[Z.tail()] << std::endl;

    for (int i = 0; i < Y.length(); i++)
    {
        std::cout << Y[i] << " ";
    }
    std::cout << std::endl;
    std::cout << Y[Y.head()] << std::endl;
    std::cout << Y[Y.tail()] << std::endl;
    // Z.addEnd(11);
    std::cout << "Z.length(): " << Z.length() << std::endl;
    cout << "-------------------addFront(25)-------------------" << endl;
    Z.addFront(25);
    std::cout << "Z.head(): " << Z.head() << std::endl;
    std::cout << "Z[0]: " << Z[0] << std::endl;
    std::cout << "Z[Z.head()]: " << Z[Z.head()] << std::endl;
    // std::cout << "Z[Z.tail()]: " << Z[0] << std::endl;
    std::cout << "Z[Z.tail()]: " << Z[Z.tail()] << std::endl;
    std::cout << "indexFront: " << Z.operatorIndex(0) << std::endl;
    std::cout << "indexBack: " << Z.operatorIndex(Z.length() - 1) << std::endl;
    Z.addFront(50);
    Z.addEnd(51);
    // Z.addFront(51);
    Z.addFront(52);
    Z.addEnd(53);
    for (int i = 0; i < Z.length(); i++)
        std::cout << "Z[" << i << "]: " << Z[i] << endl;
    std::cout << endl;
    cout << "-------------------del-------------------" << endl;
    Z.delFront();
    Z.delEnd();

    for (int i = 0; i < Z.length(); i++)
        std::cout << "Z[" << i << "]: " << Z[i] << endl;
    std::cout << endl;

    std::cout << "-------------------stableSort-------------------" << endl;

    Z.stableSort();
    std::cout << endl;
    for (int i = 0; i < Z.length(); i++)
        std::cout << Z[i] << " ";
    std::cout << endl;
    std::cout << endl;

    Big3Tester(Z, Y);
*/
    CircularDynamicArray<float> C(10);
    for (int i = 0; i < C.length(); i++)
        C[i] = i;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;

    // C => "0 1 2 3 4 5 6 7 8 9"
    cout << "-------------------Delete Front-------------------" << endl;
    C.delFront();
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;

    // cout << "-------------------Reverse-------------------" << endl;
    // C.reverse();
    // for (int i = 0; i < C.length(); i++)
    //     cout << C[i] << " ";
    // cout << endl;
    // C => "1 2 3 4 5 6 7 8 9"
    C.delEnd();
    cout << "-------------------Delete End-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    // C => "1 2 3 4 5 6 7 8"
    C.addEnd(100.0);
    cout << "-------------------Add End(100)-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    // C => "1 2 3 4 5 6 7 8 100"
    cout << "-------------------Delete Front-------------------" << endl;
    C.delFront();
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    C.addEnd(200.0);
    cout << "-------------------Add End(200)-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    // C => "2 3 4 5 6 7 8 100 200"

    C.addEnd(300.0);
    cout << "-------------------Add End(300)-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    C.addEnd(400.0);
    cout << "-------------------Add End(400)-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    // C => "2 3 4 5 6 7 8 100 200 300 400"

    // std::cout << "-------------------stableSort-------------------" << endl;

    // C.stableSort();

    // for (int i = 0; i < C.length(); i++)
    //     std::cout << C[i] << " ";
    // std::cout << endl;

    // cout << "-------------------Reverse-------------------" << endl;
    // C.reverse();
    // for (int i = 0; i < C.length(); i++)
    //     cout << C[i] << " ";
    // cout << endl;
    // // C => "400 300 200 100 8 7 6 5 4 3 2"

    C.delFront();
    cout << "-------------------Delete Front-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    C.delFront();
    cout << "-------------------Delete Front-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    C.delEnd();
    cout << "-------------------Delete End-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;
    // C => "200 100 8 7 6 5 4 3"

    // cout << "-------------------Reverse-------------------" << endl;
    // C.reverse();
    // for (int i = 0; i < C.length(); i++)
    //     cout << C[i] << " ";
    // cout << endl;

    C.addFront(900.0);
    cout << "-------------------Add Front(900)-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;

    std::cout << "-------------------stableSort-------------------" << endl;

    C.stableSort();

    for (int i = 0; i < C.length(); i++)
        std::cout << C[i] << " ";
    std::cout << endl;

    C.addEnd(700.0);
    cout << "-------------------Add End(700)-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;

    cout << "-------------------Reverse-------------------" << endl;
    C.reverse();
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;

    C.addEnd(999.0);
    cout << "-------------------Add End(999)-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;

    C.addEnd(678.0);
    cout << "-------------------Add End(678)-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;

    C.addFront(222.0);
    cout << "-------------------Add Front(222)-------------------" << endl;
    for (int i = 0; i < C.length(); i++)
        cout << C[i] << " ";
    cout << endl;

    std::cout << "-------------------stableSort-------------------" << endl;

    C.stableSort();

    for (int i = 0; i < C.length(); i++)
        std::cout << C[i] << " ";
    std::cout << endl;
    // C = > "3 4 5 6 7 8 100 200"

    cout << "-------------------A B-------------------" << endl;
    CircularDynamicArray<int> A, B;
    for (int i = 0; i < 10; i++)
    {
        A.addEnd(i);
        for (int a = 0; a < A.length(); a++)
            cout << A[a] << " ";
        cout << endl;
    }
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    B = A;
    for (int i = 0; i < B.length(); i++)
        cout << B[i] << " ";
    cout << endl;
    A.addEnd(15);
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    A.addEnd(19);
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    // A => "0 1 2 3 4 5 6 7 8 9 15 19"
    cout << "linearSearch(5) is " << A.linearSearch(5) << endl;
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    // A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => 5
    cout << "binSearch(12) is  " << A.binSearch(12) << endl;
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    // A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => -1
    cout << "binSearch(15) is " << A.binSearch(15) << endl;
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    // A => "0 1 2 3 4 5 6 7 8 9 15 19" Search => 10
    cout << "-------------------addFront(10)-------------------" << endl;
    A.addFront(10);
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;

    // A => "10 0 1 2 3 4 5 6 7 8 9 15 19"
    cout << "linearSearch(5) is " << A.linearSearch(5) << endl;
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    // A => "10 0 1 2 3 4 5 6 7 8 9 15 19" Search => 6
    cout << "QuickSelect(3) is " << A.QuickSelect(3) << endl;

    // Select => 2
    //	cout << "Select is " << A.WCSelect(12) << endl;
    // Select => 15
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;

    cout << "-------------------stableSort-------------------" << endl;
    A.stableSort();
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    // A => "0 1 2 3 4 5 6 7 8 9 10 15 19"
    A.addEnd(11);
    cout << "-------------------addEnd(11)-------------------" << endl;
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    A.addFront(1);
    cout << "-------------------addFront(1)-------------------" << endl;
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    cout << A.length() << " " << A.capacity() << endl;

    cout << "-------------------addFront(2)-------------------" << endl;
    A.addFront(2);
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    cout << A.length() << " " << A.capacity() << endl;
    // A.clear();
    cout << "-------------------addFront(3)-------------------" << endl;
    A.addFront(3);
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "capacity is " << A.capacity() << endl;
    // A => "3 2 1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"	  capacity => 32

    cout << "-------------------delFront-------------------" << endl;
    A.delFront();
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;

    cout << "-------------------delFront-------------------" << endl;
    A.delFront();
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    // A => "1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"	  capacity => 32

    cout << "-------------------foo-------------------" << endl;
    foo(A);
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
    // A => "1 0 1 2 3 4 5 6 7 8 9 10 15 19 11"
    for (int i = 0; i < B.length(); i++)
        cout << B[i] << " ";
    cout << endl;
    // B => "0 1 2 3 4 5 6 7 8 9"
}