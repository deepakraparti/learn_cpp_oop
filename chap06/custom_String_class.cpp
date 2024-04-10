#include <iostream>
#include <cstring>

using namespace std;

class String
{
    char *str;
    int length;

  public:
    String()
    {
      length = 0;
      str = new char[length+1];  // +1 to accomodate the null character in c++ string
    }

    String(char *s)
    {
      length = strlen(s);
      str = new char[length+1];
      strcpy(str, s);
    }

    void join (String s1, String s2)
    {
      length = s1.length + s2.length;
      delete str; // free-ing already allocated memory
      str = new char[length+1];

      str = s1.str;  // copying s1.str to current object using assignment operator
      strcat(str, s2.str);
    }

    void display()
    {
      cout << str << endl;
    }
};

int main()
{
  String s1("Hello ");
  String s2("World!");

  s1.display();
  s2.display();

  String s3;
  s3.join(s1,s2);
  s3.display();

  return 0;
}
