#include <iostream>

class A
{
  public:
    void display() { std::cout << "Class A\n"; }
};

class B: public A
{
  public:
    void display() { std::cout << "Class B\n"; }   // this function will override the display func in class A
};

int main()
{
  B b;
  b.display();
  b.A::display();  // this way we can explitely call the func in class A
  b.B::display();

  return 0;
}
