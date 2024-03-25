#include <iostream>
#include <vector>
using namespace std;

class DynamicArray
{
private:
    int *arr;
    int size;
    int capacity;

public:
    DynamicArray() {}

    // initialize an empty array with a capacity of capacity, where capacity > 0
    DynamicArray(int capacity) : size(0), capacity(capacity)
    {
        arr = new int[capacity];
    }

    // return the element at index i. Assume that index i is valid
    int get(int i)
    {
        return arr[i];
    }

    // set the element at index i to n. Assume that index i is valid
    void set(int i, int n)
    {
        arr[i] = n;
    }

    // push the element n to the end of the array
    // if array is full, resize the array first
    void pushback(int n)
    {
        if (size == capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    // pop and return the element at the end of the array. Assume that the array is non-empty
    int popback()
    {
        if (size > 0) {
            size--;
        }
        return arr[size];
    }

    // double the capacity of the array
    void resize()
    {
        capacity *= 2;
        int *newArr = new int[capacity];
        copy(arr, arr+size, newArr);
    }

    // return the number of elements in the array
    int getSize()
    {
        return size;
    }

    //  return the capacity of the array
    int getCapacity()
    {
        return capacity;
    }

    void init(int cap)
    {
        size = 0;
        capacity = cap;
        arr = new int[capacity];
    }
};

int main()
{
    DynamicArray da{};
    string str;
    while (cin >> str)
    {
        if (str == "Array")
        {
            int capacity;
            cin >> capacity;
            da.init(capacity);
            cout << "null\n";
        }
        else if (str == "get")
        {
            int pos;
            cin >> pos;
            cout << da.get(pos) << endl;
        }
        else if (str == "set")
        {
            int pos, val;
            cin >> pos >> val;
            da.set(pos, val);
            cout << "null\n";
        }
        else if (str == "pushback")
        {
            int val;
            cin >> val;
            da.pushback(val);
            cout << "null\n";
        }
        else if (str == "popback")
        {
            cout << da.popback() << endl;
        }
        else if (str == "getSize")
        {
            cout << da.getSize() << endl;
        }
        else if (str == "getCapacity")
        {
            cout << da.getCapacity() << endl;
        }
    }

    return 0;
}