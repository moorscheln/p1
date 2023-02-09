#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

template <typename elmtype>
class CircularDynamicArray
{
private:
    elmtype *array;
    elmtype error;
    int size, cap, front, back;
    int cdaIndex(int index)
    {
        return ((front + index) % cap);
    }
    void sizeIncrease()
    {
        cap = cap * 2;
        elmtype *increasedArray = new elmtype[cap];

        for (int i = 0; i < cap; i++)
        {
            increasedArray[i] = array[cdaIndex(i)];
        }

        delete[] array;

        array = increasedArray;
        front = 0;
    }
    void sizeReduce()
    {
        if (size <= 0)
        {
            return;
        }
        cap = cap / 2;
        elmtype *reducedArray = new elmtype[cap];

        for (int i = 0; i < cap; i++)
        {
            reducedArray[i] = array[cdaIndex(i)];
        }
        delete[] array;

        array = reducedArray;
        front = 0;
    }

public:
    // Constructors
    CircularDynamicArray()
    {
        this->size = 0;
        this->cap = 2;
        this->front = 0;
        this->back = 0;
        this->array = new elmtype[cap];
        this->error = 0;
    }
    CircularDynamicArray(int s)
    {
        this->size = s;
        this->cap = 2 * s;
        this->front = 0;
        this->back = s;
        this->array = new elmtype[cap];
        this->error = 0;
    }

    // Destructor
    ~CircularDynamicArray()
    {
        delete[] array;
    }
    // (front+i+cap)%cap gives you correct index in array from our perspective while keeping it positive
    // empty pointer when outside the index (error)

    // Copy constructor
    CircularDynamicArray(const CircularDynamicArray &old)
    {
        this->size = old.size;
        this->cap = old.size;
        this->front = old.front;
        this->back = old.back;
        this->error = old.error;
        this->array = new elmtype[cap];
        for (int i = 0; i < old.size; i++)
        {
            this->array[(front + i + cap) % cap] = old.array[(front + i + cap) % cap];
        }
    };

    // this.array = int[otherArray.size()]
    // for(int i = 0; i < otherArray.size(); i++) {
    //     this.array = otherArray[i];
    // }

    // Operators
    // Assignment operator
    CircularDynamicArray &operator=(const CircularDynamicArray &original) // Assign
    {
        if (this != &original)
        {
            delete[] array;
            this->size = original.size;
            this->cap = original.size;
            this->front = original.front;
            this->back = original.back;
            this->error = original.error;
            this->array = new elmtype[cap];
            for (int i = 0; i < original.size; i++)
            {
                this->array[(front + i + cap) % cap] = original.array[(front + i + cap) % cap];
            }
        }

        // size = old.size;
        // cap = old.cap;
        // front = 0;
        // array = new elmtype[cap];

        // for (int i = 0; i < size; i++)
        // {
        //     array[(front + i + cap) % cap] = old.array[(front + i + cap) % cap];
        // }

        return *this;
    };

    // relativeIndex = index relative to front of array
    // Bracket Operator
    elmtype &operator[](int relativeIndex)
    {
        if (relativeIndex < 0 || relativeIndex >= size)
        {
            cout << "Error: Index out of bounds." << endl;
            return this->error;
        }
        return array[(front + relativeIndex + cap) % cap];
    }

    // Add elements
    void addEnd(elmtype endElement)
    {
        if (size == cap)
        {
            sizeIncrease();
            // resize(cap * 2);
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
            sizeIncrease();
            // resize(cap * 2);
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
                // resize(cap / 2);
                sizeReduce();
            }
        }
    }
    void delFront()
    {
        if (size > 0)
        {
            elmtype temp = array[front];
            front = (front + 1) % cap;
            size--;
            if ((((double)size) / ((double)cap)) <= .25)
            {
                sizeReduce();
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
        int random = lo + rand() % (hi - lo);

        // Swap arr[random] with A[lo]
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
    // void resize(int newCapacity)
    // {
    //     elmtype *newArray = new elmtype[newCapacity];
    //     for (int i = 0; i < size; i++)
    //     {
    //         newArray[i] = array[(front + i) % cap];
    //     }
    //     delete[] array;
    //     array = newArray;
    //     front = 0;
    //     cap = newCapacity;
    // }
};