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

class D : private B
{
    int c;
  public:
    void mul();
    void display();
};

void B :: set_ab() { a = 5; b = 10; }

int B :: get_a() { return a; }

void B :: show_a() { std :: cout << "a = " << a << "\n"; }

void D :: mul() { set_ab(); c = b * get_a(); }

void D :: display()
{
  show_a();
  std::cout << "b = " << b << "\n";
  std::cout << "c = " << c << "\n";
}

int main()
{
  D d;
  //d.set_ab();  // Will not work
  d.mul();
  //d.show_a();  // will not work
  d.display();


  // data member is inaccessible now, below block will not work
  //d.b = 20;
  //d.mul();
  //d.display();

  return 0;
}
