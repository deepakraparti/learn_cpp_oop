#include <iostream>
#include <cstring>

using namespace std;

class Error
{
    int err_code;
    char *err_desc;
  public:
    Error(int c, char *d)
    {
      cout << "Constructor called\n";
      err_code = c;
      err_desc = new char[strlen(d)];
      strcpy(err_desc, d);
    }

    void err_display(void)
    {
      cout << "\nError Code: " << err_code << endl << "Error Description: " << err_desc;
    }
};

int main()
{
  try
  {
    cout << "Press any key to throw a test exception.";
    cin.get();
    throw Error(99, "Test Exception");

  }
  catch(Error e)
  {
    cout << "\nException caught successfully.";
    e.err_display();
  }

  cin.get();
  return 0;
}
