#include <iostream>

using namespace std;

int& max(int&, int &);

int main()
{
  int a = 10, b = 20;
  max(a, b) = -1;

  cout << "a= " << a << endl;
  cout << "b= " << b << endl;

}

int& max(int &a, int &b)
{
  if (a > b)
    return a;
  else
    return b;
}
