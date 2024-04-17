#include <iostream>

const int size = 3;

class vector
{
    int v[size];
  public:
    vector();        // constructs null vector
    vector(int *x);  // constructs vector from array
    friend vector operator *(int a, vector b);
    friend vector operator *(vector b, int a);
    friend std::istream & operator >> (std::istream &, vector &);
    friend std::ostream & operator << (std::ostream &, vector &);
};

vector :: vector()
{
  for (int i = 0; i < size; i++)
    v[i] = 0;
}

vector :: vector(int *x)
{
  for (int i = 0; i < size; i++)
    v[i] = x[i];
}

vector operator *(int a, vector b)
{
  vector c;

  for (int i = 0; i < size; i++)
    c.v[i] = a * b.v[i];

  return c;
}

vector operator *(vector b, int a)
{
  vector c;

  for (int i = 0; i < size; i++)
    c.v[i] = b.v[i] * a;

  return c;
}

std::istream & operator >> (std::istream &din, vector &b)
{
  for (int i = 0; i < size; i++)
    din >> b.v[i];

  return din;
}

std::ostream & operator << (std::ostream &dout, vector &b)
{
  dout << "(" << b.v[0];
  for (int i = 1; i < size; i++)
    dout << ", " << b.v[i];
 
  dout << ")"; 
  return dout;
}

int x[size] = {2, 4, 6};

int main()
{
  vector m;      // null vector constructor 1;
  vector n = x;  // intialize vector using array constructor 2;

  std::cout << "Enter elements of vector m:\n";
  std::cin >> m ; 	// this invokes operator>>() function
  std::cout << "\n";
  std::cout << "m = " << m << "\n"; // operator<<() function

  vector p, q;
  p = 2 * m;     //invokes friend function 1
  q = n * 2;     //invokes friend function 2

  std::cout << "\n";
  std::cout << "p = " << p << "\n";
  std::cout << "q = " << q << "\n";

  return 0;
}
