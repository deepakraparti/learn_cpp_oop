#include <iostream>

using namespace std;

template <class T>
void bubblesort(T a[], int n)
{
  for (int i = 0; i < n-1; i++)
  {
    for (int j = n-1; i < j; j--)
    if (a[j] < a[j-1])
    {
      swap(a[j], a[j-1]);
    }
  }
}

template <class T>
void swap(T &x, T &y)
{
  T temp = x;
  x = y;
  y = temp;
}

int main()
{
  int x[5] = {10, 50, 30, 40, 20};
  float y[5] = {1.1, 5.5, 3.3, 4.4, 2.2};

  bubblesort(x, 5);
  bubblesort(y, 5);

  cout << "Sorted x-array: ";
  for (int i = 0; i < 5; i++)
    cout << x[i] << " ";
  cout << endl;

  cout << "Sorted y-array: ";
  for (int i = 0; i < 5; i++)
    cout << y[i] << " ";
  cout << endl;

  return 0;
}
