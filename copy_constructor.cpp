
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


A move constructor, on the other hand, can simply "move" the data by 
taking ownership of the pointer that refers to the data, leaving the data
 itself where it resides. The new object now points at the original data, and
 the source object is modified to no longer point at the data. The data itself is 
left untouched.


A move constructor allows the resources owned by an rvalue object to be moved into an lvalue without creating its copy. An rvalue is an 
expression that does not have  any memory address, and an lvalue is an expression with a memory address.

int &j = 20;
The above code snippet will give an error because, in C++, a variable cannot be referenced to a temporary object. The correct way to do 
it is to create an​ rvalue reference using && :

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

class A{
  int *ptr;
public:
  A(){
    // Default constructor
    cout << "Calling Default constructor\n";
    ptr = new int ;
  }

  A( const A & obj){
    // Copy Constructor
    // copy of object is created
    this->ptr = new int;
    // Deep copying
    cout << "Calling Copy constructor\n";
  }
/*A move constructor allows the resources owned by an rvalue object to be moved into an lvalue without creating its copy. An rvalue is an expression that does not have 
any memory address, and an lvalue is an expression with a memory address.
*/
  A ( A && obj){
    // Move constructor
    // It will simply shift the resources,
    // without creating a copy.
     cout << "Calling Move constructor\n";
    this->ptr = obj.ptr;
    obj.ptr = NULL;
  }

  ~A(){
    // Destructor
    cout << "Calling Destructor\n";
    delete ptr;
  }

};

int main() {

  vector <A> vec;
  /* The copy constructor is called as the temporary object of A is pushed back in the vector.
    In the above code, there is a serious performance overhead as the temporary object A is first created in the default constructor 
    and then in the copy constructor.
     The move constructor is used to avoid this performance overhead:

  */
  vec.push_back(A());

  return 0;

}



