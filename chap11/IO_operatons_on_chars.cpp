#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
  char string[80];

  cout << "Enter a string: ";
  cin >> string;

  int len = strlen(string);

  fstream file;
  cout << "\nOpening the text file and storing the data in it." << len << "\n\n";
  file.open("TEXT", ios::in | ios::out | ios::trunc);

  for (int i = 0; i < len; i++)
  {
    file.put(string[i]);
  }

  file.seekg(0);	// move to the beginning of the file

  char ch;
  cout << "Reading the file contents: ";
  while(file)
  {
    file.get(ch);
    cout << ch;
  }

  cout << "\n";
  return 0;
}
