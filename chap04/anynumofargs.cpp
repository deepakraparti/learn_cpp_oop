#include <iostream>

using namespace std;

void something(...);

int main()
{
  something(); 
}

void something(...)
{
  cout << "demontrating any number of arguments in c++ wiht ellipses" << endl;
}
