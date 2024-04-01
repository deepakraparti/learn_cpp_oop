#include <iostream>

using namespace std;

class Temp{
  float tempInCelsius;
  float tempInFahrenheit;

  public:
    void getTempInFah()
    {
      cout << "Enter temperature in fahrenheit: ";
      cin >> tempInFahrenheit;
    }

    void displayTempInCelsius()
    {
      tempInCelsius = (tempInFahrenheit - 32) * (5.0/9);
      cout << "Temperature in celsius: " << tempInCelsius << endl;
    }
};

int main()
{
  Temp t;
  t.getTempInFah();
  t.displayTempInCelsius();
}
