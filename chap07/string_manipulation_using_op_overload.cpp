#include <iostream>
#include <string.h>

class string
{
    char *p;
    int len;
  public:
    string() { len = 0; p = 0; }     // creates null string
    string(const char *s);           // creates string from array
    string(const string &s);         // copy constrcutor
    ~string() { delete p;} 

    friend string operator+(const string &a, const string &b);
    void operator=(const string &a);
    friend int operator<=(const string &a, const string &b);
    friend void show(const string s);
};

string :: string(const char *s)
{
  len = strlen(s);
  p = new char[len+1];
  strcpy(p, s);
}

string :: string(const string &s)
{
  len = s.len;
  p = new char[len+1];
  strcpy(p, s.p);
}

string operator+(const string &a, const string &b)
{
  string temp;
  temp.len = a.len + b.len;
  delete[] temp.p;
  temp.p = new char[temp.len+1];
  strcpy(temp.p, a.p);
  strcat(temp.p, b.p);

  return temp;
}

void string :: operator=(const string &a)
{
  len = a.len;
  delete[] p;
  p = new char[len+1];
  strcpy(p, a.p);
}

int operator<=(const string &a, const string &b)
{
  int m = strlen(a.p);
  int n = strlen(b.p);

  if (m <= n)
    return (1);
  else
    return (0);
}

void show(const string s)
{
  std::cout << s.p;
}

int main()
{
  string s1 = "New ";
  string s2 = "York";
  string s3 = "Delhi";
  string string1, string2, string3;
  string1 = s1;
  string2 = s2;
  string3 = s1+s3;


  std::cout << "string1 = "; show(string1);
  std::cout << "\nstring2 = "; show(string2);
  std::cout << "\nstring3 = "; show(string3);
  std::cout << "\n\n";

  if (string1 <= string3)
  {
    show(string1);
    std::cout << " smaller than ";
    show(string3);
    std::cout << "\n";
  }
  else
  {
    show(string3);
    std::cout << " smaller than ";
    show(string1);
    std::cout << "\n";
  }

  return 0;
}
