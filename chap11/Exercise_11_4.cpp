#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

class telephone
{
    char name[20];
    char number[20];

  public:
    void putdata()
    {
      cout.setf(ios::left, ios::adjustfield);
      cout << setw(15) << name
           << setw(15) << number
           << endl;
    }

    char *getName()
    {
      return name;
    }

    char *getNumber()
    {
      return number;
    }

    void setNumber(char *num)
    {
      strcpy(number, num);
    }
};

void print_file_data(fstream &inoutfile)
{
  telephone t;
  inoutfile.seekg(0);
  while (inoutfile.read((char *) &t, sizeof(t)))
  {
    t.putdata();
  }

  inoutfile.clear();
}

int main()
{
  telephone t;
  char name[20];
  char number[20];
  int c;

  // Open the file with both input and output modes
  fstream inoutfile("TELEPHONE_DIARY", ios::in | ios::out | ios::binary);

  while (1)
  {
    inoutfile.seekg(0, ios::beg);
    cout << "Select the operation from below list: " << endl;
    cout << "1. Search for the telephone number" << endl;
    cout << "2. Search for the name" << endl;
    cout << "3. Update telephone number" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> c;

    switch (c)
    {
      case 1:
        cout << "\nEnter the name: ";
        cin >> name;

        while (inoutfile.read((char *) &t, sizeof(t)))
        {
          if (strcmp(t.getName(), name) == 0)
          {
            cout << "Number is: " << t.getNumber() << endl;
            break;
          }
        }

        if (inoutfile.eof())
        {
          cout << "\nSorry, the name doesn't exist\n";
          inoutfile.clear();
        }

        break;

      case 2:
        cout << "\nEnter the number: ";
        cin >> number;

        while (inoutfile.read((char *) &t, sizeof(t)))
        {
          if (strcmp(t.getNumber(), number) == 0)
          {
            cout << "Name is: " << t.getName() << endl;
            break;
          }
        }

        if (inoutfile.eof())
        {
          cout << "Sorry, the number does not exist\n";
          inoutfile.clear();
        }
        break;

      case 3:
        cout << "\nEnter the name: ";
        cin >> name;

        while (inoutfile.read((char *) &t, sizeof(t)))
        {
          if (strcmp(t.getName(), name) == 0)
          {
            cout << "Enter the new number: ";
            cin >> number;
            
            t.setNumber(number);
            cout << "Number is: " << t.getNumber() << endl;
            
            long position = inoutfile.tellg() - sizeof(t);
            inoutfile.seekp(position, ios::beg);  // Use seekp for writing
            inoutfile.write((char *) &t, sizeof(t)) << flush;
            break;
          }
        }

        if (inoutfile.eof())
        {
          cout << "\nSorry, the name doesn't exist\n";
          inoutfile.clear();
        }
        else
        {
          print_file_data(inoutfile);
        }
        break;

      case 4:
        goto exit;
    }
  }

exit:
  inoutfile.close();

  return 0;
}

