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
        return array[(front + index) % cap];
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