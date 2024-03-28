#include <iostream>

using namespace std;


ostream &sym(ostream &op)
{
  return op << "\tRs";
}

int main()
{
  cout << sym << endl;
  return 0;
}
