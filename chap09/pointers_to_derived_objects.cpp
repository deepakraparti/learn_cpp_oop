#include <iostream>

class BC
{
  public:
    int b;
    void show() { std::cout << "b = " << b << "\n"; }
};

class DC : public BC
{
  public:
    int d;
    void show() 
    { 
      std::cout << "b = " << b << "\n"; 
      std::cout << "d = " << d << "\n"; 
    }
};

int main()
{
  BC *bptr;
  BC base;
  bptr = &base;

  bptr->b = 100;
  std::cout << "bptr points to base object\n";
  bptr->show();

  DC derived;
  bptr = &derived;
  bptr->b = 200;
  //bptr->d = 300;  // It throws error
  std::cout << "bptr now points to derived object\n";
  bptr->show();


  DC *dptr;
  dptr = &derived;
  dptr->d = 300;
  
  std::cout << "dptr is derived type pointer\n";
  dptr->show();

  std::cout << "using ((DC *)bptr)\n";
  ((DC *)bptr)->d = 400;
  ((DC *)bptr)->show();
  return 0;
}
