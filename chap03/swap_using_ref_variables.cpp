#include <iostream>

using namespace std;

void swap(int &, int &);

int main()
{
  int a = 10, b = 20;

  cout << "Before swap: a- " << a << " b- " << b << endl;

  swap(a, b); 

  cout << "After swap: a- " << a << " b- " << b << endl;

  return 0;
}

void swap(int &a, int &b)
{
  a = a ^ b;
  b = a ^ b;
  a = a ^ b; 
}
