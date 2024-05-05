#include <iostream>

int main()
{
  int a, *ptr1=0, **ptr2;
  ptr1 = &a;
  ptr2 = &ptr1;

  std::cout << "The address of a: " << ptr1 << "\n";
  std::cout << "The address of ptr1: " << ptr2 << "\n\n";
  std::cout << "After incrementing the address values: " << "\n\n";
  ptr1+=2;
  std::cout << "The address of a: " << ptr1 << "\n";
  ptr2+=2;
  std::cout << "The address of ptr1: " << ptr2 << "\n";
  return 0;
}
