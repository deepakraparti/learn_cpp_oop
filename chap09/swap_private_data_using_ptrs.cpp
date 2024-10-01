#include <iostream>

using namespace std;

class A
{
    int a;

  public:
    A (int x) { a = x; }

    void swap(A& obj)
    {
      A temp = *this;
      *this = obj;
      obj = temp;
    }

   void print()
   {
     cout << "Data: " << a << endl;
   }
};

int main()
{
  A a1(10), a2(20);

  cout << "Before swap:" << endl;
  a1.print();
  a2.print();

  cout << "After swap:" << endl;
  a1.swap(a2);
  a1.print();
  a2.print();
  
}
