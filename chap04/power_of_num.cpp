#include <iostream>

using namespace std;

double power(double m, int n = 2)
{
  cout << "(double power) ";
  double result = 1; 
  for (int i = 0; i < n ; i++)
    result *= m;

  return result;
}

double power(int m, int n = 2)
{
  cout << "(int power) ";
  double result = 1;
  for (int i = 0; i < n ; i++)
    result *= m;

  return result;
}


int main()
{
  int m;
  cout << "Enter the number: ";
  cin >> m;

  int n = 0;
  cout << "Enter the exponent: ";
  cin >> n;

  cout << "Power of "<< m << " is " << power(m,n) << endl;
  cout << "Power of "<< m << " is " << power(double(m),n) << endl;
  cout << "Square of "<< m << " is " << power(m) << endl;
 
  return 0; 
}
