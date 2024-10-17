// This program makes use of the STOCK.DAT file generated using the 
// program reading_writing_class_objects.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class INVENTORY
{
    char name[10];
    int code;
    float cost;
  public:
    void getdata()
    {
      cout << "Enter name: "; cin >> name;
      cout << "Enter code: "; cin >> code;
      cout << "Enter cost: "; cin >> cost;
    }

    void putdata(void)
    {
      cout << setw(10) << name
           << setw(10) << code
           << setprecision(2) << setw(10) << cost
           << endl;
    }
};

int main()
{
  INVENTORY item;
  fstream file;

  file.open("STOCK.DAT", ios::ate | ios::in | ios::out | ios::binary);
  file.seekg(0, ios::beg);

  cout << "CURRENT CONTENTS OF STOCK" << "\n";

  while(file.read((char *) &item, sizeof(item)))
  {
    item.putdata();
  }

  file.clear();	// Turn off EOF flag

  // ADD the object
  cout << "\nADD AN ITEM\n";
  item.getdata();
  char ch;
  cin.get(ch);
  file.write((char *) &item, sizeof(item));

  file.seekg(0);
  cout << "CONTENTS OF APPENDED FILE\n";

  while(file.read((char *) &item, sizeof(item)))
  {
    item.putdata();
  }

  file.clear();
  file.seekg(0, ios::end);

  // Find the number of objects in a file;
  int last = file.tellg();
  int n = last/sizeof(item);

  cout << "Number of objects = " << n << "\n";
  cout << "Total bytes in the file = " << last << "\n";


  // MODIFY the object
  cout << "\nEnter object number to be updated: \n";
  int object;
  cin >> object;
  cin.get(ch);

  int location = (object-1) * sizeof(item);

  if (file.eof())
  {
    file.clear();
  }

  file.seekp(location);
  cout << "Enter new values of the object: \n";
  item.getdata();
  cin.get(ch);

  file.write((char *) &item, sizeof(item)) << flush;

  // SHOW updated file
  file.seekg(0);
  cout << "CONTENTS of UPDATED FILE\n";

  while(file.read((char *) &item, sizeof(item)))
  {
    item.putdata();
  }

  file.close();
  
  return 0;  
}
