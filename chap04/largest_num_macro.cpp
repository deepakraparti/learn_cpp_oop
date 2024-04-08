#include <iostream>

using namespace std;
#define LARGEST(a,b,c)  ((a>b)?((a>c)?a:c):((b>c)?b:c))


int main()
{
  cout << LARGEST(10,20,30);
}
