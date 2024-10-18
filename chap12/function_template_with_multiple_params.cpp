#include <iostream>

using namespace std;

template<class T1, class T2>
void display(T1 x, T2 y)
{
  cout << x << " " << y << endl;
}

int main()
{
  cout << "Calling function template with int and char string parameters...\n";
  display(1999, "EBG");

  cout << "Calling function template with float and int type parameters...\n";
  display(12.34, 1234);
  
  return 0;
}
