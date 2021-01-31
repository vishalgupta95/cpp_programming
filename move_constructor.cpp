#include <iostream>
#include <string>
using namespace std;

/*
A copy constructor constructs a new object by using the content of the argument object. An
overloaded assignment operator assigns the contents of an existing object to another existing
object of the same class.
*/

/*In the above code, there is a serious performance overhead as the temporary object cpym is first 
created in the default constructor and then in the copy constructor. The move constructor is 
used to avoid this performance overhead:
*/
/*
The move assignment operator is different than a move constructor because a move assignment
 operator is called on an existing object, while a move constructor is called on an object created by the operation. 
Thereafter, the other object's data is no longer valid.
*/
class Names{
private:
    string* name;
public:
    Names(string place_name){
        cout << "Overloaded constructor" << endl;
        name = new string;
        *name = place_name;
    }
    //copy constructor
    Names(Names& cpy){
        cout << "Copy constructor" << endl;
        name = new string;
        *name = *cpy.name;
    }
    //assignment 
    Names& operator =(const Names& cpy){
        cout << "Assignment operator" << endl;
        name = new string;
        *name = *cpy.name;
        return *this;
    }
	 // Move constructor
    // It will simply shift the resources,
    // without creating a copy
    //move constructor
	//With the move constructor, the copy of the temporary object of cpym is avoided
    Names(Names&& cpym){
        cout << "Copy move constructor" << endl;
        name = cpym.name;
        cpym.name = NULL;
    }
    //move assignment operator
    Names& operator=(Names&& cpym){
        cout << "Copy assignment operator" << endl;
        delete name;
        name = cpym.name;
        cpym.name = NULL;
        return *this;
    }
    //destructor
    ~Names(){
        cout << "Deallocating memory" << endl;
        delete [] name;
    }
};

int main(){
    Names nme("Bob");
    Names copin("something");
    copin = nme;
    system("pause");
    return 0;
} 