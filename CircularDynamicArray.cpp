#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

template <typename elmtype>
class CircularDynamicArray
{
private:
    elmtype *array;
    int size, cap, front, back;

public:
    // Constructors
    CircularDynamicArray()
    {
        size = 0;
        cap = 2;
        array = new elmtype[cap];
        front = 0;
        // back = 0;
    }
    CircularDynamicArray(int s)
    {
        size = s;
        cap = 2 * s;
        array = new elmtype[cap];
        front = 0;
        // back = 0;
    }

    // Destructor
    ~CircularDynamicArray()
    {
        delete[] array;
    }

    // Operators
    elmtype &operator[](int i)
    {
        if (i < 0 || i >= size)
        {
            cout << "Error: Index out of bounds." << endl;
        }
        return array[i];
    }

    // Add elements
    void addEnd(elmtype endElement)
    {
        if (size == cap)
        {
            resize(cap * 2);
        }
        array[(front + size) % cap] = endElement;
        size++;
    }
    //     cap *= 2;
    //     elmtype *new_array = new elmtype[cap];
    //     for (int i = 0; i < size; i++)
    //     {
    //         new_array[i] = array[i];
    //     }
    //     delete[] array;
    //     array = new_array;
    // }
    // array[size++] = v;
    void addFront(elmtype frontElement)
    {
        if (size == cap)
        {
            resize(cap * 2);
        }

        front = (front - 1 + cap) % cap;
        array[front] = frontElement;
        size++;
    }

    // Delete elements
    void delEnd()
    {
        if (size > 0)
        {
            size--;
            if (size <= cap / 4)
            {
                resize(cap / 2);
            }
        }
    }
    void delFront()
    {
        if (size > 0)
        {
            front = (front + 1) % cap;
            size--;
            if (size <= cap / 4)
            {
                resize(cap / 2);
            }
        }
    }

    // Getters
    int length()
    {
        return size;
    }
    int capacity()
    {
        return cap;
    }

    elmtype get(int i)
    {
        return array[(front + i) % cap];
    }

    // Utility functions
    void clear()
    {
        size = 0;
        cap = 2;
        delete[] array;
        array = new elmtype[cap];
    }
    int partition(elmtype arr[], int lo, int hi)
    {
        elmtype x = arr[hi];
        int i = lo;
        for (int j = lo; j <= hi - 1; j++)
        {
            if (arr[j] <= x)
            {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[hi]);
        return i;
    }

    elmtype randomPartition(elmtype arr[], int lo, int hi)
    {
        srand(time(NULL));
        int random = lo + rand() % (lo - lo);

        // Swap A[random] with A[lo]
        swap(arr[random], arr[lo]);

        return partition(arr, lo, lo);
    }

    elmtype kthSmallest(elmtype arr[], int l, int r, int k)
    {
        if (l == r)
        {
            return arr[l];
        }
        int pos = partition(arr, l, r);
        int count = pos - l + 1;
        if (count == k)
        {
            return arr[pos];
        }
        else if (count > k)
        {
            return kthSmallest(arr, l, pos - 1, k);
        }
        else
        {
            return kthSmallest(arr, pos + 1, r, k - l);
        }
    }

    elmtype QuickSelect(int k)
    {
        int left = 0;
        int right = size - 1;
        return kthSmallest(array, left, right, k);
    }

    elmtype WCSelect(int k)
    {
    }
    void stableSort()
    {
    }
    int linearSearch(elmtype e)
    {
    }
    int binSearch(elmtype e)
    {
    }
    void reverse()
    {
    }
    void resize(int newCapacity)
    {
        elmtype *newArray = new elmtype[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[(front + i) % cap];
        }
        delete[] array;
        array = newArray;
        front = 0;
        cap = newCapacity;
    }
};