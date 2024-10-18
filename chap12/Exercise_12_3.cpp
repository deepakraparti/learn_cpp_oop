#include <iostream>

using namespace std;

template <class T>
int linearSearch(T *arr, T element, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == element)
    {
      return i;
    }
  }

  return -1;
}

int main()
{
  float arr[5] = {4.1, 2.9, 9.0, 12.3, 20.2};

  int result = linearSearch(arr, (float)20.2, 5);
  if (result != -1)
  {
    cout << "Element found at index: " << result << endl;
  }
  else
  {
    cout << "Element not found in the array" << endl;
  }
  return 0;
}
