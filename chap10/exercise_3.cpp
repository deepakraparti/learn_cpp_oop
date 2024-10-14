#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  char ch, prevch = '\0';
  int lines = 0;
  int words = 0;
  int chars = 0;
  int exit = 0;
  char line[100];

  while(exit == 0)
  {
    ch = getchar();

    if (ch == '\n' && prevch == '\n')
    {
      break;
    }

    ++chars;

    if (ch == ' ' || ch == '\t' || (ch == '\n' && prevch != '\n'))
    {
      ++words;
    }

    if ( ch == '\n')
    {
      ++lines;
    }

    prevch = ch;
  }

  cout.setf(ios::left, ios::adjustfield);
  cout << setw(25) << "Number of lines" << setw(25) << "Number of words" << "Number of characters"<< endl;
  cout.setf(ios::right, ios::adjustfield);
  cout << setw(15) << lines << setw(25) << words << setw(25) << chars << endl;
  
  return 0;
}
