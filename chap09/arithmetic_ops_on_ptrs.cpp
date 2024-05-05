#include <iostream>

int main()
{
  int num[] = {56, 75, 22, 18, 90};
  int *ptr;

  std::cout << "The array values are: \n";
  for (int i = 0; i<5; i++)
    std::cout << num[i] << "\n";

  // Allocating base address of num to ptr
  ptr = num;

  // Printing values using ptr
  std::cout <<"\nValue of ptr: " << *ptr;
  
  ptr++; 
  std::cout <<"\nValue of ptr++: " << *ptr;

  ptr--;
  std::cout <<"\nValue of ptr--: " << *ptr;

  ptr+=2;
  std::cout <<"\nValue of ptr+2: " << *ptr;

  ptr-=1;
  std::cout <<"\nValue of ptr-1: " << *ptr;

  ptr+=3;
  std::cout <<"\nValue of ptr+3: " << *ptr;

  ptr-=2;
  std::cout <<"\nValue of ptr-2: " << *ptr << "\n";

  return 0;
}
