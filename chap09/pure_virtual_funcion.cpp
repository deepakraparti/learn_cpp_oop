#include <iostream>

class Balagurusamy		// Base class
{
  public:
    virtual void example() = 0; // pure virtual function
};

class C : public Balagurusamy
{
  public:
    void example()
    {
      std::cout << "C text book written by Balagurusamy\n";
    }
};

class oops : public Balagurusamy
{
  public:
    void example()
    {
      std::cout << "C++ text book written by Balagurusamy\n";
    }
};

int main()
{
  Balagurusamy *array[2];
  //Balagurusamy B;  // Throws error as its a abstract base class

  C e1;
  oops e2;

  array[0] = &e1;
  array[1] = &e2;

  array[0]->example();
  array[1]->example();
  return 0;
}
