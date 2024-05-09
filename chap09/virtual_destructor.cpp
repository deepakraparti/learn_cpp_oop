#include <iostream>

class A
{
  public:
    virtual ~A()
    {
      std::cout << "Base class destructor\n";
    }
};

class B : public A
{
  public:
    ~B()
    {
      std::cout << "Derived class destructor\n";
    }
};

int main()
{
  A *ptr = new B();

  delete ptr;
  return 0;
}
