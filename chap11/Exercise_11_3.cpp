#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class telephone
{
    char name[20];
    char number[20];

  public:
    void getdata()
    {
      cout << "Enter name: "; cin >> name;
      cout << "Enter number: "; cin >> number;
    }
};

int main()
{
  telephone t[2];
  
  for (int i = 0; i < 2; i++)
  {
    t[i].getdata();
  }

  cout << "Storing data to the file\n";

  ofstream outf("TELEPHONE_DIARY");
  for (int i = 0; i < 2; i++)
  {
    outf.write((char *) &t[i], sizeof(t[i]));
  }
}
