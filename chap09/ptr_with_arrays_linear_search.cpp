#include <iostream>

int main()
{
  int arr[10] = {1, 99, 4, 37, 88, 3, 19, 45, 62, 87};
  int num, *ptr;

  // Assigning the base address of array arr to ptr
  ptr = arr;

  std::cout << "Enter the element to be searched:";
  std::cin >> num;

  for (int i = 0; i < 10; i++)
  {
    if (*ptr == num)
    {
      std::cout << num << " is present in the array\n";
      break;
    }
    else if (i == 9)
      std::cout << num << " is not present in the array\n";

    ptr++; //incrementing the ptr so that it poitns to next element in the arry
  }

  return 0;
}
