#include <iostream>
using namespace std;

class Cpolygon
{
	protected:
		int width, height;
	public:
		void input_values (int one, int two)
		{
			width=one;
			height=two;
		}
};

class Crectangle: public Cpolygon
{
	public:
		int area ()
		{
			return (width * height);
		}
};

class Ctriangle: public Cpolygon
{
	public:
		int area ()
		{
			return (width * height / 2);
		}
};

int main ()
{
	Crectangle rectangle;
	Ctriangle triangle;
	rectangle.input_values (2,2);
	triangle.input_values (2,2);
	cout << rectangle.area() << endl;
	cout << triangle.area() << endl;
	return 0;
}