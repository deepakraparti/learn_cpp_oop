#include <iostream>

using namespace std;

void TOH(int d, char tower1, char tower2, char tower3)
{
  if (d == 1)
  {
    cout << "Shift top disk from tower " << tower1 << " to tower " << tower2 <<endl;
    return ;
  }

  TOH(d-1, tower1, tower3, tower2);
  cout << "Shift top disk from tower " << tower1 << " to tower " << tower2 << endl;
  
  TOH(d-1, tower3, tower2, tower1);
}

int main()
{
  int disk;
  
  cout << "Enter number of disks to shift: ";
  cin >> disk;

  if (disk < 1)
    cout << "\nThere are no disks to shift";
  else
    cout << "\nThere are " << disk << " disks in tower 1\n";

  TOH(disk, '1', '2', '3');
  cout << "\n\n" << disk << " disks in tower 1 are shifted to tower 2\n";

  return 0;
}
