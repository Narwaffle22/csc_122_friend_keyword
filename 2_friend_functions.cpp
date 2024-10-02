#include <iostream>

using namespace std;

class Rectangle {
private:
  int width;
  int height;

public:
  Rectangle(int w, int h) : width(w), height(h) {}
  int area() {
    return this->width * this->height;
  }
  int get_width() {
    return this->width;
  }
  int get_height() {
    return this->height;
  }
  friend Rectangle scale(Rectangle, int);
  friend Rectangle swap(Rectangle);
};

Rectangle scale(Rectangle rectangle, int factor) {
  int new_width = rectangle.width * factor;
  int new_height = rectangle.height * factor;
  return Rectangle(new_width, new_height);
}
Rectangle swap(Rectangle rectangle) {
    int temp = rectangle.width;
    int jemp = rectangle.height;
    return Rectangle(jemp, temp);
}

int main() {
  Rectangle r1(2, 3);
  cout << "Area of Rectangle 1: " << r1.area() << endl;

  Rectangle r2 = scale(r1, 2);
  cout << "Area of Rectangle 2: " << r2.area() << endl;
  
  cout << r2.get_width() << ", " << r2.get_height() << "\n";
  Rectangle r3 = swap(r2);
  cout << r3.get_width() << ", " << r3.get_height() << "\n";
  return 0;
}
