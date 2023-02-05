template <typename Elmtype>
class CircularDynamicArray
{
private:
    Elmtype *array;
    int size, cap;

public:
    // Constructors
    CircularDynamicArray()
    {
        size = 0;
        cap = 2;
        array = new Elmtype[cap];
    }
    CircularDynamicArray(int s)
    {
        size = s;
        cap = 2 * s;
        array = new Elmtype[cap];
    }

    // Destructor
    ~CircularDynamicArray()
    {
        delete[] array;
    }

    // Operators
    Elmtype &operator[](int i)
    {
        if (i < 0 || i >= size)
        {
            cout << "Error: Index out of bounds." << endl;
        }
        return array[i];
    }

    // Add elements
    void addEnd(Elmtype v)
    {
        if (size == cap)
        {
            cap *= 2;
            Elmtype *new_array = new Elmtype[cap];
            for (int i = 0; i < size; i++)
            {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }
        array[size++] = v;
    }
    void addFront(Elmtype v)
    {
        if (size == cap)
        {
            cap *= 2;
            Elmtype *new_array = new Elmtype[cap];
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

    // Delete elements
    void delEnd()
    {
        size--;
        if (size < cap / 4)
        {
            cap /= 2;
            Elmtype *new_array = new Elmtype[cap];
            for (int i = 0; i < size; i++)
            {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }
    }
    void delFront()
    {
        if (size == 0)
            return;

        array[0] = (array[0] + 1) % cap;
        size--;

        if (size == 0)
            array[0] = array[size] = -1;
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

    // Utility functions
    void clear()
    {
        size = 0;
        cap = 2;
        delete[] array;
        array = new Elmtype[cap];
    }
    Elmtype QuickSelect(int k)
    {
    }
    Elmtype WCSelect(int k)
    {
    }
    void stableSort()
    {
    }
    int linearSearch(Elmtype e)
    {
    }
    int binSearch(Elmtype e)
    {
    }
    void reverse()
    {
    }
};