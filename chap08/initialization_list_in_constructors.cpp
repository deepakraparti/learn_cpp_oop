#include <iostream>

class alpha
{
    int x;
  public:
    alpha(int i)
    {
      x = i;
      std::cout << "alpha constructed\n";
    }

    void show_alpha(void) { std::cout << "x = " << x << "\n"; }
};

class beta
{
    float p, q;
  public:
    beta(float a, float b) : p(a), q(b+p)
    {
      std::cout << "beta constructed\n";
    }

    void show_beta(void) 
    { 
      std::cout << "p = " << p << "\n"; 
      std::cout << "q = " << q << "\n"; 
    }
};

class gamma : public beta, public alpha
{
    int u, v;
  public:
    gamma(int a, int b, float c):
      alpha(a*2), beta(c,c), u(a)
    {
      v = b;
      std::cout << "gamma constructed\n";
    }

    void show_gamma(void)
    {
      std::cout << "u = " << u << "\n"; 
      std::cout << "v = " << v << "\n";
    }
};

int main()
{
  gamma g(2, 4, 2.5);
  std::cout << "\n\n Diplay member values\n\n";
  g.show_alpha();
  g.show_beta();
  g.show_gamma();
  return 0;
}
