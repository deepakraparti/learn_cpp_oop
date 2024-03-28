#include <iostream>
#include <iomanip>  // for setw


using namespace std;

int main(void)
{
  int Basic = 950, Allowance = 95, Total = 1045;

  cout << setw(10) << "Basic" << setw(10) << Basic << endl;
  cout << setw(10) << "Allowance" << setw(10) << Allowance << endl;
  cout << setw(10) << "Total" << setw(10) << Total << endl;
    
  return 0;
}
