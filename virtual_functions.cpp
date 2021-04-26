#include<iostream> 
using namespace std; 

class Base 
{ 
int x; 
public: 
	virtual void fun() = 0; 
	int getX() { return x; } 
}; 

// This class inherits from Base and implements fun() 
class Derived: public Base 
{ 
	int y; 
public: 
	void fun() { cout << "fun() called"; } 
}; 

int main_x(void) 
{ 
	Derived d; 
	d.fun(); 
	return 0; 
} 

 

class base { 
public: 
	virtual void print() 
	{ 
		cout << "print base class" << endl; 
	} 

	void show() 
	{ 
		cout << "show base class" << endl; 
	} 
}; 

class derived : public base { 
public: 
	void print() 
	{ 
		cout << "print derived class" << endl; 
	} 

	void show() 
	{ 
		cout << "show derived class" << endl; 
	} 
}; 

int main() 
{ 
	base* bptr; 
	derived d; 
	bptr = &d; 

	// virtual function, binded at runtime 
	bptr->print(); 

	// Non-virtual function, binded at compile time 
	bptr->show(); 
} 
