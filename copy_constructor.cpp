
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
But what if you wanted to move x to y rather than copying it. You have to tell the compiler about that intent. You do that using std::move.

Foo x; 
Foo y(std::move(x));  // move constructed 

A move constructor allows the resources owned by an rvalue object to be moved into an lvalue without creating its copy. An rvalue is an expression that does not have 
any memory address, and an lvalue is an expression with a memory address.
*/

class String 
{ 
private: 
	char *s; 
	int size; 
public: 
	String(const char *str = NULL); // constructor 
	~String() { delete [] s; }// destructor 
	String(const String&); // copy constructor 
	void print() { cout << s << endl; } // Function to print string 
	void change(const char *); // Function to change 
}; 

String::String(const char *str) 
{ 
	size = strlen(str); 
	s = new char[size+1]; 
	strcpy(s, str); 
} 

void String::change(const char *str) 
{ 
	delete [] s; 
	size = strlen(str); 
	s = new char[size+1]; 
	strcpy(s, str); 
} 

String::String(const String& old_str) 
{ 
	size = old_str.size; 
	s = new char[size+1]; 
	strcpy(s, old_str.s); 
} 

int main() 
{ 
	String str1("GeeksQuiz"); 
	String str2 = str1; 

	str1.print(); // what is printed ? 
	str2.print(); 

	str2.change("GeeksforGeeks"); 

	str1.print(); // what is printed now ? 
	str2.print(); 
	return 0; 
} 


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

  ~A(){
    // Destructor
    cout << "Calling Destructor\n";
    delete ptr;
  }

};

int main() {

  vector <A> vec;
  /*
  Now, when the above code is executed, the default constructor is called at the time that the temporary object A is created. 
  The copy constructor is called as the temporary object of A is pushed back in the vector.
  
  In the above code, there is a serious performance overhead as the temporary object A is first created in the default constructor and then in the copy constructor. 
  The move constructor is used to avoid this performance overhead:
  */
  vec.push_back(A());

  return 0;
}


include <iostream>
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
  vec.push_back(A());

  return 0;

}

/*When the above code is executed, the move constructor is called instead of the copy constructor. With the move constructor, the copy of the temporary object of A is avoided. For a large number of push_back statements, 
using the move constructor is an efficient choice.
*/