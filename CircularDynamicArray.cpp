#include <algorithm>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

template <class elmtype>
class CircularDynamicArray
{
private:
    elmtype *array;
    // elmtype error;
    int size, cap, front, back;
    bool isReversed;
    // friend int indexFront(int index)
    // {
    //     return ((front + index + cap) % cap);
    // }
    // friend int indexBack(int index)
    // {
    //     return ((back + index + cap) % cap);
    // }
    void sizeIncrease()
    {
        cap = cap * 2;
        elmtype *increasedArray = new elmtype[cap];

        for (int i = 0; i < cap; i++)
        {
            increasedArray[indexFront(i)] = array[indexFront(i)];
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
            reducedArray[indexFront(i)] = array[indexFront(i)];
        }
        delete[] array;

        array = reducedArray;
        front = indexFront(0);
    }
    void DeepCopy(const CircularDynamicArray<elmtype> &obj)
    {
        size = obj.size;
        cap = obj.size;
        front = obj.front;
        back = obj.back;
        isReversed = obj.isReversed;
        // error = obj.error;
        array = new elmtype[cap];
        for (int i = 0; i < obj.size; i++)
        {
            array[(front + i + cap) % cap] = obj.array[(front + i + cap) % cap];
        }
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

    void Stable()
    {
        std::vector<elmtype> vec(array, array + size);
        std::stable_sort(vec.begin(), vec.end());
        for (int i = 0; i < size; i++)
        {
            array[i] = vec[i];
        }
    }
    // void setAt(int index, elmtype value)
    // {
    //     if (index < 0 || index >= size)
    //     {
    //         throw(out_of_range(new elmtype));
    //     }
    //     array[index] = value;
    // }

public:
    // Constructors
    CircularDynamicArray()
    {
        this->size = 0;
        this->cap = 2;
        this->front = 0;
        this->back = 0;
        this->array = new elmtype[cap];
        this->isReversed = false;
        // this->error = 0;
    }
    CircularDynamicArray(int s)
    {
        this->size = s;
        this->cap = 2 * s;
        this->front = 0;
        this->back = s;
        this->array = new elmtype[cap];
        this->isReversed = false;
        // this->error = 0;
    }

    // Destructor
    ~CircularDynamicArray()
    {
        delete[] array;
    }
    // (front+i+cap)%cap gives you correct index in array from our perspective while keeping it positive
    // empty pointer when outside the index (error)

    // Copy constructor
    CircularDynamicArray(const CircularDynamicArray<elmtype> &old)
    {
        size = old.size;
        cap = old.size;
        front = old.front;
        back = old.back;
        // error = old.error;
        array = new elmtype[cap];
        for (int i = 0; i < old.size; i++)
        {
            array[(front + i + cap) % cap] = old.array[(front + i + cap) % cap];
        }
    };

    // this.array = int[otherArray.size()]
    // for(int i = 0; i < otherArray.size(); i++) {
    //     this.array = otherArray[i];
    // }

    // Operators
    // Assignment operator
    CircularDynamicArray<elmtype> &operator=(const CircularDynamicArray<elmtype> &original) // Assign
    {
        if (this != &original)
        {
            delete[] array;
            DeepCopy(original);
            // this->size = original.size;
            // this->cap = original.size;
            // this->front = original.front;
            // this->back = original.back;
            // this->error = original.error;
            // this->array = new elmtype[cap];
            // for (int i = 0; i < original.size; i++)
            // {
            //     this->array[(front + i + cap) % cap] = original.array[(front + i + cap) % cap];
            // }
        }

        return *this;
    };

    // relativeIndex = index relative to front of array
    // Bracket Operator
    elmtype &operator[](int relativeIndex)
    {
        // try(relativeIndex < size || relativeIndex >= 0) {
        //     return array[(front + relativeIndex + cap) % cap];
        // }
        // throw
        // if (relativeIndex < size || relativeIndex >= 0)
        // {
        //     try();
        //     return array[(front + relativeIndex + cap) % cap];
        // }
        // else
        // {

        // }
        // array->setAt(relativeIndex, const new elmtype);

        if (relativeIndex < 0 || relativeIndex >= size)
        {
            cout << "Error: Index out of bounds." << endl;
        }
        else
        {
            return array[(front + relativeIndex + cap) % cap];
        }
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
            // elmtype temp = array[front];
            front = (front + 1) % cap;
            size--;
            if ((((double)size) / ((double)cap)) <= .25)
            {
                sizeReduce();
            }
        }
        else
        {
            return;
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

    elmtype QuickSelect(int k)
    {
        int left = 0;
        int right = size - 1;
        return kthSmallest(array, left, right, k);
    }

    // elmtype WCSelect(int k)
    // {
    // }
    // MERGE SORT
    void stableSort()
    {
        Stable();
    }
    int linearSearch(elmtype e)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == e)
            {
                return i;
            }
        }
        return -1;
    }
    int binSearch(elmtype e)
    {
        int left = 0;
        int right = size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (array[mid] == e)
            {
                return mid;
            }
            else if (array[mid] < e)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
    void reverse()
    {

        int start = 0;
        int end = size - 1;
        while (start < end)
        {
            swap(array[start], array[end]);
            start++;
            end--;
        }
    }
    int indexFront(int index)
    {
        return ((front + index + cap) % cap);
    }
    int indexBack(int index)
    {
        return ((back + index + cap) % cap);
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