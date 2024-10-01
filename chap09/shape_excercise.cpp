#include <iostream>

using namespace std;

class Shape
{
  public:
    double x, y;

    void get_data(double a, double b)
    {
      x = a;
      y = b;
    }
  
    virtual void display_area() {};
};

class Triangle: public Shape
{
  public:
    void display_area()
    {
      double area;
      area = 0.5 * x * y;
      cout << "Area of traingle is: " << area << endl;
    }
};

class Rectangle: public Shape
{
  public:
    void display_area()
    {
      double area;
      area = x * y;
      cout << "Area of rectangle is: " << area << endl;
    }
};

int main()
{
  double x, y;
  Shape *s;
  
  cout << "Enter the base and height of the traingle: ";
  cin >> x >> y;

  Triangle t;
  s = &t;
  s->get_data(x, y);
  s->display_area();

  
  cout << "Enter the sides x and y of the rectangle: ";
  cin >> x >> y;

  Rectangle r;
  s = &r;
  s->get_data(x, y);
  s->display_area();
}
