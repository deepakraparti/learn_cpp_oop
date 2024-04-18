#include <iostream>

class test
{
  public:
    int num;
    test (int j) { num = j; }

    test* operator ->(void)
    {
      return this;
    }
};

int main()
{
  test T(5);
  test *ptr = &T;

  std::cout << "T.num = " << T.num;         // general way
  std::cout << "\nptr->num = " << ptr->num; // using object pointer
  std::cout << "\nT->num = " << T->num;  // operator overloading
  std::cout << "\n";
  return 0;
}
