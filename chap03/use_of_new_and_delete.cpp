#include <iostream>

using namespace std;

int main()
{
  int *arr;
  int size;

  cout << "Enter the size of the array: ";
  cin >> size;

  cout << "Creating an array of size " << size << "...\n";
  arr = new int[size];

  cout << "Dynamically allocated memory for the array\n";

  delete arr;
  cout << "Deleted the dynamocally allocated memory for the array\n";
  
  return 0;
}
