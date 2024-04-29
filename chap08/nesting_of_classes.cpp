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

class gamma 
{
    alpha a;		// Nesting or containership
    beta b;
    int c;  
  public:
    gamma(int j, int k, float l): a(j), b(j+l)
    {
      c = k;
      std::cout << "gamma initialized\n";
    }

    void show_ab(void)
    {
      a.show_x();
      b.show_y();
      std::cout << "c = " << c << "\n";
    }
};

int main()
{
  gamma g(5, 10, 5.5);
  std::cout << "\n";
  g.show_ab();
  return 0;
}
