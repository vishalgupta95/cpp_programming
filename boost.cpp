#include<iostream>
#include <boost/multiprecision/cpp_int.hpp>
//
//Boost libraries are intended to be widely useful, and usable across a broad spectrum of applications. 
//For example, they are helpful for handling 
//large numbers having range beyond the long long, long double data type (264) in C++.
//Boost is a set of libraries for the C++ programming language that provides support for
// tasks and structures such as linear algebra, pseudorandom number generation, multithreading, 
//image processing, regular expressions, and unit testing. It contains 164 individual libraries
//
using namespace boost::multiprecision;
using namespace std;

int128_t boost_product(long long A, long long B)
{
	int128_t ans = (int128_t) A * B;
	return ans;
}

int main()
{
	long long first = 98745636214564698;
	long long second=7459874565236544789;
	cout << "Product of "<< first << " * "
		<< second << " = \n"
		<< boost_product(first,second) ;
	return 0;
}
