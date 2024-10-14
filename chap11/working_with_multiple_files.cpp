#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ofstream fout;
  fout.open("country");
  fout << "India\n";
  fout << "USA\n";
  fout << "UK\n";
  fout.close();

  fout.open("capital");
  fout << "Delhi\n";
  fout << "Washington\n";
  fout << "London\n";
  fout.close();

  cout << "\n";

  const int N = 80;
  char line[N];

  ifstream fin;
  fin.open("country");
  cout << "List of countries:\n";
  while(fin)
  {
    fin.getline(line, N);
    cout << line << endl;
  }

  fin.close();

  fin.open("capital");
  cout << "List of capitals:\n";

  while(fin)
  {
    fin.getline(line, N);
    cout << line << endl;
  }
 
  fin.close();
 
  return 0;
}
