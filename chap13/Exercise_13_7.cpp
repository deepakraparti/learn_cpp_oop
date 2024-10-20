#include <iostream>

using namespace std;

void test3()
{
  int x = 3;
  cout << "In test3\n";
  throw x;
}
void test2()
{
  cout << "In test2\n";
  test3();
}
void test1()
{
  cout << "In test1\n";
  test2();
}

int main()
{
  cout << "in Main\n";

  try
  {
    test1();
  }
  catch(int x)
  {
    cout << "Caught an integer exception thrown by deeply nested function\n";
  }

  return 0;
}
