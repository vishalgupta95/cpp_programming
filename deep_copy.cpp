#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class String
{
private:
    char *s;
    int size;
public:
    String(const char *str = NULL);
    String(const String &src);
    ~String();
    String& operator=(const String &rhs);
    void print() const;
};

String::String(const char *str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

String::String(const String &src)
{
    size = src.size;
    s = new char[size+1];
    strcpy(s, src.s);
}

String::~String()
{
    delete [] s;
} 

void String::print() const
{
    cout << s << endl;
}

String& String::operator=(const String &rhs)
{
    if (&rhs != this)
    {
        String tmp(rhs);
        swap(s, tmp.s);
        swap(size, tmp.size);
    }
    return *this;
}

int main()
{
    String str1("learnc++");
    String str2 = str1;

    str1.print();
    str2.print();

    //str2.change("learnjava");
    str2 = "learnjava";

    str1.print();
    str2.print();

    return 0;
}