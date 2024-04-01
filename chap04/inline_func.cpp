#include <iostream>

using namespace std;

inline float mul(float a, float b)
{
  return (a*b);
}

inline double div(double a, double b)
{
  return (a/b);
}

int main()
{
  float a = 12.345;
  float b = 9.82;

  cout << mul(a,b) << "\n";
  cout << div(a,b) << "\n";

  return 0;
}
