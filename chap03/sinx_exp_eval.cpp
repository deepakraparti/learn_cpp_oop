#include <iostream>
#include <cmath>

using namespace std;

double factorial(int num)
{
  if (num == 0 || num == 1)
  {
    return 1;
  }
  else
  {
    return num * factorial(num - 1);
  }
}

double computeSin(int num, double accuracy)
{
  double calculatedSin = 0.0;
  double nextTerm = 0.0;
  int i = 1;
  int sign = 1;

  while(true)
  {
    nextTerm = pow(num, i)/factorial(i);

    if (nextTerm < accuracy)
      break;
    
    nextTerm = nextTerm * sign;
    calculatedSin += nextTerm;

    i += 2;
    sign *= -1;
  }

  return calculatedSin;
}

int main()
{
  int num;
  cout << "Enter the number for which sin needs to be calculatd: ";
  cin >> num;

  double accuracy = 0.0001;
  double result = 0.0;

  result = computeSin(num, accuracy);

  cout << "Actual Sin: " << sin(1) << endl;
  cout << "Calculated Sin: " << result << endl; 
}
