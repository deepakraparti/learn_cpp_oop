#include <iostream>

class complex
{
    float x;
    float y;
  public:
    complex() {}

    complex(float real, float imag)
    { x = real; y = imag; }

    complex operator+(complex);
    void display(void);
};

complex complex :: operator + (complex c)
{
#if 0
  // METHOD - 1
  complex temp;
  temp.x = x + c.x;
  temp.y = y + c.y;

  return temp;
#endif

  // METHOD - 2
  return complex((x+c.x), (y+c.y));  // invokes constructor 2
}

void complex :: display()
{
  std::cout << x << " + j" << y << "\n";
}

int main()
{
  complex c1, c2, c3;

  c1 = complex(2.5, 3.5);
  c2 = complex(1.6, 2.7);

  c3 = c1 + c2;

  std::cout << "c1 = "; c1.display();
  std::cout << "c2 = "; c2.display();
  std::cout << "c3 = "; c3.display();

  return 0;
}

