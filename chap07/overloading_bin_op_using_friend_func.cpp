#include <iostream>

class complex
{
    float x;
    float y;
  public:
    complex() {}

    complex(float real, float imag)
    { x = real; y = imag; }

    friend complex operator+(complex, complex);
    void display(void);
};

complex operator+(complex a, complex b)
{
  return complex((a.x + b.x), (a.y + b.y));  // invokes constructor 2
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

  c3 = c1 + c2; // is equivalent to c3 = operator+(c1, c2);

  std::cout << "c1 = "; c1.display();
  std::cout << "c2 = "; c2.display();
  std::cout << "c3 = "; c3.display();

  return 0;
}

