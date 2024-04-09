#include <iostream>

using namespace std;

class test
{
    int *a;
  public:
    test(int size)
    {
      a = new int[size];
      cout << "Constructor Msg: Integer array of size " << size << " created...\n";
    }
    ~test()
    {
      delete[] a;
      cout << "Destructor Msg: Freed up the memory allocated for integer array\n";
    }
};

int main()
{
  int s;
  cout << "Enter the size of the array: ";
  cin >> s;

  cout << "Creating an object of test class...\n";
  test T(s);

  return 0;
}
