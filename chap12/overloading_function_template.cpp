#include <iostream>

using namespace std;

template <class T>
void display(T x)
{
  cout << "Overloaded Template Display 1: " << x << endl;
}

template <class T1, class T2>
void display(T1 x, T2 y)
{
  cout << "Overloaded Template Display 2: " << x << ", " << y << endl;
}

void display(int x)
{
  cout << "Explicit display: " << x << endl;
}

int main()
{
  display(100);
  display(12.34);
  display(100, 12.34);
  display('C');

  return 0;
}
