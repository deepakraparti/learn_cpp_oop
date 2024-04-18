#include <iostream>
#include <cmath>

class Polar
{
    float radius;
    float angle;
  public:
    Polar() { radius = 0.0; angle = 0.0; }
    Polar(float r, float a) { radius = r; angle = a; }

    Polar operator+(Polar &p)
    {
      std::cout << "Overloading\n";
      // Converting to rectangular coordinates
      float x1 = radius * cos(angle);
      float y1 = radius * sin(angle);

      float x2 = p.radius * cos(p.angle);
      float y2 = radius * sin(p.angle);

      float x = x1 + x2;
      float y = y1 + y2;
      std::cout << "Rectangle conversion: x = " << x << " y = " << y << "\n";

      return Polar(sqrt(x*x + y*y), atan(y/x));
    }

    void display()
    {
      std::cout << "Point (" << radius << "," << angle << ")\n";
    }

    void setradius(float x, float y)
    {
      radius = sqrt(x*x + y*y);
    }

    void setangle(float x, float y)
    {
      angle = atan(y/x);
    }

    float getradius() { return radius; }
    float getangle() { return angle; }
};

class Rectangle
{
    float x;
    float y;
  public:
    Rectangle() { x = 0.0; y = 0.0; }
    Rectangle(float a, float b) { x = a; y = b; }

    operator Polar()
    {
      Polar temp;
      temp.setradius(x, y);
      temp.setangle(x, y);
      return temp;
    }

    Rectangle(Polar &p)
    {
      x = p.getradius() * cos(p.getangle());
      y = p.getradius() * sin(p.getangle());
    }

    void display()
    {  
      std::cout << "Rectangle x = " << x << " y = " << y << "\n";
    }
};

int main()
{
  Polar P1(10, 180);
  Polar P2(15, 270);
  Polar P3;

  P1.display();
  P2.display();

  P3 = P1 + P2;
  P3.display();

  Rectangle R1;
  R1 = P3;
  R1.display();

  return 0;
}
