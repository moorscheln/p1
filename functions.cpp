// First commit project 1
template <typename Elmtype>
class CircularDynamicArray
{
private:
    Elmtype *array;
    int size, capacity;

public:
    // Constructors
    CircularDynamicArray()
    {
        size = 0;
        capacity = 2;
        array = new Elmtype[capacity];
    }
    CircularDynamicArray(int s)
    {
        size = s;
        capacity = 2 * s;
        array = new Elmtype[capacity];
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
    void addEnd(elmtype v)
    {
        if (size == capacity)
        {
            capacity *= 2;
            Elmtype *new_array = new Elmtype[capacity];
            for (int i = 0; i < size; i++)
            {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }
        array[size++] = v;
    }
    void addFront(elmtype v);

    // Delete elements
    void delEnd();
    void delFront();

    // Getters
    int length();
    int capacity();

    // Utility functions
    void clear();
    Elmtype QuickSelect(int k);
    Elmtype WCSelect(int k);
    void stableSort();
    int linearSearch(elmtype e);
    int binSearch(elmtype e);
    void reverse();
};

// template <typename Elmtype>
// CircularDynamicArray<Elmtype>::CircularDynamicArray()
// {
//     size = 0;
//     capacity = 2;
//     array = new Elmtype[capacity];
// }

// template <typename Elmtype>
// CircularDynamicArray<Elmtype>::CircularDynamicArray(int s)
// {
//     size = s;
//     capacity = 2 * s;
//     array = new Elmtype[capacity];
// }

// template <typename Elmtype>
// CircularDynamicArray<Elmtype>::~CircularDynamicArray()
// {
//     delete[] array;
// }

// template <typename Elmtype>
// Elmtype &CircularDynamicArray<Elmtype>::operator[](int i)
// {
//     if (i < 0 || i >= size)
//     {
//         cout << "Error: Index out of bounds." << endl;
//     }
//     return array[i];
// }

template <typename Elmtype>
void CircularDynamicArray<Elmtype>::addEnd(Elmtype v)
{
    if (size == capacity)
    {
        capacity *= 2;
        Elmtype *new_array = new Elmtype[capacity];
        for (int i = 0; i < size; i++)
        {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
    }
    array[size++] = v;
}

template <typename Elmtype>
void CircularDynamicArray<Elmtype>::addFront(Elmtype v)
{
    if (size == capacity)
    {
        capacity *= 2;
        Elmtype *new_array = new Elmtype[capacity];
        for (int i = 0; i < size; i++)
        {
            new_array[i + 1] = array[i];
        }
        delete[] array;
        array = new_array;
    }
    size++;
    for (int i = size - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = v;
}

template <typename Elmtype>
void CircularDynamicArray<Elmtype>::delEnd()
{
    size--;
    if (size < capacity / 4)
    {
        capacity /= 2;
        Elmtype *new_array = new Elmtype[capacity];
        for (int i = 0; i < size; i++)
        {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
    }
}

template <typename Elmtype>
void CircularDynamicArray<Elmtype>::delFront()
{
    size--;
    for (int i = 0; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    if (size < capacity / 4)
    {
        capacity /= 2;
        Elmtype *new_array = new Elmtype[capacity];
        for (int i = 0; i < size; i++)
        {
            new_array[i] = array[i];

            template <typename Elmtype>
            void CircularDynamicArray<Elmtype>::delFront()
            {
                // Check if the array is empty
                if (size == 0)
                    return;

                // Decrement size by 1
                size--;

                // Shift the remaining elements towards the front
                for (int i = 0; i < size; i++)
                {
                    data[i] = data[i + 1];
                }

                // Shrink the capacity if only 25% of the array is being used
                if (size < (capacity / 4))
                {
                    capacity /= 2;
                    Elmtype *temp = new Elmtype[capacity];
                    for (int i = 0; i < size; i++)
                    {
                        temp[i] = data[i];
                    }
                    delete[] data;
                    data = temp;
                }
            }

            template <typename Elmtype>
            int CircularDynamicArray<Elmtype>::length()
            {
                return size;
            }

            template <typename Elmtype>
            int CircularDynamicArray<Elmtype>::capacity()
            {
                return capacity;
            }

            template <typename Elmtype>
            void CircularDynamicArray<Elmtype>::clear()
            {
                size = 0;
                capacity = 2;
                delete[] data;
                data = new Elmtype[capacity];
            }

            template <typename Elmtype>
            Elmtype CircularDynamicArray<Elmtype>::QuickSelect(int k)
            {
                // Implement quick select algorithm
            }

            template <typename Elmtype>
            Elmtype CircularDynamicArray<Elmtype>::WCSelect(int k)
            {
                // Implement worst case O(N) time algorithm
            }

            template <typename Elmtype>
            void CircularDynamicArray<Elmtype>::stableSort()
            {
                // Implement comparison based stable sort algorithm
            }

            template <typename Elmtype>
            int CircularDynamicArray<Elmtype>::linearSearch(Elmtype e)
            {
                // Implement linear search algorithm
            }

            template <typename Elmtype>
            int CircularDynamicArray<Elmtype>::binSearch(Elmtype e)
            {
                // Implement binary search algorithm
            }

            template <typename Elmtype>
            void CircularDynamicArray<Elmtype>::reverse()
            {
                // Reverse the order of the elements in the array
            }
