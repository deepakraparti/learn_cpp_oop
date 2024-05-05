#include <iostream>

int main()
{
  int a=10,  *ptr;
  ptr = &a;

  std::cout << "The value a is : "<< a << "\n\n";

  *ptr = (*ptr)/2;

  std::cout << "The value a is : "<< *ptr << "\n\n";
  return 0;
}
