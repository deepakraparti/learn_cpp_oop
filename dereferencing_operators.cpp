#include <iostream>

using namespace std;

class M
{
    int x;
    int y;
  public:
    void set_xy(int a, int b) { x=a; y=b; }
    friend int sum (M m);
};

int sum(M m)
{
  int M :: * px = &M :: x; // Pointer to member of class
  int M :: * py = &M :: y; // Pointer to member of class

  M *pm = &m;  // Pointer to object of class M

  int S = m.*px + pm->*py; //Dereferencing
  return S;
}

int main()
{
  M n;

  void (M :: *pf)(int, int) = &M :: set_xy;  // pointer to member function
  (n.*pf)(10,20);  // invoking function using pointer to member function
  cout << "Sum = " << sum(n) << "\n";

  M *op = &n;  // pointer to object of class
  (op->*pf)(30,40);
  cout << "Sum = " << sum (n) << "\n";

  return 0;
}
