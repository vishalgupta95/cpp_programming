/*
References in C++

When a variable is declared as a reference, it becomes an alternative name for an existing variable. A variable can be declared as 
a reference by putting ‘&’ in the declaration. 
 References are less powerful than pointers
1) Once a reference is created, it cannot be later made to reference another object; it cannot be reseated. This is often done with pointers. 
2) References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing. 
3) A reference must be initialized when declared. There is no such restriction with pointers

*/

#include<iostream>
using namespace std;

/*
Modify the passed parameters in a function: If a function receives a reference to a variable, it can modify the value of the variable. 
For example, the following program variables are swapped using references. 
*/
void swap (int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

int main()
{
	int a = 2, b = 3;
	swap( a, b );
	cout << a << " " << b;
	return 0;
}
// Avoiding a copy of large structures: Imagine a function that has to receive a large object.
// If we pass it without reference, a new copy of it is created which causes wastage of CPU time and memory. We can use references to avoid thi

struct Student {
string name;
string address;
int rollNo;
}

// If we remove & in below function, a new
// copy of the student object is created. 
// We use const to avoid accidental updates
// in the function as the purpose of the function
// is to print s only.
void print(const Student &s)
{
	cout << s.name << " " << s.address << " " << s.rollNo;
}


//
// In For Each Loops to modify all objects : We can use references in for each loops to modify all elements 
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	vector<int> vect{ 10, 20, 30, 40 }; 

	// We can modify elements if we 
	// use reference
	for (int &x : vect) 
		x = x + 5;

	// Printing elements
	for (int x : vect) 
	cout << x << " "; 

	return 0; 
} 

