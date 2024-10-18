#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
  char name[100], number[100];
  ifstream infile("TELE_NUMBERS");

  while(infile >> name >> number)
  {
    cout.setf(ios::left, ios::adjustfield);
    cout.width(20);
    cout << name;

    cout.setf(ios::right, ios::adjustfield);
    cout.width(10);
    cout << number << endl;
  }

  return 0;
}
