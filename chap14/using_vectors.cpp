#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> &v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }

  cout << "\n";
}

int main()
{
  vector<int> v;
  cout << "Initial size = " << v.size() << " capacity = " << v.capacity() << endl;

  int x;
  cout << "Enter five integer values: ";
  for (int i = 0; i < 5; i++)
  {
    cin >> x;
    v.push_back(x);
  }

  cout << "Size after adding 5 values= " << v.size() << " capacity = " << v.capacity() << endl;

  cout << "Display the contents: " << endl;
  display(v);

  // Add one more value
  v.push_back(6.6);  // float value trucated to int

  cout << "Size = " << v.size() << " capacity = " << v.capacity() << endl;
  cout << "Contents now: " << endl;
  display(v);

  // Inserting elements
  vector<int>::iterator itr = v.begin(); //iterator
  itr = itr + 3;
  v.insert(itr, 1, 9);

  cout << "Contents after inserting: " << endl;
  display(v);

  // Removing 4th and 5th elements
  v.erase(v.begin() + 3, v.begin() + 5);

  cout << "Contents after deletion: " << endl;
  display(v);
  cout << "Size = " << v.size() << " capacity = " << v.capacity() << endl;

  // Reverse the vector 
  reverse(v.begin(), v.end());

  cout << "Contents of the reversed vector: " << endl;
  display(v);

  // Sort the vector
  sort(v.begin(), v.end());

  cout << "Contents of the sorted vector: " << endl;
  display(v);

  cout << "END\n";
  return 0;
}
