#include <iostream>

using namespace std;

void divide(int x, int y, int z)
{
  cout << "\nWe are inside the function\n";

  if ((x-y) != 0)
  {
    int R = z/(x-y);
    cout << "Result = " << R << endl;
  }
  else
  {
    throw(x-y);  //Throw point
  }
}

int main()
{
  try
  {
    cout << "We are inside the try block\n";
    divide(10, 20, 30);
    divide(10, 10, 20);
  }
  catch (int)
  {
    cout << "Caught an exception\n";
  }

  return 0;
}
