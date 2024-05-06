#include <iostream>


void Add(int i, int j)
{
  std::cout << i << " + " << j << " = " << i + j << "\n";
}

void Subtract(int i, int j)
{
  std::cout << i << " - " << j << " = " << i - j << "\n";
}

int main()
{
  void (*FuncPtr)(int, int) = &Add;
  FuncPtr(1,2);

  FuncPtr = &Subtract;
  FuncPtr(3,2);
  return 0;
}
