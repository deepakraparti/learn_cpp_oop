#include <iostream>

class Time
{
    int hrs;
    int mins;
  public:
    Time() {}
    Time(int min) 
    {
      hrs = min/60;
      mins = min%60;
    }

    void display()
    {
      std::cout << hrs << "H:" << mins << "M\n";
    }
};

int main()
{ 
  Time t(85);
  t.display();
  
  return 0;
}
