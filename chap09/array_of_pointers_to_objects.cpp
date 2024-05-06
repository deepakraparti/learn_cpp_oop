#include <iostream>
#include <cstring>

class city
{
  protected:
    char *name;
    int len;
  public:
    city() { len = 0; name = new char[len+1]; }

    void getname(void)
    {
      char *s;
      s = new char[30];
      std::cout << "Enter city name: ";
      std::cin >> s;
      len = strlen(s);
      strcpy(name, s);
    }

    void printname(void) { std::cout << name << "\n"; }
};

int main()
{
  city *cptr[10];

  int n = 1;
  int option;

  do
  {
    cptr[n] = new city;
    cptr[n]->getname();
    n++;
    std::cout << "Do you want to enter one more name?\n";
    std::cout << "(Enter 1 or yes, 0 for no): ";
    std::cin >> option;
  }while(option);

  std::cout << "\n\n";

  for(int i = 1; i <n; i++)
  {
    cptr[i]->printname();
  }

  return 0;
}
