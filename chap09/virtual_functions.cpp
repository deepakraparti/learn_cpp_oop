#include <iostream>

class Base
{
    public:
      void display() { std::cout << "Display base\n"; }
      virtual void show() { std::cout << "Show base\n"; }
};

class Derived : public Base
{
  public:
    void display() { std::cout << "Display derived\n"; }
    void show() { std::cout << "Show derived\n"; }
};

int main()
{
  Base B;
  Derived D;
  Base *bptr;

  std::cout << "bptr points to Base\n";
  bptr = &B;
  bptr -> display();
  bptr -> show();

  std::cout << "bptr now points to Derived\n";
  bptr = &D;
  bptr -> display();
  bptr -> show();
  return 0;
}
