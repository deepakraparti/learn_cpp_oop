#include <iostream>

using namespace std;

class item
{
    int number;  // by default its private
    float cost;  // by default its private
  public:
    void getdata(int a, float b); // member function declaration

    // Function defined inside class
    void putdata(void)
    {
      cout << "number: " << number << "\n";
      cout << "cost: " << cost << "\n";
    }
};

// Member function definition
void item::getdata(int a, float b)
{
  number = a;
  cost = b;
}

int main()
{
  item x;  // object creation
  cout << "\nObject x" << "\n";
  
  x.getdata(200, 199.99);
  x.putdata();

  item y;

  cout << "\nObject y" << "\n";

  y.getdata(100, 17.45);
  y.putdata();

  return 0;
}
