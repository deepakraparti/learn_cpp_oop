#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
  auto x = 42; // x will be deduced as int

  auto pi = 3.1415926535;

  cout << "Type of x: " << typeid(x).name() << " | Value of x: " << x << endl;
  cout << "Type of pi: " << typeid(pi).name() << " | Value of pi: " << pi << endl;
  
  return 0;
}
