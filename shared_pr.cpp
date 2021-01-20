#include <memory>
 
//Smart pointers are used to make sure that an object is deleted if it is no longer used (referenced).

//The unique_ptr<> template holds a pointer to an object and deletes this object when the unique_ptr<> object is deleted.

//As the name implies, make sure that only exactly one copy of an object exist

//The shared_pointer is a reference counting smart pointer that can be used to store and pass a reference beyond the scope of a function. This is particularly useful in the context of OOP, to store a pointer as a member variable and return it to access the referenced value outside the scope of the class. Consider the following example:

Run this code
void my_func()
{
    std::unique_ptr<int> valuePtr(new int(15));
    int x = 45;
    // ...
    if (x == 45)
        return;   // no memory leak anymore!
    // ...
}
 
int main()
{
}