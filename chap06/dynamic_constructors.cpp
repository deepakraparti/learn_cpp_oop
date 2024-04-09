#include <iostream>
#include <cstring>

using namespace std;

class String
{
    char *name;
    int length;
  public:
    String()
    {
      length = 0;
      name = new char[length+1];    // dynamic memory allocation
    }

    String(char *a)
    {
      length = strlen(a);
      name = new char[length + 1];  // dynamic memory allocation
      strcpy(name, a);
    }

    void display() { cout << name << "\n";}

    void join (String &a, String &b);
};

void String :: join(String &a, String &b)
{
  length = a.length + b.length;
  delete name;
  name = new char[length + 1];  // dynamic memory allocation

  strcpy(name, a.name);
  strcat(name, b.name);
}

int main()
{
  char *first = "Joseph ";  // This will throw a warning for converting C++ string to char*, alternate declaration as below:
                            // char first[] = {'J','o','s','e','p','h',' '};
  String name1(first), name2("Louis "), name3("Lagrange");
  String s1, s2;

  s1.join(name1, name2);
  s2.join(s1, name3);
  name1.display();
  name2.display();
  name3.display();
  s1.display();
  s2.display();
  
  return 0;
}
