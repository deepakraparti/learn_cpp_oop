#include <iostream>

using namespace std;

int main()
{
  float amount;
  float value(float p, int n, float r = 0.15);
  void printline(char ch='*', int len = 40);

  printline();

  amount = value (5000.00, 5); //default value for the third argument
  cout << "\n Final Value = " << amount << "\n\n";
 
  amount = value (1000.00, 1, 0.1); //default value for the third argument
  cout << "\n Final Value = " << amount << "\n\n";

  amount = value (1000.00, 5, 0.30); // passed all arguments
  cout << "\n Final Value = " << amount << "\n\n";
  
  printline('='); // use default value for the second argument

  return 0;
}

float value(float p, int n, float r)
{
  int year = 1;
  float sum = p;

  while (year <= n)
  {
    sum = sum * (1 + r);
    year += 1;
  }

  return sum;
}

void printline(char ch, int len)
{
  for(int i = 1; i <= len; i++)
    cout << ch;

  cout << "\n";
}

