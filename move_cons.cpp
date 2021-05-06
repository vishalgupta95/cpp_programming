/*
/Default constructor does only shallow copy.
//Deep copy is possible only with user defined copy constructor.
//MyClass t1, t2; 
//MyClass t3 = t1; // ----> (1) 
//t2 = t1;       // -----> (2) 
//
//In the above example (1) calls copy constructor and (2) calls assignment operator. 
/*
Foo getFoo(); 
Foo x;   // default constructed 
Foo y(x);  // copy constructed 
Foo z(Foo());   // move constructed 
Foo w(getFoo());  // move constructed 
A copy constructor must leave the source object intact, so it must allocate 
its own copy of the object's data for itself. Both objects now refer to different 
copies of the same data in different areas of memory 
A move constructor, on the other hand, can simply "move" the data by 
taking ownership of the pointer that refers to the data, leaving the data
 itself where it resides. The new object now points at the original data, and
 the source object is modified to no longer point at the data. The data itself is 
left untouched.
*/

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class MyIntArray
{
private:
    int *arr = nullptr;
    int size = 0;

public:
    MyIntArray() = default;

    MyIntArray(int size)
    {
        arr = new int[size];
        this->size = size;
        for (int i = 0; i < size; ++i)
        {
            arr[i] = i;
        }
    }

    // copy constructor
    MyIntArray(const MyIntArray &src)
    {
        // allocate a new copy of the array...
        arr = new int[src.size];
        size = src.size;
        for (int i = 0; i < src.size; ++i)
        {
            arr[i] = src.arr[i];
        }
    }

    // move constructor
    MyIntArray(MyIntArray && src)
    {
        // just swap the array pointers...
        src.swap(*this);
    }

    ~MyIntArray()
    {
        delete[] arr;
    }

    // copy assignment operator
    MyIntArray &operator=(const MyIntArray &rhs)
    {
        if (&rhs != this)
        {
            MyIntArray temp(rhs); // copies the array
            temp.swap(*this);
        }
        return *this;
    }

    // move assignment operator
    MyIntArray &operator=(MyIntArray &&rhs)
    {
        MyIntArray temp(std::move(rhs)); // moves the array
        temp.swap(*this);
        return *this;
    }

    /*
    or, the above 2 operators can be implemented as 1 operator, like below.
    This allows the caller to decide whether to construct the rhs parameter
    using its copy constructor or move constructor...

    MyIntArray& operator=(MyIntArray rhs) {
        rhs.swap(*this);
        return *this;
    }
    */

    void swap(MyIntArray & other)
    {
        // swap the array pointers...
        std::swap(arr, other.arr);
        std::swap(size, other.size);
    }
};

int main()
{
    MyIntArray arr1(5);               // creates a new array
    MyIntArray arr2(arr1);            // copies the array
    MyIntArray arr3(std::move(arr2)); // moves the array
    MyIntArray arr4;                  // default construction
    arr4 = arr3;                      // copies the array
    arr4 = std::move(arr3);           // moves the array
    arr4 = MyIntArray(1);             // creates a new array and moves it

    copyArray(arr4);            // copies the array
    moveArray(std::move(arr4)); // moves the array

    copyArray(MyIntArray(10)); // creates a new array and copies it
    moveArray(MyIntArray(10)); // creates a new array and moves it
}
