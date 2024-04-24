#include <iostream>

class M
{
  protected:
    int m;
  public:
  void get_m(int);
};

void M :: get_m(int a) { m = a; }

class N
{
  protected:
    int n;
  public:
    void get_n(int);
};

void N :: get_n(int b) { n = b; }

class P: public M, public N
{
  public:
    void display(void);
};

void P :: display ()
{
  std::cout << "m = " << m << "\n";
  std::cout << "n = " << n << "\n";
  std::cout << "m*n = " << m*n << "\n";
}

int main()
{
  P p;
  p.get_m(10);
  p.get_n(20);
  p.display();

  return 0;
}
