#include <iostream>
using namespace std;

void nochange( int* pointer ) //passed by value
{
   pointer++; // change will be discarded once function returns
}

void change( int*& pointer ) //passed by reference
{
   pointer++; // change will persist when function returns
}


void foo(int *ptr)
{
    ptr = new int(50);    // Modifying the pointer to point to a different location
    cout << "In foo:\t" << *ptr << "\n"; 
    delete ptr ;
}

void bar(int *& ptr)
{
    ptr = new int(80);    // Modifying the pointer to point to a different location
    cout << "In bar:\t" << *ptr << "\n"; 
    // Deleting the pointer will result the actual passed parameter dangling
}
int main()
{
    int temp = 100 ;
    int *p = &temp ;

    cout << "Before foo:\t" << *p << "\n";
    foo(p) ;
    cout << "After foo:\t" << *p << "\n";

    cout << "Before bar:\t" << *p << "\n";
    bar(p) ;
    cout << "After bar:\t" << *p << "\n";

    delete p;

    return 0;
}