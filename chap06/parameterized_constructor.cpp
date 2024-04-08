#include <iostream>

using namespace std;

class integer
{
    int m, n;

  public:
    integer(int , int);

    void display(void)
    {
      cout << "m = " << m << "\n";
      cout << "n = " << n << "\n";
    }
};

integer::integer(int x, int y)
{
  m = x;
  n = y;
}

int main (void)
{
  integer int1(0, 100); // implicit calling
  integer int2 = integer(25,75); // explicit calling

  cout << "\nOBJECT1" << "\n";
  int1.display();
  cout << "\nOBJECT2" << "\n";
  int2.display();

  return 0;
}
