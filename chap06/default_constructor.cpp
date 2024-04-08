#include <iostream>

using namespace std;

class integer
{
    int m, n;
  public:
    integer()  // inline constructor definiton
    {
      m = 0;
      n = 0;
    }

    void display()
    { 
      cout << "m = " << m << " n = " << n << endl;
    }
};

int main(void)
{
  integer int1;

  int1.display();
  return 0;
}
