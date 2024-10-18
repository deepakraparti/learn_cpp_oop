#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  char c;
  ofstream outfile("OUTPUT.TXT");
  ifstream infile("INPUT.TXT");

  while(infile)
  {
    infile.get(c);
    if(c == ' ')
    {
      outfile.put(c);

      while(infile)
      {
        infile.get(c);
        if (c != ' ')
        {
          outfile.put(c);
          break;
        }
      }
    }
    else
    {
      outfile.put(c);
    }
  }

  return 0;
}
