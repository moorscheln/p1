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
    elmtype error;
    int size, cap, front, back;
    bool isReversed;

    void sizeIncrease()
    {
        cap = cap + cap;
        elmtype *increasedArray = new elmtype[cap];

        for (int i = 0; i < size; i++)
        {
            increasedArray[i] = array[(front + i) % cap];
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
        cap = cap / 2 + 1;
        elmtype *reducedArray = new elmtype[cap];

        for (int i = 0; i < size; i++)
        {
            reducedArray[i] = array[(front + i) % cap];
        }
        delete[] array;

        array = reducedArray;
        front = 0;
    }
    void DeepCopy(const CircularDynamicArray<elmtype> &obj)
    {
        size = obj.size;
        cap = obj.size;
        front = obj.front;
        back = obj.back;
        isReversed = obj.isReversed;
        error = obj.error;
        array = new elmtype[cap];
        for (int i = 0; i < obj.size; i++)
        {
            array[i] = obj.array[(front + i) % cap];
        }
    }
    int partition(elmtype arr[], int lo, int hi)
    {
        elmtype x = arr[hi];
        int i = lo - 1;
        for (int j = lo; j <= hi - 1; j++)
        {
            if (arr[j] <= x)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[hi]);
        return i + 1;
    }

    // elmtype randomPartition(elmtype arr[], int lo, int hi)
    // {
    //     srand(time(NULL));
    //     int random = lo + rand() % (hi - lo);

    //     // Swap arr[random] with A[lo]
    //     swap(arr[random], arr[lo]);

    //     return partition(arr, lo, lo);
    // }

    // elmtype randomPartition(elmtype arr[], int lo, int hi)
    // {
    //     srand(time(NULL));
    //     int random = lo + rand() % (hi - lo);

    //     // Swap arr[random] with A[lo]
    //     swap(arr[random], arr[lo]);

    //     return partition(arr, lo, lo);
    // }

    elmtype kthSmallest(elmtype arr[], int left, int right, int k)
    {
        srand(time(NULL));
        if (left == right)
        {
            return arr[left];
        }

        int pivotIndex = left + rand() % (right - left + 1);
        swap(arr[pivotIndex], arr[right]);
        int pivotNewIndex = partition(arr, left, right);
        int count = pivotNewIndex - left + 1;

        if (count == k)
        {
            return arr[pivotNewIndex];
        }
        else if (count > k)
        {
            return kthSmallest(arr, left, pivotNewIndex - 1, k);
        }
        else
        {
            return kthSmallest(arr, pivotNewIndex + 1, right, k - count);
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
        this->back = s - 1;
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

        for (int i = front; i < ((size + i) % cap); i++)
        {

            array[(front + i) % cap] = old.array[(front + i) % cap];
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
        }

        return *this;
    };

    // relativeIndex = index relative to front of array
    // Bracket Operator
    elmtype &operator[](int relativeIndex)
    {

        if (relativeIndex < 0 || relativeIndex >= cap)
        {
            cout << "Error: Index out of bounds." << endl;
            return error;
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
            size++;
            back = size - 1;
            array[size - 1] = endElement;
            // front = 0;

            // resize(cap * 2);
        }
        else
        {
            if (size == 0)
            {
                front = 0;
            }
            else if (back == (cap - 1))
            {
                back = 0;
            }
            else
            {
                back = back + 1;
            }
            array[back] = endElement;
            size++;
        }
    }
    void addFront(elmtype frontElement)
    {

        // EMPTY CASE, front = 0 --> size==1;
        // REGULAR, --> front = ()
        // INCREASE CASE,
        // front = 0, size=0 --> size==1;
        if (size == cap)
        {
            int max = cap;
            cap *= 2;
            elmtype *temp = array;
            array = new elmtype[cap];
            array[0] = frontElement;
            for (int i = 0; i < size; i++)
            {
                array[i + 1] = temp[(front + i) % max];
            }
            size++;
            front = 0;
            back = size - 1;
            delete[] temp;
        }
        else
        {
            if (front == -1)
                front = 0;
            else if (front == 0)
                front = cap - 1;
            else
                front = front - 1;
            size++;
            array[front] = frontElement;
        }
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
    int head()
    {
        return front;
    }
    int tail()
    {
        return back;
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
        CircularDynamicArray<elmtype> select(cap);

        int left = 0; // gets our front index

        int right = size;

        return kthSmallest(array, left, right - 1, k);
    }

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