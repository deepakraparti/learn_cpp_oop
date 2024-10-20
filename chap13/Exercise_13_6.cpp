#include <iostream>
#include <string>

using namespace std;

double readDouble()
{
  string input;
  double value;

  while(true)
  {
    try
    {
      getline(cin, input);

      // convert to double
      size_t idx;
      value = stod(input, &idx);

      if (idx != input.length())
      {
        throw invalid_argument("Invalid characters after number.\n");
      }
    }
    catch(const invalid_argument &)
    {
      cout << "Invalid input. Please enter a valid double value:";
    }
    catch(const out_of_range &)
    {
      cout << "Input is out of range for double. Try again:";
    }

    return value;
  }
}

void divide(double a, double b)
{
  try
  {
    if (b == 0)
    {
      throw runtime_error("Error: Division by zero is not allowed");
    }
    else
    {
      cout << "Divison is: " << a/b << endl;
    }
  }
  catch(const runtime_error &e)
  {
    cout << e.what() << endl;
  }
}

int main()
{
  double a, b;

  cout << "Enter first number: ";
  a = readDouble();

  cout << "Enter second number: ";
  b = readDouble();

  cout << "Values are a = " << a << " b = " << b << endl;

  divide(a, b);
  return 0;
}
