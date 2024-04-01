#include <iostream>

using namespace std;

int volume(int);
double volume(double, int);
long volume(long, int, int);

int main()
{
  cout << "Volume of cube: " << volume(10) << endl;
  cout << "Volume of cylinder: " << volume(2.5,8) << endl;
  cout << "Volume of rectangle: " << volume(100L, 75, 15) << endl;

  return 0;
}

int volume(int a)
{
  return a*a*a;
}

double volume(double r, int h)
{
  return 3.14159*r*r*h;
}

long volume(long l, int b, int h)
{
  return l*b*h;
}
