#include <iostream>
#include <cstring>

class person
{
  protected:
    char name[30];
    int code;
  public:
    void set_person_details(char *n, int c)
    {
      strcpy(name, n);
      code = c;
    }
};

class account : virtual public person
{
  protected:
    float pay;
  public:
    void set_pay(float p) { pay = p; }
};

class admin : virtual public person
{
  protected:
    float exp;
  public: 
    void set_exp(float e) { exp = e; }
};

class master : public account, public admin
{
  public:
    void show()
    {
      std::cout << "Name: " << name << "\n";
      std::cout << "Code: " << code << "\n";
      std::cout << "Pay: " << pay << "\n";
      std::cout << "Experience (in yrs.): " << exp << "\n";
    } 
};

int main()
{
  master m;
  m.set_person_details("Deepak", 123);
  m.set_pay(10000.00);
  m.set_exp(5.5);
  m.show();

  m.set_pay(15000.00);
  m.show();

  return 0;
}
