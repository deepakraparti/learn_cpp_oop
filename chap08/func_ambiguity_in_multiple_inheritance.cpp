#include <iostream>

class M
{
  public:
    void display() { std::cout << "Class M\n"; }
};

class N
{
  public:
    void display() { std::cout << "Class N\n"; } // Both classes has the functionw with same name
};

class P : public M, public N
{
  public: 		// As class P inherits both M & N, there will be ambiguity
    void display() { M::display(); } // Ambiguity is resolved by defining the named instance using class resolution operator
};

int main()
{
  P p;
  p.display();
}
