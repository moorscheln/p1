// First commit project 1
template <typename Elmtype>
class CircularDynamicArray
{
private:
    Elmtype *array;
    int size, capacity;

public:
    // Constructors
    CircularDynamicArray();
    CircularDynamicArray(int s);

    // Destructor
    ~CircularDynamicArray();

    // Operators
    elmtype &operator[](int i);

    // Add elements
    void addEnd(elmtype v);
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
