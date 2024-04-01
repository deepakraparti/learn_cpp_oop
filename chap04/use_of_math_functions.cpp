#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
  cout << fixed << setprecision(2);
  cout << "sin (100) = " << sin(100) << endl;
  cout << "cos (100) = " << cos(100.00) << endl;
  cout << "tan (100) = " << tan(100.00) << endl;
  cout << "7 to the power of 6 = " << pow(7, 6) << endl;
  cout << "log10(10) = " << log10(10.00) << endl;
  cout << "sqrt (2) = " << sqrt(2.0) << endl;

  return 0;
}
