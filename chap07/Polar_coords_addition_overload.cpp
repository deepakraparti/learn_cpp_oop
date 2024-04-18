#include <iostream>
#include <cmath>

#define pi 3.1416
class Polar
{
    float radius;
    float angle;
  public:
    Polar() { radius = 0.0; angle = 0.0; }
    Polar(float r, float a) { radius = r; angle = a*(pi/180); }

    Polar operator+(Polar &p)
    {
      std::cout << "Overloading\n";
      // Converting to rectangular coordinates
      float x1 = radius * cos(angle);
      float y1 = radius * sin(angle);

      float x2 = p.radius * cos(p.angle);
      float y2 = p.radius * sin(p.angle);

      float x = x1 + x2;
      float y = y1 + y2;

      Polar temp;
      temp.radius = sqrt(x*x + y*y);
      temp.angle =  atan(y/x);
      return temp;
    }

    void display()
    {
      std::cout << "Point (" << radius << "," << angle*(180/pi) << ")\n";
    }
};

int main()
{
  Polar P1(10, 45);
  Polar P2(15, 45);
  Polar P3;

  P1.display();
  P2.display();

  P3 = P1 + P2;
  P3.display();

  return 0;
}
