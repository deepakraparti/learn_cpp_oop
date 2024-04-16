#include <iostream>

class Space
{
    int x, y, z;
  public:
    void getdata(int a, int b, int c);
    void display();
    //void operator-();  //unary minus (-) overload member function
    friend void operator -(Space& t); // operator overload using friend function
};

void Space :: getdata(int a, int b, int c)
{
  x = a;
  y = b;
  z = c;
}

void Space :: display()
{
  std::cout << "x = " << x << " ";
  std::cout << "y = " << y << " ";
  std::cout << "z = " << z << "\n";
}

#if 0
void Space :: operator -()
{
  x = -x;
  y = -y;
  z = -z;
}
#endif

void operator -(Space& s)
{

  s.x = -s.x;
  s.y = -s.y;
  s.z = -s.z;
}

int main()
{
  Space s;
  s.getdata(10, -20, 5);
  std::cout << "S: ";
  s.display();

  -s;                   //operator overloading
  std::cout << "S: ";
  s.display();

  operator-(s);         //operator overloading
  std::cout << "S: ";
  s.display();
   
  return 0;
}
