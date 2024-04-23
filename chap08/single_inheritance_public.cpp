#include <iostream>

class B
{
    int a; 			// private, so will not be inherited
  public:
    int b;			// public, will be inherited
    void set_ab();
    int get_a();
    void show_a();
};

class D : public B
{
    int c;
  public:
    void mul();
    void display();
};

void B :: set_ab() { a = 5; b = 10; }

int B :: get_a() { return a; }

void B :: show_a() { std :: cout << "a = " << a << "\n"; }

void D :: mul() { c = b * get_a(); }

void D :: display()
{
  std::cout << "a = " << get_a() << "\n";
  std::cout << "b = " << b << "\n";
  std::cout << "c = " << c << "\n";
}

int main()
{
  D d;
  d.set_ab();
  d.mul();
  d.show_a();
  d.display();

  d.b = 20;
  d.mul();
  d.display();

  return 0;
}
