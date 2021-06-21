/*
Lambdas to the rescue
C-11
A lambda expression (also called a lambda or closure) allows us to define an anonymous function inside another function. The nesting is important, as it allows us both to avoid namespace naming pollution, and to define the function as close to where it is used as possible (providing additional context).

The syntax for lambdas is one of the weirder things in C++, and takes a bit of getting used to. Lambdas take the form:

[ captureClause ] ( parameters ) -> returnType
{
    statements;
}
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
 
int main()
{
  constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
 
  // Define the function right where we use it.
  const auto found{ std::find_if(arr.begin(), arr.end(),
                           [](std::string_view str) // here's our lambda, no capture clause
                           {
                             return (str.find("nut") != std::string_view::npos);
                           }) };
 
  if (found == arr.end())
  {
    std::cout << "No nuts\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }
 
  return 0;
}
