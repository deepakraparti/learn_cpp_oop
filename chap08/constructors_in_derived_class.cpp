#include <iostream>

class alpha
{
    int x;
  public:
    alpha(int i)
    {
      x = i;
      std::cout << "alpha initialized\n";
    }

    void show_x(void) { std::cout << "x = " << x << "\n"; }
};

class beta
{
    float y;
  public:
    beta(float j)
    {
      y = j;
      std::cout << "beta initialized\n";
    }

    void show_y(void) { std::cout << "y = " << y << "\n"; }
};

class gamma : public beta, public alpha
{
    int m, n;
  public:
    gamma(int a, float b, int c, int d):
      beta(b), alpha(a)
    {
      m = c;
      n = d;
      std::cout << "gamma initialized\n";
    }

    void show_mn(void)
    {
      std::cout << "m = " << m << "\n"; 
      std::cout << "n = " << n << "\n";
    }
};

int main()
{
  gamma g(5, 10.75, 20, 30);
  std::cout << "\n";
  g.show_x();
  g.show_y();
  g.show_mn();
  return 0;
}
