#include <iostream>
#include <iomanip>
#include <limits>

#define MAX_SIZE 2

using namespace std;

class item
{
  public:
    char name[30] = {0};
    int code;
    float cost;

    void display()
    {
      cout.fill('-');
      cout.precision(2);
      cout.setf(ios::fixed, ios::floatfield);
      cout.setf(ios::showpoint);
      cout.setf(ios::left, ios::adjustfield);
      cout << setw(30) << name 
           << setw(15) << code;
      cout.setf(ios::right, ios::adjustfield);
      cout << setw(20) << cost << endl;
    }

};

int main(void)
{
  item list[MAX_SIZE];

  for (int i = 0; i < MAX_SIZE; i++)
  {
    cout << "Enter item name: ";
    cin.getline(list[i].name, 30);

    cout << "Enter item code: ";
    cin >> list[i].code;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter item cost: ";
    cin >> list[i].cost;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  cout.setf(ios::left, ios::adjustfield);
  cout << setw(30) << "NAME" << setw(30) << "CODE" << setw(30) << "COST" << endl;
  
  for (int i = 0; i < MAX_SIZE; i++)
  {
    list[i].display();
  }

  return 0;
}
