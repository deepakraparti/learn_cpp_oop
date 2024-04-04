#include <iostream>

using namespace std;


class item
{
    int code;
    static int count;
  public:
    void setcode(void)
    {
      code = ++count;
    }

    void showcode(void)
    {
      cout << "Object number: " << code << "\n";
    }

    static void showcount(void) // Static member function
    {
      cout << "Count: " << count << "\n"; 
    }
};

int item::count;  // definition of static data member

int main()
{
  item i1, i2;
  i1.setcode();
  i2.setcode();

  item::showcount();  // accessing static function

  item i3;
  i3.setcode();

  i1.showcount();  // Static member function accessed using one of the object (but not recommended)

  i1.showcode();
  i2.showcode();
  i3.showcode();

  return 0;
}
