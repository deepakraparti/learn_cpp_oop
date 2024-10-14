#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  double e = 1.0;
  double term = 1.0;
  int n = 1;

  while(term > 0.0001)
  {
    term = 1.0/tgamma(n+1);
    e += term;
    n++;
  }

  cout << fixed << setprecision(4) << e << endl;
}
