#include <iostream>

using namespace std;

int c = 20;
void test(int a)
{
  static int b = 100; // local variable 
  class student  // local class
  {
    int age;
    //static int marks;  // illegal, cannot use static data members 
    public:
      void setvalue(int a) {age = a;}
      void display() { cout << "Age = " << age << "\n"; }
      //friend void test(int a);
  };

  // void student::display() { cout << "Age = " << age << "\n"; }  // Illegal, it should be defined inside class itself
  student s1;  // create object 
  //s1.setvalue(a);
  s1.setvalue(b);
  //s1.setvalue(::c);
  s1.display();

  //cout << s1.age; //illegal as its private, but can access if enclosing function is declared as friend function
}

int main()
{
  test(30);
  return 0;
}
