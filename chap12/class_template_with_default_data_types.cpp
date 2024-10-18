#include <iostream>

using namespace std;

template <class T1=int, class T2=int>
class Test
{
    T1 a;
    T2 b;

  public:
    Test(T1 x, T2 y)
    {
      a = x;
      b = y;
    }

    void show()
    {
      cout << a << " and " << b << "\n";
    }
};

int main()
{
  cout << "Instantiating the class template as test1 with float and int data types..\ntest1: ";

  Test <float, int> test1(1.23, 123);
  test1.show();

  cout << "Instantiating the class template as test2 with int and char data types..\ntest2: ";
  Test <int, char> test2(100, 'W');
  test2.show();

  cout << "Instantiating the class template with default data types..\ntest3: ";
  Test <> test3(92, 12);
  test3.show();

  return 0;
}
