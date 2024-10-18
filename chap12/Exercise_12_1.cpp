#include <iostream>

using namespace std;

template <class T>
T min_from_array(T *a, int size)
{
  T min = a[0];

  for (int i = 1; i < size; i++) 
  {
    if (a[i] < min)
      min = a[i];
  }

  return min;
}

int main()
{
  int arr[5] = {5, 2, 10, 1, 4}; 
  cout << "Minimum number is: " << min_from_array(arr, 5) << endl;
}
