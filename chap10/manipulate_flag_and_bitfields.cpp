#include <iostream>

using namespace std;

int main()
{
  int num;
  cout << "Enter an integer value: ";
  cin >> num;

  cout << "The hexadecimal, octal and decimal representation of " << num << " is: ";
  cout.setf(ios::hex, ios::basefield);
  cout << num << ", ";

  cout.setf(ios::oct, ios::basefield);
  cout << num << " and ";

  cout.setf(ios::dec, ios::basefield);
  cout << num << " respectively\n";

  cout.fill('*');
  cout.precision(3);
  cout.setf(ios::internal, ios::adjustfield);
  cout.setf(ios::scientific, ios::floatfield);
  cout.width(15);
  cout << -12.34567 << "\n";

  return 0;
}
