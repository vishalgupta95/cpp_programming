#include <iostream>   
using namespace std;
/*
Operator overloading is a compile-time polymorphism in which the operator is overloaded to provide the special meaning to the user-defined data type. Operator overloading is used to overload or redefines most of the operators available in C++.
 It is used to perform the operation on the user-defined data type.
 */
class OperatorOverload {
private:
	int x;

public:
	OperatorOverload() : x(10) {}
	void operator ++() {
		x = x + 2;
	}
	void Print() {
		cout << "The Count is: " << x;
		}
};
int main() {
	OperatorOverload ov;
	++ov;   
	ov.Print();
	return 0;
}
//output 12


#include <iostream>
using namespace std;
class TestClass {
private:
	int count;
public:
	TestClass() : count(5) {}
	void operator --() {
		count = count - 3;
	}
	void Display() { 

		cout << "Count: " << count; }
};

int main() {
	TestClass tc;
	--tc;
	tc.Display();
	return 0;
}
//output 2

#include<iostream> 
using namespace std; 

class Complex { 
private: 
	int real, imag; 
public: 
	Complex(int r = 0, int i =0) {real = r; imag = i;} 
	
	// This is automatically called when '+' is used with 
	// between two Complex objects 
	Complex operator + (Complex const &obj) { 
		Complex res; 
		res.real = real + obj.real; 
		res.imag = imag + obj.imag; 
		return res; 
	} 
	void print() { cout << real << " + i" << imag << endl; } 
}; 

int main() 
{ 
	Complex c1(10, 5), c2(2, 4); 
	Complex c3 = c1 + c2; // An example call to "operator+" 
	c3.print(); 
} 
