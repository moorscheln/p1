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
    bool isEmpty;
    void elmReverse(elmtype abc[])
    {
        // elmtype *reversedArray = new elmtype[cap];
        for (int i = 0; i < size; i++)
        {
            // increasedArray[i] = array[(front + i + max) % max];
            abc[i] = array[(front + i + cap) % cap];
        }

        // delete[] array;

        // for (int i = 0; i < size; i++)
        // {
        //     cout << array[i];
        // }
        // cout << endl;
        // int temp = back;
        // front = 0;
        // back = size - 1;
        // front = 0;
        // back = size - 1;
        int start = 0;

        int end = size - 1;
        int c = 0;
        while (start <= end)
        {
            swap(abc[start], abc[end]);
            start++;
            end--;
            c++;
        }
    }

    void elmInit(elmtype abc[])
    {
        // elmtype *reversedArray = new elmtype[cap];
        for (int i = 0; i < size; i++)
        {
            // increasedArray[i] = array[(front + i + max) % max];
            abc[i] = array[(front + i + cap) % cap];
        }
        delete[] array;

        array = abc;
    }

    elmtype inOrderArray(elmtype arr[])
    {
        elmtype *temp = new elmtype[cap];
        // array = new elmtype[cap];
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[(front + i) % cap];
        }
        return temp;
    }

    void sizeIncrease()
    {
        int max = cap;
        cap = cap * 2;
        elmtype *increasedArray = new elmtype[cap];

        for (int i = 0; i < size; i++)
        {
            // increasedArray[i] = array[(front + i + max) % max];
            increasedArray[i] = array[(front + i + cap) % cap];
        }

        delete[] array;

        array = increasedArray;
        // cout << "size increased " << endl;
        // front = 0;
        // back = size - 1;
    }
    void sizeReduce()
    {
        if (size <= 0)
        {
            return;
        }
        cap = cap / 2;
        elmtype *reducedArray = new elmtype[cap];

        for (int i = 0; i < size; i++)
        {
            reducedArray[i] = array[(front + i + cap) % cap];
        }
        delete[] array;

        array = reducedArray;
        // front = 0;
        // back = size - 1;
    }
    void DeepCopy(const CircularDynamicArray<elmtype> &obj)
    {
        // cout << "----DEEP COPY----" << endl;
        // cap = old.cap;
        // size = old.size;
        // front = old.front;
        // back = old.back;
        // isEmpty = old.isEmpty;
        // isReversed = old.isReversed;
        // array = new elmtype[cap];
        // int c = front;
        // cout << "front: " << front << endl;
        // cout << "size: " << size << endl;

        // for (int i = 0; i < cap; i++)
        // {

        //     array[c] = old.array[c];
        //     c = (c + 1);
        //     c = c % cap;
        //     // c = (c + 1) % cap;
        //     // array[(front + i + cap) % cap] = old.array[(front + i + cap) % cap];
        // }

        size = obj.size;
        cap = obj.cap;
        front = obj.front;
        back = obj.back;
        isReversed = obj.isReversed;
        isEmpty = obj.isEmpty;
        array = new elmtype[cap];
        for (int i = 0; i < obj.size; i++)
        {
            array[(front + i) % cap] = obj.array[(front + i) % cap];
        }
        // front = 0;
        // back = size - 1;
    }
    // int partition(elmtype arr[], int lo, int hi)
    // {
    //     elmtype x = arr[hi];
    //     int i = lo - 1;
    //     for (int j = lo; j <= hi - 1; j++)
    //     {
    //         if (arr[j] <= x)
    //         {
    //             i++;
    //             swap(arr[i], arr[j]);
    //         }
    //     }
    //     swap(arr[i + 1], arr[hi]);
    //     return i + 1;
    // }

    int PartitionAroundPivot(elmtype data[], int left, int right, int pivotIndex)
    {
        left = operatorIndex(left);
        right = operatorIndex(left);
        pivotIndex = operatorIndex(left);
        elmtype pivotValue = data[pivotIndex];
        int storeIndex = left;
        swap(data[pivotIndex], data[right]);
        for (int i = left; i < right; i++)
        {
            if (data[i] < pivotValue)
            {
                swap(data[i], data[storeIndex]);
                storeIndex++;
            }
        }
        swap(data[right], data[storeIndex]);
        return storeIndex;
    }

    // elmtype kthSmallest(elmtype arr[], int left, int right, int k)
    // {
    //     srand(time(NULL));
    //     if (left == right)
    //     {
    //         return arr[left];
    //     }

    //     int pivotIndex = left + rand() % (right - left + 1);
    //     swap(arr[pivotIndex], arr[right]);
    //     int pivotNewIndex = partition(arr, left, right);
    //     int count = pivotNewIndex - left + 1;

    //     if (count == k)
    //     {
    //         return arr[pivotNewIndex];
    //     }
    //     else if (count > k)
    //     {
    //         return kthSmallest(arr, left, pivotNewIndex - 1, k);
    //     }
    //     else
    //     {
    //         return kthSmallest(arr, pivotNewIndex + 1, right, k - count);
    //     }
    // }
    /*
        elmtype kthSmallest(elmtype arr[], int k)
        {
            srand(time(NULL));
            elmtype *temp = new elmtype[cap];
            temp = arr;
            // cout << endl;
            // cout << "cap: " << cap << endl;
            // for (int i = 0; i < cap; i++)
            // {
            //     cout << i << ": " << array[i] << endl;
            // }
            // cout << endl;
            int l = 0;
            cout << "l: " << l << endl;
            int leftOp = operatorIndex(front);
            cout << "leftOp: " << leftOp << endl;
            cout << "front: " << front << endl;
            // int leftOp = operatorIndex(front);

            // int l = operatorIndex(front);
            cout << "l: " << l << endl;
            int rightOp = operatorIndex(back);
            int r = size - 1;
            // int r = operatorIndex(back);
            cout << "r: " << r << endl;
            int count = 0;
            while (l < r)
            {
                // cout << "l<=r" << endl;
                // int pivotIndex = l + rand() % (r - l + 1);
                // int pivotIndex = operatorIndex(l + arc4random() % (r - l + 1));
                int pivotIndex = l + arc4random() % (r - l + 1);
                cout << "pivotIndex: " << pivotIndex << endl;
                int newPivotIndex = PartitionAroundPivot(temp, l, r, pivotIndex);
                cout << "newpivotIndex: " << newPivotIndex << endl;
                if (newPivotIndex == k)
                {
                    // cout << "arr[new]: " << arr[newPivotIndex] << endl;
                    // cout << "arr[operatorIndex]: " << arr[operatorIndex(newPivotIndex)] << endl;
                    count++;
                    cout << "temp: " << endl;
                    return temp[newPivotIndex];
                }
                else if (newPivotIndex < k)
                {
                    l = newPivotIndex + 1;
                    count++;
                }
                else
                {
                    r = newPivotIndex - 1;
                    count++;
                }
            }

            // cout << "arr[0]" << endl;
            return temp[0];
        }
        */

    int partition(elmtype arr[], int l, int r)
    {
        int i = l;
        elmtype x = arr[r];
        for (int j = l; j <= r - 1; j++)
        {
            if (arr[j] <= x)
            {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }

    elmtype kthSmallest(elmtype arr[], int l, int r, int k)
    {

        int index = partition(arr, l, r);
        if (index - l == k - 1)
        {
            return arr[index];
        }
        if (index - l > k - 1)
        {
            return kthSmallest(arr, l, index - 1, k);
        }
        return kthSmallest(arr, index + 1, r, k - index + l - 1);
    }

    elmtype Select(int k)
    {
        // if (Ordered() == true)
        //     return array[k - 1];
        // else
        // {
        // elmtype *temp = new elmtype[cap];
        elmtype *temp = new elmtype[cap];
        // array = new elmtype[cap];
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[(front + i) % cap];
        }
        // front = 0;
        // back = size - 1;

        elmtype kSmall = kthSmallest(temp, 0, size - 1, k);
        delete[] temp;
        return kSmall;
        // return kthSmallest(array, front, back, k);
        // }
    }

    // void mergeElm(elmtype arr[], int left, int mid, int right)
    // {

    //     elmtype a1 = mid - left + 1;
    //     elmtype a2 = right - mid;

    //     // Create temp arrays
    //     elmtype *leftArray = new elmtype[a1], *rightArray = new elmtype[a2];

    //     // Copy data to temp arrays leftArray[] and rightArray[]
    //     for (int i = 0; i < a1; i++)
    //     {
    //         leftArray[i] = array[(left + i) % cap];
    //     }

    //     for (int j = 0; j < a2; j++)
    //     {
    //         rightArray[j] = array[(mid + 1 + j) % cap];
    //     }

    //     int indexOfa1 = 0,
    //         indexOfa2 = 0;

    //     int indexOfMergedArray = left; // Initial index of merged array

    //     // Merge the temp arrays back into array[left..right]
    //     while (indexOfa1 < a1 && indexOfa2 < a2)
    //     {
    //         if (leftArray[indexOfa1] <= rightArray[indexOfa2])
    //         {
    //             array[indexOfMergedArray] = leftArray[indexOfa1];
    //             indexOfa1++;
    //         }

    //         else
    //         {
    //             array[indexOfMergedArray] = rightArray[indexOfa2];
    //             indexOfa2++;
    //         }

    //         indexOfMergedArray++;
    //     }

    //     // Copy the remaining elements of
    //     // left[], if there are any
    //     while (indexOfa1 < a1)
    //     {
    //         array[indexOfMergedArray] = leftArray[indexOfa1];
    //         indexOfa1++;
    //         indexOfMergedArray++;
    //     }

    //     // Copy the remaining elements of
    //     // right[], if there are any
    //     while (indexOfa2 < a2)
    //     {
    //         array[indexOfMergedArray] = rightArray[indexOfa2];
    //         indexOfa2++;
    //         indexOfMergedArray++;
    //     }

    //     delete[] leftArray;
    //     delete[] rightArray;
    // }

    /*
        void mergeSort(elmtype arr[], int l, int r)
        {
            // int distFromCap = cap - front;
            // front = (front + distFromCap + cap) % cap; // = 0
            // back = size - 1 - distFromCap;
            cout << "mergeSort" << endl;
            if (l < r)
            {
                cout << "l<r" << endl;
                int m = (l + r) / 2;
                mergeSort(arr, l, m);
                mergeSort(arr, m + 1, r);
                merge(arr, l, m, r);
            }
            else
            {
                cout << "r>=l" << endl;
                int m = (l + r) / 2;
                mergeSort(arr, l, m);
                mergeSort(arr, m + 1, r);
                merge(arr, l, m, r);
            }
        }
        */

    void mergeSort(int min, int max)
    {
        // if (isReversed == true)
        // {
        //     swap(max, min);
        //     if (min >= max)
        //     {
        //         return;
        //     }

        //     int mid = (max + min + 1) / 2;
        //     mergeSort(min, mid - 1);
        //     mergeSort(mid, max);

        //     merge(min, mid, max);
        // }
        // else
        // {
        if (isReversed == true)
        {

            // cout << "max: " << max << endl;
            // cout << "min: " << min << endl;
            if (max <= min)
                return;
        }
        if (isReversed == false)
        {
            if (min >= max)
                return;
        }

        int mid = (max + min + 1) / 2;
        mergeSort(min, mid - 1);
        mergeSort(mid, max);
        // for (int i = 0; i < size; i++)
        // {
        //     cout << i << ": " << array[i] << endl;
        // }
        mergeArr(array, min, mid, max);
        // }
    }

    void merge(int min, int mid, int max)
    {
        elmtype *temp = new elmtype[max - min + 1];
        int smin = min; // starting min

        int rmid = mid;     // right mid
        int lmid = mid - 1; // left mid
        int i = 0;
        for (; min <= lmid && max >= rmid; i++)
        {
            if (this->array[operatorIndex(rmid)] < this->array[operatorIndex(min)])
            {
                temp[i] = this->array[operatorIndex(rmid)];
                rmid++;
            }
            else
            {
                temp[i] = this->array[operatorIndex(min)];
                min++;
            }
        }

        for (; min <= lmid; i++, min++)
            temp[i] = this->array[operatorIndex(min)];
        for (; max >= rmid; i++, rmid++)
            temp[i] = this->array[operatorIndex(rmid)];

        for (int j = 0; j < i; j++)
        {

            this->array[operatorIndex(j + smin)] = temp[j];
        }
        delete[] temp;
    }

    void mergeArr(elmtype data[], int min, int mid, int max)
    {
        // cout << "i ";
        // for (int i = 0; i < size; i++)
        // {
        //     cout << data[i] << " ";
        // }
        // cout << endl;
        // cout << "opI ";
        // for (int i = 0; i < size; i++)
        // {
        //     cout << data[operatorIndex(i)] << " ";
        // }
        // cout << endl;

        // cout << "max" << max << endl;
        // cout << "size" << size << endl;
        // cout << "min" << min << endl;
        elmtype *temp = new elmtype[max - min + 1];
        int smin = min; // starting min

        int rmid = mid;     // right mid
        int lmid = mid - 1; // left mid
        int i = 0;
        for (; min <= lmid && max >= rmid; i++)
        {
            // cout << "array[operatorIndex(rmid)]" << array[operatorIndex(rmid)] << en
            if (this->array[operatorIndex(rmid)] < this->array[operatorIndex(min)])
            {
                temp[i] = this->array[operatorIndex(rmid)];
                rmid++;
            }
            else
            {
                temp[i] = this->array[operatorIndex(min)];
                min++;
            }
        }

        for (; min <= lmid; i++, min++)
        {
            // cout << "max--- " << this->array[operatorIndex(min)] << endl;
            temp[i] = this->array[operatorIndex(min)];
        }
        for (; max >= rmid; i++, rmid++)
        {
            // cout << "max--- " << this->array[operatorIndex(rmid)] << endl;
            temp[i] = this->array[operatorIndex(rmid)];
        }

        for (int j = 0; j < i; j++)
        {
            // cout << "j--- " << temp[j] << endl;
            this->array[operatorIndex(j + smin)] = temp[j];
        }
        delete[] temp;
        // cout << endl;
    }

    void Stable()
    {
        if (isReversed == false)
        {

            // cout << "regular sort" << endl;
            mergeSort(0, size - 1);
        }
        if (isReversed == true)
        {
            // for (int i = 0; i < size; i++)
            // {
            //     cout << array[operatorIndex(i)] << " ";
            // }
            // cout << endl;
            // elmtype *forwardArr = new elmtype[cap];
            // elmReverse(forwardArr);
            // for (int i = 0; i < cap; i++)
            // {
            //     cout << forwardArr[i] << " ";
            // }
            // cout << endl;
            // cout << "reversed sort" << endl;
            mergeSort(0, size - 1);
        }
        // if (isReversed == false)
        // {
        //     cout << "Stable" << endl;
        //     mergeSort(array, 0, size - 1);
        // }
        // else
        // {
        //     mergeSort(array, size - 1, 0);
        // }
        /*
                front = 0;
                back = length() - 1;

                vector<elmtype> vec(array, array + size);
                stable_sort(vec.begin(), vec.end());
                for (int i = 0; i < size; i++)
                {
                    array[i] = vec[i];
                }
                */
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
        // cout << "----DEFAULT CONSTRUCT----" << endl;
        this->size = 0;
        this->cap = 2;
        this->front = 0;
        this->back = 0;
        this->array = new elmtype[cap];
        this->isReversed = false;
        this->isEmpty = true;
        // this->error = 0;
    }
    CircularDynamicArray(int s)
    {
        // cout << "----INT CONSTRUCT----" << endl;
        this->size = s;
        this->cap = 2 * s;
        this->front = 0;
        this->back = s - 1;
        this->array = new elmtype[cap];
        this->isReversed = false;
        this->isEmpty = false;
        // this->error = 0;
    }

    // Destructor
    ~CircularDynamicArray()
    {
        // cout << "----DESTRUCTOR ----" << endl;
        delete[] array;
    }
    // (front+i+cap)%cap gives you correct index in array from our perspective while keeping it positive
    // empty pointer when outside the index (error)

    // Copy constructor
    CircularDynamicArray(const CircularDynamicArray<elmtype> &old)
    {
        // cout << "----COPY CONSTRUCTOR ----" << endl;
        DeepCopy(old);
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
            // cout << "----operator= ----" << endl;
            delete[] array;
            DeepCopy(original);
        }

        return *this;
    };

    // operatorIndex = index relative to front of array
    // Bracket Operator
    elmtype &operator[](int i)
    {

        if (i < 0 || i >= cap)
        {
            cout << "Error: Index out of bounds." << endl;
            return error;
        }
        else
        {
            return array[(i + front) % cap];
        }
    }

    // Add elements
    void addEnd(elmtype endElement)
    {

        if (size == cap)
        {
            sizeIncrease();
            // cout << "SizeIncrease" << endl;
            size++;
            back = size - 1;
            array[back] = endElement;
            // front = 0;

            // resize(cap * 2);
        }
        else
        {
            if (isEmpty == true)
            {
                front = 0;
                back = 0;
                isEmpty = false;
            }
            else if (back == (cap - 1))
            {
                // cout << "back = 0" << endl;
                back = 0;
            }
            else
            {
                // cout << "back = back+1" << endl;
                back = back + 1;
            }
            size++;
            // back++;
            array[back] = endElement;
            isEmpty = false;
        }
    }
    void addFront(elmtype frontElement)
    {

        // EMPTY CASE, front = 0 --> size==1;
        // REGULAR, --> front = ()
        // INCREASE CASE,
        // front = 0, size=0 --> size==1;
        if (size + 1 > cap)
        {
            // cout << "size: " << size << endl;
            // cout << "cap: " << cap << endl;
            // // sizeIncrease(); // reset front to 0, cap = cap*2
            // cout << "size: " << size << endl;
            // cout << "cap: " << cap << endl;
            elmtype *temp = new elmtype[cap * 2];

            temp[0] = frontElement;
            int c = 0;
            for (int i = 0; i < size; i++)
            {
                // cout << i << ": " << array[i] << endl;
                temp[i + 1] = array[operatorIndex(i)];
                c++;
            }

            delete[] array;
            array = temp;
            front = 0;
            cap = cap * 2;

            size = c + 1;
            // cout << "size = c: " << size << endl;
            // back = size - 1;
        }
        else
        {
            if (isEmpty == true)
            { // initially empty
                front = 0;
                back = 1;
                isEmpty = false;
            }
            else if (front == 0)
            {
                front = cap - 1;
            }
            else
            {
                front = front - 1;
            }
            // if (front == cap - 1)
            // {
            //     front = 0;
            // }
            // else if (front == 0)
            // {
            //     front = cap - 1;
            // }
            // else
            // {
            //     front = front - 1;
            // }
            size++;
            // cout << "addFront size: " << size << endl;
            // array[indexFront(front)] = frontElement;
            array[front] = frontElement;
        }
    }

    // Delete elements
    void delEnd()
    {
        if (isEmpty == false)
        {
            if (size <= 0)
            {
                isEmpty = true;
            }
            if (size <= cap / 4)
            {
                // resize(cap / 2);
                sizeReduce();
            }
            size--;
            back = (back - 1 + cap) % cap;
        }
    }
    void delFront()
    {
        if (isEmpty == false)
        {
            // elmtype temp = array[front];
            front = (front + 1 + cap) % cap;
            size--;
            if (size <= 0)
            {
                isEmpty = true;
            }
            else if ((((double)size) / ((double)cap)) <= .25)
            {
                // cout << "Size Reduced " << endl;
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
    int head()
    {
        return 0;
    }
    int tail()
    {
        return size - 1;
    }

    elmtype get(int i)
    {
        return array[i];
    }

    // Utility functions
    void clear()
    {
        delete[] array;
        array = new elmtype[cap];
        size = 0;
        cap = 2;
        isEmpty = true;
    }

    elmtype QuickSelect(int k)
    {

        return Select(k);
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
        int left = front;
        int right = back;
        if (front >= back)
        {
            left = back;
            right = front;
        }

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
        isReversed = !isReversed;
        if (isReversed == false) // was true, now false
        {
            elmtype *reversedArray = new elmtype[cap];
            for (int i = 0; i < size; i++)
            {
                // increasedArray[i] = array[(front + i + max) % max];
                reversedArray[i] = array[(front + i + cap) % cap];
            }

            delete[] array;

            array = reversedArray;
            // front = 0;
            // back = size - 1;
            front = 0;
            back = size - 1;
            int start = front;
            int end = back;
            int c = 0;
            while (start < end)
            {
                swap(array[start], array[end]);
                start++;
                end--;
                c++;
            }
            // cout << "front: " << front << endl;
            // cout << "back: " << back << endl;
        }
        else // was false, now true
        {
            elmtype *reversedArray = new elmtype[cap];
            for (int i = 0; i < size; i++)
            {
                // increasedArray[i] = array[(front + i + max) % max];
                reversedArray[i] = array[(front + i + cap) % cap];
            }

            delete[] array;

            array = reversedArray;
            // for (int i = 0; i < size; i++)
            // {
            //     cout << array[i];
            // }
            // cout << endl;
            // int temp = back;
            // front = 0;
            // back = size - 1;
            front = 0;
            back = size - 1;
            int start = 0;

            int end = size - 1;
            int c = 0;
            while (start <= end)
            {
                swap(array[start], array[end]);
                start++;
                end--;
                c++;
            }
            // cout << "front: " << front << endl;
            // cout << "back: " << back << endl;
        }
    }
    int operatorIndex(int i)
    {
        if (isReversed == false)
        {

            return ((front + i + cap) % cap);
        }
        else
        {
            return ((front + i + cap) % cap);
        }
    }
    // int indexBack(int i)
    // {
    //     return ((back + i + cap) % cap);
    // }
};
