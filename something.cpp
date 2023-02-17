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
        cap = cap * 2;
        elmtype *increasedArray = new elmtype[cap];
        int head = front;
        int c = 0;
        while (head != back)
        {
            increasedArray[c] = array[head];
            head = (head) % size;
            c++;
        }
        increasedArray[c] = array[head];

        front = 0;
        back = size - 1;
        delete[] array;

        array = increasedArray;
        // front = 0;
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
    // void DeepCopy(const CircularDynamicArray<elmtype> &obj)
    // {
    //     size = obj.size;
    //     cap = obj.size;
    //     front = obj.front;
    //     back = obj.back;
    //     isReversed = obj.isReversed;
    //     // error = obj.error;
    //     array = new elmtype[cap];
    //     int c = front;

    //     for (int i = 0; i < size; i++)
    //     {
    //         array[c] = obj.array[c];
    //         c = (c + 1) % cap;
    //     }
    // }
    // int partition(elmtype arr[], int lo, int hi)
    // {
    //     elmtype x = arr[hi];
    //     int i = lo;
    //     for (int j = lo; j <= hi - 1; j++)
    //     {
    //         if (arr[j] <= x)
    //         {
    //             swap(arr[i], arr[j]);
    //             i++;
    //         }
    //     }
    //     swap(arr[i], arr[hi]);
    //     return i;
    // }

    // elmtype randomPartition(elmtype arr[], int lo, int hi)
    // {
    //     srand(time(NULL));
    //     int random = lo + rand() % (hi - lo);

    //     // Swap arr[random] with A[lo]
    //     swap(arr[random], arr[lo]);

    //     return partition(arr, lo, lo);
    // }

    int randomPartition(elmtype arr[], int l, int r, int pi)
    {
        elmtype pv = array[pi];

        swap(array[pi], array[r]);

        int si = l;

        for (int i = l; i <= r; i++)
        {
            if (array[i] < pv)
            {
                swap(array[i], array[si]);
                si++;
            }
        }

        swap(array[si], array[r]);
        return si;
    }

    // elmtype kthSmallest(CircularDynamicArray<elmtype> arr, int k)
    // {

    //     // srand((unsigned)time(NULL));
    //     int n = arc4random();
    //     int randomNum = n % arr.length();
    //     int pivot = arr[randomNum];
    //     CircularDynamicArray<elmtype> L, E, G;
    //     for (int i = 0; i < arr.length(); i++)
    //     {
    //         if (arr[i] < pivot)
    //         {
    //             L.addEnd(arr[i]);
    //         }
    //         else if (arr[i] == pivot)
    //         {
    //             E.addEnd(arr[i]);
    //         }
    //         else
    //         {
    //             G.addEnd(arr[i]);
    //         }
    //     }
    //     if (k <= L.length())
    //     {
    //         return kthSmallest(L, k);
    //     }
    //     else if (k <= L.length() + E.length())
    //     {
    //         return pivot;
    //     }
    //     else
    //     {
    //         return kthSmallest(G, (k - L.length() - E.length()));
    //     }
    // }

    // elmtype kthSmallest(elmtype arr[], int l, int r, int k)
    // {
    //     if (l == r)
    //     {
    //         return array[l];
    //     }

    //     int pivot = l + (arc4random() % (r - l + 1));
    //     pivot = randomPartition(array, l, r, pivot);

    //     if (k > pivot)
    //     {
    //         return kthSmallest(array, pivot + 1, r, k);
    //     }
    //     else if (k < pivot)
    //     {
    //         return kthSmallest(array, l, pivot - 1, k);
    //     }
    //     else
    //     {
    //         return array[k];
    //     }
    // }

    elmtype kthSmallest(CircularDynamicArray<elmtype> arr, int k)
    {

        // srand((unsigned)time(NULL));
        int n = arc4random();
        int randomNum = n % arr.length();

        int pivotIndex = randomNum;

        elmtype pivot = arr[pivotIndex];
        cout << "RNANKAD" << endl;
        CircularDynamicArray<elmtype> L, E, G;

        for (int i = 0; i < arr.length(); i++)
        {
            if (arr[i] < pivot)
            {
                L.addEnd(arr[i]);
            }
            else if (arr[i] == pivot)
            {
                E.addEnd(arr[i]);
            }
            else
            {
                G.addEnd(arr[i]);
            }
        }
        if (k <= L.length())
        {
            return kthSmallest(L, k);
        }
        else if (k <= L.length() + E.length())
        {
            return pivot;
        }
        else
        {
            return kthSmallest(G, k - L.length() - E.length());
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
    CircularDynamicArray(const CircularDynamicArray &old)
    {
        size = old.size;
        cap = old.size;
        front = old.front;
        back = old.back;
        isReversed = old.isReversed;
        // error = obj.error;
        array = new elmtype[cap];
        int c = front;

        for (int i = 0; i < size; i++)
        {
            array[c] = old.array[c];
            c = (c + 1) % cap;
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

            size = original.size;
            cap = original.size;
            front = original.front;
            back = original.back;
            error = original.error;
            array = new elmtype[cap];
            int c = front;
            for (int i = front; i < size; i++)
            {
                array[c] = original.array[c];
                c = (c + 1) % cap;
            }

            return *this;
        }

        return *this;
    };

    // relativeIndex = index relative to front of array
    // Bracket Operator
    elmtype &operator[](int realIndex)
    {
        int userIndex;
        if (realIndex > back)
        {
            back = realIndex;
        }

        if (isReversed == false)
        {
            userIndex = (front + realIndex + cap) % cap;
        }

        else
        {
            userIndex = (back - realIndex + cap) % cap;
        }

        return array[userIndex];

        // if (relativeIndex < 0 || relativeIndex >= cap)
        // {
        //     cout << "Error: Index out of bounds." << endl;
        //     return error;
        // }
        // else if ((relativeIndex > size) && (relativeIndex < cap))
        // {
        //     return array[(front + relativeIndex + cap) % cap];
        // }
        // else
        // {
        //     return array[(front + relativeIndex + cap) % cap];
        // }
    }

    // Add elements
    void addEnd(elmtype endElement)
    {
        if (size == cap)
        {
            sizeIncrease();
            // size++;
            // back = size - 1;
            // array[size - 1] = endElement;
            // front = 0;

            // resize(cap * 2);
        }
        if (isReversed == false)
        {
            if (size == 0)
            {
                array[0] = endElement;
                front = 0;
                back = 0;
                size++;
            }
            else
            {
                array[(back + 1 + cap) % cap] = endElement;
                back = (back + 1 + cap) % cap;
                size++;
            }
        }
        else
        {
            if (size == 0)
            {
                array[0] = endElement;
                front = 0;
                back = 0;
                size++;
            }
            else
            {
                array[(front - 1 + cap) % cap] = endElement;
                front = (front - 1 + cap) % cap;
                size++;
            }
            // if (size == 0)
            // {
            //     front = 0;
            // }
            // else if (back == (cap - 1))
            // {
            //     back = 0;
            // }
            // else
            // {
            //     back = back + 1;
            // }
            // array[back] = endElement;
            // size++;
        }
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

        // EMPTY CASE, front = 0 --> size==1;
        // REGULAR, --> front = ()
        // INCREASE CASE,
        // front = 0, size=0 --> size==1;
        if (size == cap)
        {
            sizeIncrease();
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

        // if (size == cap)
        // {
        //     sizeIncrease();
        //     // addFront(frontElement);
        // }
        // else
        // {
        //     if (isReversed == true)
        //     {
        //     }
        //     // if not reversed and it is not empty
        //     if (size == 0)
        //     {
        //         front = 0;
        //     }
        //     else if (front == 0) // changes users perspective of array[0]
        //     {
        //         elmtype *temp;
        //         front = cap - 1;
        //     }
        //     else
        //     {
        //         front = front - 1;
        //     }
        //     size++;
        //     array[front] = frontElement;
        // }
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

        // int left = 0; // gets our front index
        CircularDynamicArray<elmtype> select;
        for (int i = 0; i < size; i++)
        {
            select.array[i] = array[((front + i + cap) % cap)];
            cout << select[i] << " ";
            cout << array[i] << " ";
            cout << array[(front + i + cap) % cap] << endl;
        }

        // int right = size;

        return kthSmallest(select, k);
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