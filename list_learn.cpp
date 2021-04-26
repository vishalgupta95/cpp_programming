#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

/*
Both vector and list are sequential containers of C++ Standard Template Library. But 
there are many differences between them because of their internal implementation i.e.

List stores elements at non contiguous memory location i.e. it internally uses a doubly
linked list i.e. nsertion and Deletion in List is very efficient as compared to vector
 because to insert an element in list at start, end or middle, internally just a couple 
of pointers are swapped.
As List is internally implemented as doubly linked list, therefore no random access is
 possible in List. It means, to access 15th element in list we need to iterate through 
 first 14 elements in list one by one.

*/

bool stringCompare(const string & l, const string & r)                                                                                   
{                                                                                                                                    
   return (l==r);                                                                                                                         
}

int main()                                                                                                                               
{                                                                                                                                        

  list<string> myStrings;                                                                                                                
  myStrings.push_back("1001");                                                                                                           
  myStrings.push_back("1001");                                                                                                           
  myStrings.push_back("81");                                                                                                             
  myStrings.push_back("1001");                                                                                                           
  myStrings.push_back("81");                                                                                                             

  myStrings.sort();                                                                                                                      
  myStrings.erase(unique(myStrings.begin(), myStrings.end(), stringCompare), myStrings.end());                                           

  list<string>::iterator it;                                                                                                             
  for(it = myStrings.begin(); it != myStrings.end(); ++it)                                                                               
  {                                                                                                                                      
    cout << *it << endl;                                                                                                                 
  }                                                                                                                                      

  return     0;                                                                                                                              
}

int abc ()
{
  std::list<int> mylist (2,100);         // two ints with a value of 100
  mylist.push_front (200);
  mylist.push_front (300);

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
  return 0;
}