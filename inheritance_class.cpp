#include <iostream>
using namespace std;

class Polygon {
    protected:
        int width, height;
    public:
        void setValues(int a, int b) {
            width = a;
            height = b;
        }
};
class Output {
    public:
        void output(int i) {
            cout << i << endl;
        }
};
class Rectangle: public Polygon, public Output {
    public: int area() {
        return (width * height);
    }
};
class Triangle: public Polygon, public Output {
    public: int area() {
        return (width * height / 2);
    }
};
int main() { //RectangleEG14.cpp
    Rectangle rect;
    Triangle trgl;
    rect.setValues(4, 5);
    trgl.setValues(4, 5);
    rect.output(rect.area());
    trgl.output(trgl.area());
    return 0;
}
