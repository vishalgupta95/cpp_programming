
#include <iostream>
#include <string.h>
using namespace std;

//Default constructor does only shallow copy.
//Deep copy is possible only with user defined copy constructor.
//MyClass t1, t2; 
//MyClass t3 = t1; // ----> (1) 
//t2 = t1;		 // -----> (2) 
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

In C++, a Copy Constructor may be called in the following cases: 

When an object of the class is returned by value. 
When an object of the class is passed (to a function) by value as an argument. 
When an object is constructed based on another object of the same class. 
When the compiler generates a temporary object.

A move constructor, on the other hand, can simply "move" the data by 
taking ownership of the pointer that refers to the data, leaving the data
 itself where it resides. The new object now points at the original data, and
 the source object is modified to no longer point at the data. The data itself is 
left untouched.


A move constructor allows the resources owned by an rvalue object to be moved into an lvalue without creating its copy. An rvalue is an 
expression that does not have  any memory address, and an lvalue is an expression with a memory address.

int &j = 20;
The above code snippet will give an error because, in C++, a variable cannot be referenced to a temporary object. The correct way to do 
it is to create and rvalue reference using && :

int &&j = 20;
Temporary objects are often created during the execution of a C++ program.

*/
/*When the above code is executed, the move constructor is called instead of the copy constructor. With the move constructor, 
the copy of the temporary object of A is avoided. For a large number of push_back statements, 
using the move constructor is an efficient choice.
*/

#include <iostream>
#include <vector>
using namespace std;

#if 0

class Point {
private:
    int x, y;

public:
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }

    // Copy constructor
    Point(const Point& p1)
    {
        x = p1.x;
        y = p1.y;
    }

    int getX() { return x; }
    int getY() { return y; }
};

int main()
{
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here

    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX()
        << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX()
        << ", p2.y = " << p2.getY();

    return 0;
}


#endif

class String
{
private:
    char *s;
    int size;
public:
    String(const char *str = NULL);
    String(const String &src);
    ~String();
    String& operator=(const String &rhs);
    void print() const;
};

String::String(const char *str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

String::String(const String &src)
{
    size = src.size;
    s = new char[size+1];
    strcpy(s, src.s);
}

String::~String()
{
    delete [] s;
} 

void String::print() const
{
    cout << s << endl;
}

String& String::operator=(const String &rhs)
{
    if (&rhs != this)
    {
        String tmp(rhs);
        swap(s, tmp.s);
        swap(size, tmp.size);
    }
    return *this;
}

int main()
{
    String str1("learnc++");
    String str2 = str1;

    str1.print();
    str2.print();

    //str2.change("learnjava");
    str2 = "learnjava";

    str1.print();
    str2.print();

    return 0;
}




// C++ program without declaring the
// move constructor
#include <iostream>
#include <vector>
using namespace std;

// Move Class
class Move {
private:
    // Declaring the raw pointer as
    // the data member of the class
    int* data;

public:
    // Constructor
    Move(int d)
    {
        // Declare object in the heap
        data = new int;
        *data = d;

        cout << "Constructor is called for "
            << d << endl;
    };

    // Copy Constructor to delegated
    // Copy constructor
    Move(const Move& source)
        : Move{ *source.data }
    {

        // Copying constructor copying
        // the data by making deep copy
        cout << "Copy Constructor is called - "
            << "Deep copy for "
            << *source.data
            << endl;
    }

    // Destructor
    ~Move()
    {
        if (data != nullptr)

            // If the pointer is not
            // pointing to nullptr
            cout << "Destructor is called for "
                << *data << endl;
        else

            // If the pointer is
            // pointing to nullptr
            cout << "Destructor is called"
                << " for nullptr"
                << endl;

        // Free the memory assigned to
        // data member of the object
        delete data;
    }
};

// Driver Code
int main()
{
    // Create vector of Move Class
    vector<Move> vec;

    // Inserting object of Move class
    vec.push_back(Move{ 10 });
    vec.push_back(Move{ 20 });
    return 0;
}

